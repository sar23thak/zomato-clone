#ifndef DELIVER_ORDER_H
#define DELIVER_ORDER_H

#include "./Order.h"

using namespace std;

class DeliveryOrder: public Order{
    private:
        string UserAddress;
    
    public:
        DeliveryOrder()
        {
            UserAddress="";
        }
        string getType()
        {
            return "delivery";
        }
        string getUserAddress()
        {
            return UserAddress;
        }
        void setUserAddress(string& add)
        {
            UserAddress=add;
        }
};
#endif