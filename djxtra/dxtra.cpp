#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int INF = 1e9;

vector<int> dxtra(vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;

    set<pair<int, int>> q; // 1 - weight, 2 - vertex !!!!!! (важно)
    q.insert({dist[start], start});

    while (!q.empty()) {
        int nearest = q.begin()->second;
        q.erase(q.begin());
        
        for (auto p : graph[nearest]) {
            int to = p.first;
            int weight = p.second;
            if (dist[to] > dist[nearest] + weight) {
                q.erase({dist[to], to});
                dist[to] = dist[nearest] + weight;
                q.insert({dist[to], to});
            }
            
        }
    }

    return dist;
}



int main() {
    int vertexCount, edgeCount; cin >> vertexCount >> edgeCount;
    vector<vector<pair<int, int>>> graph(vertexCount + 1);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight; cin >> a >> b >> weight;
        graph[a].push_back({b, weight});
        graph[b].push_back({a, weight});
    }

    int start; cin >> start;
    vector<int> dist = dxtra(graph, start);

    for (int d : dist) cout << (d < INF ? d : 0) << " ";

}