#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"

class MerkelMain
{
public:
    MerkelMain();
    /** call this to start the sim*/
    void init();

private:
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterAsk();
    void enterBid();
    void printWallet();
    void nextTimeFrame();
    int getUserOption();
    void processUseroption(int userOption);

    std::string currentTime;

    OrderBook orderBook{"20200317.csv"};

    Wallet wallet;
};