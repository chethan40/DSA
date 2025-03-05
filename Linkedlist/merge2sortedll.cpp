//Merge 2 sorted ll
//input : 1->5->7 , 3->4->9
//output : 1->3->4->5->7->9

//brute force
//add both ll ele to arr sort arr and add it to ll

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        vector<int>arr;

        while(list1!=nullptr)
        {
            arr.push_back(list1->val);
            list1=list1->next;
        }
        while(list2!=nullptr)
        {
            arr.push_back(list2->val);
            list2=list2->next;
        }
        if (arr.empty()) return nullptr;
        sort(arr.begin(),arr.end());
        return convertArr2ll(arr);
    }
    ListNode* convertArr2ll(vector<int> arr)
    {
        ListNode* head=new ListNode(arr[0]);
        ListNode* mover=head;
        for(int i=1;i<arr.size();i++)
            {
                ListNode* temp= new ListNode(arr[i]);
                mover->next=temp;
                mover=temp; 
            }
        return head;
    }
//TC->O(N1+N2+NlogN+N)
//SC->O(N)+O(N) arr creation,new ll

//Optimal
//similar to 2pointer approach of mergeSort
//use additional dummyNode

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
//TC->O(N1+N2)
//SC->O(1)
