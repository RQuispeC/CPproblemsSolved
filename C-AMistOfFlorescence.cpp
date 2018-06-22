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
char grid[34][50];
void built(){
    rep(i, 0, 8) {
        bool flag = (i%2) == 0;
        if(i%2 == 0)
            rep(j, 0, 50){
                if(flag) grid[i][j] = 'A';
                else grid[i][j] = 'B';
                flag = not flag;
            }
        else
            rep(j, 0, 50) grid[i][j] = 'B';
    }
    rep(j, 0, 50) grid[8][j] = 'A';
    rep(i, 9, 17) {
        bool flag = (i%2) == 1;
        if(i%2 == 1)
            rep(j, 0, 50){
                if(flag) grid[i][j] = 'B';
                else grid[i][j] = 'A';
                flag = not flag;
            }
        else
            rep(j, 0, 50) grid[i][j] = 'A';
    }
    grid[0][0] = 'B';
    grid[9][0] = 'A';
  //C - D
    rep(i, 17, 25) {
        bool flag = (i%2) == 0;
        if(i%2 == 0)
            rep(j, 0, 50){
                if(flag) grid[i][j] = 'C';
                else grid[i][j] = 'D';
                flag = not flag;
            }
        else
            rep(j, 0, 50) grid[i][j] = 'C';
    }
    rep(j, 0, 50) grid[25][j] = 'C';
    rep(i, 26, 34) {
        bool flag = (i%2) == 1;
        if(i%2 == 1)
            rep(j, 0, 50){
                if(flag) grid[i][j] = 'D';
                else grid[i][j] = 'C';
                flag = not flag;
            }
        else
            rep(j, 0, 50) grid[i][j] = 'D';
    }
    grid[18][1] = 'C';
    grid[27][1] = 'D';
}
void delete_elem(char start_char, char end_char, int start, int end, int cnt){
    rep(i, start, end) rep(j, 0, 50)
    {
        if(cnt && grid[i][j] == start_char)
        {
            cnt--;
            grid[i][j] = end_char;
        }
    }
}
int main()
{
    int v[4];
    rep(i, 0, 4) cin>>v[i];
    built();
    delete_elem('A', 'B', 0, 8, 100- v[0]);
    delete_elem('B', 'A', 9, 17, 100- v[1]);
    delete_elem('D', 'C', 17, 25, 100- v[3]);
    delete_elem('C', 'D', 26, 34, 100- v[2]);
    puts("34 50");
    rep(i, 0, 34){
        rep(j, 0, 50)
            cout<<grid[i][j];
        cout<<endl;
    }
}

