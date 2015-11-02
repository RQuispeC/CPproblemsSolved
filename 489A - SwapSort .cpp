#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef long long ll;
int n, a[3005], b[3005];
int pos(int x)
{
	for(int i=0;i<n;i++)
		if(a[i]==x)
			return i;
}
int main()
{
	
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
		b[i]=a[i];
	}
	sort(b, b+n);
	cout<<n<<endl;
	for(int i=n-1;i>=0;i--)
	{
		int j=pos(b[i]);
		cout<<j<<" "<<i<<endl;
		swap(a[i], a[j]);
	}
}

