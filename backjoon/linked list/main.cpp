#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    Node *next;
};

Node *head; // list는 맨 처음을 가르킴.
            // new node -> old node
            //   ^
            //  head


void init()
{
    
}

void add(int key)
{
    Node * new_node = new Node;
    new_node->data = key;
    new_node->next = NULL;

    if(head == NULL)
    {
        head = new_node;
    }
    
    else
    {
        new_node->next = head;
        head = new_node;
    }
    

}
//오름차순으로 삽입.
void ascending_order_add(int key)
{
    Node *new_node = new Node;
    new_node->data = key;
    new_node->next = NULL;

    Node *cur = new Node;

    cur = head;


    // while(cur->data)   

}
//삭제
//리스트에 노드가 없을 경우
//삭제할 key가 첫번째일경우 그 다음 노드일 경우
//그 다음 노드 일 경우, 반복문을 통해 
bool remove(int key)
{
    Node *cur = new Node;
    Node *prev = new Node;

    cur = head;
    
    if(head == NULL)
        return false; 

    if(head->data == key)
    {
        head = cur->next;
        free(cur);
        free(prev);
        return true;
    }
    
    else
    {
        cur = head->next;
        prev = head;

        while(1)
        {   

            if(cur->data != key && cur != NULL)
            {
            prev = cur;
            cur = cur->next;
            }

            else
            {
                break;
            }
            
            
        }

        prev->next = cur->next;
        free(cur);
        free(prev);

        return true;
    }

}

int main()
{
    

}