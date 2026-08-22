#include <iostream>
#include <stack>
using namespace std;

struct Frame
{
    int n;
    char source, auxiliary, destination;
    int state;
};

int main()
{
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    stack<Frame> s;

    s.push({n, 'A', 'B', 'C', 0});

    while (!s.empty())
    {
        Frame current = s.top();
        s.pop();

        if (current.n == 1)
        {
            cout << "Move disk 1 from " << current.source
                 << " to " << current.destination << endl;
            continue;
        }

        // Simulate recursive calls
        s.push({current.n - 1,
                current.auxiliary,
                current.source,
                current.destination,
                0});

        cout << "Move disk " << current.n
             << " from " << current.source
             << " to " << current.destination << endl;

        s.push({current.n - 1,
                current.source,
                current.destination,
                current.auxiliary,
                0});
    }

    return 0;
}