#include "iostream"
#include "queue"
using namespace std;
struct node {
    int data;
    vector < node*> child;
};

node* newnode(int key){
    node* p=new node{key};
    if(!p){
        return nullptr;
    }
    return p;
}
int count_children(node* root, int value){
    if(!root){
        return 0;
    }
    int numchild=0;
    queue<node*> p;
    p.push(root);
    while(!p.empty()){
        node* tmp=p.front();
        p.pop();
        if(tmp->data==value){
            numchild+=tmp->child.size();
        }
        for(int i=0;i<tmp->child.size();i++){
            p.push(tmp->child[i]);
        }
    }
    return numchild;
}
int main(){
    node* root = newnode(10);
    (root->child).push_back(newnode(20));
 
    (root->child).push_back(newnode(30));
 
    (root->child).push_back(newnode(20));
 
    (root->child[0]->child).push_back(newnode(50));
 
    (root->child[0]->child).push_back(newnode(60));
 
    (root->child[1]->child).push_back(newnode(70));
 
    (root->child[1]->child).push_back(newnode(80));
 
    (root->child[2]->child).push_back(newnode(90));
 
    (root->child[2]->child).push_back(newnode(100));
 
    (root->child[2]->child).push_back(newnode(110));
    cout<<count_children(root,20);
}