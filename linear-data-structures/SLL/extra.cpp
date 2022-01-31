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
    cout<<endl;
}

//Length of a SLL
void LengthOfSLL(){
    int len=0;
    Node* it_node=head;
    while(it_node!=NULL){
        len++;
        it_node=it_node->next;
    }
    cout<<len;
}

//Nth node ofa linked list
void nthNode(){
    int n,len=1;
    cout<<"Enter the postition of the node: ";
    cin>>n;
    Node* it_node=head;
    while(it_node!=NULL){
        if(len==n){
            break;
        }
        len++;
        it_node=it_node->next;
    }
    if(len==n) cout<<it_node->data<<endl;
    else cout<<"Please enter a valid position!\n";
}

//Reverse a linked list
void revserseSLL(){
    if(head==NULL) cout<<"Please create a linked list at first!";
    else{
        Node* it_node=head;
        Node* rev_node=NULL;
        while(it_node!=NULL){
            Node* new_node=new Node();
            new_node->data=it_node->data;
            new_node->next=rev_node;
            rev_node=new_node;
            it_node=it_node->next;
        }
        head=rev_node;
    }
}

//Main
int main(){
    createSLL();
    // LengthOfSLL();
    // nthNode();
    display();
    revserseSLL();
    display();
   return 0;
}