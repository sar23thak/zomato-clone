#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <./Cart.h>

using namespace std;

class User{
    private:
        static int nextUserId;
        int userId;
        string name;
        string address;
        Cart* cart;
    public:
        User(const string& name, const string& address)
        {
            this->userId=++nextUserId;
            this->address=address;
            this->cart=new Cart();
        }
        ~User(){
            delete cart;
        }
        string getName() const
        {
            return name;
        }
        void setName(const string& n)
        {
            name=n;
        }
        string getAddress() const
        {
            return address;
        }
        void setAddress(const string& add)
        {
            address=add;
        }
        Cart* getCart(){
            return cart;
        }
};
int User::nextUserId=0;
#endif