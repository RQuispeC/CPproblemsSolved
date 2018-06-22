/*
PAPICHA, el que codea ricucha
*/

#include<bits/stdc++.h> //g++ -std=c++11
using namespace std;

//#define DEBUG
#ifndef DEBUG
  #define din if(0) cin
  #define dout if(0) cout
#else
  #define din cin
  #define dout cout
#endif


#define inf (1 << 30)
#define pi (2*asin(1))
#define repall(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define rep(i,x,y) for (int i = x; i < y; i++)
#define irep(i,x,y) for (int i = x; i >= y; i--)
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define mp make_pair
#define MAX 100005

typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long int i64;
typedef vector < i64 > vi64;
int main()
{
    int n, p;
    string s;
    cin>>n>>p>>s;
    int ok_case = 0;
    int pos = -1;
    rep(i, 0, s.size() - p){
        if(s[i] == '.' && s[i + p] == '.'){
            ok_case = 1;
            pos = i;
            break;
        }
        if(s[i] == '.' || s[i+p] == '.'){
            ok_case = 2;
            pos = i;
            break;
        }
        if(s[i] != s[i + p]){
            ok_case = 3;
            break;
        }
    }
    if(ok_case == 0){
        puts("No");
        return 0;
    }
    if(ok_case == 1){
        s[pos] = '1';
        s[pos + p] = '0';
    }
    if(ok_case == 2){
        if(s[pos] == '.') s[pos] = ((s[pos + p] - '0' + 1) % 2) + '0';
        else s[pos + p] = ((s[pos] - '0' + 1) % 2) + '0';
    }
    //cout << "case "<<ok_case <<s.size()<<endl;
    rep(i, 0, s.size())
        if(s[i] == '.') s[i] = '0';
    cout<<s<<endl;
}

