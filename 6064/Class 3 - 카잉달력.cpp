#include <iostream>

using namespace std;

int gcd(int a, int b){
    int temp;
    while(b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b){
    return a*b / gcd(a,b);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;  cin >> T;
    for(int testcase = 0; testcase < T; testcase++){
        int N, M, x, y;
        cin >> N >> M >> x >> y;
        int x_ = 1;
        int y_ = 1;
        int standard = (x) % M;

        //<1,1>이 목표인 경우
        if(x_ == x && y_ == y){
            cout << 1 << "\n";
            continue;
        }
        //시작점이 <x,y>인 경우
        x_ = x;
        y_ = x % M;
        if(y_ == 0)
            y_ = M;
        int count = x;
        if(x_ == x && y_ == y){
            cout << count << "\n";
            continue;
        }
        //시작점이 2회이상 진행되야 하는 경우
        y_ = (y_ + N) % M;
        if(y_ == 0)
            y_ = M;
        count += N;
        if(x_ == x && y_ == y){
            cout << count << "\n";
            continue;
        }

        int except = lcm(N,M);
        while(y_ != standard){
            y_ = (y_ + N) % M;
            //나머지 연산으로 0이 되는 경우를 방지
            if(y_ == 0)
                y_ = M;
            count += N;
            if(y_ == y)
                break;
            if(count > except) {
                y_ = standard;
                break;
            }
        }
        if(y_ == standard)
            cout << "-1\n";
        else
            cout << count << "\n";
    }
}