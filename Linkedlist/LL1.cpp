#include<bits/stdc++.h>
using namespace std;

//create ll
class Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1)
    {
        data=data1;
        next=next1;
    }

    Node(int data1)
    {
        data=data1;
        next=nullptr;
    }
};

//convert arr to ll
Node* convertArr2ll(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp; 
    }
    return head;
}

//length of ll
int lengthofll(Node* head)
{
    int cnt=0;
    Node* temp=head;
    while(temp!=nullptr)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

//search the key in ll
int search(Node* head,int key)
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        if(temp->data==key)return 1;
        temp=temp->next;
    }
    return 0;
}

int main()
{
    vector<int>arr={2,5,9,7};
    // Node* y = new Node(arr[2],nullptr);
    // cout << y->data;
    // cout<< y->next;
    // Node* x=new Node(arr[1]);
    // cout << x->data;
    // cout<< x->next;
    
    //convert arr to ll
    Node* head=convertArr2ll(arr);

    //traversal & printing of ll
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<endl;

    //length of ll
    int length = lengthofll(head);
    cout<<length;
    cout<<endl;

    //search ele;
    int found=search(head,2);
    if(found==1) cout<<"ele found";
    else cout<<"ele not found";
}





