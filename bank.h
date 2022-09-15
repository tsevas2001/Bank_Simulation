#include <iostream>
#include "cashier.h"

using namespace std;

class Bank
{
    private:
        int last_customer;
        int curr_serving;
        Cashier cashiers[5];
    public:
        Bank(int);
        bool enter(int);
        int open_cashiers();
        void serve(int);
        void exit(int);
        bool check_to_open(int);
        bool check_to_close(int);
        int waiting_customers();
        void close(int);
        void open(int);
        ~Bank();

};