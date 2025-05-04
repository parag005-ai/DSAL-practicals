#include <iostream>
using namespace std;
struct node{
    int data;
    node*left;
    node*right;
};
class bst{
    public:
    node*root;
    bst(){
        root=NULL;
    }
    void create();
    void insert(node *,node*);
    void display();
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
    void min1(node*);
    void max1(node*);
    int height(node*);
    void search(node*);
    void mirror(node *);
    int leafcount(node*);
};
void bst::create(){
    char ch;
    do{
        node *nn=new node;
        nn->left=nn->right=NULL;
        cout<<"Enter data : ";
        cin>>nn->data;
        if(root==NULL){
            root=nn;
        }else{
            insert(root,nn);
        }
        cout<<"Want to add more nodes ? (y/n) : ";
        cin>>ch;
    }while(ch=='y');
}
void bst::insert(node *root,node*nn){
    if(nn->data<root->data){
        if (root->left==NULL){
            root->left=nn;
        }else{insert(root->left,nn);}
    }else{
        if (root->right==NULL){
            root->right=nn;
        }else{insert(root->right,nn);}

    }
}
void bst::inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void bst::postorder(node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
  
}
void bst::preorder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void bst::display(){
    cout<<"\nInorder Traversal : ";
    inorder(root);
  
    cout<<"\nPreorder Traversal : ";
    preorder(root);

    cout<<"\nPostorder Traversal : ";
    postorder(root);

}
void bst::min1(node *root){
    if(root==NULL){
        cout<<"Tree is empty\n";
        return;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    cout<<"Minimum element is : "<<root->data<<endl;
}
void bst::max1(node *root){
    if(root==NULL){
        cout<<"\ntreee is empty\n";
        return;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    cout<<"Maximum element is : "<<root->data<<endl;
}
int bst::height(node *root){
    if(root==NULL){
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    if(l>r){
        return l+1;
    }else{
        return r+1;
    }
}
void bst::search(node *root){
    int key;
    cout<<"Enter element to be searched : ";
    cin>>key;
    while(root!=NULL){
        if(key==root->data){
            cout<<"Element found\n";
            return;
        }else if(key<root->data){
            root=root->left;
        }else{
            root=root->right;
        }
    }
    cout<<"Element not found\n";
}
void bst::mirror(node *root){
    if(root==NULL){
        return;
    }
    mirror(root->left);
    mirror(root->right);
    node *temp=root->left;
    root->left=root->right;
    root->right=temp;

}
int bst::leafcount(node *root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }else{
        return leafcount(root->left)+leafcount(root->right);
    }
}
int main(){
    bst b;
    int choice;
    char ch;
    do{
        cout<<"1.Create\n2.Display\n3.Min\n4.Max\n5.Height\n6.Search\n7.Mirror\n8.Leaf Count\n9.Exit\nEnter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                b.create();
                break;
            case 2:
                b.display();
                break;
            case 3:
                b.min1(b.root);
                break;
            case 4:
                b.max1(b.root);
                break;
            case 5:
                cout<<"Height of tree is : "<<b.height(b.root)<<endl;
                break;
            case 6:
                b.search(b.root);
                break;
            case 7:
                b.mirror(b.root);
                cout<<"Mirror of tree is created\n";
                break;
            case 8:
                cout<<"Leaf count is : "<<b.leafcount(b.root)<<endl;
                break;
            case 9:
                cout<<"Exiting...\n";
              return 0;
            default:
                cout<<"Invalid choice\n";
        }
        cout<<"\nDo you want to continue (y/n) : ";
        cin>>ch;
    }while(ch=='y');
}
