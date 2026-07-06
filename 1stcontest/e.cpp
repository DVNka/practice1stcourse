#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> local_mins, local_maxs;
    int global_min_pos = 0, global_max_pos = 0;

    for (int i = 1; i < n; i++){
        if (a[i] < a[global_min_pos]){
            global_min_pos = i;
        }
        if (a[i] > a[global_max_pos]){
            global_max_pos = i;
        }
    }

    for (int i = 0; i < n; i++){
        bool is_local_min = true;
        bool is_local_max = true;

        if (i > 0){
            if (a[i] >= a[i - 1]){
                is_local_min = false;
            }
            if (a[i] <= a[i - 1]){
                is_local_max = false;
            }
        }

        if (i < n - 1){
            if (a[i] >= a[i + 1]){
                is_local_min = false;
            }
            if (a[i] <= a[i + 1]){
                is_local_max = false;
            }
        }
        if (is_local_min){
            local_mins.push_back(i + 1);
        }
        if (is_local_max){
            local_maxs.push_back(i + 1);
        }
    }

    cout << local_mins.size();
    for (int pos : local_mins){
        cout << ' ' << pos;
    }
    cout << "\n";

    cout << local_maxs.size();
    for (int pos : local_maxs){
    cout << ' ' << pos;
    }
    cout << endl;

    cout << global_min_pos + 1 << ' ' << global_max_pos + 1 << "\n";

    return 0;
}