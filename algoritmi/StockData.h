#ifndef STOCKDATA_H
#define STOCKDATA_H

#include <string>
#include <vector>
#include <unordered_map>
#include <chrono>

class StockData {
public:
    struct Record {
        std::string date;
        std::string stock_id;
        double open;
        double high;
        double low;
        double close;
        int volume;
        double dividends;
    };

    void addRecord(const Record& record);
    std::vector<Record> getStockDataByDate(const std::string& date) const;
    // ...existing code...

private:
    std::unordered_map<std::string, std::vector<Record>> data;
    // ...existing code...
};

#endif // STOCKDATA_H
