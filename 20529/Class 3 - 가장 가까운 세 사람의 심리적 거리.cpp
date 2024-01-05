#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

int caldist(string A, string B, string C){
    int totaldist = 0;
    for(int i=0; i<4; i++){
        totaldist += abs(A[i]-B[i]);
        totaldist += abs(A[i]-C[i]);
        totaldist += abs(B[i]-C[i]);
    }
    return totaldist;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int TC = 0; TC < T; TC++){
        int dist = 9999;
        vector<string> data;
        int N;
        cin >> N;
        for(int i=0; i<N; i++){
            string temp;
            cin >> temp;
            for(int j=0; j<4; j++){
                if(temp[j] == 'E' || temp[j] == 'S' || temp[j] == 'F' || temp[j] == 'P')
                    temp[j] = '1';
                else
                    temp[j] = '0';
            }
            data.push_back(temp);
        }
        if(N > 32){
            cout << 0 << "\n";
            continue;
        }
        for(int i=0; i<N-2; i++){
            for(int j=i+1; j<N-1; j++){
                for(int k=j+1; k<N; k++){
                    int current_dist = caldist(data[i], data[j], data[k]);
                    if(current_dist < dist)
                        dist = current_dist;
                }
            }
        }
        cout << dist << "\n";
    }
}