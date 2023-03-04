#include <iostream>
#include <vector>

using namespace std;

const int INF = 1 << 29;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;  cin >> N;

    vector<vector<int>> arr(N+1, vector<int>(N+1, INF));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int temp;   cin >> temp;
            if(temp == 1)
                arr[i][j] = temp;
        }
    }

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N ;j++){
            if(arr[i][j] == INF){
                cout << "0 ";
            }
            else
                cout << "1 ";
        }
        cout << "\n";
    }
    return 0;

}