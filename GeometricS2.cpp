#include <iostream>
using namespace std;

int main()
{
    double a, r, sum = 0;
    int n;

    cout << "Enter first term (a): ";
    cin >> a;

    cout << "Enter common ratio (r): ";
    cin >> r;

    cout << "Enter number of terms (n): ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        sum = sum + a;
        a = a * r;
    }

    cout << "Sum of geometric series = " << sum;

    return 0;
}