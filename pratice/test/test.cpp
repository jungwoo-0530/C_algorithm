#include<iostream>

using namespace std;

struct Node
{
    char data;
    Node *next;
    Node *prev;
};

Node *head;
Node *tail;
Node *cur;


void addnode(char key)//tail부분에 삽입.
{
    if(head == NULL)
    {
        head = new Node();
        head->data = key;
        tail = head;
        cur = head;
    }

    else
    {
        tail->next = new Node();
        tail = tail->next;
        tail->data = key;
        tail->prev = cur;
        cur = tail;
    }
    

}

void insertnode(Node *node, char key)//커서 부분에 삽입.
{
    Node *new_node = new Node;

    new_node->data = key;


    
    if(node->prev == NULL)
    {
        new_node->next = head;
        head->prev = new_node;
        node = node->prev;

        return;
    }

    else
    {
        Node *temp = new Node;
        
        temp = node->prev;
        
        new_node->next = node;
        node->prev = new_node;

        new_node->prev = temp;
        temp->next = new_node;

        return;
    }
    

}

void deletnode(Node *node)//노드 삭제.
{
    if(node->prev != NULL) node->prev->next = node->next;
	else head = head->next;
	
	if(node->next!= NULL) node->next->prev = node->prev;

}




int main()
{

    char arr[100000];
    char cmd1;
    char cmd2;

    int num;

    cin >> arr;

    for(int i = 0; i<100000; i++)
    {
        if(arr[i] == '\0')
            break;
        addnode(arr[i]);
    }

	addnode('\0');

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

                deletnode(cur);

            case 'P' :
                insertnode(cur, cmd2);

        }


    }

    Node* p = head;
	
	while(1){
		if(p==NULL || p->data == '\0') break;
		cout << p->data;
		p = p->next;
	}
	
    free(p);

    return 0;
}