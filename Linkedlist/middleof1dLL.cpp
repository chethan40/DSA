//middle element of 1d ll

//input : 1->2->3->4->5
//output : 3

//input : 1->2->3->4->5->6
//output : 4 (if even length return second mid)

//Brute force
//find the length of ll and return mid of ll
ListNode* middleNode(ListNode* head) {
        //length of ll
        ListNode* temp=head;
        int cnt=0;
        while(temp!=nullptr)
        {
            cnt++;
            temp=temp->next;
        }

        //return mid
        int midnode=(cnt/2)+1;
        temp=head;
        while(temp!=nullptr)
        {
            midnode=midnode-1;
            if(midnode==0) break;
            temp=temp->next;
        }
        return temp;
    }

//TC->O(N+N/2)
//SC->O(1)

//optimal
//Tortoise hare algorithm
//slow=head,fast=head = slow moves only 1 step and fast moves 2 steps
//odd length ll : 1->2->3->4->5 ; fast->next=nullptr; slow=3(mid)
//even length of ll : 1->2->3->4->5->6 ; fast=nullptr; slow=4(second mid)
//when fast->next==nullptr && fast=nullptr return slow

ListNode* middleNode(ListNode* head) {
    ListNode* slow=head;
    ListNode* fast=head;

    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    }

//TC->O(N)
SC->O(1)
