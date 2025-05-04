#include <iostream>
#include <string.h>
using namespace std;
#define max 10
class flight
{
    int f[max][max];
    string v[max];
    int n;
public:
    flight()
    {
        for (int i = 0; i < max; i++)
        {
            for (int j = 0; j < max; j++)
            {
                f[i][j] = 0;
            }
        }
    }
    void create();
    void display();
};
void flight::create()
{

    cout << "Enter number of cities: ";
    cin >> n;
    cout << "Enter name of cities : ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            char ch;
            do
            {
                cout << "\ndoes flight exist between " << v[i] << " and " << v[j] << " : (y/n) ";
                cin >> ch;
                if (ch == 'y')
                {
                    cout << "Enter time to reach  " << v[j] << " from " << v[i] << ": ";
                    cin >> f[i][j];
                    f[j][i] = f[i][j];
                    break;
                }
                else if (ch == 'n')
                {
                    f[i][j] = 0;
                    f[j][i] = 0;
                    break;
                }
                else
                {
                    cout << "Invalid choice\n";
                }

            } while (ch != 'y');
        }
    }
}
void flight::display()
{
    cout << "\n Adjcency matrix \n   \t  ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " \t|";
        for (int j = 0; j < n; j++)
        {
            cout << f[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{
    flight f;
    int choice;
    do
    {
        cout << "\n1. Create graph\n2. Display graph\n3. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            f.create();
            break;
        case 2:
            f.display();
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 3);
    return 0;
}