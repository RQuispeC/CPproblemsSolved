#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
int main()
{
	int n , m;
	cin>>n>>m;
	int tot=min(n , m);
	if(tot%2==0)
		cout<<"Malvika"<<endl;
	else
		cout<<"Akshat"<<endl;	
}

