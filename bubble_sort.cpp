#include "iostream"
using namespace std;
void bubble_sort(int* a,int n){
    for(int i=0;i<n-1;i++){
        bool flag=false;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag=true;
            }
        }
        if(!flag){
            break;
        }
    }
}
void import(int* a,int n){
    for(int i=0;i<n;i++){
        cin>>*(a+i);
    }
}
void print(int* a,int n){
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
    }
}
int main(){
    int n=10;
    int* a = new int[n+1];
    import(a,n);
    bubble_sort(a,n);
    print(a,n);
}