//doubly linked list
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1,Node* next1,Node* prev1)
    {
        data=data1;
        next=next1;
        prev=prev1;
    }
    Node(int data1)
    {
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};

//arr to 2d ll
Node* arrto2dll(vector<int> &arr)
{
    Node* head=new Node(arr[0]);
    Node* current=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp= new Node(arr[i],nullptr,current);
        current->next=temp;
        current=temp;
    }
    return head;

}

//deletion in 2d ll
//head
//tail
//kth ele(position)
//

//delete in head
Node* deleteHead(Node* head)
{
    if(head==nullptr || head->next==nullptr) return nullptr;

    Node* current=head;
    head=head->next;
    head->prev=nullptr;
    current->next=nullptr;
    delete current;
    return head;
}

//delete in tail
Node* deleteTail(Node* head)
{
    if(head==nullptr || head->next==nullptr) return nullptr;

    Node* tail=head;
    while(tail->next!=nullptr)
    {
        tail=tail->next;
    }
    Node* pretail=tail->prev;
    pretail->next=nullptr;
    tail->prev=nullptr;

    delete tail;
    return head;
    
}

//dletion of kth ele(position)
Node* deleteKth(Node* head,int k)
{
    if(head==nullptr) return nullptr;

    if(k==1)
    {
        return deleteHead(head);
    }

    Node* current=head;
    int cnt=1;
    while(cnt<k && current!=nullptr)
    {
        current=current->next;
        cnt++;
    }
    Node* back=current->prev;
    Node* front=current->next;

    if(current->next==nullptr)
    {
        return deleteTail(head);
    }

    back->next=front;
    front->prev=back;

    delete current;
    return head;
}

//deleteion by a val of a node
Node* deleteval(Node* head,int val)
{
    if(head==nullptr) return nullptr;

    Node* current=head;
    if(current->data==val)
    {
        return deleteHead(head);
    }

    while(current->data!=val && current!=nullptr)
    {
        current=current->next;
    }
    Node* back=current->prev;
    Node* front=current->next;

    if(current->next==nullptr)
    {
        return deleteTail(head);
    }

    back->next=front;
    front->prev=back;

    delete current;
    return head;
}

//insertion after!!
//head
//tail
//kth position
//value

//insertion at head
Node* insertHead(Node* head,int val)
{
    if(head==nullptr) return new Node(val);

    Node* newHead=new Node(val,head,nullptr);
    head->prev=newHead;
    head=newHead;

    return head;
}

//insertion at tail
Node* insertTail(Node* head,int val)
{
    if(head==nullptr) return new Node(val);

    Node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    Node* newTail=new Node(val,nullptr,temp);
    temp->next=newTail;

    return head;
}

//insertion at kth position
Node* insertKth(Node* head,int k,int val)
{
    if(head==nullptr) return new Node(val);

    Node* temp=head;
    if(k==1)
    {
        return insertHead(head,val);
    }
    int cnt=1;
    while(cnt<k-1 && temp!=nullptr)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==nullptr)
    {
        return insertTail(head,val);
    }
    Node* front=temp->next;
    Node* newNode=new Node(val,front,temp);
    temp->next=newNode;
    front->prev=newNode;


    return head;
}

//insertion of ele after a val in ll
Node* insertafterval(Node* head,int val,int ele)
{
    if(head==nullptr) return new Node(val);

    Node* temp=head;
    if(temp->data==val)
    {
        Node* front=temp->next;
        Node* newNode=new Node(ele,front,temp);
        temp->next=newNode;
        front->prev=newNode;

        return head;
    }
    while(temp->data!=val && temp!=nullptr)
    {
        temp=temp->next;
    }
    if(temp->next==nullptr)
    {
        return insertTail(head,ele);
    }
    Node* front=temp->next;
    Node* newNode=new Node(ele,front,temp);
    temp->next=newNode;
    front->prev=newNode;


    return head;
}

int main()
{
    vector<int> arr = {1,5,6,7,9,25};

    //arr to 2d ll
    Node* head=arrto2dll(arr);

    //deletion at head
    head=deleteHead(head);

    //deletion at tail
    head=deleteTail(head);

    //deletion of kth(position) node
    head=deleteKth(head,2);

    //deletion of a val node
    head=deleteval(head,1);

    //insertion at head
    head=insertHead(head,8);

    //insertion at tail
    head=insertTail(head,69);

    //insertion at kth position
    head=insertKth(head,5,100);

    //insertion after a value
    head=insertafterval(head,7,73);

    //traverse and print
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
