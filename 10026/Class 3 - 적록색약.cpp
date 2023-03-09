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