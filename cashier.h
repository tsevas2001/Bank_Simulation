#include <iostream>

using namespace std;

class Cashier
{
    private:
        int max_serve;
        bool open_flag;
        bool serving_flag;
        int customers_served;
    public:
        Cashier(int);
        void open();
        void close();
        void serve();
        void free();
        bool is_open();
        bool is_free();
        ~Cashier();
};