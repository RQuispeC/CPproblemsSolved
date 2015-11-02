#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX  2000000
using namespace std;
int ages[MAX];
void Quicksort(int vector[], int first, int last)
{
     int i,j;
     int pivote=vector[(first + last) / 2];
     int auxiliar;
     i=first;
	 j=last;
     do
     {
          while(vector[i]<pivote) i++;      
          while(vector[j]>pivote) j--;
 
          if (i<=j)
          {
               auxiliar=vector[j];
               vector[j]=vector[i];
               vector[i]=auxiliar;
               i++;
               j--;
          }
     }
     while (i<=j);
 
     if(first<j)
     {
          Quicksort(vector,first, j);
     }

     if(last>i)
     {
          Quicksort(vector,i, last);
     }
}
int main()
{
    int n;
	while(cin>>n && n!=0)
	{
		memset(ages,0,sizeof(ages));
		for(int i=0;i<n;i++)
			cin>>ages[i];
		Quicksort(ages,0,n-1);
		for(int i=0;i<n;i++)
		{
			cout<<ages[i];
			if(i<n-1)
				cout<<" ";
		}
		cout<<endl;	
	}
	return 0;
}
