#include<iostream>
using namespace std;
int f(int k)
{
	if(k==0)return 3;
	int n;
	for(n=1;n*(n+1)/2<k;n++);
	while((n*(n+1)/2-k)%2)n++;
	return n;
}
int main()
{
	int tested;
	cin>>tested;
	for(int i=0;i<tested;i++){
		int k;
		cin>>k;
		k=max(k,-k);
		if(i)cout<<endl;
		cout<<f(k)<<endl;
	}
	return 0;
}	
