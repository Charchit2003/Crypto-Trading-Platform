# Crypto Trading Platform

Crypto Trading Platform, a powerful and fully functional object-oriented C++ application that enables you to trade various cryptocurrencies such as Bitcoin (BTC) and Ethereum (ETH) efficiently. The project implements several advanced C++ concepts, including static functions, function overloading, and more, to provide a robust and seamless trading experience.

One of the key highlights of this platform is the implementation of an order book and a sophisticated matching algorithm. The order book efficiently organizes all the buy (bids) and sell (asks) orders at different price levels. The matching algorithm ensures that buy orders are matched with appropriate sell orders, facilitating seamless transactions and timely order resolution.

## Features

* Print market stats.
* Make an ask or a bid.
* Check your wallet balance.

## Key Functionalities

The platform offers the following essential functionalities:

- **Print Market Stats**: Users can access and view market statistics. Although static data is currently used for demonstration purposes, the platform can be extended to fetch real-time market data from various sources.

- **Make an Ask/Bid**: Users can place sell (ask) and buy (bid) orders for various cryptocurrencies. The platform dynamically adds these orders to the order book, organizing them based on the appropriate timestamp.

- **Wallet Balance**: Users can check the balance in their virtual wallet, which keeps track of their holdings and available funds.

- **Time Frame Resolution**: The platform supports different time frames for trading activities. At the end of each time frame, all pending asks and bids from the previous timestamp are resolved and updated accordingly.

- **CSV Order Import**: The application reads order data from a CSV file and generates an order book from it. This feature enables users to simulate and analyze historical trading data efficiently.

## Usage

- Clone the repository.
```
git clone https://github.com/gautamV19/Crypto-Trading-Plateform.git
```
-  Compile the code using the following command:
```
g++ main.cpp -o trading_platform
```
- Run the trading platform using the following command:
```
./trading_platform
```
- Successful execution will show this:
```
1: Print help
2: Print exchange stats
3: Make an offer
4: Make a bid
5: Print wallet
6: Continue
===========
Current time is: 2020/03/17 17:01:24.884492
Type in 1-6
```

## Credits

This project was created by [@gautamV19](https://www.github.com/gautamV19).
