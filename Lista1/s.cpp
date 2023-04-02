   #include <iostream>
 #include <string.h>
  
 using namespace std;
  
const int MAX = 100000 + 2000;
  
  int main()
  {
     char a[MAX];
 
     while(cin>>(a+1))
     {
         int len = strlen(a+1);
         int next[MAX];
         int last = 0,cur = 0;
         next[0] = 0;
         for(int i = 1;i <=len;i++)
         {
             char ch = a[i];
             if( ch == '[') cur = 0;
             else if(ch == ']') cur = last;
             else {
                 next[i] = next[cur];
                // cout<<"i  == cur == netx[i] == netx[cur]="<<i<<cur<<next[i]<<next[cur]<<endl;
 
                 next[cur] = i;
                // cout<<"cur **==netx[cur] **== "<<cur<<"   "<<next[cur]<<endl;
 
                 if(cur == last) last = i;
                 cur = i;
                //cout<<"cur last =="<<cur<<last<<endl;
             }
         }
         for(int i = next[0];i!=0;i =next[i])
                 cout<<a[i];
         cout<<endl;
     }
 
     return 0;
 }