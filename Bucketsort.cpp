#include <iostream>
#include <algorithm>
using namespace std;

void bucketSort(int a[], int n)
{
    int maxElement = a[0];

    for (int i = 1; i < n; i++)
        maxElement = max(maxElement, a[i]);

    int bucketCount = maxElement / 10 + 1;
    int bucket[100][100] = {0};
    int count[100] = {0};

    for (int i = 0; i < n; i++)
    {
        int index = a[i] / 10;
        bucket[index][count[index]++] = a[i];
    }

    for (int i = 0; i < bucketCount; i++)
        sort(bucket[i], bucket[i] + count[i]);

    int k = 0;

    for (int i = 0; i < bucketCount; i++)
    {
        for (int j = 0; j < count[i]; j++)
            a[k++] = bucket[i][j];
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bucketSort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}