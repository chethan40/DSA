//add 1 to a ll
//input:4->5->6
//output:4->5->7
//input:9->9->9
//output:1->0->0->0

//Brute force
//first reverse the ll
//add 1 to left value similar to add 2 ll
//use carry=1
//if carry exists at last create new node for it
//again reverse the ll for final output

Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding on
        if(head==nullptr) return head;
        Node* dummyNode=new Node(-1);
        Node* current = dummyNode;
        int carry=1;
        Node* temp=reverseList(head);
        while(temp!=nullptr)
        {
            int sum=carry;
            sum=sum+temp->data;
            temp=temp->next;
            
            Node* sumNode=new Node(sum%10);
            carry=sum/10;
            
            current->next=sumNode;
            current=current->next;
        }
        if(carry)
        {
            Node* carryNode=new Node(carry);
            current->next=carryNode;
        }
        return reverseList(dummyNode->next);
    }
    Node* reverseList(Node* head) {
        //recursive
        if(head==nullptr || head->next==nullptr)return head;
        Node* newHead = reverseList(head->next); //start from 2nd node
  
        Node* front=head->next;
        front->next=head;
        head->next=nullptr;

        return newHead;    
    }
//Tc->O(3N)
//SC->O(1)

//Optimal
//Recursion


Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        if(head==nullptr)return head;
        
        int carry=helper(head);
        if(carry==1)
        {
            Node* newNode=new Node(1);
            newNode->next=head;
            
            return newNode;
        }
        return head;
    }
    int helper(Node* temp)
    {
        if(temp==nullptr)return 1; //this returns 1 at last node
        int carry=helper(temp->next);
        
        temp->data=temp->data + carry;
        if(temp->data<10) return 0;
        
        temp->data=0; //if temp->data>0 make that node 0 and return 1
        return 1;
    }

//TC->O(N)
//SC->O(N) recursive stack
