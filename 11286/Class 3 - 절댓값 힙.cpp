#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first > b.first;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;  cin >> N;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> min_heap;
    for(int i=0; i<N; i++){
        int input;  cin >> input;
        if(input == 0){
            if(min_heap.size() == 0)
                cout << 0 << "\n";
            else {
                cout << min_heap.top().second << "\n";
                min_heap.pop();
            }
        }
        else{
            min_heap.push(make_pair(abs(input),input));
        }
    }
    return 0;
}