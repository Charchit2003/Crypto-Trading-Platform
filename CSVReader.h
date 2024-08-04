#pragma once

#include "OrderBookEntry.h"
#include <vector>
#include <string>

class CSVReader
{
public:
    CSVReader();
    // This function doens't need any instance of class to be created.
    static std::vector<OrderBookEntry> readCSV(std::string csvFile);
    static std::vector<std::string> tokenise(std::string csvLine, char separator);
    static OrderBookEntry stringsToOBE(std::string priceString, std::string amountString, std::string timestamp,
                                       std::string product, OrderBookType orderType);

private:
    static OrderBookEntry stringsToOBE(std::vector<std::string> strings);
};