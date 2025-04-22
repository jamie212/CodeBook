/*
Time complexity: O(V^3)
Space complexity: O(V^2)
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

vector<vector<int>> FloydWarshall(unordered_map<int, vector<pii>>& graph){
    int n = graph.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for(const auto& node: graph){
        dist[node.first][node.first] = 0;
        for(const auto& neighbor: node.second){
            dist[node.first][neighbor.first] = neighbor.second;
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}

int main(){
    unordered_map<int, vector<pii>> graph = { // u: v, w
        {0, {{1, 3}, {3, 7}}}, 
        {1, {{0, 8}, {2, 2}}}, 
        {2, {{0, 5}, {3, 1}}}, 
        {3, {{0, 2}}}
    };
    int n = graph.size();
    vector<vector<int>> dist = FloydWarshall(graph);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}