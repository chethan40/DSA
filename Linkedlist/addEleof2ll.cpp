//add 2 ll from left to right
//input
//2->4->3
//5->6->4
//output
//7->0->8->

//Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//Output: [8,9,9,9,0,0,0,1]

//Optimal
//use dummyNode for better code

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;

        ListNode* dummyNode=new ListNode(-1);
        ListNode* current=dummyNode;

        int carry=0;
        while(temp1!=nullptr || temp2!=nullptr)
        {
            int sum=carry;
            if(temp1) sum=sum+temp1->val;
            if(temp2) sum=sum+temp2->val;

            ListNode* newNode=new ListNode(sum%10); //only 1 digit (6+4=10 add 0 to newNode)
            carry=sum/10; //(6+4=10 update carry to 1)

            current->next=newNode;
            current=newNode;

            if(temp1)temp1=temp1->next;
            if(temp2)temp2=temp2->next;
        }
        if(carry) //if carry remain at end of addition
        {
            ListNode* carryNode=new ListNode(carry);
            current->next=carryNode;
        }
        return dummyNode->next;
    }
//TC->O(max(m,n))
//SC->O(max(m,n)) to return the added ll
