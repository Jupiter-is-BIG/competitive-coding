#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> colors; // 0 -> unvisited, 1 -> red, -1 -> black

bool bfs(int root) {
    queue<int> neighbour;
    neighbour.push(root);
    colors[root] = 1;
    while(!neighbour.empty()) {
        int player = neighbour.front();
        neighbour.pop();
        int color = colors[player];
        for(int i: graph[player]) {
            if (colors[i] == 0) {colors[i] = -color; neighbour.push(i);}
            else if (colors[i] == color) return false;
        }
    }
    return true;
}

int main() {
    int n, r;
    cin >> n >> r;
    graph.resize(n);
    colors.resize(n); 

    for(int i = 0; i < r; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i = 0; i < n; ++i) {
        if (colors[i] == 0 && !bfs(i)) {
            cout << "Not possible\n";
            return 0;
        }
    }
    
    cout << "Possible\n\nFollowing is the parition"; 
    cout << "Babyfaces:\n";
    for(int i = 0; i < n; ++i) if(colors[i] == 1) cout << i << " ";
    cout << "\nHeels:\n";
    for(int i = 0; i < n; ++i) if(colors[i] == -1) cout << i << " ";
    cout << "\n";

    return 0;
}
