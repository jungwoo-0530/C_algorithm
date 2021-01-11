#include<iostream>
#include<vector>
using namespace std;


int N;
int t;
int cnt;
vector<int>v;
struct Node
{
    int value;
    Node* right;
    Node* left;
};

Node* rootnode;


void post(Node* start)
{
    cout << "post start" <<endl;
    if(start->left != NULL)
        post(start->left);
    else if(start->right != NULL)
        post(start->right);
    cout << start->value;
    
}


void Input(int a)
{

    Node *Newnode;
    Newnode = new Node;
    Newnode->value = a;
    Newnode->right = NULL;
    Newnode->left = NULL;

    if(cnt == 0)
    {
        rootnode = Newnode;
        cnt++;
        return;
    }

    Node *cur = rootnode;

    while(1)
    {
        //cout << "b";
        if(cur->value < a)
        {
            if(cur->left == NULL){
                cur->left = Newnode;
                break;
            }
            cur = cur->left;   
        }

        else if(cur->value > a)
        {
            if(cur->right == NULL)
            {
                cur->right = Newnode;
                break;
            }
            cur = cur->right;
        }
    }

    cnt++;
    return;
}
void solve()
{
    while(cin >> t)v.push_back(t);
    for(int i=0; i<v.size(); i++)
        Input(v[i]);
    post(rootnode);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}