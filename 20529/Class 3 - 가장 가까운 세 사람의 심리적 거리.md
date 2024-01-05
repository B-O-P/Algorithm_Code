문제 링크 : https://www.acmicpc.net/problem/20529

<hr>

### 접근 1

`ESTJ`와 `INFP`의 거리를 구한다고 한다면 4이다.
4인 이유는 E와 I, S와 N, T와 F, J와 P는 각각 거리가 1이기 때문이다.
즉 입력 당시에 `ESTJ`를 `1111` `INFP`를 `0000`로 봐도 무방하다는 것이다.

그리고 문자열을 숫자로 변환 없이 바로 빼도 상관이 없다.
`1`역시 `ASCII`로 변환 시 48이 더해져 있고 `0`역시 48이 더해져 있기 때문에 문자열을 빼도 0과 1을 숫자로 계산한 것과 똑같은 결과를 받을 수 있다.

#### 입력
```c++
//data에 입력을 저장합니다.
vector<string> data;

for(int i=0; i<N; i++){
	string temp;
	cin >> temp;
	for(int j=0; j<4; j++){
	//입력을 0혹은 1로 변환해서 저장합니다.
		if(temp[j] == 'E' || temp[j] == 'S' || temp[j] == 'F' || temp[j] == 'P')
			temp[j] = '1';
		else
			temp[j] = '0';
	}
	data.push_back(temp);
}
```

#### 입력에 대한 거리 계산
```c++
int caldist(string A, string B, string C){
    int totaldist = 0;
    for(int i=0; i<4; i++){
    //바로 거리 계산을 해도 상기된 이유로 상관이 없다.
        totaldist += abs(A[i]-B[i]);
        totaldist += abs(A[i]-C[i]);
        totaldist += abs(B[i]-C[i]);
    }
    return totaldist;
}
```

### 접근 2

브루트포스로 모든 거리를 계산한다면 최대 입력이 $10^5$이니 연산량이 $10^15$이다. 당연히 시간초과이다.

하지만 생각해보자
가위,바위,보를 하는데 4번을 한다면 반드시 1번은 겹치는 수가 나온다.
가위,바위,보를 하는데 7번을 한다면 반드시 2번은 겹치는, 즉 3번 나오는 수가 나온다.

범위를 이 문제까지 넓혀서 본다면 MBTI는 각각의 항이 2개로 구성되니 $2^4$개의 경우의 수가 존재한다.
총 16가지의 경우의 수가 있는데 만약 17번의 입력을 받는다면 반드시 1번은 겹치는 수가 나온다.
33번의 입력을 받는다면 반드시 2번 겹치는, 즉 3번 나오는 경우의 수가 존재하고 이 때 세 사람의 심리적 거리는 당연히 0이다.

브루트포스로 계산은 하되 입력의 개수가 32를 넘어선다면 어차피 결과는 0이니 계산 할 필요가 없다.

### Code.
```c++
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
        int N;
        cin >> N;
        vector<string> data;
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
```
