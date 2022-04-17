#include<iostream>
#include<algorithm>

using namespace std;

class Course{

    public:
        int start;
        int end;

        Course(int start, int end)
        {
            this->start = start;
            this->end = end;
        }


}

int main()
{
    int course_num = 0;
    int count = 0;
    int Time = 0;//현재 시간.


    scanf("%d", &course_num);
    
    if(course_num>=200000)
    {
        return 0;
    }

    int course_time[course_num][2];

    for(int i = 0; i<course_num; i++)
    {
        scanf("%d %d",&course_time[i][0], &course_time[i][1]);
        
    }

    sort(course_time[0], cousre_time[0]+course_num);

    for(int j = 0; j<course_num; j++)
    {
        if(Time <= course_time[j][0])
        {
            count++;
            Time += course_time[j][1];
        }        
    }

    printf("%d\n",count);

    return 0;
}