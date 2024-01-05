#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> arr;
vector<vector<bool>> visited;
int N,M;

void bfs(int y, int x){
    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(y,x),0));

    while(!q.empty()){
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int count = q.front().second;
        if(visited[cy][cx] || arr[cy][cx] == 0){
            q.pop();
            visited[cy][cx] = true;
            continue;
        }
        visited[cy][cx] = true;
        arr[cy][cx] = count;
        count += 1;
        q.pop();
        //x-1, y
        if(cx-1 >= 0 && !visited[cy][cx-1]){
            q.push(make_pair(make_pair(cy,cx-1),count));
        }
        //x+1, y
        if(cx+1 < M && !visited[cy][cx+1]){
            q.push(make_pair(make_pair(cy,cx+1),count));
        }
        //x,y-1
        if(cy-1 >= 0 && !visited[cy-1][cx]){
            q.push(make_pair(make_pair(cy-1,cx),count));
        }
        //x,y+1
        if(cy+1 < N && !visited[cy+1][cx]){
            q.push(make_pair(make_pair(cy+1,cx),count));
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    int dy,dx;
    arr = vector<vector<int>> (N, vector<int> (M));
    visited = vector<vector<bool>> (N, vector<bool> (M,false));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                dy = i;
                dx = j;
            }
        }
    }
    bfs(dy,dx);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 0 || visited[i][j])
                cout << arr[i][j];
            else{
                cout << -1;
            }
            if(j != M-1)
                cout << ' ';
        }
        cout << "\n";
    }
}