//remove Nth node from end
//input 1->3->2->4->8 n=2
//output 1->3->2->8

//brute force
//count length of ll
//go to deleteNode-1 using count
//delete the node and return head

ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return nullptr;
  
        ListNode* temp=head; //length of ll
        int cnt=0;
        while(temp!=nullptr)
        {
            cnt++;
            temp=temp->next;
        }

        if(cnt==n) //first node
        {
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }

        temp=head; 
        int res=cnt-n; //reach the node before the node to be deleted
        while(temp!=nullptr)
        {
            res--;
            if(res==0)break;
            temp=temp->next;
        }
        ListNode* nextnode=temp->next; //nextnode=node to be deleted
        temp->next=temp->next->next;
        delete nextnode;

        return head;
    }
//TC->O(len of ll)+O(len of ll-n)
//SC->O(1)

//Optimal
//use slow and fast
//place fast at head and move n times front
//so fast points to the node before delnode
//if fast point null means it is the first node
//now place slow at head
//and move slow and fast 1step simoultaneously
//when fast->next==null it means slow is standing right before delnode

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        for(int i=0;i<n;i++) fast=fast->next;
        if (fast==nullptr)
        {
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }

        ListNode* slow=head;
        while(fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next;
        }

        ListNode* nextnode=slow->next;
        slow->next=slow->next->next;
        delete nextnode;

        return head;
    }
//you may think why slow pointer 
//slow pointer is needed if(n==1) last ele->dry run!!!

//TC->O(len of ll)
//SC->O(1)
