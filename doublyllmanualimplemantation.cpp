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
void display(node* head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
void displayrev(node* tail){
    while(tail){
        cout<<tail->val<<" ";
        tail=tail->prev;
    }
}
void displayrec(node* head){
    if(head==NULL) return;
    cout<<head->val<<" ";
    displayrec(head->next);

}
void displayrecrev(node* head){
    if(head==NULL) return;
    displayrecrev(head->next);
    cout<<head->val<<" ";

}
int main(){
    node* a=new node(10);
    node* b=new node(20);
    node* c=new node(30);
    node* d=new node(40);
    node* e=new node(50);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->prev=d;
    d->prev=c;
    c->prev=b;
    b->prev=a;
    // display(a);
    // displayrec(a);
    // displayrecrev(a);
    displayrev(e);
}