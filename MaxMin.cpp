#include <iostream>
using namespace std;

struct MinMax {
    int min;
    int max;
};

MinMax findMinMax(int a[], int low, int high) {
    MinMax result, left, right;

    if (low == high) {
        result.min = result.max = a[low];
        return result;
    }

    if (high == low + 1) {
        if (a[low] < a[high]) {
            result.min = a[low];
            result.max = a[high];
        } else {
            result.min = a[high];
            result.max = a[low];
        }
        return result;
    }

    int mid = (low + high) / 2;

    left = findMinMax(a, low, mid);
    right = findMinMax(a, mid + 1, high);

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    MinMax result = findMinMax(a, 0, n - 1);

    cout << "Minimum element = " << result.min << endl;
    cout << "Maximum element = " << result.max << endl;

    return 0;
}