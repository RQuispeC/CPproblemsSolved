#include<iostream>
#include<cmath>
using namespace std;
bool f(int ang)
{
  bool flag=false;
  for(int hora=0;hora<=2 && ! flag ;hora++)
  {
      for(int min=0;min<=59 && !flag ;min++)
      {        
          int t=(int) abs(6*min-(hora*30+6*(min/12)));
          if( t== ang || (180-t)==ang )
          {  
              flag=true;
          } 
      }
  } 
  if(flag) return true;
  else return false;
}
int main()
{
  int ang;
  while (cin>>ang)
  {
    if(f(ang))
      cout<<"Y"<<endl;
    else
      cout<<"N"<<endl;  
  }
  return 0;
}

