// Unbounded Knapsack
// ROd cutting Problem
#include<bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n) {
        vector<int> wt(n);
        iota(wt.begin(), wt.end(), 1);
        int dp[n+1][n+1];
        
        for(int i = 0; i< n+1; i++){
            for(int j = 0; j< n+1; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i< n+1; i++){
            for(int j = 1; j< n+1; j++){
                if(wt[i-1] <= j){
                    dp[i][j] = max(price[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][n];

}
int main(){
	int n;
	cin >> n;
	int val[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> val[i];
	}
	cout<<cutRod(val, n)<<'\n';


}