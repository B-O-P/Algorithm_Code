#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited(101);
vector<int> snake_ladder(101,0);

void bfs(int start, int count){
    queue<pair<int,int>> q;
    visited[start] = true;
    q.push(make_pair(start, 0));

    while(!q.empty()){
        int current = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for(int i=1; i<=6; i++){
            int next = current + i;
            while(snake_ladder[next] != 0){
                next = snake_ladder[next];
            }
            if(next == 100){
                cout << cnt + 1;
            }
            if(!visited[next] && next <= 100) {
                visited[next] = true;
                q.push(make_pair(next, cnt + 1));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;    cin >> N >> M;
    for(int i=0; i<N+M; i++){
        int a,b;    cin >> a >> b;
        snake_ladder[a] = b;
    }

    bfs(1,0);
}