#include "iostream"
#include "vector"
using namespace std;
struct node {
    int data;
    vector < node*> child;
};
node * new_node(int key){
    node* ptmp=new node {key};
    if(!ptmp){
        return nullptr;
    }
    return ptmp;
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
int main(){
    node* root=new_node(127);
    (root->child).push_back(new_node(1));
    (root->child).push_back(new_node(2));
    (root->child).push_back(new_node(3));
    (root->child).push_back(new_node(4));
    (root->child[0]->child).push_back(new_node(5));
    (root->child[0]->child).push_back(new_node(5));
    (root->child[3]->child).push_back(new_node(5));
    (root->child[3]->child).push_back(new_node(5));
    (root->child[3]->child[0]->child).push_back(new_node(9));
    (root->child[3]->child[0]->child).push_back(new_node(9));
   print_all_leaf(root);
    return 0;

}