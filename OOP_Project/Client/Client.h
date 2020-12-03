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
    Client(string name, float creditBalance, float giftBalance);

    string getName();
    float getBalance(string card);

    void buy(string card, float price);
    bool canBuy(string card, float price);
};
