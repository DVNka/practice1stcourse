#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> dp(N + 1, 0);
    dp[1] = 0;

    for (int i = 2; i <= N; i++){
        long long min_cost = dp[i - 1];

        if (i % 2 == 0){
            min_cost = min(min_cost, dp[i / 2]);
        }
        if (i % 3 == 0){
            min_cost = min(min_cost, dp[i / 3]);
        }
        dp[i] = i + min_cost;
    }

    cout << dp[N] << endl;

    return 0;
}