#include<iostream>
#include<cstring>
#include<sstream>
#include<stdlib.h>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	string hour;
	char dia [2]="";
	//hour 1
	cin>>hour;
	dia[0]=hour[0];
	dia[1]=hour[1];
	int hora1=atoi(dia);
	dia[0]=hour[3];
	dia[1]=hour[4];
	int minuto1=atoi(dia);
	//hour 2
	cin>>hour;
	dia[0]=hour[0];
	dia[1]=hour[1];
	int hora2=atoi(dia);
	dia[0]=hour[3];
	dia[1]=hour[4];
	int minuto2=atoi(dia);
	//solution
	if(hora1==0) hora1=24;
	if(hora2==0) hora2=24;
	int time1=hora1*60+minuto1;
	int time2=hora2*60+minuto2;
	time1=time1-time2;
	if(time1>=0)//currend day
	{
		hora1=time1/60;
		minuto1=time1%60;
		if( hora1 < 10) cout<<"0"<<hora1<<":";
		else cout<<hora1<<":";
		if(minuto1<10) cout<<"0"<<minuto1<<endl;
		else cout<<minuto1<<endl;
	}
	else//yesterday
	{
		time1=-1*time1;
		time1=1440-time1;
		hora1=time1/60;
		minuto1=time1%60;
		if( hora1 < 10) cout<<"0"<<hora1<<":";
		else cout<<hora1<<":";
		if(minuto1<10) cout<<"0"<<minuto1<<endl;
		else cout<<minuto1<<endl;
	}
	
}
