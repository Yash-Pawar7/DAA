#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0-1 Knapsack problem using Dynamic Programming
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));  // 2D table to store results

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i-1] <= w) {
                // Include the item or exclude it, take the maximum value
                dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w]);
            } else {
                // Cannot include the item, take the previous value
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[n][W];  // Maximum value that can be obtained
}

int main() {
    int n, W;  // Number of items and capacity of knapsack
    cout << "Enter the number of items: ";
    cin >> n;
    
    vector<int> values(n), weights(n);
    
    cout << "Enter the values and weights of the items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i+1 << " - Value: ";
        cin >> values[i];
        cout << "Item " << i+1 << " - Weight: ";
        cin >> weights[i];
    }
    
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    // Call the knapsack function and print the maximum value
    int maxValue = knapsack(W, weights, values, n);
    cout << "Maximum value in the knapsack = " << maxValue << endl;

    return 0;
}

/*OUTPUT

Enter the number of items: 3
Enter the values and weights of the items:
Item 1 - Value: 12
Item 1 - Weight: 45
Item 2 - Value: 40
Item 2 - Weight: 60
Item 3 - Value: 32
Item 3 - Weight: 65
Enter the capacity of the knapsack: 50
Maximum value in the knapsack = 12

*/
