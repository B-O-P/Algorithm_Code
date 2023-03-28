#include <iostream>

using namespace std;

int A,B,C;

long long divide_and_conquer(long long factor){
    if(factor == 1)
        return A % C;
    //모듈러 성질
    // (A * B) % C = (A % C * B % C) % C
    //지수 법칙
    // A ^ (M+N) = A^N * A^M
    //log n의 풀이를 위해서는 지수가 반씩 나눠저야 한다.
    long long mid_value = divide_and_conquer(factor / 2) % C;

    //지수를 반으로 나눴으니 두번 곱해줘야 한다.
    if(factor % 2 == 0)
        return mid_value * mid_value % C;
    //홀수라면 A하나가 남는다.
    else
        return mid_value * mid_value % C * A % C;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    cout << divide_and_conquer(B);
}