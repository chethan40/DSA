//reverse a 1D ll

//brute force 
//Stack

ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        //push
        ListNode* temp=head;
        stack<int> st;
        while(temp!=nullptr)
        {
            st.push(temp->data);
            temp=temp->next;
        }
        //pop
        temp=head; //replace ll ele from stack ele start with head
        while(temp!=nullptr)
        {
            temp->data=st.top();  //replace top ele to each node and move
            st.pop();
            temp=temp->next;
        }
        return head;
    }

//TC-> O(2N)
//SC-> O(N)

//better (iterative)
//use extra node(variable)

ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode* temp=head;
        ListNode* prev=nullptr; //for first node

        while(temp!=nullptr)
        {
            ListNode* front=temp->next; //remember next node
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev; //return temp is wrong as temp would have reached nullptr at last
                     //iteration         
    }

//TC->O(N)
//SC->O(1)

//Optimal (recursive)
//1->2->3
//recursion happens for reverseList(2->3->4)-->reverseList(3->4)-->reverseList(4)
//reverseList(4) returns newNode = 4 in function reverseList(3,4)

ListNode* reverseList(ListNode* head) {
        //recursive
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* newHead = reverseList(head->next); //start from 2nd node
  
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;

        return newHead;    
    }
//TC->O(N)
//SC-> O(N) recursive stack space

