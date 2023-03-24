#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(int start, vector<int> &ans, vector<vector<int>> &graph, vector<bool> &visited){

    queue<pair<int,int>> q;
    //0 -> 1을 삽입
    q.push(make_pair(start, graph[start][0]));
    while(!q.empty()){
        //crt.first가 현재 위치 crt.second가 미래 위치
        pair<int,int> crt = make_pair(q.front().first, q.front().second);
        ans[q.front().second] = q.front().first;
        visited[q.front().second] = true;
        q.pop();

        for(int i=0; i<graph[crt.second].size(); i++){
            if(visited[graph[crt.second][i]])
                continue;
            else{
                q.push(make_pair(crt.second, graph[crt.second][i]));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;  cin >> N;

    vector<vector<int>> graph(N+1);
    vector<bool> visited(N+1, false);
    vector<int> ans(N+1);

    graph[0].push_back(1);
    for(int i=0; i<N-1; i++){
        int a,b;    cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(0, ans, graph, visited);

    for(int i=2; i<=N; i++){
        cout << ans[i] << "\n";
    }
}