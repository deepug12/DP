// Unbounded Knapsack
// coin change Problem(Count the number of ways)
// the number of combinations that make up that amount
#include<bits/stdc++.h>
using namespace std;

int change(int amount, int n, vector<int>& coins) {
        int  dp[n+1][amount + 1];
    
        dp[0][0] = 1;
        for(int i = 1; i < n + 1; i++){
                dp[i][0] = 1;
        }
        for(int j = 1; j < amount + 1; j++){
                dp[0][j] = 0;
        }
        for(int i = 1; i< n+1; i++){
            for(int j = 0; j < amount + 1; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = (dp[i][j-coins[i-1]]) + (dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
int main(){
	int n, sum;
	cin >> n >> sum;
	vector<int> wt(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> wt[i];
	}
	cout<<change(sum, n,  wt)<<'\n';


}