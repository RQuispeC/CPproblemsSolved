#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n!=-1)
    {
      string a,b;
      cin>>a>>b;
      int wrong=0;
      for(int i=0 ; i<b.size() && wrong <7 && a.size()!=0 ;i++ )
      {
        int aux=(int) a.find(b[i]);      
        if(aux<0) wrong ++;
        else
        {
            string h="";
            for(int j=0; j<a.size();j++)
            {
                if(a[j]!=b[i])
                   h+=a[j];
            }

            a=h;
        }
      }
      cout<<"Round "<<n<<endl;
      if(a.size()==0 )
          cout<<"You win."<<endl;
      else
          if(wrong==7) 
            cout<<"You lose."<<endl;
          else
            cout<<"You chickened out."<<endl;  
      cin>>n;
    }
    return 0;
      
}

