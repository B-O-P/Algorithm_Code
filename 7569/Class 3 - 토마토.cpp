#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int H, int N, int M,vector<vector<vector<int>>> &arr, vector<vector<vector<bool>>> &visited){
//pair<높이,pair<y,x>>
queue<pair<int,pair<int,int>>> q;
for (int k = 0; k < H; k++) {
for (int i = 0; i < N; i++) {
for (int j = 0; j < M; j++) {
if(arr[k][i][j] != 0 && arr[k][i][j] != -1 && !visited[k][i][j]){
q.push(make_pair(k, make_pair(i,j)));
visited[k][i][j] = true;
}
}
}
}

//시작지점을 찾았으면 3차원 그래프 탐색
while(!q.empty()){
pair<int,pair<int,int>> current = make_pair(q.front().first,make_pair(q.front().second.first, q.front().second.second));
q.pop();
//2차원 - 상
if(current.second.first - 1 >= 0){
//갈 수 없는 칸이 아니고 방문하지 않았다면
if(arr[current.first][current.second.first - 1][current.second.second] != -1 &&
!visited[current.first][current.second.first - 1][current.second.second]){
//큐에 삽입해주고, 방문처리
q.push(make_pair(current.first, make_pair(current.second.first - 1, current.second.second)));
visited[current.first][current.second.first - 1][current.second.second] = true;
//이전 값에 + 1
arr[current.first][current.second.first - 1][current.second.second] =
arr[current.first][current.second.first][current.second.second] + 1;
}
}
//2차원 - 하
if(current.second.first + 1 < N){
//갈 수 없는 칸이 아니고 방문하지 않았다면
if(arr[current.first][current.second.first + 1][current.second.second] != -1 &&
!visited[current.first][current.second.first + 1][current.second.second]){
//큐에 삽입해주고
q.push(make_pair(current.first, make_pair(current.second.first + 1, current.second.second)));
visited[current.first][current.second.first + 1][current.second.second]= true;
//이전 값에 + 1
arr[current.first][current.second.first + 1][current.second.second] =
arr[current.first][current.second.first][current.second.second] + 1;
}
}
//2차원 - 좌
if(current.second.second - 1 >= 0){
//갈 수 없는 칸이 아니고 방문하지 않았다면
if(arr[current.first][current.second.first][current.second.second - 1] != -1 &&
!visited[current.first][current.second.first][current.second.second - 1]){
//큐에 삽입해주고
q.push(make_pair(current.first, make_pair(current.second.first, current.second.second - 1)));
visited[current.first][current.second.first][current.second.second - 1] = true;
//이전 값에 + 1
arr[current.first][current.second.first][current.second.second - 1] =
arr[current.first][current.second.first][current.second.second] + 1;
}
}
//2차원 - 우
if(current.second.second + 1 < M){
//갈 수 없는 칸이 아니고 방문하지 않았다면
if(arr[current.first][current.second.first][current.second.second + 1] != -1 &&
!visited[current.first][current.second.first][current.second.second + 1]){
//큐에 삽입해주고
q.push(make_pair(current.first, make_pair(current.second.first, current.second.second + 1)));
visited[current.first][current.second.first][current.second.second + 1] = true;
//이전 값에 + 1
arr[current.first][current.second.first][current.second.second + 1] =
arr[current.first][current.second.first][current.second.second] + 1;
}
}
//3차원 - 상
if(current.first - 1 >= 0){
if(arr[current.first - 1][current.second.first][current.second.second] != -1 &&
!visited[current.first - 1][current.second.first][current.second.second]){
q.push(make_pair(current.first - 1, make_pair(current.second.first,current.second.second)));
visited[current.first - 1][current.second.first][current.second.second] = true;
arr[current.first - 1][current.second.first][current.second.second] =
arr[current.first][current.second.first][current.second.second] + 1;
}
}
//3차원 - 하
if(current.first + 1 < H){
if(arr[current.first + 1][current.second.first][current.second.second] != -1 &&
!visited[current.first + 1][current.second.first][current.second.second]){
q.push(make_pair(current.first + 1, make_pair(current.second.first,current.second.second)));
visited[current.first + 1][current.second.first][current.second.second] = true;
arr[current.first + 1][current.second.first][current.second.second] =
arr[current.first][current.second.first][current.second.second] + 1;
}
}
}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //가로,세로,높이
    int M,N,H;  cin >> M >> N >> H;
    //삼차원 벡터 생성
    vector<vector<vector<int>>> arr(H, vector<vector<int>>(N, vector<int>(M,0)));
    vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(N, vector<bool>(M,false)));

    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> arr[k][i][j];
            }
        }
    }

    bfs(H,N,M,arr,visited);

    int max = -2;
    for(int k = 0; k < H; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[k][i][j] > max)
                    max = arr[k][i][j];
                if(arr[k][i][j] == 0){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << max - 1;
    return 0;
}
