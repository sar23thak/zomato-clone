#ifndef PICKUP_H
#define PICKUP_H

#include "./Order.h"

using namespace std;

class PickupOrder: public Order{
    private:
        string RestaurantAddress;
    
    public:
        PickupOrder()
        {
            RestaurantAddress="";
        }
        string getType()
        {
            return "pickup";
        }
        string getRestaurantAddress()
        {
            return RestaurantAddress;
        }
        void setRestaurantAddress(const string& add)
        {
            RestaurantAddress=add;
        }
};
#endif