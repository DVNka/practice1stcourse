#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int count = 0;

    for (int i = 0; i < n - 1; i++){
        if (a[i + 1] - a[i] == 1){
            count++;
        } else {
            break;
        }
    }
    if (count == n - 1){
        cout << "Deck looks good" << "\n";
    } else {
        cout << "Scammed" << "\n";
    }

    return 0;
}