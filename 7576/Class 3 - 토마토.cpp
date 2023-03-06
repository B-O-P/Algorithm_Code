#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int biggest = 0;


void bfs(int N, int M, int y, int x, vector<vector<bool>> &visited, vector<vector<int>> &arr){
    queue<pair<int,int>> q;
    for(int i=0; i<N; i++){
        for(int j=0 ;j<M; j++){
            if(!visited[i][j] && arr[i][j] != -1 && arr[i][j] != 0) {
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }

    while(!q.empty()){
        pair<int,int> current = make_pair(q.front().first,q.front().second);
        q.pop();
        //상
        if(current.first - 1 >= 0){
            if(!visited[current.first - 1][current.second] &&
               arr[current.first - 1][current.second] != -1) {
                visited[current.first - 1][current.second] = true;
                arr[current.first - 1][current.second] =
                        arr[current.first][current.second] + 1;
                q.push(make_pair(current.first - 1, current.second));
            }
        }
        //하
        if(current.first + 1 < N){
            if(!visited[current.first + 1][current.second] &&
            arr[current.first + 1][current.second] != -1) {
                visited[current.first + 1][current.second] = true;
                arr[current.first + 1][current.second] =
                        arr[current.first][current.second] + 1;
                q.push(make_pair(current.first + 1, current.second));
            }
        }
        //좌
        if(current.second - 1 >= 0) {
            if (!visited[current.first][current.second - 1] &&
                arr[current.first][current.second - 1] != -1) {
                visited[current.first][current.second - 1] = true;
                arr[current.first][current.second - 1] =
                        arr[current.first][current.second] + 1;
                q.push(make_pair(current.first,current.second - 1));
            }
        }
        //우
        if(current.second + 1 < M) {
            if (!visited[current.first][current.second + 1] &&
                arr[current.first][current.second + 1] != -1) {
                visited[current.first][current.second + 1] = true;
                arr[current.first][current.second + 1] =
                        arr[current.first][current.second] + 1;
                q.push(make_pair(current.first,current.second + 1));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M,N;    cin >> M >> N;
    vector<vector<int>> arr(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M,false));

    for(int i=0; i<N; i++){
        for(int j=0 ; j<M ;j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j] && arr[i][j] != -1 && arr[i][j] != 0){
                bfs(N,M,i,j,visited,arr);
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] > biggest)
                biggest = arr[i][j];
            if(arr[i][j] == 0){
                cout << -1;
                return 0;
            }
        }
    }

    cout << biggest-1;
    return 0;
}