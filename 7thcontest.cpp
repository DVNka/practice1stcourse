#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const long long INF = 1e18;

struct Edge{
    int u, v;
    long long w;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s;
    cin >> n >> m >> s;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<long long> dist(n + 1, INF);
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++){
        for (const auto& edge : edges){
            if (dist[edge.u] < INF){
                dist[edge.v] = min(dist[edge.v], dist[edge.u] + edge.w);
            }
        }
    }

    vector<bool> in_negative_cycle(n + 1, false);

    for (const auto& edge : edges){
        if (dist[edge.u] < INF && dist[edge.u] + edge.w < dist[edge.v]){
            in_negative_cycle[edge.v] = true;
        }
    }

    bool changed = true;
    while (changed){
        changed = false;
        for (const auto& edge : edges){
            if (in_negative_cycle[edge.u] && !in_negative_cycle[edge.v]){
                in_negative_cycle[edge.v] = true;
                changed = true; 
            }
        }
    }

    bool has_negative_cycle_on_path = false;
    for (int i = 1; i <= n; i++){
        if (in_negative_cycle[i] && dist[i] < INF){
            has_negative_cycle_on_path = true;
            break;
        }
    }

    if (has_negative_cycle_on_path){
        cout << "Negative cycle" << endl;
    } else {
        for (int i = 1; i <= n; i++){
            if (i > 1) cout << " ";
            if (dist[i] == INF){
                cout << "inf";
            } else {
                cout << dist[i];
            }
        }
        cout << endl;
    }

    return 0;
}