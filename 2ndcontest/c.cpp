#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long > a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long long count = 0;

    for (int k = n - 1; k >= 2; k--){
        int i = 0, j = k - 1;

        while (i < j){
            if (a[i] + a[j] > a[k]){
                count += j - i;
                j--;
            } else {
                i++;
            }
        }
    }
    cout << count << "\n";
    
    return 0;
    
}