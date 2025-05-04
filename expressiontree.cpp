#include <iostream>
#include <string.h>
#include <cctype>  // for isalpha
using namespace std;

struct node
{
    node *left;
    node *right;
    char data;
};

class stack
{
    node *st[20];
    int top;

public:
    stack()
    {
        top = -1;
    }
    void push(node *p)
    {
        st[++top] = p;
    }
    node *pop()
    {
        return st[top--];
    }

    int isemp()
    {
        return (top == -1);
    }
};

class exp
{
public:
    stack s;
    char expr[20];
    node *top;
    void expression(const char[]);
    void post(node *);
    void display(node *);
    void del(node *);
};

void exp::expression(const char p[])
{
    int len = strlen(p);
    for (int i = len - 1; i >= 0; i--)
    {
        node *nn = new node;
        nn->left = nn->right = NULL;
        if (isalpha(p[i]))
        {
            nn->data = p[i];
            s.push(nn);
        }
        else if (p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/')
        {
            node *t1 = s.pop();
            node *t2 = s.pop();
            nn->data = p[i];
            nn->left = t1;
            nn->right = t2;
            s.push(nn);
        }
    }
    top = s.pop();
}

void exp::post(node *t)
{
    if (t == NULL)
        return;

    stack a, b;
    node *t1, *t2;
    t1 = t;
    a.push(t1);
    while (!a.isemp())
    {
        t2 = a.pop();
        b.push(t2);
        if (t2->left != NULL)
        {
            a.push(t2->left);
        }
        if (t2->right != NULL)
        {
            a.push(t2->right);
        }
    }
    while (!b.isemp())
    {
        node *x;
        x = b.pop();
        cout << x->data << " ";
    }
}

void exp::display(node *t)
{
    if (t != NULL)
    {
        display(t->left);
        cout << t->data << " ";
        display(t->right);
    }
}

void exp::del(node *t)
{
    if (t == NULL)
    {
        return;
    }
    del(t->left);
    del(t->right);
    cout << t->data << " deleted\n";
    delete t;
}

int main()
{
    int choice;
    char c;
    exp e;
    do
    {
        cout << "1.Expression\n2.Display\n3.Delete\n4.Exit\nEnter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter expression : ";
            cin >> e.expr;
            e.expression(e.expr);
            break;
        case 2:
            cout << "Inorder traversal : ";
            e.display(e.top);
            cout << endl;
            cout << "Postorder traversal : ";
            e.post(e.top);
            cout << endl;
            break;
        case 3:
            e.del(e.top);
            e.top = NULL; // reset pointer to avoid reuse after delete
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }

        cout << "Do you want to continue (y/n) : ";
        cin >> c;
    } while (c == 'y');
    return 0;
}
