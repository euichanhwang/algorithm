## [백준 11729번 : 하노이 탑 이동 순서](https://www.acmicpc.net/problem/11729)
### 💡접근 과정
**재귀를 이용한 대표적인 예제이다.재귀호출 시에는**
- 재귀호출 할 때 인자는 반드시 규모를 줄이도록 변화시킨다.  
- 재귀호출 없이 해결할 수 있는 최소문제를 결정한다. => 이때 답을 바로 반환한다.  
### 하노이 탑 문제
![하노이 탑의 이동순서](https://github.com/euichanhwang/algorithm/blob/main/img/%ED%95%98%EB%85%B8%EC%9D%B4%20%ED%83%91%EC%9D%98%20%EC%9D%B4%EB%8F%99%EC%88%9C%EC%84%9C.png)  
**3개의 탑이 준비되어있고, 첫번째 탑에 크기가 다른 여러개의 원판이 쌓여져 있다. 이 원판을 모두 c 탑으로 옮긴다.**  
- 원반은 한 번에 하나씩만 옮길 수 있다.  
- 옮기는 과정에서 작은 원반의 위에 큰 원반이 올려져서는 안된다.  
### 재귀적으로 해결하기
                                                         
```c++
void hanoi(int n,int start, int mid, int end) {
    //출력문으로 옮기는 작업을 시뮬레이션
    if (n == 1) {
        cout << start << " " << end<< "\n";
    }
    else {
        hanoi(n-1,start,end,mid); // 처음에서 중간을 보내고 중간을 경유지로 사용
        cout << start << " " << end << "\n";
        hanoi(n-1,mid,start,end); // 경우지에 있던것을 마지막으로 옮김. 그 때 경유지로 중간 사용
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cout << (int)pow(2, n) - 1 << '\n';
    hanoi(n,1,2,3);
}

```  

