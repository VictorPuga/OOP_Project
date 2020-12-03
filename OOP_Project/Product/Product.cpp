#include <string>
using namespace std;

#include "Product.h"

Product::Product(int id, string name, int quantity, float price) {
    _id = id;
    _name = name;
    _quantity = quantity;
    _price = price;
}

int Product::getId() {
    return _id;
}

string Product::getName() {
    return _name;
}

int Product::getQuantity() {
    return _quantity;
}

float Product::getPrice() {
    return _price;
}

bool Product::isAvailable() {
    return _quantity > 0;
}

void Product::sell() {
    if (isAvailable()) {
        _quantity--;
    }
}

