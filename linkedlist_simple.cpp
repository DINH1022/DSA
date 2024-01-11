#include "iostream"
#include "stdio.h"
using namespace std;
struct NODE{
    int data;
    NODE* next;
};
NODE* Create_Node(int data){
    NODE* pnode=new(nothrow) NODE;
    if(!pnode){
        return nullptr;
    }
    pnode->data=data;
    pnode->next=nullptr;
    return pnode;
}
void Print_Node(NODE* x){
    printf("%d\n",x->data);
}
struct LIST{
    NODE* pHead;
    NODE* pTail;
};
bool Push_Head(LIST* ll,int data){
    NODE* pnode=Create_Node(data);
    if(!pnode){
        return false;
    }
    if(ll->pHead==nullptr){
        ll->pHead=ll->pTail=pnode;
    }
    else{
        pnode->next=ll->pHead;
        ll->pHead=pnode;
    }
    return true;
}
bool Push_Tail(LIST* ll,int data){
    NODE* pnode=Create_Node(data);
    if(!pnode){
        return false;
    }
    if(ll->pTail==nullptr){
        ll->pHead=ll->pTail=pnode;
    }
    else{
        ll->pTail->next=pnode;
        ll->pTail=pnode;
    }
    return true;
}
int Count_List(LIST* ll){
    int c=0;
    NODE* p;
    for(p=ll->pHead;p!=nullptr;p=p->next){
        c++;
    }
    return c;
}
// chen vao truoc vi tri cua gia tri co position hien tai
bool Push_Front(LIST* ll,int data,int position){
    int n=Count_List(ll);
    if(position>n || position<1){
        return false;
    }
    if(position==1){
        return Push_Head(ll,data);
    }
    NODE* pnode=Create_Node(data);
    if(!pnode){
        return false;
    }
    NODE* pcur=ll->pHead;
    while(position>2){
        position--;
        pcur=pcur->next;
    }
    pnode->next=pcur->next;
    pcur->next=pnode;
    return true;
}
// chen vao sau vi tri cua gia tri co position hien tai
bool Push_Behind(LIST* ll,int data,int position){
    int n=Count_List(ll);
    
    if(position>n || position<1){
        return false;
    }
    if(position==n){
        return Push_Tail(ll,data);
    }
    Push_Front(ll,data,position);
    NODE* pcur=ll->pHead;
     while(position>1){
        position--;
        pcur=pcur->next;
    }
    int tmp=pcur->data;
    pcur->data=pcur->next->data;
    pcur->next->data=tmp;
    return true;
}
bool Delete_Node(LIST** ll,int position){
    int n=Count_List(*ll);
    if(position>n || position<1){
        return false;
    }
    NODE* pnode;
    NODE* tmp;
    tmp=pnode=(*ll)->pHead;
    int i=1;
    while(i<=position){
        if(i==1 && position==1){
            (*ll)->pHead=(*ll)->pHead->next;
            delete(tmp);
        }
        else{
            if(i==position && tmp!=nullptr){
                pnode->next=tmp->next;
                delete(tmp);
            }
            else{
                pnode=tmp;
                if(!pnode){
                    break;
                }
                tmp=tmp->next;
            }
        }
        i++;
    }
    return true;
}

void Print_List(LIST* ll){
    NODE* pnode=ll->pHead;
    for(;pnode!=nullptr;pnode=pnode->next){
        Print_Node(pnode);
    }
}
LIST* Create_List(){
    LIST* ll=new(nothrow) LIST{nullptr,nullptr};
    if(!ll){
        return nullptr;
    }
    return ll;
}
void DeleteAll_K(LIST* ll,int x){
    int position=1;
    int k=1;
    int n=Count_List(ll);
    int* a=new(nothrow) int[n+5];
    NODE* p=ll->pHead;
    while(p!=nullptr){
        if(p->data==x){
            *(a+k)=position;
            k++;
        }
        p=p->next;
        position++;
    }
    for(int i=1;i<k;i++){
        Delete_Node(&ll,a[i]-i+1);
    }
    delete[] a;
}
void RemoveAll(LIST** ll){
    NODE* p=(*ll)->pHead;
    while(p!=nullptr){
        NODE* tmp=p;
        p=p->next;
        delete(tmp);
        tmp=nullptr;
    }
    (*ll)=nullptr;
}
int main(){
    LIST* plist=Create_List();
    for(int i=1;i<=9;i++){
        Push_Tail(plist,i);
    }
    Push_Tail(plist,2);
    //Push_Behind(plist,10,5);
    //Push_Front(plist,11,3);
    Delete_Node(&plist,9);
    Delete_Node(&plist,1);
    DeleteAll_K(plist,2);
    Print_List(plist);
    RemoveAll(&plist);
    /*NODE* a=plist->pHead;
    NODE* b=a->next;
    a->next=nullptr;
    delete b;*/

}