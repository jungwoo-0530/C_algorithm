# 알고리즘

1. 문제 풀기 전에 항상 종료 조건 제대로 확인
2. 문제 풀기 전에 어떤 함수를 구현할 것인지 확인
3. 시간 복잡도



## DFS, BFS

1. [**구슬탈출2**](./삼성역량테스트기출/구슬탈출2/main.cpp)

   - [링크](https://www.acmicpc.net/problem/13460)
   - 삼성 기출

   - DFS
   - brute force
   - 완전탐색
   - DFS시작시 조건
   - DFS함수 안에서 이동하는 함수실행. 이동하는 함수에서는 오직 이동만.
   - 이동 완료 후 두 공이 겹치는 상황에서 재조정
   - backtracking

2. [**뱀**](./삼성역량테스트기출/3190뱀/main.cpp)





## Brute-force search

1. [1일차-view](./삼성역량테스트기출/12061일차-View/main.cpp)
   - [링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh)
   - 삼성a형기출
   - brute force
   - 현재 기준에서 오른쪽에서 가장 큰 빌딩, 왼쪽에서 가장 큰 빌딩 찾기
   - 현재 기준 빌딩에서 오른쪽에서 가장 큰 빌딩, 왼쪽에서 가장 큰 빌딩 크기 비교해서 하나라도 현재 빌딩보다 크다면 0리턴
   - 아니면 두 방향에서 가장 큰 빌딩을 현재 빌딩 크기를 빼서 결과.



