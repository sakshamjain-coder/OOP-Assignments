#include <iostream>
using namespace std;

template <typename T>
class Bubble
{
    T a[100];
    int n;

public:
    void input()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements: ";

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }

    void sort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    T temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    void display()
    {
        cout << "Sorted elements: ";

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    cout << "INTEGER SORTING" << endl;

    Bubble<int> b1;
    b1.input();
    b1.sort();
    b1.display();

    cout << "\nFLOAT SORTING" << endl;

    Bubble<float> b2;
    b2.input();
    b2.sort();
    b2.display();

    return 0;
}