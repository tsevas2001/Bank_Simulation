#include "cashier.h"

// Constructor of cashier
Cashier::Cashier(int L) : max_serve{L}
{
    cout << "Creating a cashier..." << endl;
    open_flag = false;
    serving_flag = false;
    customers_served = 0;
    cout << "Cashier created successfully!" << endl;
}

// opening cashier 
void Cashier::open()
{
    cout << "Cashier opening..." << endl;
    customers_served = 0;
    open_flag = true;
    cout << "Cashier opened successfully!" << endl;
}

// closing Cashier
void Cashier::close()
{
    cout << "Cashier closing..." << endl;
    open_flag = false;
    cout << "Cashier closed successfully!" << endl;
}

// current cashier is serving
void Cashier::serve()
{
    serving_flag = true;
}

// free the cashier
void Cashier::free()
{
    serving_flag = false;
    customers_served++;
    cout << "Customer served successfully!" << endl;

    if (customers_served == max_serve)
    {
        cout << "Cashier overworked!" << endl;
        close();
    }
}

// return if cashier is open or not
bool Cashier::is_open()
{
    return open_flag;
}

// return if cashier is free or not
bool Cashier::is_free()
{
    return serving_flag;
}

// Destructor of Cashier
Cashier::~Cashier()
{
    cout << "Destroying a cashier..." << endl;

    cout << "Cashier destroyed successfully!" << endl;
}