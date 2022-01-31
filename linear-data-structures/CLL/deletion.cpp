#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

Node* head=NULL;

//Create CLL
void createCLL(){
    int n;
    cout<<"Enter the size of the CLL: ";
    cin>>n;
    cout<<"Enter elements: \n";
    Node* it_node=new Node();
    cin>>it_node->data;
    head=it_node;
    n-=1;
    while(n--){
        int data;
        cin>>data;
        Node* new_node=new Node();
        new_node->data=data;
        new_node->next=it_node;
        it_node=new_node;
    }
    head->next=it_node;
    head=it_node;
}

//Display
void display(){
    Node* it_node=head;
    do{
        cout<<it_node->data<<" ";
        it_node=it_node->next;
    }while(it_node!=head);
    cout<<endl;
}

//Deletion
void deleteNode(){
    if(head==NULL) cout<<"Create a linked list at first!";
    else{
        int pos;
        cout<<"Enter the position: ";
        cin>>pos;
        Node* it_node=head;
        do{
            if((it_node->next)->data==pos) break;
            it_node=it_node->next;
        }while(it_node!=head);
        Node* new_node=it_node->next;
        it_node->next=new_node->next;
        delete new_node;
    }
}

//Main
int main(){
    createCLL();
    deleteNode();
    display();
    return 0;
}