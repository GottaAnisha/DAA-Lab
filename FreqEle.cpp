#include <iostream>
using namespace std;

class FrequencyHash
{
private:
    int *value;
    int *frequency;
    int size;

public:
    // Constructor
    FrequencyHash(int s)
    {
        size = s;

        value = new int[size];
        frequency = new int[size];

        for (int i = 0; i < size; i++)
        {
            value[i] = -1;
            frequency[i] = 0;
        }
    }

    // Insert element or increase its frequency
    void insert(int key)
    {
        int index = key % size;

        while (value[index] != -1 && value[index] != key)
        {
            index = (index + 1) % size;
        }

        if (value[index] == -1)
        {
            value[index] = key;
            frequency[index] = 1;
        }
        else
        {
            frequency[index]++;
        }
    }

    // Display frequency
    void display()
    {
        cout << "\nFrequency of each distinct element:\n";

        for (int i = 0; i < size; i++)
        {
            if (value[i] != -1)
            {
                cout << value[i] << " : "
                     << frequency[i] << endl;
            }
        }
    }

    // Destructor
    ~FrequencyHash()
    {
        delete[] value;
        delete[] frequency;
    }
};

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Create hash table
    FrequencyHash ht(2 * n + 1);

    // Count frequencies
    for (int i = 0; i < n; i++)
    {
        ht.insert(arr[i]);
    }

    ht.display();

    delete[] arr;

    return 0;
}