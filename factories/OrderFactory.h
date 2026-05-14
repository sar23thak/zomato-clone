#ifndef ORDER_FACTORY_H
#define  ORDER_FACTORY_H
#include "../models/User.h"
#include "../Strategies/PaymentStrategy.h"
#include "../models/Order.h"


using namespace std;

class OrderFactory{
    public:
        virtual Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>& menuItems,
                                   PaymentStrategy* paymentStrategy, double totalCost, const string& orderType)=0;

        ~OrderFactory(){}
};

#endif