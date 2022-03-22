// Top-Down Approach
#include <bits/stdc++.h>
using namespace std;
bool canPartition(vector<int>& nums, int n) {
        int sum  = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2){
            return false;
        }
        else{
            int sumP = sum/2;
            int dp[n+1][sumP+1];
            
            for(int i = 0; i< n+1; i++){
                for(int j = 0; j < sumP+1; j++){
                    if(i == 0){
                        dp[i][j] = false;
                    }
                    if(j == 0){
                        dp[i][j] = true;
                    }
                }
            }
            for(int i = 1; i< n+1; i++){
                for(int j = 1; j<sumP+1; j++){
                    if(nums[i-1] <= j){
                        dp[i][j] = (dp[i-1][j-nums[i-1]] or (dp[i-1][j]));
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            return dp[n][sumP];
        }
        
    }
int main()
{
    int n;
    cin >> n;
    vector<int> wt(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> wt[i];
    }
    
    cout<<canPartition(wt, n)<<'\n';

    return 0;

}