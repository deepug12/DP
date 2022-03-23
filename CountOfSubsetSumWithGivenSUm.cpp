// Top-Down Approach
#include <bits/stdc++.h>
using namespace std;
int perfectSum(vector<int> wt, int n, int sum){
        long long  dp[n+1][sum+1];
        long long mod = (1000000007);
    
        dp[0][0] = 1;        
        for(int j = 1; j < sum+1; j++){
                dp[0][j] = 0;
        }
        for(int i = 1; i< n+1; i++){
            for(int j = 0; j<sum+1; j++){
                if(wt[i-1] <= j){
                    dp[i][j] = (dp[i-1][j-wt[i-1]] % mod) + (dp[i-1][j] % mod);
                }
                else{
                    dp[i][j] = dp[i-1][j] % mod;
                }
            }
        }
        return dp[n][sum] % mod;
        
}
int main()
{
    int n, sum;
    cin >> n;
    cin >> sum;
    vector<int> wt(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> wt[i];
    }
    
    cout<<perfectSum(wt, n, sum)<<'\n';

    return 0;

}