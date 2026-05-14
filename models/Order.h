#ifndef ORDER_H
#define ORDER_H
#include "User.h"
#include "../Strategies/PaymentStrategy.h"

using namespace std;

class Order{
    private:
        static int nextOrderId;
        int orderId;
        User* user;
        Restaurant* restaurant;
        vector<MenuItem>items;
        PaymentStrategy* paymentStrategy;
        double total;
        string scheduled;
    
    public:
        Order(){
            this->user=NULL;
            restaurant=NULL;
            paymentStrategy=NULL;
            total=0;
            scheduled="";
            orderId=++nextOrderId;
        }
        virtual ~Order()
        {
            delete paymentStrategy;
        }
        bool processPayment()
        {
            if(paymentStrategy==NULL)
            {
                cout << "Please choose a payment mode first" << endl;
                return false;
            }
            paymentStrategy->pay(total);
            return true;
        }
        virtual string getType()=0;
        
        //getters and setters
        int getOrderId()
        {
            return orderId;
        }
        
        User* getUser() const{
            return user;
        }
        void setUser(User* u)
        {
            user=u;
        }
        Restaurant* getRestaurant()
        {
            return restaurant;
        }
        void setRestaurant(Restaurant* res)
        {
            restaurant=res;
        }
        void setItems(const vector<MenuItem>& cartItems)
        {
            items=cartItems;
            total=0;
            for(auto& i: items)
            {
                total += i.getPrice();
            }
        }
        vector<MenuItem> getItems()
        {
            return items;
        }
        void setSchedule(const string& time)
        {
            scheduled=time;
        }
        string getSchedule()
        {
            return scheduled;
        }
        double getTotal()
        {
            return total;
        }
        void setTotal(double total)
        {
            this->total=total;
        }
        void setPaymentStrategy(PaymentStrategy* paymentStrategy)
        {
            this->paymentStrategy = paymentStrategy;
        }
};
int Order::nextOrderId=0;
#endif