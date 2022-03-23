#include <bits/stdc++.h>
using namespace std;
int CountSubsetWithGivenSum(vector<int> wt, int n, int result){

        int dp[n+1][result+1];
    
        dp[0][0] = 1;        
        for(int j = 1; j < result+1; j++){
                dp[0][j] = 0;
        }
        for(int i = 1; i< n+1; i++){
            for(int j = 0; j < result+1; j++){
                if(wt[i-1] <= j){
                    dp[i][j] = (dp[i-1][j-wt[i-1]]) + (dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][result];
        
}
int main()
{
    int n, diff;
    cin >> n;
    cin >> diff;
    vector<int> wt(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> wt[i];
    }
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += wt[i];
    }
    int result = (diff + sum)/2;
    cout<<CountSubsetWithGivenSum(wt, n, result)<<'\n';

    return 0;

}