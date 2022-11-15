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
        unique_ptr<Fibonacci> a = make_unique<Fibonacci>(n - 1);
        unique_ptr<Fibonacci> b = make_unique<Fibonacci>(n - 2);

        return a->Calculate() + b->Calculate();
    }
};
int main()
{
    cout << "Fibonacci:" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            unique_ptr<Fibonacci> fib = make_unique<Fibonacci>(j);
            cout << "Fib(" << j << ") = " << fib->Calculate() << endl;
        }
    }
}