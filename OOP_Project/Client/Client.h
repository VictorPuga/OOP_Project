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
    PaymentMethod getCreditCard();
    PaymentMethod getGiftCard();
};
