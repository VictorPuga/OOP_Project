#include <iostream>
#include <string>
using namespace std;

#include "Store.h"
#include "Product.h"
#include "PaymentMethod.h"
#include "Client.h"

void testPurchase(Store *store, Client *client, int prodId, string card) {
    Product prod = store->getProduct(prodId);
    
    cout << "Selling " << prod.getName() << "..." << endl;
    
    if (!prod.isAvailable()) {
        cout << "This product is sold out" << endl << endl;
    } else  if (!client->canBuy(card, prod.getPrice())) {
        cout << "This payment method does't have enough balance" << endl << endl;
    } else {
        client->buy(card, prod.getPrice());
        store->registerSale(prodId);

        cout
            << "Payment successfull" << endl
            << "You now have $" << client->getBalance(card) << " in " << card << " card" << endl << endl;
    }
}

int main() {
    Store walmart;
    Client client("John", 300, 50);
    
    walmart.open();
    cout << "Welcome to Walmart Online Store, what do you want to buy?" << endl;
    walmart.showProducts();
    
    // expected: success
    testPurchase(&walmart, &client, 3, "CREDIT");
    
    // expected: success
    testPurchase(&walmart, &client, 3, "GIFT");
    
    // expected: sold out
    testPurchase(&walmart, &client, 0, "CREDIT");
    
    // expected: success
    testPurchase(&walmart, &client, 5, "GIFT");
    
    // expected: no balance
    testPurchase(&walmart, &client, 9, "GIFT");

    // expected: success
    testPurchase(&walmart, &client, 9, "CREDIT");
    
    cout
        << "Thanks for visiting Walmart. See you soon :)" << endl << endl;
    
    walmart.close();
    
    cout
        << "Sales report:" << endl
        << "$" << walmart.getTodayBalance() << " sold today" << endl;
    return 0;
}
