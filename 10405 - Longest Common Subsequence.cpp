#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <algorithm>  
#include <string>  
using namespace std;  
#define MAX 1007  
  
int dp[MAX][MAX],n;  
int main()  
{  
    int m,n,i,j;  
    string s1,s2;  
    while(getline(cin,s1) && getline(cin,s2))  
    {  
        m = s1.length();  
        n = s2.length();  
        s1 = " " + s1;  
        s2 = " " + s2;  
        for(i=1;i<=m;i++)  
            dp[i][0] = 0;  
        for(j=0;j<=n;j++)  
            dp[0][j] = 0;  
        for(i=1;i<=m;i++)  
        {  
            for(j=1;j<=n;j++)  
            {  
                if(s1[i] == s2[j])  
                    dp[i][j] = dp[i-1][j-1] + 1;  
                else  
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);  
            }  
        }  
        cout<<dp[m][n]<<endl; 
    }  
    return 0;  
}
