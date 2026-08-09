#include <iostream>
using namespace std;

int main()
{
    int n, key;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements in sorted order: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> key;

    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            cout << "Element found at position " << mid + 1 << endl;
            return 0;
        }
        else if(arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "Element not found" << endl;

    return 0;
}
