#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;  cin >> N;
    vector<vector<int>> arr(N+1, vector<int> (3));
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }
    //r,g,b순으로 저장하자
    vector<vector<int>> ans(N+1, vector<int> (3));
    ans[0][0] = arr[0][0];
    ans[0][1] = arr[0][1];
    ans[0][2] = arr[0][2];

    for(int i=1; i<N; i++){
        ans[i][0] = min(ans[i-1][1], ans[i-1][2]) + arr[i][0];
        ans[i][1] = min(ans[i-1][0], ans[i-1][2]) + arr[i][1];
        ans[i][2] = min(ans[i-1][0], ans[i-1][1]) + arr[i][2];
    }
    cout << *min_element(ans[N-1].begin(),ans[N-1].end());
}