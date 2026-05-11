#ifndef Order_Manager_H
#define Order_Manager_H

#include <vector>
#include <iostream>
#include "../models/Order.h"
#include <Order.h>
using namespace std;

class OrderManager{
    private:
        vector<Order> orders;
        static OrderManager* instance;
        OrderManager()
        {
            //private constructor
        }
    public:
        OrderManager* getInstance()
        {
            if(instance==NULL)
            {
                instance=new OrderManager;
            }
            return instance;
        }
        void addOrder(Order order){
            orders.push_back(order);
        }
        void listOrders()
        {
            cout << "\n--- All Orders ---" << endl;
            for(auto& o: orders)
            {
                cout<<o.getType()<<" order for user: "<<o.getUser()->getName()<<"Total Rs "<<o.getTotal()
                    <<" Scheduled at "<<o.getSchedule()<<endl;
            }
        }

};
OrderManager* OrderManager::instance=NULL;
#endif