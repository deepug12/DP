// Top-Down Approach
#include <bits/stdc++.h>
using namespace std;
bool subsetSum(vector<int> wt, int sum, int n) 
{

        int dp[n+1][sum+1];
        
        for(int i = 0; i< n+1; i++){
            for(int j = 0; j< sum+1; j++){
                if(i == 0){
                    dp[i][j] = false;
                }
                if(j == 0){
                    dp[i][j] = true;
                }
            }
        }
        for(int i = 1; i< n+1; i++){
            for(int j = 1; j< sum+1; j++){
                if(wt[i-1] <= j){
                    dp[i][j] = (dp[i-1][j-wt[i-1]] or dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];

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
    
    cout<<subsetSum(wt, sum, n)<<'\n';

    return 0;

}