//1
//delete all occurences of a given key
//input : 2<->2<->10<->8<->4<->2<->5<->2 , key=2
//output : 10<->8<->4<->5
//Explanation: 
//All Occurences of 2 have been deleted.

void deleteAllOccurOfX(struct Node** head, int x) {
        
        Node* temp=head;
        while(temp!=nullptr)
        {
        if(temp->data==x)
        {
            Node* prevNode=temp->prev;
            Node* nextNode=temp->next;
            
            if(temp==head) head=nextNode;
            
            if(prevNode)prevNode->next=nextNode;
            if(nextNode)nextNode->prev=prevNode;
            
            delete temp;
            temp=nextNode;
        }
        else temp=temp->next;
        }
    }
//TC->O(N)
//SC->O(1)

//2
//find pairs with given sum in SORTED doubly ll
//Input:  
//1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
//target = 7
//Output: (1, 6), (2,5)
//Explanation: We can see that there are two pairs 
//(1, 6) and (2,5) with sum 7.

//2 pointer approach
//place left at head and right at tail

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> ans;
        if(head==nullptr) return ans;
        
        Node* left=head;
        Node* right=findtail(head); //O(N)
        
        while(left->data<right->data) //O(N)
        {
            if(left->data+right->data==target)
            {
                ans.push_back({left->data,right->data});
                left=left->next;
                right=right->prev;
            }
            else if((left->data+right->data)<target)
            {
                left=left->next;
            }
            else right=right->prev;
        }
        return ans;
    }
    Node* findtail(Node* head)
    {
        Node* tail=head;
        while(tail->next!=nullptr)tail=tail->next;
        return tail;
    }

//TC->O(2N)
//SC->O(1) or no of pairs

//3
//remove duplicates from sorted doubly ll
// Input:
// n = 7
// 1<->2<->2<->3<->3<->4<->4
// Output:
// 1<->2<->3<->4
// Explanation:
// Only the first occurance of nodes with values 2,3 and 4 are 
// retained, rest repeating nodes are deleted.

Node * removeDuplicates(struct Node *head)
    {
        Node* temp=head;
        while(temp!=nullptr && temp->next!=nullptr)
        {
            Node* nextNode=temp->next;
            while(nextNode!=nullptr && nextNode->data==temp->data)
            {
                Node* duplicate=nextNode;
                nextNode=nextNode->next;
                delete duplicate;
            }
            temp->next=nextNode;
            if(nextNode!=nullptr)nextNode->prev=temp;
            
            temp=nextNode;
        }
        return head;
    }
//TC->O(N)
//SC->O(1)
