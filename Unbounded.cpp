// Unbounded Knapsack
#include<bits/stdc++.h>
using namespace std;

int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[N+1][W+1];
        
        for(int i = 0; i< N+1; i++){
            for(int j = 0; j< W+1; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i< N+1; i++){
            for(int j = 1; j< W+1; j++){
                if(wt[i-1] <= j){
                    dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][W];
}
int main(){
	int n, w;
	cin >> n >> w;
	int wt[n], val[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> val[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> wt[i];
	}
	cout<<knapSack(n, w, val, wt)<<'\n';


}