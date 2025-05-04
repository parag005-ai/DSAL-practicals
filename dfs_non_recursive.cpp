// fs -- matrix -- non-recursive
#include <iostream>
using namespace std;
#define max 10
class graph
{
    bool visited[max];
    int a[max][max];
    int v;

public:
    void create();
    void display();
    void DFS(int);
};
void graph::create()
{
    int e, v1, v2;
    cout << "\nEnter no of vertices : ";
    cin >> v;
    cout << "\nEnter no of edges: ";
    cin >> e;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            a[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        cout << "enter edges (v1 v2) "<<i+1<<":";
        cin >> v1 >> v2;
        cout<<endl;
        if (v1 >= v || v2 >= v || v1 < 0 || v2 < 0)
        {
            cout << "\ninvalid node\n";
            i--;
            continue;
           
        }
        a[v1][v2] = 1;
        a[v2][v1] = 1;
        cout << "edge added between " << v1 << " and " << v2 << endl;
        cout<<endl;
    }
}
void graph::display()
{
    cout << "\nADJACENCY MATRIX\n   ";
    for (int i = 0; i < v; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << " |";
        for (int j = 0; j < v; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void graph::DFS(int start)
{
    int st[max];
    int top = -1;
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    st[++top] = start;
    visited[start] = true;
    cout << start << " ";
    while (top != -1)
    {
        int f = 0;
        int t = st[top];
        for (int i = 0; i < v; i++)
        {
            if (a[t][i] == 1 && !visited[i])
            {
                st[++top] = i;
                visited[i] = true;
                cout << i << " ";
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            top--;
        }
    }
    cout << endl;
}
int main()
{
    int choice;
    char r;
    graph g;
    do
    {
        cout << "\n1. Create graph\n2. Display graph\n3. DFS\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            g.create();
            break;
        case 2:
            g.display();
            break;
        case 3:
            int start;
            cout << "Enter starting node: ";
            cin >> start;
            g.DFS(start);
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
        cout << "Do you want to continue (y/n)? ";
        cin >> r;
    }while(r=='y');
        return 0;
    }