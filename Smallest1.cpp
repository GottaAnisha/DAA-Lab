#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter value of k: ";
    cin >> k;

    sort(a, a + n);

    cout << "Kth smallest element = " << a[k - 1];

    return 0;
}