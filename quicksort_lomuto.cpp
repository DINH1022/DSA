#include "iostream"

using namespace std;

int partition(int *a, int low,int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if (a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}
void quicksort_lomuto(int *a,int low,int high){
    if(low<high){
        int p=partition(a,low,high);
        quicksort_lomuto(a,low,p-1);
        quicksort_lomuto(a,p+1,high);
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
    quicksort_lomuto(a,0,n);
    print(a,n);
}

