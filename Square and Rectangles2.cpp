#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<utility>
#include <set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<sstream>
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define pb push_back
using namespace std;

struct rectangle{
  int x1,x2,y1,y2,area;
  rectangle() { }
  rectangle(int px1,int py1,int px2,int py2) { 
    x1=px1;  x2 = px2;
    y1=py1;  y2 = py2;
    area = abs(y1-y2)*abs(x1-x2);
  }
};
int main(){
  int n;scanf("%d\n",&n);
  int x1,y1,x2,y2;
  bool goal=0;
  vector<rectangle> v;
  while(n--){
    scanf("%d %d %d %d\n",&x1,&y1,&x2,&y2);
    if(abs(x1-x2)==abs(y1-y2)) {goal=true;break;}
    v.pb(rectangle(x1,y1,x2,y2));
  }
  int m=v.size();
  if(!goal&&m>1){
    for(int i=0;i<m;i++)
      for(int j=i+1;j<m;j++){
	vector<int> vx,vy;
	for(int k=0;k<m;k++){
	  vx.pb(v[i].x1);
	  vx.pb(v[i].x2);
	  vx.pb(v[j].x1);
	  vx.pb(v[j].x2);
	  vy.pb(v[i].y1);
	  vy.pb(v[i].y2);
	  vy.pb(v[j].y1);
	  vy.pb(v[j].y2);
	}
	sort(ALL(vx));
	sort(ALL(vy));
	int cua=(int)sqrt(v[i].area+v[j].area);	
	if(abs(vx[0]-vx[vx.size()-1])==abs(vy[0]-vy[vy.size()-1])&&(cua*cua==v[i].area+v[j].area)){
	  goal=true;
	  i=j=m;
	}
      }
  }
  if(!goal&&m>2){
    for(int i=0;i<m;i++)
      for(int j=i+1;j<m;j++)
	for(int l=j+1;l<m;l++){
	  vector<int> vx,vy;
	  for(int k=0;k<m;k++){
	    vx.pb(v[i].x1);
	    vx.pb(v[i].x2);
	    vx.pb(v[j].x1);
	    vx.pb(v[j].x2);
	    vx.pb(v[l].x1);
	    vx.pb(v[l].x2);
	    vy.pb(v[i].y1);
	    vy.pb(v[i].y2);
	    vy.pb(v[j].y1);
	    vy.pb(v[j].y2);
	    vy.pb(v[l].y1);
	    vy.pb(v[l].y2);
	  }
	  sort(ALL(vx));
	  sort(ALL(vy));
	  int cua=(int)sqrt(v[i].area+v[j].area+v[l].area);
	  if(abs(vx[0]-vx[vx.size()-1])==abs(vy[0]-vy[vy.size()-1])&&(cua*cua==v[i].area+v[j].area+v[l].area)){
	    goal=true;
	    i=j=l=m;
	  }
	}
  }
  if(!goal&&m>3){
    for(int i=0;i<m;i++)
      for(int j=i+1;j<m;j++)
	for(int l=j+1;l<m;l++)
	  for(int p=l+1;p<m;p++){
	    vector<int> vx,vy;
	    for(int k=0;k<m;k++){
	      vx.pb(v[i].x1);
	      vx.pb(v[i].x2);
	      vx.pb(v[j].x1);
	      vx.pb(v[j].x2);
	      vx.pb(v[l].x1);
	      vx.pb(v[l].x2);
	      vx.pb(v[p].x1);
	      vx.pb(v[p].x2);
	      
	      vy.pb(v[i].y1);
	      vy.pb(v[i].y2);
	      vy.pb(v[j].y1);
	      vy.pb(v[j].y2);
	      vy.pb(v[l].y1);
	      vy.pb(v[l].y2);
	      vy.pb(v[p].y1);
	      vy.pb(v[p].y2);
	    }
	    sort(ALL(vx));
	    sort(ALL(vy));
	    int cua=(int) sqrt(v[i].area+v[j].area+v[l].area+v[p].area);
	    if(abs(vx[0]-vx[vx.size()-1])==abs(vy[0]-vy[vy.size()-1])&&(cua*cua==v[i].area+v[j].area+v[l].area+v[p].area)){
	      goal=true;
	      i=j=l=p=m;
	    }
	  }
  }
  if(!goal&&m>4){
    for(int i=0;i<m;i++)
      for(int j=i+1;j<m;j++)
	for(int l=j+1;l<m;l++)
	  for(int p=l+1;p<m;p++)
	    for(int q=p+1;q<m;q++){
	      vector<int> vx,vy;
	      for(int k=0;k<m;k++){
		vx.pb(v[i].x1);
		vx.pb(v[i].x2);
		vx.pb(v[j].x1);
		vx.pb(v[j].x2);
		vx.pb(v[l].x1);
		vx.pb(v[l].x2);
		vx.pb(v[p].x1);
		vx.pb(v[p].x2);
		vx.pb(v[q].x1);
		vx.pb(v[q].x2);
		
		vy.pb(v[i].y1);
		vy.pb(v[i].y2);
		vy.pb(v[j].y1);
		vy.pb(v[j].y2);
		vy.pb(v[l].y1);
		vy.pb(v[l].y2);
		vy.pb(v[p].y1);
		vy.pb(v[p].y2);
		vy.pb(v[q].y1);
		vy.pb(v[q].y2);
	      }
	      sort(ALL(vx));
	      sort(ALL(vy));
	      int cua=(int)sqrt(v[i].area+v[j].area+v[l].area+v[p].area+v[q].area);
	      if(abs(vx[0]-vx[vx.size()-1])==abs(vy[0]-vy[vy.size()-1])&&(cua*cua==v[i].area+v[j].area+v[l].area+v[p].area+v[q].area)){
		goal=true;
		i=j=l=p=q=m;
	      }
	    }
  }
  if(goal) printf("YES\n");
  else printf("NO\n");
  return 0;
}

