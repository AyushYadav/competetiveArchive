#include "stdc++.h"

using namespace std;

bool ______________ok(int a,int b,int c,int d)
{
    return a<=255 and b<=255 and c<=255 and d<=255;
}

string ____________G(int a,int b,int c,int d)
{
    return to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d);
}


vector<string> _______________ip(string s)
{
        vector<string> res;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                for(int k=1;k<=3;k++)
                {
                    for(int l=1;l<=3;l++)
                    {
                        if(i+j+k+l==s.length())
                        {
                            int a = stoi(s.substr(0,i));
                            int b = stoi(s.substr(i,j));
                            int c = stoi(s.substr(i+j,k));
                            int d = stoi(s.substr(i+j+k,l));

                            if(______________ok(a,b,c,d))
                            {
                                string str =____________G(a,b,c,d);
                                /*+3 because of 3 dots*/
                                if(str.length()==s.length()+3)
                                {
                                    res.push_back(str);
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
}


vector<string> genIp(string s);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;

        /*generating naively*/
       vector<string> str = _______________ip(s);
       sort(str.begin(),str.end());
       vector<string> res =  genIp(s);
       sort(res.begin(),res.end());
       if(res.size()!=str.size())
        cout<<0<<endl;
       else{
       bool f=true;
       for(int i=0;i<str.size();i++)
       {
          if(res[i]!=str[i])
          {
              f=false;
              cout<<0<<endl;
              break;
          }
       }
       if(f)
        cout<<1<<endl;
       }
    }
}


/*You are required to complete this method*/
vector<string> result;
bool isValidIp(string s){
    int dotCnt=0;
    char prev=s[0];
    int prevDot=0;
    if(prev=='.')return false;
    int i;
    for(i=1;i<s.length();i++){
        char ch=s[i];
        if(i==s.length()-1 && ch=='.')return false;
        if(ch=='.' && prev=='.')return false;
        if(ch=='.'){
            string pk=s.substr(prevDot,i-prevDot);
            if(pk.length() > 3)return false;
            if(pk.length()>1 && pk[0]=='0')return false;
            stringstream ss(pk);
            int a;
            ss >> a;
            
            if(a>255)return false;
            prevDot=i+1;
            dotCnt++;    
        }
        prev=ch;
    }
    string pk=s.substr(prevDot,i-prevDot);
    if(pk.length() > 3)return false;
    if(pk.length()>1 && pk[0]=='0')return false;
    stringstream ss(pk);
    int a;
    ss >> a;
    if(a>255)return false;
    return true;
}
void _genIpUtil(string s, int n,int j, string p, int i,int dot){
    if( j==n || i==n+3 ){
        if(dot==3 && isValidIp(p)) result.push_back(p);
        return;
    }
    if(dot>3)return;
    _genIpUtil(s,n,j+1,p+s[j],i+1,dot);
    _genIpUtil(s,n,j,p+'.',i+1,dot+1);
}


vector<string> genIp(string s){
    result.erase(result.begin(),result.end());
    _genIpUtil(s,s.length(),0,"",0,0);
    return result;
    
}


