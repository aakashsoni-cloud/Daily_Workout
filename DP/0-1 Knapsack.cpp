#include <bits/stdc++.h>
#define ll long long
using namespace std;


int max(int a, int b) {
	return (a > b) ? a : b;
}

/*Kanpsack fucntion*/ 
int knapSack(int C, int wt[], int val[], int n) {


	int dp[n + 1][C + 1]; //2-D dp array

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= C; j++)
		{
			if (i == 0 || j == 0) {
				dp[i][j] = 0;   // base condition
			}
			else if (wt[i - 1] <= C)
			{
				dp[i][j] = max(dp[i - 1][C - wt[i - 1]] + val[i - 1], dp[i - 1][j - 1]); // max of including thr last value and checking for the next one and excluding the value 
			}
			else
				dp[i][j] = dp[i - 1][j]; //if weight is greater than the capacity of knapsack
		}
	}
	return dp[n][C];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int w[] = {5, 10, 15, 20};
	int val[] = {10, 20, 30, 50};

	int W = 8; //KnapSack max weight/capacity
	int n = sizeof(val) / sizeof(int);
	cout << knapSack(W, w, val, n) << endl;
	return 0;
}

