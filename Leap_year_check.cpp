#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t>0)
  {
    int n;
    cin>>n;
     /* A leap year is exactly divisible by 4 except for century years (years ending with 00). 
     The century year is a leap year only if it is perfectly divisible by 400.*/
     //here v.imp if a number is divisible by 4 and it is divisible by 100 it doesn't mean it will be divisible by 400 (imp point);
    if(n%100==0)
    {
      if(n%400==0)   /* here you can't apply if(n%4==0) (don't think like that:
                           if it is divisible by 100 then inside if check by 4 also
                        means it is divisible by 400 but this thing is totally wrong 
                        e.g. 1900 is divisible by 100 and by 4 also but not by 400
                          hence it is not leap year ) , you must apply if(n%400==0) */
      cout<<"Yes";          
      else
      cout<<"No";
    }
    else
    { 
      if(n%4==0)
      cout<<"Yes";
      else
      cout<<"No";
    }
    cout<<endl;
    t--;
  }
  
  return 0;
}