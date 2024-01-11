#include "iostream"
using namespace std;
void selection_sort(int* a,int n){
    int min_pos=0;
    for(int i=0;i<n-1;i++){
        min_pos=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min_pos]){
                min_pos=j;
            }
        }
        if(min_pos!=i){
            swap(a[min_pos],a[i]);
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
    int n=5;
    int* a = new int[n+1];
    import(a,n);
    selection_sort(a,n);
    print(a,n);
}