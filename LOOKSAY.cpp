#include<iostream>
#include<cstring>
#include<cstdio>
#include<sstream>
using namespace std;
int main()
{
	int tested;
	scanf("%d", &tested);
	while(tested--)
	{
		string a, ans="";
		cin>>a;
		for(int i=0;i<a.size();)
		{
			stringstream stream;
			int j;
			int con=0;
			for(j=i;j<a.size();j++)
			{
				if(a[j]!=a[i])
				{
					break;
				}
				else con++;
			}
			//cout<<con<<" : "<<a[i]<<endl;
			stream << con;
			//cout<<stream.str()<<endl;
			ans+=stream.str();
			ans+=a[i];
			i=j;
		}
		cout<<ans<<endl;
	}
}
