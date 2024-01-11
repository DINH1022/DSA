#include "iostream"
#include "string"
#include "math.h"
using namespace std;

class Stack { 
public: 
    string data; 
    Stack* next; 
}; 
  
Stack* newNode(string data) 
{ 
    Stack* St = new Stack; 
    St->data = data; 
    St->next = nullptr; 
    return St; 
} 
  
int isEmpty(Stack* root) 
{ 
    return !root; 
} 
  
void push(Stack** root, string data) 
{ 
    Stack* Stack = newNode(data); 
    Stack->next = *root; 
    *root = Stack; 
} 
  
void pop(Stack** root) 
{ 
    if (isEmpty(*root)) 
        return; 
    Stack* temp = *root; 
    *root = (*root)->next; 
    free(temp); 
}
bool isdigit(char x){
    if (x>='0' && x<='9') {
        return true;
    }
    return false;
}

void Try(string& s){
    int k=s.find(' ');
    while(k>=0 && k<s.length()){
        s.erase(k,1);
        k=s.find(' ');
    }
    s='('+s+')';
}
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string get_string(char x){
    string s(1,x);
    return s;
}
Stack* infix_to_postfix(string s){
    Stack* result=nullptr;
    Stack* tmp=nullptr;
    string ss="";
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])){
            ss+=s[i];
        }
        else if(s[i]=='('){
            push(&tmp,get_string(s[i]));
        }
        else if(s[i]==')'){
            if(ss!=""){
                push(&result,ss);
                ss="";
            }
            while(tmp->data!="("){
                push(&result,tmp->data);
                pop(&tmp);
            }
            pop(&tmp);
        }
        else{
            if(ss!=""){
                push(&result,ss);
                ss="";
            }
            while(!isEmpty(tmp) && prec(s[i])<=prec((tmp->data)[0])){
                push(&result,tmp->data);
                pop(&tmp);
            }
            push(&tmp,get_string(s[i]));
        }
    }
    while(!isEmpty(tmp)){
        push(&result,tmp->data);
        pop(&tmp);
    }
    return result;
}
int get_int(string s){
    int result=0;
    while(s.length()>0){
        result+=(s[0]-'0');
        result*=10;
        s.erase(0,1);
    }
    return result/10;
}
int main(){
    string s="-1+-15+6+4";
    Try(s);
    Stack* a=infix_to_postfix(s);
    while (!isEmpty(a)){
        cout<<a->data<<endl;
        pop(&a);
    }
}