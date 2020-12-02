#include <string>
using namespace std;

#include "PaymentMethod.h"

PaymentMethod::PaymentMethod(string type, float balance) {
    _type = type;
    _balance = balance;
}

string PaymentMethod::getType() {
    return _type;
}

float PaymentMethod::getBalance() {
    return _balance;
}

bool PaymentMethod::canBuy(float amount) {
    return amount <= _balance;
}

void PaymentMethod::makePayment(float amount) {
    if (canBuy(amount)) {
        _balance -= amount;
    }
}

void PaymentMethod::addFunds(float amount) {
    _balance += amount;
}
