/*
	Author - Arvind K
	College - BITS Pilani
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 5005
using namespace std;

int dp[2][MAX];
char str[MAX];
int N;

int solve()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(str[i-1]==str[N-j])
            {
                dp[i%2][j]= 1+dp[(i-1)%2][j-1];
            }
            else
            {
                dp[i%2][j]=max(dp[(i-1)%2][j], dp[i%2][j-1]);
            }
        }
    }
    return dp[N%2][N];
}

int main()
{
    scanf("%d",&N);
    scanf("%s",str);
    
    printf("%d\n",N-solve());
    return 0;
}

