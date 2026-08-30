#include <iostream>
using namespace std;

class TwoSum
{
private:
    int *hash;
    int size;

public:
    // Constructor
    TwoSum(int s)
    {
        size = s;
        hash = new int[size];

        for (int i = 0; i < size; i++)
        {
            hash[i] = -1;
        }
    }

    // Insert element into hash table
    void insert(int key)
    {
        int index = key % size;

        while (hash[index] != -1)
        {
            index = (index + 1) % size;
        }

        hash[index] = key;
    }

    // Search element in hash table
    bool search(int key)
    {
        int index = key % size;
        int start = index;

        while (hash[index] != -1)
        {
            if (hash[index] == key)
                return true;

            index = (index + 1) % size;

            if (index == start)
                break;
        }

        return false;
    }

    // Destructor
    ~TwoSum()
    {
        delete[] hash;
    }
};

int main()
{
    int n, T;

    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target T: ";
    cin >> T;

    // Create hash table
    TwoSum ht(2 * n + 1);

    for (int i = 0; i < n; i++)
    {
        int required = T - arr[i];

        if (ht.search(required))
        {
            cout << "\nYes, two elements exist.\n";
            cout << "Elements are " << required
                 << " and " << arr[i] << endl;

            delete[] arr;
            return 0;
        }

        ht.insert(arr[i]);
    }

    cout << "\nNo, two elements with sum "
         << T << " exist.\n";

    delete[] arr;

    return 0;
}