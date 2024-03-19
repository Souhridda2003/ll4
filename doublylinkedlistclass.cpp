#include<iostream>
using namespace std;
class node{
    public:
        int val;
        node* next;
        node* prev; //extra for ll
        node(int val){
            this->val=val;
            this->next=NULL;
            this->prev=NULL; //extra for dll
        }
};
class DLL{ // user defined data structure
public:
    node* head;
    node* tail;
    int size;
    DLL(){
        head=tail=NULL;
        size=0;
    }
    void insertAtHead(int val){
        node* temp=new node(val);
        if(size==0) head=tail=temp;
        else{
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        size++;
    }
    void insertAtidx(int idx,int val){
        if(idx<0 || idx>size) cout<<"Invalid Index"<<endl;
        else if(idx==0) insertAtHead(val);
        else if(idx==size) insertAtEnd(val);
        else{
            node* t=new node(val);
            node* temp=head;
            for(int i=1;i<=idx-1;i++){
                temp=temp->next;
            }
            t->next=temp->next;
            temp->next=t;
            t->prev=temp;
            t->next->prev=t;
            size++;
        }
    }
    void insertAtEnd(int val){
        node* temp=new node(val);
        if(size==0) head=tail=temp;
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        size++;
    }
    int getAtIdx(int idx){
        if(idx<0 || idx>=size){
             cout<<"Inavlid Index";
             return -1;
        }
        else if(idx==0) return head->val;
        else if(idx==size-1) return tail->val;
        else{
            node* temp=head;
            for(int i=1;i<=idx;i++){
                temp=temp->next;
            }
            return temp->val;
        }
    }
    void deleteAtHead(){
        if(size==0){
            cout<<"List is empty";
            return;
        } 
        head=head->next;
        if(head!=NULL) head->prev=NULL; //extra
        else tail=NULL; //extra
        size--;
    }
     void deleteAtEnd(){
        if(size==0){
            cout<<"List is empty";
            return;
        }
        else if(size==1){ //extra
            deleteAtHead();
            return;
        }
        node* temp=tail->prev;
        temp->next=NULL;;
        tail=temp;
        size--;
    }
    void deleteatidx(int idx){
        if(idx<0 || idx>=size){
            cout<<"Invalid index";
            return;
        }
        else if(idx==0) return deleteAtHead();
        else if(idx==size-1) return deleteAtEnd();
        else{
            node* temp=head;
            for(int i=1;i<=idx-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            temp->next->prev=temp; //extra
            size--;
        }
    }
    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    DLL list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();
    list.insertAtEnd(40);
    list.display();
    list.insertAtHead(50);
    list.display();
    list.insertAtidx(2,60);
    list.display();
    list.deleteAtEnd();
    list.display();
    list.deleteAtHead();
    list.display();
    list.insertAtEnd(90);
    list.display();
    list.deleteatidx(3);
    list.display();
    cout<<list.getAtIdx(1);
}