#include "iostream"
using namespace std;
int max_value(int* a,int n){
    int m=a[0];
    for(int i=0;i<n;i++){
        m=max(m,a[i]);
    }
    return m;
}
void count_sort(int* a,int n,int exp){
    int result[n+1];
    int count[10]={0};

    for(int i=0;i<n;i++){
        count[(a[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        result[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        a[i]=result[i];
    }
}
void radixsort(int* a,int n){
    int m=max_value(a,n);
    for(int i=1; m/i>0;i*=10){
        count_sort(a,n,i);
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
    radixsort(a,n);
    print(a,n);
}