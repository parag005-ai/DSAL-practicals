// Given sequence k = k1 <k2 < … < kn of n sorted keys, with a search probability pi
// for each key ki . Build the Binary search tree that has the least search cost given
// the access probability for each key.

#include <iostream>
#include <queue> //for stl
#include <string.h>
using namespace std;
#define max 10

class obst
{
    int w[max][max], c[max][max], r[max][max]; // weight matrix,cost,root
    double p[max], q[max + 1];                    // p-probablity of successful search (1...n),q-probablity unsuccessful search (0...n)
    int n;
    string k[max]; // keys of tree
public:
    void create();
    void build();
    void display();
    int search(int, int);
};
void obst::create()
{
    cout << "Enter no. of keys: ";
    cin >> n;
    cout << "Enter keys : ";
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    cout << "Enter probablity of successful search:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "p[" << i << "] : ";
        cin >> p[i];
    }
    cout << "Enter probablity of unsuccessful search:\n";
    for (int i = 0; i <= n; i++)
    {
        cout << "q[" << i << "] : ";
        cin >> q[i];
    }
}
int obst::search(int i, int j)
{
    int m;
    int min = 100;
    for (int k = i + 1; k <= j; k++)       // value of k expected in ==v i<k<=j 
    {
        if (c[i][k - 1] + c[k][j] < min)
        {
           min= c[i][k - 1] + c[k][j];
            m = k;
        }
    }
    return m;
}
void obst::build()
{
    for (int i = 0; i <= n; i++) { // for diagonal elements (i=j        j-i=0(absolute difference))
        w[i][i] = q[i];
        c[i][i] = 0;
        r[i][i] = 0;
    }
    for (int m = 1; m <= n; m++)       // m=1,2,3...n (length of keys)
    {
        for (int i = 0; i <= n - m; i++)        //starting index of keys
        {
            int j = i + m;                   //j-i=1,2,3.....n-1
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            int k = search(i, j);
            c[i][j] = c[i][k - 1] + c[k][j] + w[i][j];
            r[i][j] = k;
        }
    }
    cout<<"building completed\n";
}
void obst::display()
{
    queue<int> q;
    cout << "\nOBST REPRESENTATION\n";
    cout << "\nroot of tree " << r[0][n];
    cout << "\nCost of tree " << c[0][n];
    cout << "\n\tnode  \t left   \t right\n";
    q.push(0);
    q.push(n);
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        int j = q.front();
        q.pop();
        int k = r[i][j];
        cout << "\n          " << k;
        if (r[i][k - 1] != 0) {
            cout << "\t         " << r[i][k - 1];
            q.push(i);
            q.push(k - 1);
        } else {
            cout << "\t     NULL";
        }
        
        if (r[k][j] != 0) {
            cout << "\t      " << r[k][j];
            q.push(k);
            q.push(j);
        } else {
            cout << "\t      NULL";
        }
    }
}
int main()
{
    obst o;
    int ch;
    do{
        cout << "\n1. Create\n2. Build\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            o.create();
            break;
        case 2:
            o.build();
            break;
        case 3:
            o.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
    }while(ch!=4);
    cout<<"...ExITEd";
    return 0;
}