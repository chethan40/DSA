//Sort a given ll
//input:2->4->6->1->7
//output:1->2->4->6->7

//brute force
//store ll ele to a arr
//sort arr and replace it to ll

ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        vector<int> arr;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        int i=0;
        temp=head;
        while(temp!=nullptr)
        {
            temp->val=arr[i];
            i++;
            temp=temp->next;
        }

        return head;
    }
//TC->O(N) + O(N log N) + O(N)
//SC->O(N)

//Optimal 
//MERGE SORT IN LL
//write seperate function to find mid

ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode* mid=findmid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=nullptr;

        ListNode* lefthead=sortList(left);
        ListNode* righthead=sortList(right);

        return mergeTwoLists(lefthead,righthead);
    }
    ListNode* findmid(ListNode* head) //find first mid
    {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)  //O(N/2)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
       return slow;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;

        while(list1!=nullptr && list2!=nullptr)
        {
            if(list1->val <= list2->val)
            {
                temp->next=list1;
                temp=temp->next;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=temp->next;
                list2=list2->next;
            }
        }
        if(list1)temp->next=list1; //add remaining list1
        if(list2)temp->next=list2; //add remaining list2

        ListNode* newhead=dummyNode->next;
        delete dummyNode;

        return newhead;
    }
//TC->O(N log N)
//SC->O(1)
