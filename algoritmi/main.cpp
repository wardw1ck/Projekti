#include "projekt.h"
#include <iostream>

int main() {
    StockData stockData;
    stockData.loadFromFile("data.txt");

    auto dataByDate = stockData.getStockDataByDate("1962-01-02");
    std::cout << "prvi:\n";
    for (const auto& rec : dataByDate) {
        std::cout << rec.ticker << " " << rec.close << "\n";
    }

    double avgClose = stockData.getAverageClosingPrice("IBM");
    std::cout << "drugi: " << avgClose << "\n";

    double highestPrice = stockData.getHighestPrice("IBM", "1962-01-01", "1962-01-31");
    std::cout << "treci u sijecnju 1062: " << highestPrice << "\n";

    auto uniqueTickers = stockData.getUniqueTickers();
    std::cout << "cetvrti:\n";
    for (const auto& ticker : uniqueTickers) {
        std::cout << ticker << "\n";
    }

    bool exists = stockData.tickerExists("IBM");
    std::cout << "peti trebo bi bit da? " << (exists ? "Yes" : "No") << "\n";

    int countDates = stockData.countDatesWithClosingPriceAbove(0.5);
    std::cout << "sesti: " << countDates << "\n";
    
    
    double closingPrice = stockData.getClosingPrice("IBM", "1962-01-02");
    std::cout << "sedmi na ibm 1962-01-02: " << closingPrice << "\n";

    auto closingPrices = stockData.getClosingPrices("IBM");
    std::cout << "osmi ibm:\n";
    for (const auto& price : closingPrices) {
        std::cout << price.first << ": " << price.second << "\n";
    }

    int totalVolume = stockData.getTotalVolume("IBM");
    std::cout << "deveti ibm: " << totalVolume << "\n";

    bool hasData = stockData.hasData("IBM", "1962-01-02");
    std::cout << "deseti ibm 1962-01-02? " << (hasData ? "Yes" : "No") << "\n";

    auto openClosePrices = stockData.getOpenClosePrices("IBM", "1962-01-02");
    std::cout << "jedanaesti ibm 1962-01-02: " << openClosePrices.first << ", " << openClosePrices.second << "\n";

    double dividends = stockData.getDividends("IBM", "1962-01-02");
    std::cout << "dvanaesti ibm 1962-01-02: " << dividends << "\n";

    auto top10VolumeStocks = stockData.getTop10VolumeStocks("1962-01-02");
    std::cout << "trinaesti 1962-01-02:\n";
    for (const auto& rec : top10VolumeStocks) {
        std::cout << rec.ticker << " " << rec.volume << "\n";
    }

    auto bottom5ClosingPrices = stockData.getBottom5ClosingPrices();
    std::cout << "cetrnaesti:\n";
    for (const auto& rec : bottom5ClosingPrices) {
        std::cout << rec.ticker << " " << rec.close << "\n";
    }

    auto top5Dividends = stockData.getTop5Dividends();
    std::cout << "petnaesti:\n";
    for (const auto& div : top5Dividends) {
        std::cout << div.first << ": " << div.second << "\n";
    }

    return 0;
}
