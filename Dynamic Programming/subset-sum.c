// Algorithm: Subset Sum
// Type: Dynamic Programming
// Time: O(n * sum)
// Space: O(n * sum)

#include <stdio.h>
#include <stdbool.h>

bool subsetSum(int arr[], int n, int sum) {
    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }

    return dp[n][sum];
}
