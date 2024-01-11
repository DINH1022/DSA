#include "iostream"
using namespace std;
int partition(int* a,int left,int right){
    int pivot = a[left+(right-left)/2]; 
    int i = left - 1;
    int  j = right + 1; 
    while (true) { 
        do { 
            i++; 
        } while (a[i] < pivot); 
        do { 
            j--; 
        } while (a[j] > pivot); 
        if (i >= j) 
            return i; 
        swap(a[i], a[j]); 
    } 
}
void quicksort_hoare(int* a,int begin,int end){
    if(begin>=end){
        return;
    }
    int mid=partition(a,begin,end);
    quicksort_hoare(a,begin,mid);
    quicksort_hoare(a,mid+1,end);
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
    quicksort_hoare(a,0,n);
    print(a,n);
}