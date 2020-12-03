#include <string>
using namespace std;

#include "Client.h"
#include "PaymentMethod.h"

Client::Client(string name, float creditBalance, float giftBalance)
// You need to explicityly initialize the `PaymentMethod`s
    : _creditCard("CREDIT", creditBalance),
      _giftCard("GIFT", giftBalance)
{
    _name = name;
}

string Client::getName() {
    return _name;
}

void Client::buy(string card, float price) {
    if (card == "CREDIT") {
        _creditCard.makePayment(price);
    }
    else if (card == "GIFT") {
        _giftCard.makePayment(price);
    }
}

bool Client::canBuy(string card, float price) {
    if (card == "CREDIT") {
        return _creditCard.canBuy(price);
    }
    else if (card == "GIFT") {
        return _giftCard.canBuy(price);
    }
    return false;
}

float Client::getBalance(string card) {
    if (card == "CREDIT") {
        return _creditCard.getBalance();
    }
    else if (card == "GIFT") {
        return _giftCard.getBalance();
    }
    return false;
}
