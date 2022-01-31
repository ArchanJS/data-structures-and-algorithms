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

//Push
void push(int data){
    Node* newNode=new Node();
    newNode->data=data;
    newNode->next=head;
    head=newNode;
}

//Insert after
void insertAfter(int pos,int data){
    if(head==NULL) cout<<"Insertion is not possible!";
    else{
        Node* temp_node=head;
        while(temp_node->data!=pos){
            temp_node=temp_node->next;
            if(temp_node==NULL){
                cout<<"Position not found!";
                break;
            }
        }
        Node* new_node=new Node();
        new_node->data=data;
        new_node->next=temp_node->next;
        temp_node->next=new_node;

    }
}

//Append
void append(int data){
    if(head==NULL){
        cout<<"Can not append!";
    }
    else{
        Node* temp_node=head;
        while(temp_node->next!=NULL){
            temp_node=temp_node->next;
        }
        Node* new_node=new Node();
        new_node->data=data;
        temp_node->next=new_node;
    }

}

//Main
int main(){
    createSLL();
    push(70);
    insertAfter(40,30);
    append(2);
    display();
   return 0;
}