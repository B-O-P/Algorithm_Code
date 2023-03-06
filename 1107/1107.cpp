#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

bool can_press(int N, vector<bool> &broken){
    string target = to_string(N);
    for(auto i : target){
        if(!broken[int(i) - 48]){
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //이동하려고 하는 채널
    int N;  cin >> N;

    //고장난 버튼의 개수
    int M;  cin >> M;
    vector<bool> broken(10, true);
    for(int i=0; i<M; i++) {
        int temp;   cin >> temp;
        broken[temp] = false;
    }

    //+,-만 누르는 경우
    int brute = abs(N-100);

    //100이면 뭐 할것도 없다
    if(N == 100){
        cout << "0";
        return 0;
    }

    //N에 바로 도착할 수 있다면
    bool can_make_n = true;
    string temp = to_string(N);
    if(!can_press(N,broken))
        can_make_n = false;

    //N에 바로 도착할 수 없다면
    if(!can_make_n) {
        //입력값 보다 큰 경우
        int over = 429496729;
        for (int i = N + 1; i < 1000000; i++) {
            if(can_press(i,broken)){
                over = i;
                break;
            }
        }

        //입력값 보다 작은 경우
        int under = 429496729;
        for (int i = N - 1; i >= 0; i--) {
            if (can_press(i,broken)) {
                under = i;
                break;
            }
        }

        //큰 경우 눌러야 할 버튼의 수
        int over_press = 0;
        over_press += to_string(over).size();
        over_press += abs(N - over);

        //작은 경우 눌려야 할 버튼의 수
        int under_press = 0;
        under_press += to_string(under).size();
        under_press += abs(N - under);
        int press_min = min(over_press, under_press);

        cout << min(press_min,brute);
        return 0;
    }

    //N을 만들 수 있는 경우의 비교
    cout << min(int(to_string(N).size()), brute);
    return 0;
}