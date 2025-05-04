#include<iostream>
#include<iomanip>
#include<cstring>  // Changed from <string.h> to modern C++
#define max 10
using namespace std;

struct node {
    int chain;
    long long int mn;
    char name[20];

    node() {
        strcpy(name, "");
        chain = -1;
        mn = -1;  // Use -1 to mark empty slots (0 could be valid)
    }
};

class dict {
public:
    node a[max];

    int hashfun(long long int key) {
        return key % max;
    }

    void insert() {
        node n;
        cout << "Enter phone number and name: ";
        cin >> n.mn >> n.name;

        int ind = hashfun(n.mn);
        int start = ind;
        int prev = -1;

        // Find empty slot
        while (a[ind].mn != -1) {
            prev = ind;
            ind = (ind + 1) % max;
            if (ind == start) {
                cout << "Hash table is full!" << endl;
                return;
            }
        }
        a[ind] = n;
        // Update chain
        if (prev != -1) {
            a[prev].chain = ind;
        }
    }

    void search() {
        long long int mn;
        cout << "Enter number to search: ";
        cin >> mn;

        int ind = hashfun(mn);
        while (ind != -1) {
            if (a[ind].mn == mn) {
                cout << "Found at index " << ind << endl;
                return;
            }
            ind = a[ind].chain;
        }
        cout << "Not found!" << endl;
    }

    void del()
{
    long int mn;
    cout << "Enter phone number to delete : ";
    cin >> mn;
    int idx = hashfun(mn);
    int prev = -1;
    while (idx != -1)
    {
        if (a[idx].mn == mn)
        {
            if (a[idx].chain == -1)
            {
                strcpy(a[idx].name, "");
                a[idx].mn = 0;
                a[idx].chain = -1;
            }
            else if(prev==-1 && a[idx].chain!=-1){
                int next=a[idx].chain;
                a[idx]=a[next];
                strcpy(a[next].name, "");
                a[next].mn = 0;
                a[next].chain = -1;

            }else{
                a[prev].chain=a[idx].chain;
                strcpy(a[idx].name, "");
                a[idx].mn = 0;
                a[idx].chain = -1;
            }
            cout << "Phone number deleted\n";
            return;

        }
        prev = idx;
        idx = a[idx].chain;

    }
    cout << "Phone number not found\n";
}
void display(){
    cout<<left<<setw(10)<<"index"<<setw(20)<<"name"<<setw(20)<<"mobile_no"<<setw(20)<<"chain"<<setw(10)<<endl;
    for(int i=0;i<max;i++){
        cout<<left<<setw(10)<<i<<setw(20)<<a[i].name<<setw(20)<<a[i].mn<<setw(20)<<a[i].chain<<setw(10)<<endl;
    }
}
};

int main() {
    dict d;
    char r;
    do {
        cout << "\n1. Insert\n2. Search\n3. Display\n4. Delete\n5. Exit\nEnter choice: ";
        int ch;
        cin >> ch;

        switch (ch) {
            case 1: d.insert(); break;
            case 2: d.search(); break;
            case 3: d.display(); break;
            case 4: d.del(); break;
            case 5: exit(0);
            default: cout << "Invalid choice!" << endl;
        }

        cout << "Continue? (y/n): ";
        cin >> r;
    } while (r == 'y' || r == 'Y');

    return 0;
}