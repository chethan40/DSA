//sort 0s 1s 2s in a ll
//input 1->2->2->1->0->2->1->0
//output 0->0->1->1->1->2->2->2

//brute force
//count no of 0s 1s 2s
//put that many ele back to ll

Node* sor0s1s2s(Node* head) {

        // Add code here
        int zero=0;
        int one=0;
        int two=0;
        
        Node* temp=head;
        while(temp!=nullptr)
        {
            if(temp->data==0) zero++;
            else if(temp->data==1) one++;
            else two++;
            
            temp=temp->next;
        }
        
        temp=head;
        while(temp!=nullptr)
        {
            if(zero>0)
            {
                temp->data=0;
                zero--;
            }
            else if(one>0)
            {
                temp->data=1;
                one--;
            }
            else
            {
                temp->data=2;
                two--;
            }
            temp=temp->next;
        }
        return head;
    }
//TC->O(2N)
//SC->O(1)

//Optimal
//create 3 dummyNodes for 0,1,2
//from those dummyNodes point to the main ll respect to node val
//at last connect last node of each dummyNode to start of next dummyNode


Node* sort0s1s2s(Node* head) {
        if(head==nullptr || head->next==nullptr)return head;

        //dummy nodes
        Node* zerohead=new Node(-1);
        Node* onehead=new Node(-1);
        Node* twohead=new Node(-1);
        
        Node* zero=zerohead;
        Node* one=onehead;
        Node* two=twohead;
        
        Node* temp=head;
        while(temp!=nullptr)
        {
            if(temp->data==0)
            {
                zero->next=temp;
                zero=zero->next;
            }
            else if(temp->data==1)
            {
                one->next=temp;
                one=one->next;
            }
            else{
                two->next=temp;
                two=two->next;
            }
            temp=temp->next;
        }
        zero->next=(onehead->next)?(onehead->next):(twohead->next); //last node of zeroll to start of nextll
        one->next=twohead->next; //last node of onell to start of twoll
        two->next=nullptr; //twoll last points to null
        
        Node* newHead=zerohead->next;
        delete zerohead;
        delete onehead;
        delete twohead;
        
        return newHead;
    }
//TC->O(N)
//SC->O(1)
