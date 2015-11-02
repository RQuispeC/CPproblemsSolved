#include <iostream>
#include <string.h>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int T,a,b;
	bool R=false;
	cin>>T;
	for(int t=0;t<T;t++){
		if(R)
			cout<<endl;
		R=true;
		cin>>a;
		cin>>b;
		for(int i=0;i<b;i++)
		{
			if(i>0)
				cout<<endl;
			for(int j=1;j<=a;j++){
				for(int k=0;k<j;k++)
					cout<<j;
				cout<<endl;
			}
			for(int j=a-1;j>=1;j--){
				for(int k=0;k<j;k++)
					cout<<j;
				cout<<endl;
				}
		}
	}
	return 0;
}
