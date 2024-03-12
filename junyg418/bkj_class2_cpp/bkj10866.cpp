// 1차 성공

#include <iostream>
#include <string>

using namespace std;

class Node{
public:
    int data;
    Node * link;

    Node(int data, Node *link) : data(data), link(link){}
};

class Deque{
    public:
        Node *arr;
        int len;

    Deque(){
        arr = nullptr;
        len = 0;
    }

    void push_front(int x){
        if (arr == nullptr) arr = new Node(x, nullptr);
        else arr = new Node(x, arr);

        len++;
    }

    void push_back(int x){
        if (arr == nullptr) arr = new Node(x, nullptr);
        else{
            Node *temp = arr;
            while(true){
                if (temp->link == nullptr) break;
                temp = temp->link;
            }
            temp->link = new Node(x, nullptr);
        }
        len++;
    }

    int pop_front(){
        if (arr == nullptr) return -1;
        int result = arr->data;
        arr = arr->link;
        len--;
        return result;
    }

    int pop_back(){
        Node *temp = arr;
        int result;
        if (arr == nullptr) return -1;
        else if (arr->link == nullptr){
            result = arr->data;
            arr = nullptr;
        }
        else{
            while (true){
                if (temp->link->link == nullptr) break;
                temp = temp->link;
            }
            result = temp->link->data;
            temp->link = nullptr;
        }
        len--;
        return result;
    }

    int size(){
        if (arr == nullptr) return 0;
        int cnt = 1;
        Node *temp = arr;
        while(true){
            if (temp->link == nullptr) return cnt;
            temp = arr->link;
            cnt++;
        }
    }

    int empty(){
        if (arr == nullptr) return 1;
        return 0;
    }

    int front(){
        if (arr == nullptr) return -1;
        return arr->data;
    }

    int back(){
        if (arr == nullptr) return -1;

        Node *temp = arr;
        while(true){
            if (temp->link == nullptr) return temp->data;
            temp = temp->link;
        }
    }
};

int main(){
    int n;
    cin >> n;

    Deque * dq = new Deque();
    string commend;
    int data;
    for (int i=0; i<n; i++){
        cin >> commend;
        if (commend == "push_front"){
            cin >> data;
            dq->push_front(data);
        }
        else if (commend == "push_back"){
            cin >> data;
            dq->push_back(data);
        }
        else if (commend == "pop_back"){
            cout << dq->pop_back() << endl;
        }
        else if (commend == "pop_front"){
            cout << dq->pop_front() << endl;
        }
        else if (commend == "size"){
            cout << dq->len << endl;
        }
        else if (commend == "empty"){
            cout << dq->empty() << endl;
        }
        else if (commend == "front"){
            cout << dq->front() << endl;
        }
        else if (commend == "back"){
            cout << dq->back() << endl;
        }
    }
}