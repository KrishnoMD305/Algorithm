#include <iostream>
#include <vector>
using namespace std;

// Also can be used to find the unique ways to go from top left corner to bottom right corner of a board
class Solution {
public:
    // Method 1: Dynamic Programming (2D array)
    int uniquePaths2D(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
    
    // Method 2: Space-optimized DP (1D array)
    int uniquePaths1D(int m, int n) {
        vector<int> dp(n, 1);
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j-1];
            }
        }
        
        return dp[n-1];
    }
    
    // Method 3: Mathematical approach using combinations
    int uniquePathsMath(int m, int n) {
        long long result = 1;
        int moves = m + n - 2;  // Total moves needed
        int down = m - 1;       // Number of down moves
        
        // Calculate C(moves, down) = moves! / (down! * (moves-down)!)
        for (int i = 1; i <= down; i++) {
            result = result * (moves - down + i) / i;
        }
        
        return (int)result;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    vector<pair<int, int>> testCases = {
        {3, 7},  // 3x7 grid
        {3, 2},  // 3x2 grid
        {7, 3},  // 7x3 grid
        {3, 3},  // 3x3 grid
        {1, 1},  // 1x1 grid
        {4, 4}   // 4x4 grid
    };
    
    cout << "Grid Size\t2D DP\t1D DP\tMath\n";
    cout << "=========\t=====\t=====\t====\n";
    
    for (auto& test : testCases) {
        int m = test.first, n = test.second;
        int result2D = sol.uniquePaths2D(m, n);
        int result1D = sol.uniquePaths1D(m, n);
        int resultMath = sol.uniquePathsMath(m, n);
        
        cout << m << "x" << n << "\t\t" << result2D << "\t" << result1D << "\t" << resultMath << "\n";
    }
    
    // Interactive input
    cout << "\nEnter custom grid dimensions:\n";
    int m, n;
    cout << "Rows (m): ";
    cin >> m;
    cout << "Columns (n): ";
    cin >> n;
    
    if (m > 0 && n > 0) {
        cout << "\nFor a " << m << "x" << n << " grid:\n";
        cout << "Unique paths: " << sol.uniquePaths2D(m, n) << "\n";
    } else {
        cout << "Invalid dimensions!\n";
    }
    
    return 0;
}