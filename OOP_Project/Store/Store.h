#pragma once

#include <string>
using namespace std;

#include "Product.h"

class Store {
private:
    string _name;
    Product _products [10];
    float _todayBalance;
    bool _closed;

public:
    Store();

    Product getProduct(int id);
    float getTodayBalance();

    void open();
    void close();
    void registerSale(int productId);
    void showProducts();
    
};
