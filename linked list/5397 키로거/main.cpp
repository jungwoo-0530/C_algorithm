#include<iostream>
#include<string>

using namespace std;

struct Node
{
    char data;
    Node* next;
    Node* prev;
};

int main()
{

    int num = 0;

    cin >> num;

    string a;

while(num--)
{
        cin >> a;

        Node* head = new Node;
        Node* cur = new Node;

        Node* newnode = new Node;
        newnode->data = 'a';
        newnode->prev = newnode->next = NULL;
        cur =newnode;
        head = newnode;
        for(int k = 0; k<a.size(); k++)
        {
        switch(a.at(k))
            {
                case '<' :
                {
                    if(cur->prev == NULL)
                        continue;
                    cur = cur->prev;
                    break;
                }
                case '>' :
                {
                    if(cur->next == NULL)
                        continue;
                    cur = cur->next;
                    break;
                }
                case '-' :
                {
                    if(head == cur)
                        continue;
                    Node* del = new Node;
                    del = cur;
                    cur = del->prev;
                    if(del->next)
                    {
                        cur->next = del->next;
                        del->prev = cur;
                        del->next = del->prev = NULL;
                    }
                    else
                    {
                        cur->next = NULL;
                        del->prev = NULL;
                    }
                    free(del);
                    break;
                }
                default :
                { 
                    Node *new_node = new Node;
                    new_node->data = a.at(k);
                    if(cur->next)
                    {
                        new_node->prev = cur;
                        new_node->next = cur->next;
                        cur->next = new_node;
                        new_node->next->prev = new_node;
                        cur = new_node;
                    }
                    else
                    {
                        cur->next = new_node;
                        new_node->prev = cur;
                        cur = new_node;
                    }
                }
            }
        }
        head = head->next;
        while(head)
        {
            printf("%c",head->data);
            head = head->next;
        }
        printf("\n");
        //여기서 printf
    
}
    return 0;
}