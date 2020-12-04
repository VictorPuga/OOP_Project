#include <iostream>
#include <string>
using namespace std;

#include "Store.h"
#include "Product.h"

Store::Store()
// we need to explicitly initialize `_products`
: _products {
    Product(0, "Product A", 0, 30.0),
    Product(1, "Product B", 0, 40.0),
    Product(2, "Product C", 8, 50.0),
    Product(3, "Product D", 7, 10.0),
    Product(4, "Product E", 6, 15.0),
    Product(5, "Product F", 5, 12.0),
    Product(6, "Product G", 4, 21.0),
    Product(7, "Product H", 3, 55.0),
    Product(8, "Product I", 2, 90.0),
    Product(9, "Product J", 1, 200.0),
} {
    _name = "Walmart";
    _closed = true;
}

void Store::open() {
    _closed = false;
}

void Store::close() {
    _closed = true;
}

void Store::registerSale(int productId) {
    if (!_closed) {
        _products[productId].sell();
        _todayBalance += _products[productId].getPrice();
        cout << _products[productId].getQuantity() << " "  << " remaining" << endl;
    }
}

void Store::showProducts() {
    for (int i = 0; i < 10; i++) {
        cout
            << _products[i].getId()
            << ") "
            << _products[i].getName()
            << " $"
            << _products[i].getPrice()
            << " ("
            << _products[i].getQuantity()
            << " in stock)"
            << endl;
    }
    cout << endl;
}

Product Store::getProduct(int id) {
    return _products[id];
}

float Store::getTodayBalance() {
    return _todayBalance;
}
