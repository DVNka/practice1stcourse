#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    long long omega;
    cin >> n >> omega;

    vector<pair<long long, int>> holes(n);
    for (int i = 0; i < n; i++){
        cin >> holes[i].first;
        holes[i].second = i + 1;
    }

    sort(holes.begin(), holes.end());

    vector<int> order;
    long long cur_mass = omega;

    for (int i = 0; i < n; i++){
        if (holes[i].first < cur_mass){
            cur_mass += holes[i].first;
            order.push_back(holes[i].second);
        } else {
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
    for (int idx : order){
        cout << idx << " ";
    }
    cout << "\n";

    return 0;
}