#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* head=NULL;

//Create SLL
void createSLL(){
    int n;
    cout<<"Enter size of the linked list: ";
    cin>>n;
    cout<<"Enter elements:\n";
    while(n--){
        int data;
        cin>>data;
        Node* new_node=new Node();
        new_node->data=data;
        new_node->next=head;
        head=new_node;
    }
}

//Display
void display(){
    Node* temp_node=head;
    while(temp_node!=NULL){
        cout<<temp_node->data<<" ";
        temp_node=temp_node->next;
    }
}

//Delete from beginning
void pop(){
    if(head==NULL) cout<<"Deletion is not possible!";
    else{
        Node* temp_node=head;
        head=head->next;
        delete temp_node;
    }
}

//Delete from specific position
void delFromSpPos(){
    if(head==NULL) cout<<"Deletion is not possible!";
    else{
        cout<<"Enter the node: ";
        int data;
        cin>>data;
        Node* it_node=head;
        while((it_node->next)->data!=data){
            it_node=it_node->next;
        }
        Node* temp_node=it_node->next;
        it_node->next=temp_node->next;
        delete temp_node;
    }
}

//Delete from end
void delFromEnd(){
    if(head==NULL) cout<<"Deletion is not possible!";
    else if(head->next==NULL){
        Node* temp_node=head;
        head=NULL;
        delete temp_node;
    }
    else{
        Node* it_node=head;
        while((it_node->next)->next!=NULL){
            it_node=it_node->next;
        }
        Node* temp_node=it_node->next;
        it_node->next=NULL;
        delete temp_node;
    }
}

//Main
int main(){
    createSLL();
    pop();
    delFromSpPos();
    delFromEnd();
    display();
   return 0;
}