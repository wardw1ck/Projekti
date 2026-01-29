// StockData.h
#ifndef STOCKDATA_H
#define STOCKDATA_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <chrono>
#include <fstream>
#include <algorithm>

class StockData {
public:
    struct Record {
        std::string date;
        std::string ticker;
        double open;
        double close;
        double high;
        double low;
        int volume;
        double dividends;
    };

    void addRecord(const Record& record); // O(1)
    std::vector<Record> getStockDataByDate(const std::string& date) const; // O(1)
    double getAverageClosingPrice(const std::string& ticker) const; // O(n)
    double getHighestPrice(const std::string& ticker, const std::string& startDate, const std::string& endDate) const; // O(n)
    std::set<std::string> getUniqueTickers() const; // O(n log n)
    bool tickerExists(const std::string& ticker) const; // O(1)
    int countDatesWithClosingPriceAbove(double threshold) const; // O(n)
    double getClosingPrice(const std::string& ticker, const std::string& date) const; // O(1)
    std::vector<std::pair<std::string, double>> getClosingPrices(const std::string& ticker) const; // O(n)
    int getTotalVolume(const std::string& ticker) const; // O(n)
    bool hasData(const std::string& ticker, const std::string& date) const; // O(1)
    std::pair<double, double> getOpenClosePrices(const std::string& ticker, const std::string& date) const; // O(1)
    double getDividends(const std::string& ticker, const std::string& date) const; // O(1)
    std::vector<Record> getTop10VolumeStocks(const std::string& date) const; // O(n log n)
    std::vector<Record> getBottom5ClosingPrices() const; // O(n log n)
    std::vector<std::pair<std::string, double>> getTop5Dividends() const; // O(n log n)
    void loadFromFile(const std::string& filepath); // O(n)

private:
    std::vector<Record> records;
    std::unordered_map<std::string, std::vector<Record>> date_map;
    std::unordered_map<std::string, std::vector<Record>> stock_map;
    std::unordered_map<std::string, std::unordered_map<std::string, Record>> stock_date_map;
    std::unordered_map<std::string, double> stock_volume_map;
    std::unordered_map<std::string, double> stock_dividend_map;
    std::set<std::pair<double, std::string>> closing_price_set;
    std::set<std::pair<double, std::string>> dividend_set;
    std::unordered_map<std::string, std::vector<Record>> data;
    std::unordered_map<std::string, std::unordered_map<std::string, Record>> tickerDateMap;
};

#endif // STOCKDATA_H