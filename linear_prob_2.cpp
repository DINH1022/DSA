#include <iostream>
#include <string>
using namespace std;
struct Node {
    int key;
    string value;
};

int code(int key, int capacity) {
    return key % capacity;
}

void insertNode(Node **arr, int key, const string &value, int capacity, int &size) {
    Node *temp = new Node{key, value};
    int i = code(key, capacity);
    while (arr[i] && arr[i]->key != key && arr[i]->key != -1) {
        i++;
        i %= capacity;
    }
    if (!arr[i] || arr[i]->key == -1) {
        size++;
    }
    arr[i] = temp;
}

string deleteNode(Node **arr, int key, int capacity, int &size) {
    int i = code(key, capacity);
    while (arr[i]) {
        if (arr[i]->key == key) {
            Node *temp = arr[i];
            arr[i] = new Node{-1, ""};
            size--;
            return temp->value;
        }
        i++;
        i %= capacity;
    }
    return "";
}

string getNode(Node **arr, int key, int capacity, int &counter) {
    int i = code(key, capacity);
    while (arr[i]) {
        if (counter++ > capacity) {
            return "";
        }
        if (arr[i]->key == key) {
            return arr[i]->value;
        }
        i++;
        i %= capacity;
    }
    return "";
}

int mapSize(int size) {
    return size;
}

bool isEmpty(int size) {
    return (size == 0);
}

void printMap(Node **arr, int capacity) {
    for (int i = 0; i < capacity; i++) {
        if (arr[i] && arr[i]->key != -1) {
            cout << "key: " << i << " value: " << arr[i]->value << endl;
        }
    }
}

int main() {
    int capacity = 10;
    int size = 0;
    Node **arr = new Node *[capacity];
    for (int i = 0; i < capacity; i++) {
        arr[i] = nullptr;
    }

    insertNode(arr, 1, "abc", capacity, size);
    insertNode(arr, 11, "bcas", capacity, size);
    insertNode(arr, 2, "aabc", capacity, size);
    insertNode(arr, 4, "bfabc", capacity, size);

    printMap(arr, capacity);
    cout << mapSize(size) << endl;
    cout << deleteNode(arr, 2, capacity, size) << endl;
    cout << isEmpty(size) << endl;
    int counter = 0;
    cout << getNode(arr, 11, capacity, counter);

    // Clean up allocated memory
    for (int i = 0; i < capacity; i++) {
        delete arr[i];
    }
    delete[] arr;

    return 0;
}
