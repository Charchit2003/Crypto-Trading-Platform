#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include <limits>

#include "OrderBookEntry.h"
#include "CSVReader.h"

MerkelMain::MerkelMain()
{
}

void MerkelMain::init()
{
    int input;
    currentTime = orderBook.getEarliestTime();

    wallet.insertCurrency("BTC", 10);

    while (true)
    {
        printMenu();
        input = getUserOption();
        processUseroption(input);
    }
}

void MerkelMain::printMenu()
{
    /**
     * print help
     * print exchange stats
     * make an offer
     * make a bid
     * print wallet
     * continue
     */

    std::cout << "1: Print help" << std::endl;
    std::cout << "2: Print exchange stats" << std::endl;
    std::cout << "3: Make an offer" << std::endl;
    std::cout << "4: Make a bid" << std::endl;
    std::cout << "5: Print wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;

    std::cout << "===========" << std::endl;

    std::cout << "Current time is: " << currentTime << std::endl;
}

int MerkelMain::getUserOption()
{
    std::cout << "Type in 1-6" << std::endl;

    int userOption = 0;
    std::string line;
    std::getline(std::cin, line);
    try
    {
        userOption = std::stoi(line);
    }
    catch (const std::exception &e)
    {
    }

    std::cout << "You chose: " << userOption << std::endl;

    return userOption;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers." << std::endl;
}
void MerkelMain::printMarketStats()
{
    for (std::string const &p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
    }
    // std::cout << "Orderbook Contains :" << orders.size() << " entries." << std::endl;
    // unsigned int asks = 0;
    // unsigned int bids = 0;

    // for (OrderBookEntry &e : orders)
    // {
    //     if (e.orderType == OrderBookType::ask)
    //     {
    //         asks++;
    //     }
    //     if (e.orderType == OrderBookType::bid)
    //     {
    //         bids++;
    //     }
    // }

    // std::cout << "Orderbook Contains :" << asks << " " << bids << std::endl;
}
void MerkelMain::enterAsk()
{
    std::cout << "Make a ask - enter the amount: product, price, amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterAsk Bad input!" << input << std::endl;
    }
    else
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::ask);
            obe.username = "simuser";

            if (wallet.canFulfillOrder(obe))
            {
                std::cout << "Wallet looks good." << std::endl;
                orderBook.insertOrder(obe);
            }
            else
            {
                std::cout << "Wallet has insufficient funds." << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "MerkelMain::enterAsk Bad input" << std::endl;
        }
    }

    std::cout << "you typed " << input << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter the amount: product, price, amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterBid  Bad input!" << input << std::endl;
    }
    else
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::bid);
            obe.username = "simuser";

            if (wallet.canFulfillOrder(obe))
            {
                std::cout << "Wallet looks good." << std::endl;
                orderBook.insertOrder(obe);
            }
            else
            {
                std::cout << "Wallet has insufficient funds." << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "MerkelMain::enterBid Bad input" << std::endl;
        }
    }

    std::cout << "you typed " << input << std::endl;
}
void MerkelMain::printWallet()
{
    // std::cout << "Your wallet is empty." << std::endl;
    std::cout << wallet.toString() << std::endl;
}
void MerkelMain::nextTimeFrame()
{
    std::cout << "Going to next time frame." << std::endl;

    for (std::string &p : orderBook.getKnownProducts())
    {
        std::cout << "matching " << p << std::endl;
        std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids(p, currentTime);
        std::cout << "Sales: " << sales.size() << std::endl;
        for (OrderBookEntry &sale : sales)
        {
            std::cout << "Sale Price: " << sale.price << " "
                      << "Sale Amount: " << sale.amount << std::endl;

            if (sale.username == "simuser")
            {
                // update wallet
                wallet.processSale(sale);
            }
        }
    }

    currentTime = orderBook.getNextTime(currentTime);
}
void MerkelMain::processUseroption(int userOption)
{
    if (userOption == 0)
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enterAsk();
    }
    if (userOption == 4)
    {
        enterBid();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        nextTimeFrame();
    }
}