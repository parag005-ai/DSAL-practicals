#include<iostream>
#define max 10
using namespace std;
class num{
    long long int a[max];
    public:
    num(){
        for(int i=0;i<max;i++){
            a[i]=0;
        }
    }
    int hashfun(long long int);
    void insert();
    void search();
    void display();
};
int num::hashfun(long long int key){
    return key % max;
}
void num::insert(){
    long long int key;
    cout<<"enter the phone number to be insert";
    cin>>key;
    int index=hashfun(key);
    int cnt=0;
    while(cnt<max){
        if(a[index]==0){
            a[index]=key;
            cout<<"phone number is inserted at"<<index<<endl;
            return;
        }
        else{
            index=(index+1)%max;
            cnt++;
        }
    }
    cout<<"hash table is filled completely";
}
void num::search(){
    long long int key;
    cout<<"enter the phone number to be search";
    cin>>key;
    int index=hashfun(key);
    for(int i=0;i<max;i++){
        int newind=(index+i)%max;
        if(a[newind]==key){
            cout<<"the phone number is found at"<<newind<<endl;
            return;
        }
        else if(a[newind]==0){
            break;
        }
    }
    cout<<"sorry phone number not found";
}
void num::display(){
    for(int i=0;i<max;i++){
        if(a[i]==0){
            cout<<i<<"------"<<"null"<<endl;
        }
        else{
            cout<<i<<"------"<<a[i]<<endl;
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
        switch (ch) {
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
        cout << "Want to continuee : (y/n) : ";
        cin >> r;
    } while (r == 'y');
    return 0;
}