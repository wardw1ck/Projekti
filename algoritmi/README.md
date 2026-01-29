<!-- README.md -->
# Stock Data Management System

This project implements a `StockData` class in C++ to efficiently manage and query stock data. The class supports various queries and allows for manual entry of stock records.

## Features

1. Retrieve all stock data for a specific date.
2. Calculate the average closing price of a specific stock in the entire data set.
3. Find the highest price for a specific stock in a given time period.
4. Identify all unique stock identifiers in the data set.
5. Check if a specific stock tag exists in the data set.
6. Count the number of dates when at least one stock had a closing price above a certain threshold.
7. Get the closing price of a specific share for a specific date.
8. Display all dates and corresponding closing prices for a specific stock.
9. Calculate the total trading volume for a specific stock across the entire data set.
10. Check if there is data for a specific date and a specific share.
11. Retrieve the opening and closing prices for a specific stock and date in constant time.
12. Find the amount of dividends paid on a given stock on a given date.
13. Find the 10 stocks with the highest trading volume on a given date.
14. Retrieve the 5 stocks with the lowest closing prices across the entire data set.
15. Maintain a list of the 5 stocks with the highest dividend payouts over the entire data set period.

## Performance

Each query method prints the time required to perform the operation in milliseconds.

## Manual Entry

The class allows for manual entry of stock records, ensuring that all data structures are updated accordingly.

## Usage

Include the `StockData.h` and `StockData.cpp` files in your project and use the `StockData` class to manage and query stock data.

```cpp
#include "StockData.h"

int main() {
    StockData stockData;
    StockData::Record record = {"2023-10-01", "AAPL", 150.0, 155.0, 157.0, 149.0, 1000000, 0.5};
    stockData.addRecord(record);

    auto data = stockData.getStockDataByDate("2023-10-01");
    for (const auto& rec : data) {
        std::cout << rec.stock_id << " " << rec.close << "\n";
    }

    return 0;
}
```

## Data Format

The data is formatted by `Date,Ticker,Open,High,Low,Close,Volume,Dividends,Stock Splits`.