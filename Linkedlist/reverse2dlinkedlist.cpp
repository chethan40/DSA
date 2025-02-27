//Reverse a doubly linked list

//input : 3->4->5
//output : 5->4->3

//brute force:
//use stack push into it first then pop

DLLNode* reverseDLL(DLLNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
  
        //push
        DLLNode* temp=head;
        stack<int> st;
        while(temp!=nullptr)
        {
            st.push(temp->data);
            temp=temp->next;
        }
        //pop
        temp=head;
        while(temp!=nullptr)
        {
            temp->data=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
    }

//TC->O(2N) 
//SC->O(N)  of stack

//Optimal
//swap next and prev pointer of a node

DLLNode* reverseDLL(DLLNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        
        DLLNode* current=head;
        DLLNode* last=nullptr;
        while(current!=nullptr)
        {
            last=current->prev;             //temp=a
            current->prev=current->next;    //a=b
            current->next=last;             //b=temp
            
            current=current->prev;          //to move to next node
        }
        return last->prev;
    }

//TC->O(N) 
//SC->O(1)
