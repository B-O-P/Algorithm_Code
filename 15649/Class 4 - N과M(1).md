# Class 4 - N과 M(1)

## 문제 링크

[15649번: N과 M (1)](https://www.acmicpc.net/problem/15649)

## 문제

자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

- 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

## 입력

첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

## 출력

한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

## 예제 입력 1

```
3 1
```

## 예제 출력 1

```
1
2
3
```

## 예제 입력 2

```
4 2
```

## 예제 출력 2

```
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3
```

## 예제 입력 3

```
4 4
```

## 예제 출력 3

```
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1
```

## 문제 풀이

1. 중복을 허용하지 않는다.
    1. 이걸 해결하려면 visit배열이 필요하다.
2. (1,2) (2,1)을 다른 순열로 본다.
    1. visit = true가 아니라면 arr의 요소를 다시 사용해도 된다.

### N,M이 각각 4와 2인 경우를 보자

- index는 make[]의 index이다.
- visit은 visit[]의 상태 변화이다.

|  | index_0 | index_1 | visit_0 | visit_1 | visit_2 | visit_3 |
| --- | --- | --- | --- | --- | --- | --- |
| try_1 | 1 | 0(초기값) | T | F | F | F |
| try_2 | 1 | 2 | T | T | F | F |
| try_3 | 1 | 3 | T | F | T | F |
| try_4 | 1 | 4 | T | F | F | T |
| try_5 | 1 | 4 | T | F | F | F |
| try_6 | 1 | 4 | F | F | F | F |
| try_7(push x) | 2 | 4 | F | T | F | F |
| try_8 | 2  | 1 | T | T | F | F |
| try_9 | 2  | 3  | F | T | T | F |
- arr배열 : 수열 제작에 사용할 수를 저장한다.
- make배열 : arr배열에서 수를 불러와 저장한다.
- dfs함수의 인자는 (현재 위치, 진행된 깊이)이다.
- 현재 위치(at)는 make배열의 인덱스를 제어하는 것이다.

---

### N,M이 각각 4와 2인 경우를 보자

현재 위치가 0이고 깊이가 0이라면

```cpp
visit[0]가 false이니 make[depth] = arr[0]를 진행한다.
visit[0]를 true처리 한다.
dfs를 실행한다.
visit[0] = false처리한다.
//여기까지만 해도 위의 table의 try_6까지가 진행된다.

visit[1]가 false이니 make[depth] = arr[1]를 진행한다.
visit[1]를 true처리 한다.
dfs를 실행한다.
visit[1] = false처리한다.

visit[2]가 false이니 make[depth] = arr[2]를 진행한다.
visit[2]를 true처리 한다.
dfs를 실행한다.
visit[2] = false처리한다.

visit[3]가 false이니 make[depth] = arr[3]를 진행한다.
visit[3]를 true처리 한다.
dfs를 실행한다.
visit[3] = false처리한다.
```

위의 경우가 2자리중 첫번째 자리가 돌아가는 경우이다.

### 그렇다면 각 dfs안에서 또 일어나는 일은?

```cpp
visit[0]가 true이니 continue → i++만 실행된다.

visit[1]이 false이니 make[depth] = arr[1]을 진행한다.
visit[1]을 true처리한다.
dfs를 실행한다.
visit[1]을 false처리한다.

visit[2]가 false이니 make[depth] = arr[2]를 진행한다.
visit[2]를 true처리한다.
dfs를 실행한다.
visit[2]를 false처리한다.

...
```

### 그럼 그 다음 dfs에서는?

```cpp
이제 if(depth == m)이 충족된다.
현재의 make[]를 ans[][]에 push_back해준다.
//[] -> 1차월 배열
//[][] -> 2차월 배열
```

### (4,2)의 경우 진행과정

![mermaid-diagram-2023-03-20-150904.png](Class%204%20-%20N%E1%84%80%E1%85%AA%20M(1)%20b65f95d3b85d47fa9017753758875601/mermaid-diagram-2023-03-20-150904.png)