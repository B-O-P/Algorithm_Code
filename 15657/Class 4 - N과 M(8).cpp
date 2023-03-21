#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
vector<int> arr;
vector<int> make;
vector<vector<int>> ans;

void dfs(int start, int depth){
    if(depth == m){
        ans.push_back(make);
        return;
    }
    for(int i = start; i<n ;i++){
        make[depth] = arr[i];
        dfs(i, depth + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for(int i=0; i<n; i++){
        int temp;   cin >> temp;
        arr.push_back(temp);
        make.push_back(0);
    }
    sort(arr.begin(), arr.end());
    dfs(0,0);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<m; j++){
            cout << ans[i][j] << ' ';
        }
        cout << "\n";
    }
}

