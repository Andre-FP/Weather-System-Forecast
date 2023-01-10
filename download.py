import requests
import pandas as pd
from tqdm import tqdm


def download_dataset(city, latitude, longitude, end_date="2022-12-31"):
    response = requests.get(f"https://archive-api.open-meteo.com/v1/archive?latitude={latitude}&longitude={longitude}&start_date=2018-01-01&end_date=2022-12-31&daily=temperature_2m_max,temperature_2m_min,shortwave_radiation_sum,rain_sum,windspeed_10m_max&timezone=America%2FSao_Paulo"
    )

    # Saving dataset
    data = response.json()
    table_data = data["daily"]
    pd.DataFrame(table_data).to_csv(f"./datas/{city}.csv")
    table = pd.read_csv(f"./datas/{city}.csv")


def download_all_datasets(end_date="2022-12-31"):
    gps_infos = {
        "RioDeJaneiro": (-22.91, -43.18),
	    "SãoPaulo": (-23.55, -46.64),
	    "PortoAlegre": (-30.03, -51.23),
	    "Florianópolis": (-27.60, -48.55),
	    "RioBranco": (-9.97, -67.81),
	    "Manaus": (-3.10, -60.02),
	    "Recife": (-8.05, -34.88),
	    "Natal": (-5.79, -35.21),
	    "Cuiabá": (-15.60, -56.10),
	    "Brasília": (-15.78, -47.93)
    }
    print("Baixando os dados...")
    for city, coordinates in tqdm(gps_infos.items()):
        download_dataset(city, coordinates[0], coordinates[1], end_date)

if __name__ == "__main__":
    download_all_datasets()