
// //dfs로 모든 노드를 방문(완전탐색)
// //visit 배열을 사용해야함. 같은 depth에서 같은 숫자가 있을 수 있음.
// //swap해야하므로 한 칸당 한 숫자를 삽입.
// //https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15Khn6AN0CFAYD&categoryId=AV15Khn6AN0CFAYD&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1#
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int ans, change;
// string s;

// void dfs(int index, int current)
// {
//     if (current == change)
//     {
//         ans = max(ans, stoi(s));
//         return;
//     }
//     for (int i = index; i < s.size() - 1; i++)
//     {
//         for (int j = i + 1; j < s.size(); j++)
//         {
//             swap(s[i], s[j]);
//             dfs(i, current + 1);
//             swap(s[i], s[j]);
//         }
//     }
// }

// int main(void)
// {
//     int t;
//     cin >> t;

//     for (int i = 1; i <= t; i++)
//     {
//         cin >> s >> change;
//         ans = 0;

//         if (change > s.size())
//             change = s.size();
//         dfs(0, 0);
//         cout << "#" << i << " " << ans << endl;
//     }
//     return 0;
// }
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int N;
string Number;
int ChangeNum;
vector<int> v;
int answer = 0;
bool visit[1000000][11] = {
    false,
};
//dfs로 모든 노드를 방문(완전탐색)
//visit 배열을 사용해야함. 같은 depth에서 같은 숫자가 있을 수 있음.
//swap해야하므로 한 칸당 한 숫자를 삽입.
//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15Khn6AN0CFAYD&categoryId=AV15Khn6AN0CFAYD&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1#
void swap(int index_x, int index_y)
{
    int temp;
    temp = v[index_x];
    v[index_x] = v[index_y];
    v[index_y] = temp;
}
int pow_()
{
    int temp = 0;
    for (int i = 0; i < v.size(); i++)
    {
        temp += v[i] * pow(10, v.size() - i - 1);
    }
    return temp;
}
int bigger(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
void dfs(int index, int depth)
{
    int currentValue = pow_();
    if (depth == ChangeNum)
    {
        answer = bigger(answer, currentValue);
        return;
    }

    if (visit[currentValue][depth] == true)
        return;

    visit[currentValue][depth] = true;

    for (int i = index; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (j > v.size())
                continue;
            swap(i, j);
            dfs(i, depth + 1);
            swap(i, j);
        }
    }
}

void solve()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        v.clear();
        answer = 0;
        Number = "";
        ChangeNum = 0;

        cin >> Number >> ChangeNum;

        for (int j = 0; j < Number.length(); j++)
        {
            v.push_back(Number[j] - '0');
        }
        dfs(0, 0);

        cout << "#" << i + 1 << ' ' << answer << '\n';
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}