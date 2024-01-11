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
    cout<<diameter(root);
    return 0;

}