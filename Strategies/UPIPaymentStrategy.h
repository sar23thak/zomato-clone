#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include <string>
#include "./PaymentStrategy.h"

using namespace std;

class UPIPaymentStrategy : public PaymentStrategy{
    private:
        string MobileNumber;
    public:
        UPIPaymentStrategy(const string& number)
        {
            MobileNumber=number;
        }
        void pay(double amount) override{
            cout<<"Paying Rs "<<amount<<" through UPI linke with the mobile: "<<MobileNumber<<endl;
        }

};

#endif //UPI_PAYMENT_STRATEGY_H