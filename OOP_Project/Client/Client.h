#pragma once

#include <string>
using namespace std;

#include "PaymentMethod.h"

class Client {
private:
    string _name;
    PaymentMethod _creditCard;
    PaymentMethod _giftCard;
    
public:
    Client(string name, float creditCardBalance, float giftCardBalance);

    string getName();
    float getBalance(string card);

    void buy(string card, float price);
    bool canBuy(string card, float price);
};
