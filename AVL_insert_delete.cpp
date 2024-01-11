#include "iostream"
#include "math.h"
using namespace std;
struct node{
    int data;
    node* pleft;
    node* pright;
    int height;
};
int max(int a, int b){
    return (a>=b) ? a : b;
}
int get_height(node* pnode){
    if(!pnode){
        return 0;
    }
    return max(get_height(pnode->pleft),get_height(pnode->pright))+1;
}
node* create(int item){
    node* pnode=new node{item,nullptr,nullptr,1};
    return pnode;
}

node* right_rotate(node* y){
    node* x=y->pleft;
    node* t2=x->pright;
    x->pright=y;
    y->pleft=t2;
    y->height=max(get_height(y->pleft),get_height(y->pright))+1;
    x->height=max(get_height(x->pleft),get_height(x->pright))+1;
    return x;
}

node* left_rotate(node* x){
    node* y=x->pright;
    node* t2=y->pleft;
    y->pleft=x;
    x->pright=t2;
    y->height=max(get_height(y->pleft),get_height(y->pright))+1;
    x->height=max(get_height(x->pleft),get_height(x->pright))+1;
    return y;
}

int balance(node* pnode){
    if(!pnode){
        return 0;
    }
    return get_height(pnode->pleft)-get_height(pnode->pright);
}

node* Insert(node* root, int item){
    if(!root){
        return create(item);
    }
    if(root->data < item){
        root->pright=Insert(root->pright,item);
    }
    else if (root->data > item){
        root->pleft=Insert(root->pleft,item);
    }
    else {
        return root;
    }
    root->height=max(get_height(root->pleft),get_height(root->pright))+1;
    int bl=balance(root);

    if(bl>1 && item<root->pleft->data){
        return right_rotate(root);
    }
    if(bl<-1 && item>root->pright->data){
        return left_rotate(root);
    }
    if(bl>1 && item>root->pleft->data){
        root->pleft= left_rotate(root->pleft);
        return right_rotate(root);
    }
    if(bl<-1 && item< root->pright->data){
        root->pright=right_rotate(root->pright);
        return left_rotate(root);
    }
    return root;
}
int minValue(node* root){
    while(root){
        root=root->pleft;
    }
    return root->data;
}
node* Delete(node* root, int item){
    if(!root){
        return nullptr;
    }
    if(item < root->data){
        root->pleft=Delete(root->pleft,item);
    }
    else if(item > root->data){
        root->pright=Delete(root->pright,item);
    }
    else{
        if(!root->pleft || !root->pright){
            node* tmp=root->pleft ? root->pleft : root->pright;
            if(!tmp){
                tmp=root;
                root=nullptr;
            }
            else{
                *root=*tmp;
            }
            delete(tmp);
        }
        else{
            int tmp=minValue(root->pright);
            root->data=tmp;
            root->pright=Delete(root->pright,tmp);
        }
    }
    if(!root){
        return root;
    }
    root->height=1+max(get_height(root->pleft),get_height(root->pright));
    int bl=balance(root);

    if(bl>1 && balance(root->pleft)>=0){
        return right_rotate(root);
    }
    if(bl<-1 && balance(root->pright)<=0){
        return left_rotate(root);
    }
    if(bl>1 && balance(root->pleft)<0){
        root->pleft= left_rotate(root->pleft);
        return right_rotate(root);
    }
    if(bl<-1 && item< balance(root->pright)>0){
        root->pright=right_rotate(root->pright);
        return left_rotate(root);
    }
    return root;

}
void preorder(node* root){
    if(root){
        cout<<root->data<<" "<<get_height(root)<<endl;
        preorder(root->pleft);
        preorder(root->pright);
    }
}
int main(){
    node* root=nullptr;
    root=Insert(root,100);
    root=Insert(root,10);
    root=Insert(root,90);
    root=Insert(root,40);
    root=Insert(root,60);
    root=Insert(root,80);
    root=Insert(root,110);
    root=Insert(root,120);
    root=Delete(root,100);
    root=Delete(root,80);

    preorder(root);
}