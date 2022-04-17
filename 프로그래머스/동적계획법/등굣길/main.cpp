#include <string>
#include <vector>
#include <iostream>

using namespace std;


int visit[101][101] = {0, };


void dfs(){

}


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    for(int i = 0; i < puddles.size(); i++){

        visit[puddles[i][0]][puddles[i][1]] = 2;
        
    }


    return answer;
}


int main(){

    int m = 4;
    int n = 3;

    vector<vector<int>> puddles = {{2,2}};
    
    int answer = solution(m, n, puddles);

    cout << answer;

    return 0;
}