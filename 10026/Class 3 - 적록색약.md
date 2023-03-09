# Class 3 - 적록색약

## 문제 접근

1. R,G,B에 해당하는 BFS가 필요하다.
2. RG,B에 해당하는 BFS가 필요하다.
3. (R,G,B),(RG,B)BFS를 할 때 마다 방문 배열을 초기화 해줘야한다.
4. 각각의 BFS를 실행시키는 횟수가 R,G,B구역의 갯수 혹은 RG,B구역의 갯수다.

---

다른 사람들의 코드를 보다가 방문을 보기 좋게 하는 것을 보았다.

|  | 상 | 하 | 좌 | 우 |
| --- | --- | --- | --- | --- |
| x | 0 | 0 | -1 | 1 |
| y | -1 | 1 | 0 | 0 |

### 예를들어

//q.front()가 지금의 위치, x가 그 다음 이동할 x위치, y가 그 다음 이동할 y위치라면

[q.front().first + x][q.front().second + y]에 해당하는 코드를 4번 작성하는 것보다

x[4]를 만들고 y[4]를 만들어서 for문을 통해서 코드를 1번만 작성할 수 있는 것이다.

```cpp
int next_y[] = {1,-1,0,0};
int next_x[] = {0,0,1,-1};
```

### 이후 인덱스 초과 문제를 피하기 위해서 while문 안에서는

1. y좌표가 0보다 작아지거나 
2. y좌표가 배열의 최대 크기보다 크거나 같거나
3. x좌표가 0보다 작아지거나
4. x좌표가 배열의 최대 크기보다 크거나 같거나

4가지중 1가지라도 해당하면 다음 for문으로 가서 그 다음 이동할 수 있는 좌표를 확인하면 된다.

```cpp
if(next.first + next_y[i] < 0 || 
next.first + next_y[i] >= N || 
next.second + next_x[i] < 0 || 
next.second + next_x[i] >= N){
                continue;
```

### (R,G,B) BFS

함수 인자로 색깔을 받아서 해당하는 색만 찾는 함수이다.

단일 색을 받기 때문에 모든 경우에 범용적으로 사용이 가능하다.

(RG) BFS의 경우 B를 판단하면 안되기 때문에 따로 함수작성이 필요하다.

```cpp
void bfs(int N, int y, int x, vector<vector<char>> &arr, 
vector<vector<bool>> &visited, char color){
```

## 그래서 bfs와 RG_bfs의 함수 인자가 다르다.

```cpp
if(visited[i][j] == false){
    if(arr[i][j] == 'B')
        bfs(N, i, j, arr, visited, arr[i][j]);
    else
        RG_bfs(N,i,j,arr,visited);
    count++;
}
```

---

## 코드

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void bfs(int N, int y, int x, vector<vector<char>> &arr, vector<vector<bool>> &visited, char color){
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));
    visited[y][x] = true;

    int next_y[] = {1,-1,0,0};
    int next_x[] = {0,0,1,-1};

    while(!q.empty()){
        pair<int,int> next = make_pair(q.front().first, q.front().second);
        q.pop();
        for(int i = 0; i < 4; i++){
            if(next.first + next_y[i] < 0 || next.first + next_y[i] >= N || next.second + next_x[i] < 0 || next.second + next_x[i] >= N){
                continue;
            }
            else {
                if (arr[next.first + next_y[i]][next.second + next_x[i]] == color && visited[next.first + next_y[i]][next.second + next_x[i]] == false) {
                    q.push(make_pair(next.first+next_y[i], next.second+next_x[i]));
                    visited[next.first + next_y[i]][next.second + next_x[i]] = true;
                }
            }
        }
    }
}

//R,G를 동일하게 봐야한다.
void RG_bfs(int N, int y, int x, vector<vector<char>> &arr, vector<vector<bool>> &visited){
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));
    visited[y][x] = true;

    int next_y[] = {1,-1,0,0};
    int next_x[] = {0,0,1,-1};

    while(!q.empty()){
        pair<int,int> std = make_pair(q.front().first,q.front().second);
        q.pop();
        for(int i=0; i<4; i++){
            if(std.first + next_y[i] < 0 || std.first + next_y[i] >= N ||
            std.second + next_x[i] < 0 || std.second + next_x[i] >= N)
                continue;
            else{
                if(arr[std.first + next_y[i]][std.second + next_x[i]] == 'R' ||
                arr[std.first + next_y[i]][std.second + next_x[i]] == 'G'){
                    if(visited[std.first + next_y[i]][std.second + next_x[i]] == false){
                        q.push(make_pair(std.first + next_y[i], std.second + next_x[i]));
                        visited[std.first + next_y[i]][std.second + next_x[i]] = true;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;  cin >> N;

    vector<vector<char>> arr(N, vector<char>(N));
    vector<vector<bool>> visited(N, vector<bool>(N,false));

    for(int i=0; i<N; i++){
        string input;
        cin >> input;
        for(int j=0; j<N; j++){
            arr[i][j] = input[j];
        }
    }

    int count = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] == false) {
                bfs(N, i, j, arr, visited, arr[i][j]);
                count++;
            }
        }
    }
    cout << count <<' ';
    count = 0;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            visited[i][j] = false;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] == false){
                if(arr[i][j] == 'B')
                    bfs(N, i, j, arr, visited, arr[i][j]);
                else
                    RG_bfs(N,i,j,arr,visited);
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
```