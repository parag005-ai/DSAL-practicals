//QUADRATIC PROBING
#include <iostream>
#define max 10
using namespace std;
class num
{
    long int a[max];

public:
    num()
    {
        for (int i = 0; i < max; i++)
        {
            a[i] = 0;
        }
    }
    int hashfun(long int);
    void insert();
    void search();
    void display();
};
int num::hashfun(long int key)
{
    return key % max;
}
void num::insert()
{
    long int key;
    cout << "Enter phone number : ";
    cin >> key;
    int index = hashfun(key);
    int cnt = 0;

    for (int i = 0; i < max; i++)
    {
        int newindex = (index + i * i) % max;
        if (a[newindex] == 0)
        {
            a[newindex] = key;
            cout << "phone number inserted at " << newindex;
            return;
        }
        cnt++;
    }
    if (cnt == max)
    {
        cout << "\nHash table is full \n";
    }
}

void num::search()
{
    long int key;
    cout << "Enter phone number to search : ";
    cin >> key;
    int index = hashfun(key);
    for (int i = 0; i < max; i++)
    {
        int newidx = (index + i * i) % max;
        if (a[newidx] == key)
        {
            cout << "\nphone number found at index " << newidx << endl;
            return;
        }
        else if (a[newidx] == 0)
        {
            break;
        }
    }
    cout << "\nphone number not found" << endl;
}
void num::display()
{
    for ( int i = 0; i < max; i++)
    {
        if (a[i] == 0)
        {
            cout << i << " --- " << "NULL" << endl;
        }
        else
        {
            cout << i << " --- " << a[i] << endl;
        }
    }
}
int main()
{
    num n;
    char r;
    int ch;
    do
    {
        cout << "1.Insert \n2.Display \n3.Search \n4.EXIT \n";
        cout << "Your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            n.insert();
            break;

        case 2:
            n.display();
            break;

        case 3:
            n.search();
            break;

        case 4:

            break;

        default:
            cout << "invalid choice ";
            break;
        }
        cout << "\nWant to continuee : (y/n) : ";
        cin >> r;
    } while (r == 'y');
    return 0;
}