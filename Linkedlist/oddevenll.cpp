//Odd-even linkedlist
//given a ll return ll with odd number nodes first and even number nodes next
//input:1->2->3->5->7->6
//index:1--2--3--4--5--6
//output:1->3->7->2->5->6

//brute force
//store odd index val first and even indev val next into arr[]
//insert arr val to ll

ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        vector<int> arr;
        
        ListNode* temp=head; //odd index
        while(temp!=nullptr && temp->next!=nullptr)
        {
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp) arr.push_back(temp->val);

        ListNode* temp1=head->next; //even index
        while(temp1!=nullptr && temp1->next!=nullptr)
        {
            arr.push_back(temp1->val);
            temp1=temp1->next->next;
        }
        if(temp1) arr.push_back(temp1->val);

        ListNode* temp2=head;
        int i=0;
        while(temp2!=nullptr)
        {
            temp2->val=arr[i];
            i++;
            temp2=temp2->next;
        }
        return head;
    }
//TC->O(N)
//SC->O(N)

//optimal
//remember evenHead=head->next
//create 2 var odd,even and move 2 steps
//after odd nodes added connect odd->next=evenHead

ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=head->next;

        while(even!=nullptr && even->next!=nullptr)  //even reaches end early
        {
            odd->next=odd->next->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        }
        odd->next=evenHead;

        return head;   
    }
//TC->O(N)
//SC->O(1)
