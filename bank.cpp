#include "bank.h"

// Constructor of Bank
Bank::Bank(int L) : cashiers {L, L, L, L, L}
{
    cout << "Creating a bank..." << endl;
    last_customer = 1;
    curr_serving = 1;
    open(0);
    cout << "Bank created successfully!" << endl;
}

// Customers enter in the bank
bool Bank::enter(int K)
{
    // Checking if customers are enough
    if (check_to_open(K) == false)
    {
        last_customer++;
        return true;
    }
    else
    {
        int temp = open_cashiers();
        for (int i = 0; i < 5; i++)
        {
            if (temp == 5)
            {
                cout << "Sorry you cannot enter until some customers are served!" << endl;
                return false;
            }

            if (cashiers[i].is_open() == false)
            {
                open(i);
                last_customer++;
                return true;
            }
        }
        return false;
    }
}
// Checking how many cashiers are open 
int Bank::open_cashiers()
{
    int countOpenedCashiers = 0;

    for (int i = 0; i < 5; i++)
    {
        if (cashiers[i].is_open())
            countOpenedCashiers++;
    }

    cout << "Cashiers: " << countOpenedCashiers << " are opened" << endl;
    return countOpenedCashiers;
}

// Serving the customers
int last_cashier = -1;
void Bank::serve(int K)
{
    bool closed = false;
    // checks if cashiers are closed
    if (open_cashiers() == 0)
        closed = true;
    // if closed then opens the first cashier
    if (closed)
    {
        open(0);
        cashiers[0].serve();
        cout << "Customer no: " << curr_serving << " by cashier no: " << 0 << endl;
        last_cashier = 0;
        cashiers[0].free();
        curr_serving++;
        exit(K);
    }
    // if only one cashier is open the continue with that cashier
    else if (open_cashiers() == 1) 
    {
        for (int i = 0; i < 5; i++)
        {
            if (cashiers[i].is_open())
            {
                cashiers[i].serve();
                cout << "Customer no: " << curr_serving << " by cashier no: " << i << endl;
                last_cashier = i;
                cashiers[i].free();
                curr_serving++;
                exit(K);
            }
        }
    }
    // else continue serving the customers with cashiers like cyrcle
    else
    {
        // finding the first open cashier
        int first_open;
        for (int i = 0; i < 5; i++)
            if (cashiers[i].is_open())
            {
                first_open = i;
                break;
            }

        for (int i = 0; i < 5; i++)
        {
            // finding the last open cashier
            int last;
            for (int j = 0; j < 5; j++)
            {
                if (cashiers[j].is_open())
                {
                    last = j;
                }
            }
            // if last_cashier equal with last go on the first open cashier and serve
            if (last_cashier == last)
            {
                cashiers[first_open].serve();
                cout << "Customer no: " << curr_serving << " by cashier no: " << first_open << endl;
                last_cashier = first_open;
                cashiers[first_open].free();
                curr_serving++;
                exit(K);
            }
            // go on the next cashier
            else if (i > last_cashier && cashiers[i].is_open() && cashiers[i].is_free() == false)
            {
                cashiers[i].serve();
                cout << "Customer no: " << curr_serving << " by cashier no: " << i << endl;
                last_cashier = i;
                cashiers[i].free();
                curr_serving++;
                exit(K);
            }
        }
    }
}

// exiting the Customer from the bank and checking to close cashier if it necessary
void Bank::exit(int K)
{
    last_customer++;
    if(check_to_close(K))
    {
        for(int i = 0; i < 5; i++)
        {
            if(cashiers[i].is_open())
            {
                close(i);
                break;
            }
        }
    }
}

// checking to open cashier if it is necessary
bool Bank::check_to_open(int K)
{
    int countClosedCashiers = 0;

    for (int i = 0; i < 5; i++)
    {
        if (cashiers[i].is_open() == false)
            countClosedCashiers++;
    }

    if ((last_customer - curr_serving) > countClosedCashiers * K)
        return true;
    else
        return false;
}
// checking to close cashier if it is necessary
bool Bank::check_to_close(int K)
{
    int countOpenedCashiers = 0;

    for (int i = 0; i < 5; i++)
    {
        if (cashiers[i].is_open())
            countOpenedCashiers++;
    }

    if ((last_customer - curr_serving) <= (countOpenedCashiers - 1) * K)
        return true;
    else
        return false;
}

// shows how many customers are waiting
int Bank::waiting_customers()
{
    cout << last_customer - curr_serving << " Customers are waiting!" <<  endl;
    return last_customer - curr_serving;
}

// closing cashiers
void Bank::close(int NumOfCashier)
{
    cashiers[NumOfCashier].close();
    cout << "Cashier " << NumOfCashier + 1 << " closed!" << endl;
}

// opens cashiers
void Bank::open(int NumOfCashier)
{
    cashiers[NumOfCashier].open();
    cout << "Cashier " << NumOfCashier + 1 << " opened!" << endl;
}

// Destructor of bank
Bank::~Bank()
{
    cout << "Destroying a bank!" << endl;
    cout << "Bank destroyed successfully!" << endl;
}