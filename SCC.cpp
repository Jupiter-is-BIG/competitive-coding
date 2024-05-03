#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> rgraph;
vector<vector<int>> opt_graph;
stack<int> clk;
vector<int> visited;
vector<int> rvisited;

void dfs(int root) {
    visited[root] = 1;
    for(int& i: graph[root]) if (visited[i] == 0) dfs(i);
    clk.push(root);
}

void scc(int root, vector<int> &component) {
    rvisited[root] = 1;
    component.push_back(root);
    for(int& i: rgraph[root]) if (rvisited[i] == 0) scc(i, component);
}

int main() {
    int n, m; // n: #vertices, m: #edges
    cin >> n >> m;
    
    graph.resize(n); // adj list
    rgraph.resize(n); // ajs list for reverse edges
    opt_graph.resize(n); // G' with less edges
    visited.resize(n); // 0: unvisited, 1: visited (1st dfs)
    rvisited.resize(n); // 0: unvisited, 1: visited (2nd dfs)

    for(int i = 0; i < m; ++i) {
        int u, v; // Edge: u -> v
        cin >> u >> v;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }

    // first dfs
    for(int i = 0; i < n; ++i) {
        if (visited[i] == 0) dfs(i);
    }

    vector<int> SCC(n); // maps graph vertex to ssc vertex
    set<pair<int, int>> C_edges; // edges in component graph
    int C_count = 0; // #vertex in component graph
    while(!clk.empty()) {
        if (rvisited[clk.top()] == 1) clk.pop();
        else {
            vector<int> component;
            scc(clk.top(), component);
            int comp_size = component.size();
            if (comp_size == 1) {
                SCC[component[0]] = C_count;
                C_count++;
                continue;
            }
            for(int i = 0; i < comp_size; ++i) {
                opt_graph[component[i]].push_back(component[(i+1)%comp_size]);
                SCC[component[i]] = C_count;
            }
            C_count++;
        }
    }

   for (int i = 0; i < n; ++i) {
        for (int& j: graph[i]) {
            if (SCC[i] != SCC[j] && C_edges.count({SCC[i], SCC[j]}) == 0) {
                C_edges.insert({SCC[i], SCC[j]});
                opt_graph[i].push_back(j);
            }
        }
    }

    // printing the new graph
    cout << "Vertices from 0 to " << n << "\nEdges:\n";
    for(int i = 0; i < n; ++i) {
        for(int& j: opt_graph[i]) cout << i << " -> " << j << "\n";
    }

    return 0;
}
