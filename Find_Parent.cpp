#include "iostream"
#include "queue"
using namespace std;
struct node {
    int data;
    node* pleft;
    node* pright;
};
node* newnode(int key){
    node* tmp=new node{key,nullptr,nullptr};
    if(!tmp){
        return nullptr;
    }
    return tmp;
}
void find_parent(node* root, int child,int parent){
    if(!root) {
        return;
    }
    if(root->data==child){
        cout<< parent;
    }
    else {
        find_parent(root->pleft,child,root->data);
        find_parent(root->pright,child,root->data);
    }
}

int main(){
    node* root = newnode(5);
    root->pleft = newnode(10);
    root->pright = newnode(15);
    root->pleft->pleft = newnode(20);
    root->pleft->pright = newnode(25);
    root->pleft->pright->pright = newnode(45);
    root->pright->pleft = newnode(30);
    root->pright->pright = newnode(35);
    find_parent(root,7,-1);
}