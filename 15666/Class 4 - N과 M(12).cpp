#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N,M;

vector<int> arr;
vector<int> make;

void dfs(int start, int count){
    if(count == M){
        for(int i=0; i<M; i++){
            cout << make[i] << ' ';
        }
        cout << "\n";
    }
    else{
        //각 열을 마다 pre_num을 지닌다.
        int pre_num = -1;
        for(int i=start; i<N; i++){
            //이번 열에서 읽었던 수는 2번 읽지 않는다.
            if(arr[i] == pre_num) {
                continue;
            }
            //처음 읽어들인 수라면 pre_num에 저장
            pre_num = arr[i];
            make[count] = arr[i];
            //진행할 때마다 사용 가능한 수를 1개씩 줄여나간다.
            dfs(i, count + 1);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        int temp;   cin >> temp;
        arr.push_back(temp);
        make.push_back(0);
    }
    sort(arr.begin(), arr.end());
    dfs(0,0);
}