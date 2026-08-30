#include <iostream>
using namespace std;

class HashTable
{
private:
    int *table;
    int size;

public:
    // Constructor
    HashTable(int s)
    {
        size = s;
        table = new int[size];

        for (int i = 0; i < size; i++)
        {
            table[i] = -1;
        }
    }

    // Insert element using quadratic probing
    void insert(int key)
    {
        int index = key % size;

        for (int i = 0; i < size; i++)
        {
            int newIndex = (index + i * i) % size;

            if (table[newIndex] == -1)
            {
                table[newIndex] = key;
                return;
            }
        }

        cout << "Hash table is full. Cannot insert "
             << key << endl;
    }

    // Display hash table
    void display()
    {
        cout << "\nHash Table:\n";

        for (int i = 0; i < size; i++)
        {
            cout << "Index " << i << " : ";

            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];

            cout << endl;
        }
    }

    // Destructor
    ~HashTable()
    {
        delete[] table;
    }
};

int main()
{
    int size, n, key;

    cout << "Enter hash table size: ";
    cin >> size;

    HashTable ht(size);

    cout << "Enter number of elements: ";
    cin >> n;

    if (n > size)
    {
        cout << "Number of elements cannot be greater than hash table size.";
        return 0;
    }

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> key;
        ht.insert(key);
    }

    ht.display();

    return 0;
}