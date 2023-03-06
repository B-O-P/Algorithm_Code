# Class 3 토마토

## 문제 접근

```cpp
6 4 -> 가로,세로
1 -1 0 0 0 0
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1
```

일반적인 BFS문제라고 생각했다.

그런데 초기 큐 삽입을 다르게 해야한다.

(0,0)과 (3,5)에서 동시에 BFS를 실행해야 중간에서 만나면서 최단시간을 구할 수 있을 것이기 때문이다.

### 실행결과

```cpp
1 -1 7 6  5 4
2 -1 6 5  4 3
3  4 5 6 -1 2
4  5 6 7 -1 1
```

그렇다면 일반적은 bfs는 시작지점이 1개이기 때문에 시작지점의 방문 배열을 true처리를 하고 큐 삽입을하지만

**이 문제는 초기에 1인 지점을 모두 큐에 삽입해줘야 한다.**

그렇게 해야 1인 지점에서 확산을 하면서 최단시간을 구할 수 있을 것이기 때문이다.

1. 큐는 FIFO구조다. 거기에 방문 배열이 있기 때문에 그래프를 탐색하면서 이미 도착한 지점을 더 높은 수를 가진 큐가 갱신할 가능성은 없어서 더 이상의 예외처리를 생각할 것은 없다고 생각했다.
2. 그래프 탐색을 완료하고 완전탐색을 한 번 돌려서 여전히 0인 수가 있다면 도착할 수 없는 지점이 있다는 의미이므로 1을 출력해주면 끝이다.

### BFS의 인자

```cpp
//상하좌우 이동을 위한 최대치인 N,M
//현재 위치를 표현하는 y,x
void bfs(int N, int M, int y, int x, 
vector<vector<bool>> &visited, vector<vector<int>> &arr)
```

### BFS에서 처음 큐를 삽입하는 부분

```cpp
queue<pair<int,int>> q;
    for(int i=0; i<N; i++){
        for(int j=0 ;j<M; j++){
            if(!visited[i][j] && arr[i][j] != -1 && arr[i][j] != 0) {
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }
```

### 상,하,좌,우를 확인하고 이동할 수 있다면 큐에 삽입

```cpp
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
```

### main()부분

```cpp
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

//전체 배열을 탐색하면서 시작가능한 지점을 찾아줌
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j] && arr[i][j] != -1 && arr[i][j] != 0){
                bfs(N,M,i,j,visited,arr);
            }
        }
    }

//전체 배열을 탐색하면서 지금까지의 최대 값을 찾음
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
//시작지점이 1이지만 그때 걸린 시간은 0일이다.
//따라서 출력은 -1일을 해줘야한다.
    cout << biggest-1;
    return 0;
}
```

## 구현

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int biggest = 0;

//상하좌우 이동을 위한 최대치인 N,M
//현재 위치를 표현하는 y,x
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
```