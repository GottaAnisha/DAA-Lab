#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter weight and value of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items, items + n, compare);

    double maxProfit = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            maxProfit += items[i].value;
        } else {
            maxProfit += items[i].ratio * capacity;
            break;
        }
    }

    cout << "Maximum profit = " << maxProfit << endl;

    return 0;
}