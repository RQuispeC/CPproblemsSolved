#include<iostream>
#define pii pair <int ,int >
#define MAX 10000
using namespace std;
int n[MAX]; 
int a[MAX];
pii egcd ( int a , int  b ) 
{
	if ( b == 0) 
		return  make_pair( 1 , 0) ;
	else 
	{
		pii RES = egcd ( b , a%b ) ;
		return  make_pair (RES.second ,RES.first -RES.second *( a/b ) ) ;
	}
}
int inv ( int n , int  m)
{
	pii EGCD = egcd ( n , m) ;
	return  ( (EGCD.first% m)+m)% m;
}
int Tchino (int k )
{
	int i , tmp , MOD, RES ;
	MOD = 1 ;
	for ( i =0; i<k ; i++)
		MOD *= n[i];
	RES = 0 ;
	for( i =0; i<k ; i++)
	{
		tmp = MOD/n[i] ;
		tmp *= inv ( tmp ,n [ i ] ) ;
		RES += ( tmp*a [ i ] )% MOD;
	}
	return RES% MOD;
}
int main()
{
	int t;
	cin>>t;
	int j=0;
	while(t--)
	{
		int m;
		for(int i=0;i<m;i++)
			cin>>n[i];
		for(int i=0;i<m;i++)
			cin>>a[i];
		j++;
		cout<<"Case "<<j<<": "<<Tchino(m)<<endl;	
	}
	return 0;
}
