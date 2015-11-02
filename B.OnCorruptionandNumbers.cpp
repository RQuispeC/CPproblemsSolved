#include<iostream>
using namespace std;
int l,r,n;
int main()
{
	int tested;
	cin>>tested;
	while(tested--)
	{
		cin>>n>>l>>r;
		int nro=n/l;
		if(nro>0)
		{
			int res=n%l;
			int max=l;
			int aux=res/nro;
			max+=aux;
			res=res%nro;
			if(res>0) max++;
			//cout<<max<<endl;
			if(max<=r)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;	
		}
		else
			cout<<"No"<<endl;	
	}
	
}

