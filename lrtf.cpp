#include <bits/stdc++.h>
using namespace std;

struct Stu
    {
	int Comp_Time=0 ;
	int F_time;
	int student_id;
    int Brust_time;
	};


void Total_Task_Time(Stu st[])
	{
       for (int i=0;i<3;i++)
	       {
            if(st[i].F_time!=0)
                st[i].Comp_Time +=1;
           }
	}

bool REMAIN(Stu st[])
	{
    	for (int i=0;i<3;i++)
		{
        	if(st[i].F_time!=0)
			{
            return true;
       	 	}
    	}
    return false;
	}
	
void SORT_DESC(Stu st[])
	{
    for(int i=1;i<3;i++)
		{
        for(int j=0;j<3-i;j++)
			{
            if(st[j].F_time < st[j+1].F_time)
			{
                Stu temp = st[j];
                st[j]=st[j+1];
                st[j+1]=temp;
            }
            else if(st[j].F_time == st[j+1].F_time){
                if(st[j].student_id > st[j+1].student_id){
                    Stu temp = st[j];
                    st[j]=st[j+1];
                    st[j+1]=temp;
                }
            }
        }
    }

}



int main(){
	Stu st[3];

	
	for(int i=0;i<3;i++){
        printf("enter studnets id number %d \n",i+1);
        scanf("%d",&st[i].student_id);

		//cin>>s[i].id;
        printf("enter food taken time %d \n",i+1);
        scanf("%d",&st[i].F_time);
		st[i].Brust_time = st[i].F_time;

	}
	SORT_DESC(st);

    printf("STUDENTS ENTERED THE QUEUE IN THE FOLLOWING WAY \n");
    while(REMAIN(st)){
        printf("%d \n ",st[0].student_id);
        Total_Task_Time(st);
        st[0].F_time--;
        SORT_DESC(st);
    }
    int sum = 0;
    int sum1 = 0;
    printf("STUDENT ID | TURN AROUND TIME | WAITING TIME\n");
    for(int i=0;i<3;i++){
        printf("\n%d :\t\t %d \t\t",st[i].student_id,st[i].Comp_Time);
        printf("%d \n",st[i].Comp_Time - st[i].Brust_time);
        sum += st[i].Comp_Time;
        sum1 += st[i].Brust_time;
    }
    int n=sum/3;
    int n1=sum1/3;
    printf("\n THE FINAL AVERAGE TURN AROUND TIME IS : %d",n);
    printf("\n THE FINAL AVERAGE WAITING TIME IS     : %d",n1);
  
}
