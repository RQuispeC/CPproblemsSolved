#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<set>
#include<bitset>
#define MAX 20005
using namespace std;
int a[MAX];
int c[MAX];
int LIS(int A[], int size) {
 
    int len=1; 
    c[0] = A[0];
    for( int i = 1; i < size; i++ ) {
        if( A[i] < c[0] )
            c[0] = A[i];
        else if( A[i] > c[len-1] )
            c[len++] = A[i];
        else
            c[lower_bound(c, c+len, A[i])-c] = A[i];
    }
 
    return len;
}
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			scanf("%d", & a[i]);
			
		int inc, dec; 
		inc=LIS(a, n);
		reverse(a, a+n);
		dec=LIS(a, n);
		if(inc==dec)
			cout<<"Caution. I will not intervene."<<endl;
		else
			cout<<"Don't worry. I must intervene."<<endl;		
	}
	
}
