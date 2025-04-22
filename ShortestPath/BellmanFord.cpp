/*
Time complexity: O(V * E)
Space complexity: O(V)
*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

// // by using adjcent list
// unordered_map<int, int> BellmanFord(unordered_map<int, vector<pii>> graph, int start){
//     unordered_map<int, int> dist;
//     for(const auto& node: graph){
//         dist[node.first] = INT_MAX;
//     }
//     dist[start] = 0;

//     // Bellman: relax every edge V - 1 times
//     int V = graph.size();
//     for(int k = 0; k < V - 1; k++){
//         for(const auto& node: graph){
//             for(const auto& edge: node.second){
//                 int u = node.first, v = edge.first, d = edge.second;
//                 if(dist[u] + d < dist[v]){
//                     dist[v] = dist[u] + d;
//                 }
//             }
//         }
//     }

//     // relax again, if can get smaller -> negative cycle
//     for(const auto& node: graph){
//         for(const auto& edge: node.second){
//             int u = node.first, v = edge.first, d = edge.second;
//             if(dist[u] + d < dist[v]){
//                 cout << "Graph contains a negative weight cycle!" << endl;
//             }
//         }
//     }

//     return dist;
// }

struct Edge{
    int from, to, weight;
};

// by using edge list
unordered_map<int, int> BellmanFord(unordered_map<int, vector<pii>> graph, int start){
    unordered_map<int, int> dist;
    for(const auto& node: graph){
        dist[node.first] = INT_MAX;
    }
    dist[start] = 0;

    // translate adjecent list to edge list
    vector<Edge> edges;
    for(const auto& node: graph){
        for(const auto& edge: node.second){
            int u = node.first, v = edge.first, w = edge.second;
            edges.push_back({u, v, w});
        }
    }

    // Bellman: relax every edge V - 1 times
    int V = graph.size();
    for(int k = 0; k < V - 1; k++){
        for(const auto& edge: edges){
            if(dist[edge.from] + edge.weight < dist[edge.to]){
                dist[edge.to] = dist[edge.from] + edge.weight;
            }
        }
    }

    // relax again, if can get smaller -> negative cycle
    for(int k = 0; k < V - 1; k++){
        for(const auto& edge: edges){
            if(dist[edge.from] + edge.weight < dist[edge.to]){
                cout << "Graph contains a negative weight cycle!" << endl;
                return {};
            }
        }
    }

    return dist;
}

int main(){
    unordered_map<int, vector<pii>> graph = {
        {0, {{1, -1}, {2, 4}}}, 
        {1, {{2, 3}, {3, 2}, {4, 2}}}, 
        {2, {}}, 
        {3, {{1, 1}, {2, 5}}}, 
        {4, {{3, -3}}} // if want to check negative cycle: change {3, -3} to {3, -6}, since negative cycle means weight sum of cycle < 0
    };

    int start = 0;
    unordered_map<int, int> dist = BellmanFord(graph, start);
    for(const auto& d: dist){
        cout << "From " << start << " to " << d.first << " dist: " << d.second << endl;
    }
}