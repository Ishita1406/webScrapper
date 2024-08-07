from bs4 import BeautifulSoup
import requests

def get_valid_url(prompt):
    while True:
        url = input(prompt)
        response = requests.get(url, headers=headers)
        if response.status_code == 200:
            return url
        else:
            print("Invalid URL. Please enter a valid URL.")

headers = {"User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/117.0.0.0 Safari/537.36"}

URL_Amazon = get_valid_url("Enter the Amazon product URL: ")
page1 = requests.get(URL_Amazon, headers=headers)
soup1 = BeautifulSoup(page1.content, "html.parser")
soup2 = BeautifulSoup(soup1.prettify(), "html.parser")
title1  = soup2.find('span', {'id':"productTitle"}).text.strip()
price1 = soup2.find('span', {'class':"a-price-whole"}).text.strip()[0:20]
print("Title: {}".format(title1))
print("Price: Rs.{}".format(price1.strip()))

URL_snapdeal = get_valid_url("Enter the Snapdeal product URL: ")
page2 = requests.get(URL_snapdeal, headers=headers)
soup3 = BeautifulSoup(page2.content, "html.parser")
soup4 = BeautifulSoup(soup3.prettify(), "html.parser")
title2 = soup4.find('h1', {'class':"pdp-e-i-head"}).text.strip()
price2 = soup4.find('span', {'class':"payBlkBig"}).text.strip()
print("Title: {}".format(title2))
print("Price: Rs.{}".format(price2))