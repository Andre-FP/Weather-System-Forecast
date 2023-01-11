import pandas as pd
from sklearn.linear_model import LinearRegression


def wether_predict(dataset_path, target_column, day):
    """Predict wether climate selected on the target day

    Args:
        dataset_path (str): csv dataset path
        target_column (str): column choosed to be the target
        day (str): day on format "DD/MM/AAAA"

    Returns:
        list: prediction_desired, real_value
    """
    shift_times = 3
    day = format_day(day)

    ### Tirando as duas primeiras linhas ###
   
    # Verificando se já foi tirado as duas primeiras linhas do csv 
    with open(dataset_path, 'r') as ff:
        lines = ff.readlines()     
    
    if lines[0] != "\n":
        # Tirando as duas primeiras linhas 
        with open(dataset_path, 'r+') as ff:
            lines = ff.readlines()
            ff.seek(0)
            ff.truncate()
            ff.writelines(lines[2:])

    ### Lendo o csv ###
    df = pd.read_csv(dataset_path)

    # Guardando as colunas sem shift
    columns_no_shift = list(df.columns)
    columns_no_shift.remove("time")

    ## Shiftando o dataset para incluir dados passados
    columns = list(df.columns)
    columns.remove("time")
    for column in columns:
        first = column.split("_")[0]
        last = column.split("_")[-1]
        last = last.split(" ")[0]
        
        df[f"{first}_{last}_lastDay"] = df[column].shift(1)
        for i in range(1, shift_times):
            df[f"{first}_{last}_{i+1}DaysBack"] = df[column].shift(i + 1)

    df = df.drop(df.index[0:shift_times])
    df = df.reset_index()
    df = df.drop("index", axis=1)

    exclude_columns = columns_no_shift.copy()
    exclude_columns.remove(target_column)
    df = df.drop(exclude_columns, axis=1)

    ## Separando treino e teste
    df_test = df.iloc[-341:]
    df_train = df.drop(df.index[-341:])
    df_test.reset_index(inplace=True, drop=True)

    ## Separando X e Y
    time = df_train["time"]
    time = pd.DataFrame(time)
    Y_train = df_train[target_column]
    X_train = df_train.drop(["time", target_column], axis=1)

    time_test = df_test["time"]
    time_test = pd.DataFrame(time_test)
    Y_test = df_test[target_column]
    X_test = df_test.drop(["time", target_column], axis=1)

    ## Treinando
    rgs = LinearRegression()
    rgs = rgs.fit(X_train, Y_train)

    ## Validando
    y_pred = rgs.predict(X_test)
    y_pred = list(y_pred)
    if target_column == "rain_sum (mm)":
        y_pred = [0.0 if yi < 0 else yi for yi in y_pred ]

    ## Retornando a previsão desejada
    time_test["predictions"] = pd.Series(list(y_pred))
    time_test["real_value"] = Y_test

    prediction_desired = float(time_test.loc[time_test["time"] == day, "predictions"])
    real_value = float(time_test.loc[time_test["time"] == day, "real_value"])

    return f"{prediction_desired} {real_value}"

def format_day(day):
    """Convert day string to the right format

    Args:
        day (str): day on format "DD/MM/AAAA"

    Returns:
        str: day on format "AAAA-MM-DD" '30/12/2022'
    """
    dd, mm, aaaa = day.split("/")
    return f"{aaaa}-{mm}-{dd}"



if __name__ == '__main__':
    target_column = "windspeed_10m_max (km/h)"
    dataset_path = './datas/archive_porto_alegre.csv'
    day = '01/12/2022'
    prediction, real_value = wether_predict(dataset_path, target_column, day)
    
    print("\nPrediction:", prediction)
    print("Real Value:", real_value)

    # Possíveis colunas: 
    # temperature_2m_max (°C)	
    # temperature_2m_min (°C)	
    # shortwave_radiation_sum (MJ/m²)	
    # rain_sum (mm)	
    # windspeed_10m_max (km/h)
