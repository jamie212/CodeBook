/*
Time complexity: O((V + E) * log(V))
Space complexity: O(V)
*/
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <limits>

using namespace std;

typedef pair<int, int> pii;

unordered_map<int, int> dijkstra(unordered_map<int, vector<pii>>& graph, int start){
    unordered_map <int, int> dist; // dist[i] means min dist from start to node i
    // initialize
    for(const auto& node: graph){
        dist[node.first] = INT_MAX; 
    }
    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq; // priority_queue default max heap, set to min heap
    pq.push({0, start}); // item in pq: {node, cur dist from start}
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue; //already have shorter path

        for(const auto& [v, weight]: graph[u]){ // u->v (try every u's neighbor whether can get shorter path by u)
            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            } 
        }
    }
    return dist;
}

int main(){
    unordered_map<int, vector<pii>> graph = { // key: u point, value: vector of {v point, weight}
        {0, {{1, 1}, {2, 4}}}, 
        {1, {{0, 1}, {2, 2}, {3, 5}}}, 
        {2, {{0, 4}, {1, 2}, {3, 1}}}, 
        {3, {{1, 5}, {2, 1}}}
    };
    int start = 0;
    unordered_map<int, int> res = dijkstra(graph, start);
    for(const auto& [v, dist]: res){
        cout << "from " << start << " to " << v << " cost " << dist << endl;
    }
}