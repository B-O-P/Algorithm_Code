#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
vector<int> arr;
vector<int> make;
vector<bool> visit;
vector<int> pre_num(9,0);

void dfs(int start, int depth){
    if(depth == m){
        for(int i=0; i<m; i++){
            cout << make[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = start; i<n ;i++){
        if(arr[i] == pre_num[depth])
            continue;
        if(visit[i] == false) {
            make[depth] = arr[i];
            pre_num[depth] = arr[i];
            visit[i] = true;
        }
        else
            continue;
        dfs(0, depth + 1);
        pre_num[depth + 1] = 0;
        visit[i] = false;
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
    visit = vector<bool> (n,false);
    sort(arr.begin(), arr.end());

    dfs(0,0);
}