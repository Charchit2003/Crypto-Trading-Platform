#include <iostream>
#include <string>
#include <vector>

#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
#include "Wallet.h"

int main()
{
    MerkelMain app{};
    app.init();

    // Wallet wallet;
    // wallet.insertCurrency("BTC", 5);
    // wallet.insertCurrency("USDT", 10);
    // std::cout << "wallet has BTC " << wallet.containsCurrency("USDT", 10) << std::endl;
    // std::cout << wallet.toString() << std::endl;
    // wallet.removeCurrency("USDT", 7);
    // std::cout << wallet.toString() << std::endl;

    // CSVReader::readCSV("20200317.csv");

    return 0;
}
