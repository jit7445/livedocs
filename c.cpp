#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int helper(int i, int j, int k, int dir, vector<vector<vector<int>>> &dp) {
    
    if (i == 0 && j == 0) {
        return 0;
    }

    
    if (dp[i][j][dir] != -1) {
        return dp[i][j][dir];
    }

    int ans = 1e9; 

    for (int step = 0; step <= k; step++) {
        int st;
        if (dir == 1) {  
            if (i - step >= 0) {
                st = 1 + helper(i - step, j, k, 0, dp);
                ans = min(ans, st);
            }
        } else { 
            if (j - step >= 0) {
                st = 1 + helper(i, j - step, k, 1, dp);
                ans = min(ans, st);
            }
        }
    }
    
    return dp[i][j][dir] = ans; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;

        
        vector<vector<vector<int>>> dp(x + 1, vector<vector<int>>(y + 1, vector<int>(2, -1)));

        // Start the recursion from (x, y) with direction as x-direction (1)
        int ans = helper(x, y, k, 1, dp);
        cout << ans << endl;
    }
    return 0;
}
