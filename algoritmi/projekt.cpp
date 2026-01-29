#include "projekt.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <chrono>

using namespace std;

void StockData::addRecord(const Record& record) {
    data[record.date].push_back(record);
    tickerDateMap[record.ticker][record.date] = record;
}

// Dohvati sve podatke o dionicama za određeni datum.
std::vector<StockData::Record> StockData::getStockDataByDate(const std::string& date) const {
    auto it = data.find(date);
    if (it != data.end()) {
        return it->second;
    }
    return {};
}

// Izračunaj prosječnu završnu cijenu određene dionice u cijelom skupu podataka
double StockData::getAverageClosingPrice(const std::string& ticker) const {
    auto it = tickerDateMap.find(ticker);
    if (it == tickerDateMap.end()) return 0.0;
    double sum = 0.0;
    int count = 0;
    for (const auto& entry : it->second) {
        sum += entry.second.close;
        count++;
    }
    return count ? sum / count : 0.0;
}

// Pronađi najvišu cijenu za određenu dionicu u zadanom vremenskom razdoblju.
double StockData::getHighestPrice(const std::string& ticker, const std::string& startDate, const std::string& endDate) const {
    auto it = tickerDateMap.find(ticker);
    if (it == tickerDateMap.end()) return 0.0;
    double highest = 0.0;
    for (const auto& entry : it->second) {
        if (entry.first >= startDate && entry.first <= endDate) {
            highest = max(highest, entry.second.high);
        }
    }
    return highest;
}

// Identificiraj sve jedinstvene oznake dionica u skupu podataka
std::set<std::string> StockData::getUniqueTickers() const {
    std::set<std::string> tickers;
    for (const auto& entry : tickerDateMap) {
        tickers.insert(entry.first);
    }
    return tickers;
}

// Provjeri postoji li određena oznaka dionice u skupu podataka
bool StockData::tickerExists(const std::string& ticker) const {
    return tickerDateMap.find(ticker) != tickerDateMap.end();
}

// Izbroji broj datuma kada je barem jedna dionica imala završnu cijenu iznad određenog praga.
int StockData::countDatesWithClosingPriceAbove(double threshold) const {
    std::set<std::string> dates;
    for (const auto& entry : tickerDateMap) {
        for (const auto& record : entry.second) {
            if (record.second.close > threshold) {
                dates.insert(record.first);
            }
        }
    }
    return dates.size();
}

// Dohvati završnu cijenu određene dionice za određeni datum
double StockData::getClosingPrice(const std::string& ticker, const std::string& date) const {
    auto it = tickerDateMap.find(ticker);
    if (it != tickerDateMap.end()) {
        auto dateIt = it->second.find(date);
        if (dateIt != it->second.end()) {
            return dateIt->second.close;
        }
    }
    return 0;
}

// Prikaži sve datume i odgovarajuće završne cijene za određenu dionicu.
std::vector<std::pair<std::string, double>> StockData::getClosingPrices(const std::string& ticker) const {
    std::vector<std::pair<std::string, double>> prices;
    auto it = tickerDateMap.find(ticker);
    if (it != tickerDateMap.end()) {
        for (const auto& entry : it->second) {
            prices.emplace_back(entry.first, entry.second.close);
        }
    }
    return prices;
}

// Izračunaj ukupni volumen trgovanja za određenu dionicu kroz cijeli skup podataka
int StockData::getTotalVolume(const std::string& ticker) const {
    auto it = tickerDateMap.find(ticker);
    if (it == tickerDateMap.end()) return 0;
    int totalVolume = 0;
    for (const auto& entry : it->second) {
        totalVolume += entry.second.volume;
    }
    return totalVolume;
}

// Provjeri ima li podataka za određeni datum i određenu dionicu.
bool StockData::hasData(const std::string& ticker, const std::string& date) const {
    auto it = tickerDateMap.find(ticker);
    if (it != tickerDateMap.end()) {
        return it->second.find(date) != it->second.end();
    }
    return false;
}

// Dohvati cijene otvaranja i zatvaranja za određenu dionicu i datum u konstantnom vremenu.
std::pair<double, double> StockData::getOpenClosePrices(const std::string& ticker, const std::string& date) const {
    auto it = tickerDateMap.find(ticker);
    if (it != tickerDateMap.end()) {
        auto dateIt = it->second.find(date);
        if (dateIt != it->second.end()) {
            return {dateIt->second.open, dateIt->second.close};
        }
    }
    return {0.0, 0.0};
}

// Pronađi iznos dividendi isplacenih za određenu dionicu na određeni datum.
double StockData::getDividends(const std::string& ticker, const std::string& date) const {
    auto it = tickerDateMap.find(ticker);
    if (it != tickerDateMap.end()) {
        auto dateIt = it->second.find(date);
        if (dateIt != it->second.end()) {
            return dateIt->second.dividends;
        }
    }
    return 0.0;
}

// Pronađi 10 dionica s najvećim volumenom trgovanja na određeni datum.
std::vector<StockData::Record> StockData::getTop10VolumeStocks(const std::string& date) const {
    auto it = data.find(date);
    if (it == data.end()) return {};
    std::vector<Record> records = it->second;
    std::sort(records.begin(), records.end(), [](const Record& a, const Record& b) {
        return b.volume < a.volume;
    });
    if (records.size() > 10) records.resize(10);
    return records;
}

// Dohvati 5 dionica s najnižim završnim cijenama kroz cijeli skup podataka.
std::vector<StockData::Record> StockData::getBottom5ClosingPrices() const {
    std::vector<Record> allRecords;
    for (const auto& entry : data) {
        for (const auto& record : entry.second) {
            allRecords.push_back(record);
        }
    }
    std::sort(allRecords.begin(), allRecords.end(), [](const Record& a, const Record& b) {
        return a.close < b.close;
    });
    if (allRecords.size() > 5) allRecords.resize(5);
    return allRecords;
}

// Održavaj popis 5 dionica s najvećim isplaćenim dividendama tijekom cijelog razdoblja skupa podataka.
std::vector<std::pair<std::string, double>> StockData::getTop5Dividends() const {
    std::unordered_map<std::string, double> dividendMap;
    for (const auto& entry : tickerDateMap) {
        for (const auto& record : entry.second) {
            dividendMap[entry.first] += record.second.dividends;
        }
    }
    std::vector<std::pair<std::string, double>> dividends(dividendMap.begin(), dividendMap.end());
    std::sort(dividends.begin(), dividends.end(), [](const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
        return b.second < a.second;
    });
    if (dividends.size() > 5) dividends.resize(5);
    return dividends;
}




















void StockData::loadFromFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Nije otvorilo nekak: " << filepath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string token;
        Record record;

        std::getline(ss, record.date, ',');
        std::getline(ss, record.ticker, ',');
        try {
            std::getline(ss, token, ',');
            record.open = std::stod(token);
            std::getline(ss, token, ',');
            record.high = std::stod(token);
            std::getline(ss, token, ',');
            record.low = std::stod(token);
            std::getline(ss, token, ',');
            record.close = std::stod(token);
            std::getline(ss, token, ',');
            record.volume = std::stoi(token);
            std::getline(ss, token, ',');
            record.dividends = std::stod(token);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument: " << e.what() << " in line: " << line << std::endl;
            continue;
        } catch (const std::out_of_range& e) {
            std::cerr << "Out of range: " << e.what() << " in line: " << line << std::endl;
            continue;
        }

        addRecord(record);
    }
    file.close();
}