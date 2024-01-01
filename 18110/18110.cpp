#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int N;  cin >> N;
    if(N == 0){
        cout << "0";
        return 0;
    }
    vector<int> score(N,0);
    for(int i=0; i<N; i++){
        int temp;   cin >> temp;
        score[i] = temp;
    }
    float fifteen = N * 0.15;
    int R = round(fifteen);

    sort(score.begin(), score.end());
    score.erase(score.begin(), score.begin() + R);
    score.erase(score.end() - R, score.end());

    float sum = 0;
    for(auto s : score){
        sum += s;
    }

    cout << round(sum / (N - (2 * R)));
}