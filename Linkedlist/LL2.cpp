#include<bits/stdc++.h>
using namespace std;

//creation of node
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

//deletion of node
//head
//tail
//kth ele or position
//value

//deletion of head node
Node* deleteHead(Node *head)
{
    if(head==nullptr) return nullptr;

    Node* temp=head;
    head=head->next;
    delete temp;

    return head;
}

//deletion of tail node
Node* deleteTail(Node* head)
{
    if(head==nullptr || head->next==nullptr) return nullptr;

    Node* temp=head;
    while(temp->next->next!=nullptr)
    {
        temp=temp->next;
    }
    delete temp->next; //free 7
    temp->next=nullptr;

    return head;
}

//deletion of kth ele or position
Node* deleteKthele(Node* head,int k)
{
    if(head==nullptr) return nullptr;

    if(k==1)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    int cnt=1;
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=nullptr && cnt<k)
    {
        prev=temp;
        temp=temp->next;
        cnt++;
    }
    prev->next=temp->next;
    delete prev->next;
    return head;
}

//deletion by value
Node* deleteValue(Node* head,int val)
{
    if(head==nullptr) return nullptr;

    if(head->data==val)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=nullptr && temp->data!=val)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete prev->next;
    return head;
}

//insertion of node
//head
//tail
//Kth position with val
//ele before existing val in ll

//insertion in head
Node* insertHead(Node* head,int ele)
{
    Node*temp= new Node(ele);
    temp->next=head;
    head=temp;

    return head;
}

//insertion in tail
Node* insertTail(Node* head,int ele)
{
    if(head==nullptr) return new Node(ele);
    
    Node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    Node* newNode=new Node(ele);
    temp->next=newNode;

    return head;
}

//insertion in Kth position with ele
Node* insertKth(Node* head,int k,int ele)
{
    if(head==nullptr)
    {
        if(k==1) return new Node(ele);
        else return nullptr;
    }
    if(k==1)
    {
        Node* temp=new Node(ele,head);
        head=temp;

        return head;
    }
    int cnt=0;
    Node* temp=head;

    while(temp!=nullptr)
    {
        cnt++;
        if(cnt==k-1)
        {
            Node* newNode= new Node(ele);
            newNode->next=temp->next;
            temp->next=newNode;

            return head;
        }
        temp=temp->next;
    }
    return head;
}

//insert val(ele) in front of a ele in ll
Node* insertbeforevalue(Node* head,int ele,int before_val)
{
    if(head==nullptr)
    {
        return new Node(ele);
    }
    if(head->data==before_val)
    {
        Node* temp=new Node(ele,head);
        head=temp;

        return head;
    }

    Node* temp=head;

    while(temp->next!=nullptr)
    {
        if(temp->next->data==before_val)
        {
            Node* newNode= new Node(ele);
            newNode->next=temp->next;
            temp->next=newNode;

            return head;
        }
        temp=temp->next;
    }
    return head;
}

int main()
{
    //4->5->6->7
    Node* head=new Node(7);
    Node* x=new Node(6,head);
    Node* y=new Node(5,x);
    Node* z=new Node(4,y);
    head=z;
    //alternative creation
    // Node* head=new Node(4);
    // head->next=new Node(5);
    // head->next->next=new Node(6);
    // head->next->next->next=new Node(7);

    //deletion of head node
    head=deleteHead(head);

    //deletion of tail node
    head=deleteTail(head);

    //deletion of kth ele or position
    head=deleteKthele(head,3);

    //deletion by value
    head=deleteValue(head,7);

    //insertion in head
    head=insertHead(head,3);

    //insertion in tail
    head=insertTail(head,80);

    //insertion in kth position with ele
    head=insertKth(head,2,45);

    //insertion of a val(ele) before a ele in ll
    head=insertbeforevalue(head,100,4);

    //traversal and printing of node
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    return 0;
}