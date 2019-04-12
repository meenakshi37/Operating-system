#include<iostream>
#include<math.h>
using namespace std;
struct os
{
	int AT,ID_P,BT;
	int WT,TAT,CT,BTbackup;
	char p_no;
};
struct os obj[3];
int totaltime=0;
int prefinaltotal=0;
//*******************************
int find(int at)
{
	int max=0,i;
	for(i=0;i<3;i++)
	{
		if(obj[i].AT<=at)
		{
			if(obj[i].BT>obj[max].BT)
			{
				max=i;
			}
		}
	}
	return max;
}
int findCT()
{
	int index,flag=0,i=obj[0].AT;
	while(1)
	{
		if(i<=3)
		{
			index=find(i);
		}
		else
		{
			index=find(3);
		}
		//cout<<"Process execution at time "<<totaltime<<" is : "<<index+1<<"\t";
		cout<<"Process execution at time "<<totaltime<<" is : "<<obj[index].p_no<<"\t";
		obj[index].BT-=1;
		totaltime+=1;
		i++;
		if(obj[index].BT==0)
		{
			obj[index].CT=totaltime;
			
			cout<<"Process "<<obj[index].p_no<<" is completed at "<<totaltime;
		}
		cout<<endl;
		if(totaltime==prefinaltotal)
		{
			break;
		}
	}
}
//*******************************
int main()
{
	int i;
	//assigning name to process
	obj[0].p_no='a';
	obj[1].p_no='b';
	obj[2].p_no='c';
	//***********************************
	//assigning arrival time
	for(i=0;i<3;i++)
	{
		obj[i].AT=1;
	}
	//**********************************
	//assigning burst time
	for(i=0;i<3;i++)
	{
		obj[i].BT=pow(2,i+1);
		obj[i].BTbackup=obj[i].BT;
		prefinaltotal+=obj[i].BT;
	}
	//*************************************
	//assigning id to student
	obj[0].ID_P=2132;
	obj[1].ID_P=2102;
	obj[2].ID_P=2453;
	//************************************
	cout<<"Process\tAt\tbt\tid\n";
	for(i=0;i<3;i++)
	{
		cout<<obj[i].p_no<<"\t";
		cout<<obj[i].AT<<"\t";
		cout<<obj[i].BT<<"\t";
		cout<<obj[i].ID_P<<"\t";
		cout<<endl;
	}
	cout<<endl;
	//************************************
	totaltime+=obj[0].AT;
	prefinaltotal+=obj[0].AT;
	findCT();
	int totalWT=0;
	int totalTAT=0;
	for(i=0;i<3;i++)
	{
		obj[i].TAT=obj[i].CT-obj[i].AT;
		obj[i].WT=obj[i].TAT-obj[i].BTbackup;
		totalWT+=obj[i].WT;
		totalTAT+=obj[i].TAT;
	}
	cout<<"After execution ********************"<<endl;
	cout << "PNo\tAT\tid\tBT\tCT\tTAT\tWT\n";
	for(i=0;i<3;i++)
	{
		cout<<obj[i].p_no<<"\t";
		cout<<obj[i].AT<<"\t";
		cout<<obj[i].ID_P<<"\t";
		cout<<obj[i].BTbackup<<"\t";
		cout<<obj[i].CT<<"\t";
		cout<<obj[i].TAT<<"\t";
		cout<<obj[i].WT<<"\t";
		cout<<endl;
	}
	cout<<endl;
	cout << "Total TAT = " << totalTAT << endl; 
    cout << "Average TAT = " << totalTAT / 3.0 << endl; 
    cout << "Total WT = " << totalWT << endl; 
    cout << "Average WT = " << totalWT / 3.0 << endl; 
    return 0; 
}
