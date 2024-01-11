#include "iostream"
using namespace std;
void merge(int* a,int const left,int const mid,int const right){
    int const arr1_len=mid-left+1;
    int const arr2_len=right-mid;

    int* arr1=new int[arr1_len];
    int* arr2=new int[arr2_len];

    for(int i=0;i<arr1_len;i++){
        arr1[i]=a[left+i];
    }
    for(int i=0;i<arr2_len;i++){
        arr2[i]=a[mid+i+1];
    }

    int index=left;
    int index1=0;
    int index2=0;
    while (index1<arr1_len && index2<arr2_len){
        if(arr1[index1]<=arr2[index2]){
            a[index]=arr1[index1];
            index1++;
        }
        else{
            a[index]=arr2[index2];
            index2++;
        }
        index++;
    }
    while(index1<arr1_len){
        a[index++]=arr1[index1++];
    }
    while(index2<arr2_len){
        a[index++]=arr2[index2++];
    }
}
void mergesort(int* a,int const begin,int const end){
    if(begin<end){
        int mid=begin+(end-begin)/2;
        mergesort(a,begin,mid);
        mergesort(a,mid+1,end);
        merge(a,begin,mid,end);
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
    mergesort(a,0,n);
    print(a,n);
}