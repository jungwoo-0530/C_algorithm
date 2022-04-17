#include<iostream>

using namespace std;

struct Node
{
    int data;
    int order;
    Node *next;
    Node *prev;
};

Node *tail;
Node *head;
Node *del;

int count_ = 0;
int order_ = 1;

void addnode(int key[], int c)
{
    for(int j =0; j<c; j++)
    {
    Node *newnode = new Node;
    newnode->data = key[j];
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->order = order_;
    
    if(order_ == 1)//첫번째 노드생성
    {
        head = newnode;
        tail = newnode;
        del = newnode;
        order_++;
    }
    else//끝노드이므로 끝노드 next를 head, head의 노드의 prev를 newnode
    {   
        newnode->next = head;
        newnode->prev = tail;
        tail->next = newnode;
        head->prev = newnode;
        tail = newnode;
        order_++;
    }
    }
}

void delnode()
{   
    int i = 0;
    Node *temp = new Node;

    while(count_ >0)
    {
        cout<<del->order << " ";
        if(i == 0)//첫번째는 삭제하고 시작하기 때문에 첫번쨰 노드 삭제하면서 출력
        {
            i++;
            
            
            if(del->data > 0)
            { 
                for(int k=0; k<head->data; k++)
                {
                    del = del->next;
                }
            }
            else
            {
                for(int j=0; j<-(head->data); j++)
                    del = del->prev;  
            }
           
            head = head->next;
            head->prev = tail;
            tail->next = head;
            count_--;
            
            continue;
        }

        else
        {
            int tem = 0;
            Node* temp = new Node;
            temp = del;
            if(del->data >0)
                temp= temp->next;
            else
                temp= temp->prev;
            
            del->prev->next = del->next;
            del->next->prev = del->prev;
            
            
            if(del->data > 0)
            {
                for(int a=0; a<(del->data-1); a++)
                {
                    temp = temp->next;
                }
                del = temp;
            }
            else
            {
                
             for(int j=0; j<-(del->data+1); j++)
                {
                    temp = temp->prev;
                }   
                del = temp;
                
            }
            
            
            count_--;
            continue;
        }
        
    }
}


int main()
{
    int num = 0;
    int paper_num[100000];

    cin >> num;
    count_ = num;

    for(int i =0; i<num; i++)
        cin >> paper_num[i];

    addnode(paper_num,num);

    
    delnode();


    return 0;
}