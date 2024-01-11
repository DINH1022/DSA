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
int find_level_nodeX(node* root, int x){ //last level
    if(!root) {
        return -1;
    }
    int level=-1;
    int tmp=0;
    queue <node*> row;
    row.push(root);
    while(!row.empty()){
        int n=row.size();
        for(int i=1;i<=n;i++){
            node* p=row.front();
            row.pop();
            if(p->data==x) {
                level=tmp;
            }
            if(p->pleft){
                row.push(p->pleft);
            }
            if(p->pright){
                row.push(p->pright);
            }
        }
        tmp++;
    }
    return level;
}

int main(){
    node* root = newnode(5);
    root->pleft = newnode(10);
    root->pright = newnode(25);
    root->pleft->pleft = newnode(20);
    root->pleft->pright = newnode(25);
    root->pleft->pright->pright = newnode(45);
    root->pright->pleft = newnode(30);
    root->pright->pright = newnode(35);
    cout<<find_level_nodeX(root,90);
}