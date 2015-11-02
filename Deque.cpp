#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int s [1005], t[1005];
	int front, back, n;
	while(cin>>n)
	{
		//cout<<n<<" * "<<endl;
		front=0;
		back=n-1;
		for(int i=0;i<n;i++)
			scanf("%d", &s[i]);
		for(int i=0;i<n;i++)
			scanf("%d", &t[i]);	
		bool flag=true;
		for(int i=0;i<n && flag;)
		{
			if(s[front] != t[i] && s[back]!=t[i] )
			{
				//cout<<"imp"<<endl;
				flag=false;
				break;
			}
			else
			{
				if(front==back && s[front]==t[i])
						break;
				//cout<<s[front]<<" ####  "<<s[back]<<endl;
				if(s[front]==s[back])
				{
					//cout<<2<<endl;
					int ad=front, det=back, pos=i;
					cout<<"an : "<<ad<<"  "<<det<<"  : "<<pos<<endl;
					while(s[ad]==s[det] && det-1 > ad )
					{
						if(t[pos] != s[det]  && t[pos] != s[ad] )
						{
							//cout<<"cua"<<endl;
							break;
						}
						ad++;
						det--;
						pos++;
					}
					cout<<"dep  : "<<ad<<"  "<<det<<"  : "<<pos<<endl;
					if(t[pos] != s[det]  && t[pos] != s[ad] )
					{
						flag=false;
						break;
					}
					else
					{
						if(t[pos]==s[ad])
						{
							i=pos+1;
							front=ad+1;
						}
						else
						{
							i=pos+1;
							back=det-1;
						}
					}
				}
				else
				{
					cout<<3<<endl;
					cout<<"$$$$$  "<<front<<"  ++ "<<back<<" ** "<<i<<endl;	
					if(s[front]==t[i])
						front++;
					else
						back--;
					i++;				
				}
			}	
		}
		if(flag)
			cout<<1<<endl;
		else 
			cout<<0<<endl;
		cout<<".........................."<<endl;	
	}	
}
/*
3
1 2 3
1 3 2

4
1 2 3 4
4 3 2 1

3
1 2 3
2 1 3

4
1 2 3 1
1 2 1 3

9
1 2 3 6 5 4 3 2 1
1 2 3 6 5 4 3 2 1

9
1 2 3 6 5 4 3 2 1
1 2 3 4 5 6 3 2 1

9
1 2 3 6 5 4 3 2 1
1 2 3 4 1 2 3 5 6

9
1 2 3 6 5 4 3 2 1
1 2 3 5 1 2 3 5 6

5
1 2 3  2 1
1 2 3 1 2 

*/
