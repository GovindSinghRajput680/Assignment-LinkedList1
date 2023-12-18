#include<iostream>
using namespace std;
class Node{//User defined data type
public:
    int val;
    Node *next;
    Node(int val){
        this->val = val;
        next = NULL;
    }
};
class LinkedList{//User defined data structure
public:
    Node* head;
    Node *tail;
    int size;
    //Constructor for LinkedList
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }
    //Insertion of an element at end:
    void InsertAtTail(int val){
        Node *temp = new Node(val);
        if(size == 0) head = tail = temp;
        else tail->next = temp,tail = temp;
        size++;
    }
    //Insert At Head
    void InsertAtHead(int val){
        Node *temp = new Node(val);
        if(size == 0) head = tail = temp;
        else temp->next = head,head = temp;
        size++;
    }
    //Insert an ele at idx
    void InsertAt(int idx,int val){
        if(idx<0 || idx>size) cout<<"Invalid Index!!";
        else if(idx == 0) InsertAtHead(val);
        else if(idx == size) InsertAtTail(val);
        else{
            Node *t = new Node(val);
            Node *temp = head;
            for(int i =1;i<=idx-1;i++) temp= temp->next;
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }
    //Getting an ele at idx 
    int GetAtIdx(int idx){
        if(idx<0 || idx>=size) {
            cout<<"Invalid index";
            return -1;
        }
        if(idx == 0) return head->val;
        if(idx == size-1) return tail->val;
        Node *temp = head;
        for(int i =1;i<=idx;i++) temp= temp->next;
        return temp->val;
    }
    //Delete At Head
    void DeletAtHead(){
        if(size == 0){
            cout<<"Your LinkedList is empty!!";
            return;
        }
        head= head->next;
        size--;
    }
    //Delete at tail
    void DeletAtTail(){
        if(size == 0){
            cout<<"Your LinkedList is empty!";
            return;
        }
        Node *temp = head;
        while(temp->next != tail) temp = temp->next;
        temp->next = NULL;
        size--;
        tail = temp;
    }
    //Delet At index 
    void DeletAtIdx(int idx){
        if(idx<0 || idx>=size){
            cout<<"Invalid index!";
            return;
        }
        if(idx == 0) return DeletAtHead();
        if(idx == size-1) return DeletAtTail();
            Node *temp = head;
            for(int i =1;i<=idx-1;i++) temp= temp->next;
            temp->next = temp->next->next;
            size--;
    }
    //Displaying a LL
    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){LinkedList ll;
    ll.InsertAtTail(10);
    ll.display();//10 
    ll.InsertAtTail(20);
    ll.display();//10->20
    ll.InsertAtTail(30);
    ll.display();//10->20->30
    ll.InsertAtTail(40);
    ll.display();//10->20->30->40
    ll.InsertAtHead(5);
    ll.display();//5->10->20->30->40
    cout<<ll.size<<endl;
    ll.InsertAt(2,15);
    ll.display();//5->10->15->20->30->40
    ll.InsertAt(5,35);
    ll.display();//5->10->15->20->30->35->40
    cout<<ll.GetAtIdx(6)<<endl;
    ll.DeletAtHead();
    ll.display();//10->15->20->30->35->40
    ll.DeletAtTail();
    ll.display();//10->15->20->30->35
    ll.DeletAtIdx(2);
    ll.display();//10->15->30->35
    cout<<ll.size;

}