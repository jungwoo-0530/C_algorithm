#include<stdio.h>

int get_password()
{
    int password;
    printf("비밀번호 : ");
    scanf("%d", &password);
    return password;
}

int check()
{
    static int count = 0;
    

    if(get_password() == 1234)
    {
        printf("로그인성공\n");
        return 1;
    }

    else{
        count++;
        if(count == 3)
            printf("로그인 시도횟수 초과\n");
        return 0;
    }

}


int main(){

    int password;
    int cnt = 0;


    while(!check()){
        cnt++;
        if(cnt == 3)
            break;
    }
    return 0;
}