#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, r, sum;
    int n;

    cout << "Enter first term (a): ";
    cin >> a;

    cout << "Enter common ratio (r): ";
    cin >> r;

    cout << "Enter number of terms (n): ";
    cin >> n;

    if (r == 1)
        sum = a * n;
    else
        sum = a * (pow(r, n) - 1) / (r - 1);

    cout << "Sum of geometric series = " << sum;

    return 0;
}