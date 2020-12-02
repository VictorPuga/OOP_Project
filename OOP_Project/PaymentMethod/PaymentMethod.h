#pragma once

#include <string>
using namespace std;

class PaymentMethod {
    string _type;
    float _balance;

public:
    PaymentMethod(string type, float balance);
    
    string getType();
    float getBalance();
    
    bool canBuy(float amount);
    void makePayment(float amount);
    void addFunds(float amount);
};
