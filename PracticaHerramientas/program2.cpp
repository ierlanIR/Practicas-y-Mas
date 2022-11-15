#include <iostream>
#include <memory>
using namespace std;
class Fibonacci
{
private:
    int n;

public:
    Fibonacci(int n) : n(n){};
    int Calculate()
    {
        if (n < 1)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        Fibonacci a(n-1);
        Fibonacci b(n-2);

        return a.Calculate() + b.Calculate();
    }
};
int main()
{
    cout << "Fibonacci:" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            Fibonacci fib(j);
            cout << "Fib(" << j << ") = " << fib.Calculate() << endl;
        }
    }
}