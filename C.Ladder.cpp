#include<bits/stdc++.h>
#define	INF 1<<30
#define MAX  100005
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
typedef pair< int64, int64 > pll;
int n, m, a[MAX], arr[MAX], k;
void getArray()
{
    k=0;
    arr[k++] = 0;
    bool f=1;
    for(int i=0;i+1<n;i++)
        if(a[i]!=a[i+1])
        {
            f=a[i]<a[i+1];
            break;
        }        
    for(int i=1;i+1<n;i++)
        if(f)
        {
            if(a[i]>a[i+1])
            {
                f = not f;
                arr[k++] = i;
            }
        }
        else
        {
            if(a[i]<a[i+1])
            {
                f = not f;
                arr[k++] = i;
            }
        }
    arr[k++] = n-1;
    //for(int i=0;i<k;i++) cout<<"**> "<< arr[i]<<endl;
}
int main()
{
   scanf("%d %d", &n, &m);
   for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
   if(n<=3)
        for(int i=0;i<m;i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            puts("Yes");
        }
   else
   {
        getArray();
        for(int i=0;i<m;i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            x--,y--;
            int posL = lower_bound(arr, arr+k, x) - arr;
            int posR = lower_bound(arr, arr+k, y) - arr;
            if(arr[posL]>x) posL--;
            posR--;
            if(posR<posL) posR=posL;
            bool ok = posR-posL<=1 && a[arr[posL]]<=a[arr[posR]];
            if(!ok && posR-posL<=2)
            {
                ok = a[arr[posL+1]]<=a[arr[posR]];
                ok = ok && a[x]==a[arr[posL+1]];
            }
            puts(ok?"Yes":"No");
        }
   }
}

