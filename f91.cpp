#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n && n!=0)
	{
		int ans=(n>100)?n-10:91;
		cout<<"f91("<<n<<") = "<<ans<<endl;
	}

}
