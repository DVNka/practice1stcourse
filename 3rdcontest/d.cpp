#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<bool>> dangerous(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        dangerous[x][y] = true;
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (dangerous[i][j]){
                dp[i][j] = 0;
                continue;
            }

            if (i > 0){
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }

            if (j > 0){
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    cout << dp[n][m] << endl;

    return 0;
}