#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H

#include "./PaymentStrategy.h"

using namespace std;

class CreditCardPaymentStrategy : public PaymentStrategy{
    private:
        string cardNumber;
    public:
        CreditCardPaymentStrategy(const string& cardNumber)
        {
            this->cardNumber=cardNumber;
        }
    void pay(double amount) override{
        //logic for credit card payments
        cout<<"Payment of Rs "<<amount<<" processing through credit card number: "<<cardNumber<<endl;
    }

};

#endif