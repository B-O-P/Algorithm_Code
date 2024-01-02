#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> arr;
vector<vector<char>> visited;
int N,M;
int meet = 0;

void bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        if(visited[cy][cx]){
            q.pop();
            continue;
        }
        if(arr[cy][cx] == 'P'){
            meet += 1;
        }
        visited[cy][cx] = true;
        q.pop();
        //x-1, y
        if(cx-1 >= 0 && arr[cy][cx-1] != 'X' && !visited[cy][cx-1]){
            q.push(make_pair(cy,cx-1));
        }
        //x+1, y
        if(cx+1 < M && arr[cy][cx+1] != 'X' && !visited[cy][cx+1]){
            q.push(make_pair(cy,cx+1));
        }
        //x,y-1
        if(cy-1 >= 0 && arr[cy-1][cx] != 'X' && !visited[cy-1][cx]){
            q.push(make_pair(cy-1,cx));
        }
        //x,y+1
        if(cy+1 < N && arr[cy+1][cx] != 'X' && !visited[cy+1][cx]){
            q.push(make_pair(cy+1,cx));
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    int dy,dx;
    arr = vector<vector<char>> (N, vector<char> (M));
    visited = vector<vector<char>> (N, vector<char> (M,false));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'I'){
                dy = i;
                dx = j;
            }
        }
    }
    bfs(dy,dx);
    if(meet == 0){
        cout << "TT";
    }
    else{
        cout << meet;
    }
}