// Top-Down Approach
#include <bits/stdc++.h>
using namespace std;
int knapSack(int WBag, vector<int> wt, vector<int> val, int n) 
    {
        int dp[n+1][WBag+1];
        
        for(int i = 0; i< n+1; i++){
            for(int j = 0; j< WBag+1; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i< n+1; i++){
            for(int j = 1; j< WBag+1; j++){
                if(wt[i-1] <= j){
                    dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][WBag];
    }
int main()
{

    int n, WBag;
    cin >> n;
    cin >> WBag;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> wt[i];
    }
    cout<<knapSack(WBag, wt, val, n)<<'\n';

    return 0;

}