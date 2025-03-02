//Check if a given ll is palindrome or not
//1->2->3->2->1 is a palindrome

//brute (Stack)

bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        //push
        ListNode* temp=head;
        stack<int> st;
        while(temp!=nullptr)
        {
            st.push(temp->val);
            temp=temp->next;
        }
        //pop
        temp=head; 
        while(temp!=nullptr)
        {
            if(temp->val!=st.top()) return false;
            st.pop();
            temp=temp->next;
        }
        return true;
    }
//TC->O(2N)
//SC->O(N)

//Optimal
//find the FIRST mid by tortoise hare algo mid=slow
//for first mid use while(fast->next!=nullptr && fast->next->next!=nullptr)
//reverse the half of the ll from slow->next

//1->2->3->2->1
//after reverse
//1->2->3  X<-2<-1   //newHead is 1
//      |        ^
//      |________|

bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)  //O(N/2)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reversell(slow->next);

        
        
        ListNode* low=head;
        ListNode* high=newHead;
        while(high!=nullptr)    //O(N/2)
        {
            if(low->val!=high->val)
            {
                return false;
            }
            low=low->next;
            high=high->next;
        }
        return true;

    }
    ListNode* reversell(ListNode* head) //(recursive reversell) O(N/2)
    {
        if(head==nullptr || head->next==nullptr)return head;

        ListNode* newhead=reversell(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;

        return newhead;

    }
//SC->O(1)

