//loops in ll
//imp pattern

//3 questions
//detection of loop->return true if loop exists else false
//starting point(node) of the loop
//length of the loop

//Approach->2 ways
//Hashmap
//tortoise hare algo

//detection of loop->return true if loop exists else false

//brute force(hashmap)

bool hasCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr)return false;
        map<ListNode*,int>mpp;
        ListNode* temp=head;

        while(temp!=nullptr)
        {
            if(mpp.find(temp)!=mpp.end())return true;
            mpp[temp]=1;
            temp=temp->next;
        }
        return false;        
    }
//TC->O(N*2*logN) 2=insertion+find, logN=ordered map
//SC->O(N) hashmap


//Optimal (tortoise hare algo)
//if a loop exists then slow and fast meet a point(node) at some time definitely

bool hasCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr)return false;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return true; //slow and fast meet at same node
        }        
        return false;
    }
//TC->O(N)
//SC->O(1)

//starting point(node) of the loop

//brute(hashmap)

ListNode *detectCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr)return 0;
        map<ListNode*,int>mpp;
        ListNode* temp=head;

        while(temp!=nullptr)
        {
            if(mpp.find(temp)!=mpp.end())return temp;
            mpp[temp]=1;
            temp=temp->next;
        }
        return nullptr; 
    }
//TC->O(N*2*logN) 2=insertion+find, logN=ordered map
//SC->O(N) hashmap

//Optimal (tortoise hare algo)
//when ever slow and fast meet at a node then set slow to head
//and fast remain in meet node
//now move slow and fast by only ONE step
//when slow and fast meet again that is the starting point of loop

//OP point-> the distance between the starting point of the loop and the point where the two pointers meet 
//is indeed equal to the distance between the starting point and head of the linked list.

ListNode *detectCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr)return 0;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                slow=head;
                while(slow!=fast)
                {
                slow=slow->next;
                fast=fast->next;
                }
                return slow;
            }
        }        
        return nullptr;
    }
//TC->O(N)
//SC->O(1)

//length of a loop

//brute(hashmap)
//1->2->5->6->7->8->5
//timer:
//1->2->3->4->5->6->7
//mpp[temp]=timer
//mpp[5]=3
//when 5 is met again return timer-value->timer-mpp[5]->7-3=4

int countNodesinLoop(Node *head) {
        Node* temp=head;
        map<Node*,int>mpp;
        int timer=1;
        
        while(temp!=nullptr)
        {
            if(mpp.find(temp)!=mpp.end())
            {
                int value=mpp[temp];
                return timer-value;
            }
            mpp[temp]=timer;
            timer++;
            temp=temp->next;
        }
        return 0;
    }
//TC->O(N*2*logN) 2=insertion+find, logN=ordered map
//SC->O(N) hashmap

//Optimal(tortoise hare algo)
//when slow and fast meets create count=1;
//move fast by 1 step and count++ till it reaches the meet point again
//when fast meets slow again return the count

int countNodesinLoop(Node *head) {
        // Code here
        Node* slow=head;
        Node* fast=head;
        
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return findlength(slow,fast);
        }
        return 0;
    }
    int findlength(Node* slow,Node* fast)
        {
            int count=1;
            fast=fast->next;
            while(fast!=slow)
            {
                fast=fast->next;
                count++;
            }
            return count;
        }
//TC->O(N)
//SC->O(1)


