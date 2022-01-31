#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;
};

Node* head=NULL;

//Create DLL
void createDLL(){
    int n;
    cout<<"Enter the size of the DLL: ";
    cin>>n;
    cout<<"Enter elements:\n";
    Node* it_node=new Node();
    cin>>it_node->data;
    it_node->next=NULL;
    it_node->prev=NULL;
    head=it_node;
    n-=1;
    while(n--){
        Node* new_node=new Node();
        cin>>new_node->data;
        new_node->next=head;
        new_node->prev=NULL;
        head->prev=new_node;
        head=new_node;
    }
}

//Display
void display(){
    if(head==NULL) cout<<"Create a DLL at first!";
    else{
        Node* it_node=head;
        do{
            cout<<it_node->data<<" ";
            it_node=it_node->next;
        }while(it_node!=NULL);
        cout<<endl;
    }
}

//Push
void push(){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    Node* new_node=new Node();
    new_node->data=data;
    new_node->next=head;
    new_node->prev=NULL;
    head->prev=new_node;
    head=new_node;
}

//Insert at specific position
void insertAtSpPos(){
    int pos,data;
    cout<<"Enter position: ";
    cin>>pos;
    cout<<"Enter data: ";
    cin>>data;
    Node* new_node=new Node();
    Node* it_node=head;
    new_node->data=data;
    do{
        if(it_node->data==pos){
            new_node->prev=it_node->prev;
            (it_node->prev)->next=new_node;
            new_node->next=it_node;
            it_node->prev=new_node;
            break;
        }
        it_node=it_node->next;
        if(it_node==NULL) cout<<"Position not found!\n";
    }while(it_node!=NULL);
}

//Append
void append(){
    if(head==NULL) cout<<"Create a DLL at first!";
    else{
        Node* it_node=head;
        while(it_node->next!=NULL){
            it_node=it_node->next;
        }
        Node* new_node=new Node();
        cout<<"Enter data: ";
        cin>>new_node->data;
        new_node->prev=it_node;
        it_node->next=new_node;
        new_node->next=NULL;
    }
}

//Main
int main(){
    createDLL();
    push();
    insertAtSpPos();
    append();
    display();
    return 0;
}