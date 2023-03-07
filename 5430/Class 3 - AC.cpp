//
// Created by brewers on 2023-03-07.
//
#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;  cin >> T;
    for(int testcase = 0; testcase < T; testcase++){
        string order;   cin >> order;
        int N;  cin >> N;
        string input_arr;   cin >> input_arr;

        deque<int> arr;
        //input_arr부터 처리해보자
        for(int i=0; i<input_arr.size(); i++){
            //숫자라면 덱에 삽입
            //숫자가 한 자리수가 아닐 수 있음
            string count;
            while(int(input_arr[i])-48 >=0 && int(input_arr[i])-48 < 10){
                count += input_arr[i];
                i++;
            }
            if(count.size() != 0)
                arr.push_back(stoi(count));
        }

        //사용가능한 연산은 r과 d가 있다.
        //is_right가 true라면 D연산시 pop_front()
        //is_right가 false라면 D연산시 pop_back()
        bool is_break = false;
        bool is_right = true;
        for(int i=0; i<order.size(); i++){
            if(is_break) {
                cout << "error\n";
                break;
            }
            if(order[i] == 'R') {
                if (is_right)
                    is_right = !is_right;
                else
                    is_right = true;
            }

            if(order[i] == 'D'){
                //크기가 0인데 D를 만나면 오류,분기처리 해야
                if(arr.size() == 0){
                    is_break = true;
                }
                if(is_right)
                    arr.pop_front();
                else
                    arr.pop_back();
            }
        }

        //오류 없이 진행됐다면
        if(!is_break){
            //is_right가 true라면 출력시 앞에서부터
            //is_right가 false라면 출력시 뒤에서부터
            cout << "[";
            if(is_right){
                for(int i=0; i<arr.size(); i++){
                    cout << arr[i];
                    if (i != arr.size() - 1)
                        cout << ',';
                }
            }
            else{
                for(int i=arr.size()-1; i>=0; i--){
                    cout << arr[i];
                    if(i != 0)
                        cout << ',';
                }
            }
            cout << "]\n";
        }
        else{
            cout << "error\n";
        }
    }

    return 0;
}