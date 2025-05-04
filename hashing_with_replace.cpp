#include<iostream>
#include<cstring>
#include<iomanip>
#define max 10
using namespace std;
struct node{
    char name[20];
    int chain;
    long long int mn;

    node(){
        strcpy(name," ");
        chain=-1;
        mn=0;
    }
};
class dict{
    node a[max];
    public:
    int hashfun(long long int);
    void insert();
    void search();
    void del();
    void display();
    int isfull();
};

int dict::hashfun(long long int key){
    return key%max;
}

int dict::isfull(){
    for(int i=0;i<max;i++){
       if(a[i].mn==0){
        return 0;
       }
    }
    return 1;
}
void dict::search(){
    long long int mn;
    cout<<"enter the roll number to be search"<<endl;
    cin>>mn;
    int ind=hashfun(mn);
    while(ind!=-1){
        if(a[ind].mn==mn){
            cout<<"the phone number is found at"<<ind<<endl;
            return;
        }
        ind=a[ind].chain;
    }
    cout<<"not found sorry"<<endl;
}

void dict::del(){
    long long int mn;
    cout<<"enter the mobile number to be deleted"<<endl;
    cin>>mn;
    int ind=hashfun(mn);
    int prev=-1;
    while(ind!=-1){
        if(a[ind].mn==mn){
            if(a[ind].chain==-1){
                strcpy(a[ind].name,"");
                a[ind].chain=-1;
                a[ind].mn=0;
            }
            else if(prev==-1 && a[ind].chain!=-1){
                int next=a[ind].chain;
                a[ind]=a[next];
                strcpy(a[next].name," ");
                a[next].chain=-1;
                a[next].mn=0;
            }
            else{
                a[prev].chain=a[ind].chain;
                strcpy(a[ind].name,"");
                a[ind].chain=-1;
                a[ind].mn=0;
            }
            cout<<"element deleted successfully"<<endl;
            return;
        }
        prev=ind;
        ind=a[ind].chain;
    }
    cout<<"number not found";
}

void dict::display(){
        cout<<left<<setw(10)<<"index"<<setw(20)<<"name"<<setw(20)<<"mobile_no"<<setw(20)<<"chain"<<setw(10)<<endl;
        for(int i=0;i<max;i++){
            cout<<left<<setw(10)<<i<<setw(20)<<a[i].name<<setw(20)<<a[i].mn<<setw(20)<<a[i].chain<<setw(10)<<endl;
        }
    }

    void dict::insert()
  {
    if(isfull()){
        cout<<"hash table is full"<<endl;
        return;
    }
    node n;
    cout<<"enter name and phone number"<<endl;
    cin>>n.name>>n.mn;
    int ind=hashfun(n.mn);
    int prev=-1;
    if(a[ind].mn==0){
        a[ind]=n;
    }
    else if(hashfun(n.mn)==hashfun(a[ind].mn)){
        while(a[ind].mn!=0){
            if(hashfun(n.mn)==hashfun(a[ind].mn)){
                prev=ind;
            }
            ind=(ind+1)%max;
        }
        a[ind]=n;
        a[prev].chain=ind;
    }
    else{
        node temp;
        temp=a[ind];
        a[ind]=n;
        while(a[ind].mn!=0){
            ind=(ind+1)%max;
        }
        a[ind]=temp;
        int ind2=hashfun(temp.mn);
        prev=ind2;
            while(a[ind2].chain!=-1){
                ind2=a[ind2].chain;
                if(a[ind2].chain!=-1){
                    prev=ind2;
            }
        }
        a[prev].chain=ind;
    }
  }
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