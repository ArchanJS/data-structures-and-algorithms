#include<bits/stdc++.h>
using namespace std;
#define n 100
class Stack{
    char* arr;
    int top;
    public:
    Stack(){
        arr=new char[n];
        top=-1;
    }
    void push(char data){
        if(top==n-1){
            // cout<<"Stack overflow!";
            return;
        }
        else{
            arr[++top]=data;
        }
    }
    void pop(){
        if(top==-1){
            // cout<<"Stack underflow!";
            return;
        }
        else{
            top--;
        }
    }
    char Top(){
        if(top==-1){
            // cout<<"Stack underflow!";
            return '$';
        }
        else return arr[top];
    }
    void display(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
    }
};
bool balanced(string s){
    Stack st;
    bool isBalanced=true;
    for(char ch:s){
        if(ch=='('||ch=='{'||ch=='[') st.push(ch);
        else if(ch==')'){
            if(st.Top()!='(') {
                isBalanced=false;
                break;
            }
            else{
                st.pop();
            }
        }
        else if(ch=='}'){
            if(st.Top()!='{'){
                isBalanced=false;
                break;
            }
            else{
                st.pop();
            }
        }
        else if(ch==']'){
            if(st.Top()!='[') {
                isBalanced=false;
                break;
            }
            else{
                st.pop();
            }
        }
    }
    if(isBalanced&&st.Top()==-1) return true;
    return false;
}
int prec(char ch){
    if(ch=='('||ch==')') return 3;
    else if(ch=='*'||ch=='/') return 2;
    return 1;
}
string infixToPostfix(string s){
    string res="";
    Stack st;
    for(char ch:s){
        if(ch=='('||ch==')'||ch=='*'||ch=='/'||ch=='+'||ch=='-'){
            if (st.Top()=='$' ||prec(ch)>prec(st.Top())) st.push(ch);
            else{
                while(prec(ch)<=prec(st.Top())||st.Top()!='$'){
                    res+=st.Top();
                    st.pop();
                }
            }
        }
        else res+=ch;
    }
    if(st.Top()!='$'){
        while(st.Top()!='$'){
            res+=st.Top();
            st.pop();
        }
    }
    return res;
}
int main(){
    string s;
    cin>>s;
    cout<<infixToPostfix(s);
    return 0;
}