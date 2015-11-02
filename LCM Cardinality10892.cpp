#include<iostream>
#include<vector>
using namespace std;
vector <int> divis;
int total;
int gsd(int x,int y)
{
	if(x%y==0) return y;
	else
		return gsd(y,x%y);
}
void di(int n)//genera todos los divisores de n
{
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			divis.push_back(i);
			if(i*i!=n)
			divis.push_back(n/i);
		}
	}
}
int main()
{
	int n;
	while(cin>>n && n!=0)
	{
		divis.clear();
		di(n);
		total=0;
		/*for(int i=0;i<divis.size();i++)
			cout<<divis[i]<<"  ";
		cout<< "   estos son los divisores de : "<< n<<endl;*/
		total+=divis.size();
		for(int i=2;i<divis.size();i++)
			for(int j=i+1;j<divis.size();j++)
				if(gsd(divis[i],divis[j])==1) total++;
		cout<<n<<" "<<total<<endl;		
			
	}
	return 0;
}
