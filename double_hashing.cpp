#include "iostream"
using namespace std;
template<typename K, typename V>
class Node { 
    public: 
    V value;
    K key;
    Node(K key, V value){
        this->value=value;
        this->key=key;
    }
};

template<typename K, typename V>
class Map{
    Node<K,V>**arr;
    int capacity;
    int size;
    Node<K,V>* dummy;

    public:
    Map(){
        capacity=10;
        size=0;
        arr=new Node<K,V>*[capacity];
        for(int i=0;i<capacity;i++){
            arr[i]=nullptr;
        }
        dummy=new Node<K,V>(-1,-1);
    }
    int code1(K key){
        return key%capacity;
    }
    int code2(K key){
        return key%(capacity/2)+1;
    }
    void insert_node(K key, V value){
        Node<K,V>* temp=new Node<K,V>(key,value);
        int i=code1(key);
        int j=1;
        while(arr[i] && arr[i]->key!=key && arr[i]->key!=-1){
            i=code1(key)+j*code2(key);
            j++;
            i%=capacity;
        }
        if(!arr[i] || arr[i]->key==-1){
            size++;
        }
        arr[i]=temp;
    }

    V delete_node(int key){
        int i=code1(key);
        int j=0;
        while(arr[i]){
            if(arr[i]->key==key){
                Node<K,V>* temp=arr[i];
                arr[i]=dummy;
                size--;
                return temp->value;
            }
            j++;
            i=code1(key)+j*code2(key);
            i%=capacity;
        }
        return V();
    }
    V get(int key){
        int i=code1(key);
        int j=0;
        int counter=0;
        while(arr[i]){
            if(counter++ > capacity){
                return V();
            }
            if(arr[i]->key==key){
                return arr[i]->value;
            }
            j++;
            i=code1(key)+j*code2(key);
            i%=capacity;
        }
        return V();
    }

    int map_size(){
        return size;
    }
    bool isempty(){
        return (size==0);
    }
    void print(){
        for(int i=0;i<capacity;i++){
            if(arr[i] && arr[i]->key!=-1){
                //cout<<"key: "<<arr[i]->key<<" value: "<<arr[i]->value<<endl;
                cout<<"key: "<<i<<" value: "<<arr[i]->value<<endl;

            }
        }
    }
};
int main(){
    Map<int,int>* m=new Map<int,int>;
    m->insert_node(1,1);
    m->insert_node(2,4);
    m->insert_node(3,8);
    m->insert_node(15,14);
    m->insert_node(25,78);
    m->insert_node(16,12);
    m->insert_node(12,13);

    m->print();
    cout<<m->map_size()<<endl;
    cout<<m->delete_node(12)<<endl;
    cout<<m->map_size()<<endl;
    cout<<m->isempty()<<endl;
    cout<<m->get(12)<<endl;
}



