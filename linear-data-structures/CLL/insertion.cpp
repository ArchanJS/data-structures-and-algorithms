#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* head=NULL;

//Create CLL
void createCLL(){
    int n;
    cout<<"Enter the size of the linked list: ";
    cin>>n;
    cout<<"Enter elements:\n";
    while(n--){
        Node* new_node=new Node();
        int data;
        cin>>data;
        new_node->data=data;
        new_node->next=head;
        head=new_node;
    }
    Node* it_node=head;
    while(it_node->next!=NULL){
        it_node=it_node->next;
    }
    it_node->next=head;
}

///display
void display(){
    if(head==NULL) cout<<"Please create a linked list at first!";
    else{
        Node* it_node=head->next;
        cout<<head->data<<" ";
        while(it_node!=head){
            cout<<it_node->data<<" ";
            it_node=it_node->next;
        }
    }
}

//Insertion
void insert(){
    int pos,data;
    cout<<"Enter the position: ";
    cin>>pos;
    cout<<"Enter data: ";
    cin>>data;
    if(head==NULL) cout<<"Create a linked list at first!";
    else {
        Node* new_node=new Node();
        new_node->data=data;
        Node* it_node=head;
        while((it_node->next)->data!=pos){
            it_node=it_node->next;
        }
        if(pos==head->data){
            it_node->next=new_node;
            new_node->next=head;
            head=new_node;
        }
        else{
            new_node->next=it_node->next;
            it_node->next=new_node;
        }
    }
}

//Main
int main(){
    createCLL();
    insert();
    display();
    return 0;
}