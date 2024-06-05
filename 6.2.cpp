#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    int cost;
};

int minCost(vector<vector<Edge>>& graph, vector<int>& fuelCost, int start, int end) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int currNode = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        if (currDist > dist[currNode]) continue;

        for (Edge& edge : graph[currNode]) {
            int newDist = currDist + edge.cost * fuelCost[edge.to];
            if (newDist < dist[edge.to]) {
                dist[edge.to] = newDist;
                pq.push({newDist, edge.to});
            }
        }
    }

    return (dist[end] == INT_MAX) ? -1 : dist[end];
}

int main() {
    int N;
    cin >> N;

    vector<int> fuelCost(N);
    for (int i = 0; i < N; ++i) {
        cin >> fuelCost[i];
    }

    int M;
    cin >> M;

    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from - 1].push_back({to - 1, 1});
        graph[to - 1].push_back({from - 1, 1});
    }

    int result = minCost(graph, fuelCost, 0, N - 1);
    
    cout << result << endl;

    return 0;
}