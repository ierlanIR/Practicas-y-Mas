#include <iostream>
using namespace std;
class Fibonacci {
private:
int n;
public:
Fibonacci(int n) : n(n){};
int Calculate() {
if (n < 1) {
return 0;
}
Fibonacci* a = new Fibonacci(n - 2);
Fibonacci* b = new Fibonacci(n - 2);
return a->Calculate() + b->Calculate();
}
};
int main() {
cout << "Fibonacci:" << endl;
for (int i = 0; i < 10000; i++) {
for(int j = 0; j < 55; j++) {
auto fib = new Fibonacci(j);
cout << "Fib(" << j << ") = " << fib->Calculate() << endl;
}
}
}