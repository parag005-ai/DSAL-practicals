#include <iostream>
using namespace std;

struct node {
    int cnt;
    char label[50];
    node *child[50];

    node() {
        for (int i = 0; i < 50; i++) {
            child[i] = NULL;
        }
    }
};

class book {
    node *root;
public:
    book() {
        root = NULL;
    }
    void create();
    void display();
};

void book::create() {
    root = new node;
    cout << "enter the name of book" << endl;
    cin >> root->label;
    cout << "enter total number of chapters" << endl;
    cin >> root->cnt;

    for (int i = 0; i < root->cnt; i++) {
        root->child[i] = new node();
        cout << "enter the name of the chapters" << i + 1 << endl;
        cin >> root->child[i]->label;
        cout << "enter total number of sections" << endl;
        cin >> root->child[i]->cnt;

        for (int j = 0; j < root->child[i]->cnt; j++) {
            root->child[i]->child[j] = new node();
            cout << "enter the name of section" << j + 1 << endl;
            cin >> root->child[i]->child[j]->label;
            cout << "enter total numebr of subsections" << endl;
            cin >> root->child[i]->child[j]->cnt;

            for (int k = 0; k < root->child[i]->child[j]->cnt; k++) {
                root->child[i]->child[j]->child[k] = new node();  
                cout << "Enter sub-section name: ";
                cin >> root->child[i]->child[j]->child[k]->label; 
            }
        }
    }
}

void book::display() {
    if (root == NULL) {
        cout << "nhi hai bhai book";
        return;
    }

    cout << "book name is :" << root->label << endl;

    for (int i = 0; i < root->cnt; i++) {
        cout << "chapter :" << i + 1 << root->child[i]->label<<endl;
    
        for (int j = 0; j < root->child[i]->cnt; j++) {
            cout << "section :" << j + 1 << root->child[i]->child[j]->label<<endl;
    
            for (int k = 0; k < root->child[i]->child[j]->cnt; k++) {
                cout << "subsection :" << k + 1 << root->child[i]->child[j]->child[k]->label<<endl;
            }
        }
    }
}

int main() {
    book b;
    int ch;
    char c;

    do {
        cout << "\n1. Create book\n2. Display book\n3. Exit\nEnter your choice : ";
        cin >> ch;

        switch (ch) {
            case 1:
                b.create();
                break;
            case 2:
                b.display();
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice\n";
        }

        cout << "Do you want to continue (y/n) : ";
        cin >> c;
    } while (c == 'y');

    return 0;
}