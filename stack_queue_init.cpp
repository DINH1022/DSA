#include <iostream>
#include <string>
#include<string.h>
using namespace std;

struct Node {
    string data;
    Node* next = nullptr;
};

struct List {
    Node* head = nullptr;
};

Node* CreateNode(const string& data) {
    Node* node = new (nothrow) Node;
    if (!node)
        return nullptr;
    node->data = data;
    node->next = nullptr;
    return node;
}

void PushBack(List& l, const string& data) {
    if (!l.head) {
        l.head = CreateNode(data);
        return;
    }
    Node* cur = l.head;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = CreateNode(data);
}

void PushFront(List& l, const string& data) {
    Node* node = CreateNode(data);
    if (!node)
        return;
    if (!l.head)
        l.head = node;
    else {
        node->next = l.head;
        l.head = node;
    }
}

void PopBack(List& l) {
    if (!l.head)
        return;
    if (!l.head->next) {
        delete l.head;
        l.head = nullptr;
        return;
    }
    Node* cur = l.head;
    while (cur->next->next) {
        cur = cur->next;
    }
    delete cur->next;
    cur->next = nullptr;
}

void PopFront(List& l) {
    if (!l.head)
        return;
    Node* tmp = l.head->next;
    delete l.head;
    l.head = tmp;
}

bool Empty(List& l) {
    return l.head == nullptr;
}

void Delete(Node*& node) {
    if (!node)
        return;
    Delete(node->next);
    delete node;
    node = nullptr;
}

struct Queue {
    List list;
};

void PushQ(Queue& q, const string& data) {
    PushBack(q.list, data);
}

void PopQ(Queue& q) {
    PopFront(q.list);
}

string FrontQ(Queue& q) {
    return q.list.head->data;
}

bool EmptyQ(Queue& q) {
    return Empty(q.list);
}

struct Stack {
    List list;
};

void PushS(Stack& st, const string& data) {
    PushFront(st.list, data);
}

void PopS(Stack& st) {
    PopFront(st.list);
}

string TopS(Stack& st) {
    return st.list.head->data;
}

bool EmptyS(Stack& st) {
    return Empty(st.list);
}
