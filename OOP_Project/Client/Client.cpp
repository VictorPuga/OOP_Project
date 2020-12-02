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

PaymentMethod Client::getCreditCard() {
    return _creditCard;
}

PaymentMethod Client::getGiftCard() {
    return _giftCard;
}
