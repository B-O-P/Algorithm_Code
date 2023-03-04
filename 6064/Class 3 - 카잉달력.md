# Class 3 - 카잉 달력

### 문제 이해

입력으로 <M,N> (한계치) <x,y> (목표치)가 들어온다

```cpp
10 12 3 9
```

|  | x | y |
| --- | --- | --- |
| 1번째 | 1 | 1 |
| 2번째 | 2 | 2 |
| 3번째 | 3 | 3 |
| …번째 | … | … |
| 10번째 | 10 | 10 |
| 11번째 | 1 | 11 |
| 12번째 | 2 | 12 |
| 13번째 | 3 | 1 |
| 14번째 | 4 | 2 |
| 15번째 | 5 | 3 |

이런 식으로 진행된다. 

### **즉 < x, y > 에서 x가 m에 도착하면 1로 돌아가고 y가 n에 도착하면 1로 돌아간다.**

그렇다면 x에 해당하는 y의 영역(값)이 있지 않을까?

|  | x | y |
| --- | --- | --- |
| 3번째 | 3 | 3 |
| 13번째 | 3 | 1 |
| 23번째 | 3 | 11 |
| 33번째 | 3 | 9 |
| 43번째 | 3 | 7 |
| 53번째 | 3 | 5 |
| 63번째 | 3 | 3 |

```cpp
10 12 7 2
```

|  | x | y |
| --- | --- | --- |
| 7번째 | 7 | 7 |
| 17번째 | 7 | 5 |
| 27번째 | 7 | 3 |
| 37번째 | 7 | 1 |
| 47번째 | 7 | 11 |
| 57번째 | 7 | 9 |
| 67번째 | 7 | 7 |

```cpp
13 11 5 6
```

|  | x | y |
| --- | --- | --- |
| 5번째 | 5 | 5 |
| 18번째 | 5 | 7 |
| 31번째 | 5 | 9 |
| 44번째 | 5 | 11 |
| 57번째 | 5 | 2 |
| 70번째 | 5 | 4 |
| 83번째 | 5 | 6 |

### 문제의 설명에 <M:N>은 그들 달력의 마지막 해로서, 이 해에 세상의 종말이 도래한다는 예언이 전해 온다.

즉 <10,12>가 <M,N>이면 <10,12>이후로 더 이상 진행할 수 없다가 힌트이다.

### 최대로 진행할 수 있는 해의 수는 M과 N의 최소공배수이다.

M,N의 최소공배수를 넘어서는 경우 예외처리로 -1을 출력해야 한다.

---

## 구현

```cpp
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
```