#include<iostream>

using namespace std;
struct Node
{
    char data;
    Node *next;
    Node *prev;
};

Node *head;
Node *cur;
//////////////////////////////////////////////////////////////////////
//dmih입력. 
//a(이 노드가 있어야 d뒤로 커서를 가상으로 만들수있음.) -> d -> m -> i -> h//
/////////////////////////////////////////////////////////////// 

void addnode(char key)
{
    
        Node *new_node = new Node;
        new_node->data = key;
        new_node->prev = cur;
        new_node->next = NULL;
        cur->next = new_node;
        cur = new_node;

}

void insertnode(char key)//cur부분 오른쪽에 노드 추가. cur는 새로 만들어진 노드를 가르킴.
{
    Node *new_node = new Node;
    new_node->data = key;

    if(cur->next == NULL)//맨 뒤노드
    {
        cur->next = new_node;
        new_node->prev = cur;
        new_node->next = NULL;
        cur = new_node;
    }

    else
    {
        new_node->next = cur->next;
        new_node->prev = cur;
        cur->next = new_node;
        new_node->next->prev = new_node;
        cur = new_node;
    }
    
    

}

void deletnode()//노드 삭제. Pos 가리키는 노드를 삭제.
{
    Node *del = new Node;
    del = cur;
    cur = del->prev;

    if(del->next == NULL)
    {
        cur->next = NULL;
        
        
    }
    else
    {
        cur->next = del->next;
        del->next->prev = cur;
        del->next = del->prev =NULL;
    }
    
    free(del);
}




int main()
{

    char arr[100000];
    char cmd1;
    char cmd2;

    int num;

    Node *new_node = new Node;
    new_node->data = 'a';
    new_node->prev = new_node->next = NULL;
    head = new_node;
    cur = new_node;

    cin >> arr;

    for(int i = 0; i<100000; i++)
    {
        if(arr[i] == '\0')
            break;
        addnode(arr[i]);
    }

    cin >> num;

    for(int j = 0; j<num; j++)
    {
        cin >> cmd1;
        if(cmd1 == 'P')
            cin >> cmd2;

        switch(cmd1)
        {
            case 'L' :
                if(cur->prev == NULL)
                    continue;
                cur = cur->prev;
                break;
            
            case 'D' :
                if(cur->next == NULL)
                    continue;
                cur = cur->next;
                break;
            
            case 'B' :
                if(cur->prev==NULL)continue;
                deletnode();
                break;

            case 'P' :
                insertnode(cmd2);
                break;

        }


    }

    head = head->next;
    while(head)
    {
        printf("%c",head->data);
        head=head->next;
    }


    return 0;
}