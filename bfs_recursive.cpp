// bfs -- matrix -- recursive
#include <iostream>
#include <queue>
#define max 10
using namespace std;
class graph
{
    int n;
    int a[max][max];
    bool visited[max];
    queue<int> q;

public:
    void create();
    void addedge();
    void display();
    void bfs(int);
    void recursive_bfs();
};
void graph::create()
{
    cout << "Enter number  of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
}
void graph::addedge()
{
    int v1, v2;
    cout << "EnTer nodes to connect v1 and v2(v1 v2): ";
    cin >> v1 >> v2;
    if (v1 >= n || v2 >= n || v2 < 0 || v1 < 0)
    {
        cout << "\nInvalid nodes\n";
        return;
    }
 
    a[v1][v2] = 1;
    a[v2][v1] = 1;
    cout << "Edge added between " << v1 << " and " << v2 << endl;
}
void graph::bfs(int start)
{
    if (start >= n || start < 0)
    {
        cout << "\nInvalid node\n";
        return;
    }
    cout << "BFS traversal: ";
    for(int i=0; i<n; i++) {
        visited[i] = false;    }
    while (!q.empty())
    {
        q.pop();
    }
    visited[start] = true;
    q.push(start);
    recursive_bfs();
}
void graph::recursive_bfs()
{
    if(q.empty()) return;
    int curr = q.front();
    q.pop();
    cout << curr << " ";


        for (int i = 0; i < n; i++)
        {
            if (a[curr][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
        recursive_bfs();
    }

void graph::display() {
        cout << "\nAdjacency Matrix:\n   ";
        for(int j=0; j<n; j++) {
            cout << j << " ";
        }//column index
        cout << "\n";
        
        for(int i=0; i<n; i++) {
            cout << i << " |";  // Row index
            for(int j=0; j<n; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
int main()
{
    int choice;
    graph g;
    char r;
    do
    {
        cout << "\n1.create graph\n2.Add edge\n3.isplay\n4.BFS\n5.Exit\nEnter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
g.create();
            break;
        case 2:
            g.addedge();
            break;
        case 3:
            g.display();
            break;

        case 4:
            int start;
            cout << "Enter tart node : ";
            cin >> start;
            g.bfs(start);
            break;
        case 5:
            exit(0);
        default:
            cout << "\nINVALID CHOICE\n";

            break;
        }
        cout << "\nDo you want to continue (y/n) : ";
        cin >> r;
    }while(r=='y');
    return 0;
}