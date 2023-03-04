# Class 3 - 절댓값 힙

## 1차 문제 접근

XX 힙이라고 해서 우선순위 큐로 접근해야 겠다고 생각했다.

생각보다 간단했다.

-1이든 1이든 절댓값으로 보면 1이니 우선순위 큐에 1을 넣어주면 됐다. 그리고 출력은 절댓값이 작은순이니 priority_queue에서 비교연산자가 greater를 쓰면 됐다.

그리고 절댓값이 같은경우 입력값이 작은 순으로 출력해야하기 때문에 같이 저장해주기 위해 원소 타입이 pair<int,int>를 사용해서 pair<절댓값, 입력값>순으로 저장했다. 

그리고 정렬은

```cpp
if(절댓값이 같다면){
    return 입력값이 작은 순;
else{
    return 절댓값이 작은 순;
}
```

---

## 2차 문제 접근

![Untitled](Class%203%20-%20%E1%84%8C%E1%85%A5%E1%86%AF%E1%84%83%E1%85%A2%E1%86%BA%E1%84%80%E1%85%A1%E1%86%B9%20%E1%84%92%E1%85%B5%E1%86%B8%20e26256dffedb4594a3207a48e69180f7/Untitled.png)

이렇게 처리하고 나니 시간제한이 1000ms였는데 912ms로 겨우 통과했다.

```cpp
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
```

이 구문만 추가해줘도 시간이 기하급수적으로 줄었다. 

앞으로 입력이 크고 출력이 많은 문제는 꼭 넣어줘야겠다…

![Untitled](Class%203%20-%20%E1%84%8C%E1%85%A5%E1%86%AF%E1%84%83%E1%85%A2%E1%86%BA%E1%84%80%E1%85%A1%E1%86%B9%20%E1%84%92%E1%85%B5%E1%86%B8%20e26256dffedb4594a3207a48e69180f7/Untitled%201.png)

---

## 구현

```cpp
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
```