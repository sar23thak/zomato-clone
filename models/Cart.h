#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include <string>
#include "../models/MenuItem.h"
#include "../models/Restaurant.h"

using namespace std;
class Cart{
    private:
        Restaurant* restaurant;
        vector<MenuItem> items;
    public:
        Cart(){
            restaurant=NULL;
        }

        void addItem(const MenuItem& item){
            if(restaurant==NULL)
            {
                cout<<"Select a restaurant before adding an item"<<endl;
                return;
            }
            items.push_back(item);
        }
        double getTotalCost() const{
            double sum=0;
            for(const auto& it : items)
            {
                sum = sum + it.getPrice();
            }
            return sum;
        }
        bool isEmpty()
        {
            return (restaurant==NULL || items.empty()==true);
        }
        void clear()
        {
            items.clear();
            restaurant=NULL;
        }
};

#endif