#include <iostream>
#include <string>
using namespace std;

#include "Store.h"
#include "Product.h"

Store::Store() {
    _name = "Walmart";
    
    string productNames [10] = {
        "Prod A",
        "Prod B",
        "Prod C",
        "Prod D",
        "Prod E",
        "Prod F",
        "Prod G",
        "Prod H",
        "Prod I",
        "Prod J",
    };

    int productQuantities [10] = {
        0,
        0,
        8,
        7,
        6,
        5,
        4,
        3,
        2,
        1,
    };

    float productPrices [10] = {
        30.0,
        40.0,
        50.0,
        10.0,
        15.0,
        12.0,
        21.0,
        55.0,
        90.0,
        400.0,
    };

    for (int i = 0; i < 10; i++) {
        // "initialize" products
        _products[i].setData(i, productNames[i], productQuantities[i], productPrices[i]);
    }
}

void Store::open() {
    _closed = false;
}

void Store::close() {
    _closed = true;
}

void Store::registerSale(float price) {
    if (!_closed) {
        _todayBalance += price;
    }
}

void Store::showProducts() {
    for (int i = 0; i < 10; i++) {
        Product prod = _products[i];
        cout
            << prod.getId()
            << ") "
            << prod.getName()
            << " $"
            << prod.getPrice()
            << " ("
            << prod.getQuantity()
            << " in stock)"
            << endl;
    }
}

Product Store::getProduct(int id) {
    return _products[id];
}

float Store::getTodayBalance() {
    return _todayBalance;
}
