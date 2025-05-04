// Represent a given graph using adjacency list to perform BFS using non-recursive method.
#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int data;
    node *next;
};
class graph
{
    node *g[10];
    int n;

public:
    void create();
    void display();
    void bfs(int);
};
void graph::create()
{
    node *last;
    int an;
    cout << "Enter number of nodes : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        node *nn = new node;
        cout << "Enter value of node " << i + 1 << " : ";
        cin >> nn->data;
        nn->next = NULL;
        g[i] = nn;
        last = nn;
        cout << "Enter number of adjcaent nodes : ";
        cin >> an;
        for (int j = 0; j < an; j++)
        {
            node *nn = new node;
            cout << "Enter value of adjacent node : ";
            cin >> nn->data;
            nn->next = NULL;
            last->next = nn;
            last = nn;
        }
    }
}
void graph::display()
{
    for (int i = 0; i < n; i++)
    {
        node *t = g[i];
        while (t != NULL)
        {
            cout << t->data << " -> ";
            t = t->next;
        }
        cout << "NULL\n";
    }
}
void graph::bfs(int start)
{
    bool visited[10] = {false};
    queue<int> q;
    cout << "BFS traversal strting from node " << start << ": ";
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for (int i = 0; i < n; i++)
        {
            if (g[i]->data == current)
            {
                node *nn = g[i]->next; //to store the address of first adjacent node
                while (nn != NULL)
                {
                    if (!visited[nn->data])
                    {
                        visited[nn->data] = true;
                      q.push(nn->data);
                    }
                    nn = nn->next;
                }

                break;
            }
        }
    }
}
int main()
{
    graph g;
    int choice;
    char r;
    do
    {
        cout << "\n1.create \n2.display \n3.bfs\n4.exit\n";
        cout << "Enter your choice : ";
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
            cout << "Enter starting node for BFS: ";
            cin >> start;
            g.bfs(start);
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid choice\n";
            break;
        }
        cout << "\nDo you want to continue (y/n) : ";
        cin >> r;

    } while (r == 'y');
    return 0;
}