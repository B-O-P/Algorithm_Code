#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;   cin >> N >> M;
    vector<vector<int>> arr(N+1, vector<int> (N+1,0));
    vector<vector<int>> sum(N+1, vector<int> (N+1,0));
    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            cin >> arr[i][j];
        }
    }

    //1행,1열 구간합
    for(int i=1; i<N+1; i++){
        sum[1][i] = sum[1][i-1] + arr[1][i];
        sum[i][1] = sum[i-1][1] + arr[i][1];
    }
    //2,2부터의 구간합
    for(int i=2; i<N+1; i++){
        for(int j=2; j<N+1; j++){
            sum[i][j] = sum[i][j-1] + sum[i-1][j] + arr[i][j] - sum[i-1][j-1];
        }
    }

    //구간 입력을 받자
    for(int testcase = 0; testcase < M; testcase++){
        int x_1,y_1,x_2,y_2;    cin >> y_1 >> x_1 >> y_2 >> x_2;
        cout << sum[y_2][x_2] - sum[y_1-1][x_2] - sum[y_2][x_1-1] + sum[y_1-1][x_1-1] << '\n';
    }
}
