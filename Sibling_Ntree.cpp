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
void find_sibling(node* root, int x) {
    
    if(!root){
        return;
    }
    
    int flag=0;
    queue<node*>p;
    p.push(root);

    while(!p.empty()){
        node* tmp=p.front();
        p.pop();
        int n=tmp->child.size();
        for(int i=0;i<n;i++){
            if(tmp->child[i]->data==x){
                flag=1;
                for(int j=0;j<n;j++){
                    if(tmp->child[j]->data!=x){
                        cout<<tmp->child[j]->data<<" ";
                    }
                }
                break;
            }
            p.push(tmp->child[i]);
        }
    }
    if(flag==0){
        cout<<"no siblings";
    }
}
int main(){
    node* root = newnode(10);
    (root->child).push_back(newnode(20));
 
    (root->child).push_back(newnode(30));
 
    (root->child).push_back(newnode(40));
 
    (root->child[0]->child).push_back(newnode(50));
 
    (root->child[0]->child).push_back(newnode(60));
 
    (root->child[1]->child).push_back(newnode(70));
 
    (root->child[1]->child).push_back(newnode(80));
 
    (root->child[2]->child).push_back(newnode(90));
  
    (root->child[2]->child).push_back(newnode(100));
 
    (root->child[2]->child).push_back(newnode(110));
    find_sibling(root,90);
}