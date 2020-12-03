#include <iostream>
#include <string>
using namespace std;

#include "Store.h"
#include "Product.h"

Store::Store()
// you need to explicitly initialize `_products`
: _products {
    Product(0, "Prod A", 0, 30.0),
    Product(1, "Prod B", 0, 40.0),
    Product(2, "Prod C", 8, 50.0),
    Product(3, "Prod D", 7, 10.0),
    Product(4, "Prod E", 6, 15.0),
    Product(5, "Prod F", 5, 12.0),
    Product(6, "Prod G", 4, 21.0),
    Product(7, "Prod H", 3, 55.0),
    Product(8, "Prod I", 2, 90.0),
    Product(9, "Prod J", 1, 200.0),
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
    cout << endl;
}

Product Store::getProduct(int id) {
    return _products[id];
}

float Store::getTodayBalance() {
    return _todayBalance;
}
