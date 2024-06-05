#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int dijkstra(vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[start] = 0;

    for (int i = 0; i < n - 1; ++i) {
        int min_dist = INT_MAX;
        int u = -1;

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }

        if (min_dist == INT_MAX) break;

        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] != -1 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return (dist[end] == INT_MAX) ? -1 : dist[end];
}

int main() {
    int N, S, F;
    cin >> N >> S >> F;

    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];
        }
    }

    int result = dijkstra(graph, S - 1, F - 1);

    cout << result << endl;

    return 0;
}