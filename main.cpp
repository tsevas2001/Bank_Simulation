#include "bank.h"

int main()
{
    int K, M, N, L;

    cout << "Enter K: ";
    cin >> K;
    cout << "Enter M: ";
    cin >> M;
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter L: ";
    cin >> L;

    Bank* bank = new Bank(L);

    int can_serve = 0, not_served = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (bank->enter(K))
                can_serve++;
            else
                not_served++;
        }
        for (int h = 0; h < can_serve; h++)
        {
            bank->serve(K);
        }
    }
    bank->waiting_customers();
    for (int i = 0; i < not_served; i++)
    {
        bank->serve(K);
    }

    delete bank;
    return 0;
}