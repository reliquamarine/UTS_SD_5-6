#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {    
    int V, E;
    cout << "Jumlah vertex dan edge: ";
    cin >> V >> E;
    
    vector<vector<int>> graph(V);
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int S, K;
    cout << "Node Awal dan Hari Terinfeksi: ";
    cin >> S >> K;
    
    vector<int> level(V, -1);
    queue<int> q;
    q.push(S);
    level[S] = 0;   
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int neighbor : graph[curr]) {
            if (level[neighbor] == -1) {
                level[neighbor] = level[curr] + 1;
                q.push(neighbor);
            }
        }
    }
    
    vector<int> infected;
    for (int i = 0; i < V; i++) {
        if (level[i] == K) {
            infected.push_back(i);
        }
    }
    
    cout << "Node terinfeksi: ";
    if (infected.empty()) {
        cout << "(TIDAK ADA)" << endl;
    } else {
        for (size_t i = 0; i < infected.size(); i++) {
            cout << infected[i];
            if (i < infected.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
