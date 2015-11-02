#include<bits/stdc++.h>
using namespace std;
int const MAX=40005;
int  nums[MAX];
map < int, int > mapa;
int main(void)
{
    long int i,j;
    int N,kase=0;
    vector < int > frec;
    while(1)
    {
        scanf("%d",&N);
        if(N==0) break;
        for(i=0;i<N;i++)
            scanf("%d", &nums[i]);
        mapa.clear();
        vector < int >  nume;
        nume.clear();
        for(int i=0;i<N;i++)
        {
        	if(mapa[nums[i]]==0)
        		nume.push_back(nums[i]);
        	mapa[nums[i]]++;
        }
        int tot=0;
        for(int i=0;i<nume.size();i++)
        {
        	int frec=mapa[nume[i]];
        	tot+=((frec* (frec-1 ) )/2);
        }
        int posi=(N*(N-1))/2;
		printf("Case %d: %d\n",++kase,posi- tot);
    }
    return 0;
}

