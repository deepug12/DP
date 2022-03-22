// Top-Down Approach
#include <bits/stdc++.h>
using namespace std;
int dp[102][1002];
int knapSack(vector<int> wt, vector<int> val, int w, int n) 
{
        
        if(n == 0 or w == 0){
            return 0;
        }
        if(dp[n][w] != -1){
            return dp[n][w];
        }

        if(wt[n-1] <= w){
            dp[n][w] = max((val[n-1]+knapSack(wt, val, w-wt[n-1], n-1)), knapSack(wt, val, w, n-1));
            return dp[n][w];
        }
        else{
            dp[n][w] = knapSack(wt, val, w, n-1);
            return dp[n][w];
        }

    }
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n;
    cin >> w;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> wt[i];
    }
    
    cout<<knapSack(wt, val, w, n)<<'\n';

    return 0;

}