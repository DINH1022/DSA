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
int find_depth(node* root){
    if(!root){
        return 0;
    }
    int maxdepth=0;
    for(vector<node*>::iterator it= root->child.begin(); it!=root->child.end();it++){
        maxdepth=max(maxdepth,find_depth(*it));
    }
    return maxdepth+1;
}
int diameter(node* p){
    if(!p){
        return -1;
    }
    int max1=0;
    int max2=0;
    for(vector<node*>::iterator it = p->child.begin();it!=p->child.end();it++){
        int depth=find_depth(*it);
        if(depth>max1){
            max2=max1;
            max1=depth;
        }
        else if(depth>max2){
            max2=depth;
        }
    }
    int depth_child=0;
    for(vector<node*>::iterator it=p->child.begin();it!=p->child.end();it++){
        depth_child=max(depth_child,diameter(*it));
    }
    return max(depth_child,max1+max2+1);
}
void print_all_leaf(node* root){
    if(!root){
        return;
    }
    if(root->child.empty()){
        cout<<root->data<<" ";
        return;
    }
    else {
        for(vector<node*>::iterator it=root->child.begin(); it != root->child.end();it++){
            print_all_leaf(*it);
        }
    }
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