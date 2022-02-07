## [백준 2493 : 탑](https://www.acmicpc.net/problem/2493)  
### 💡접근 과정  
- stack과 pair을 같이 사용하는 문제.  
![2493번 설명](https://github.com/euichanhwang/algorithm/blob/main/img/%EB%B0%B1%EC%A4%80%202493%EB%B2%88%20%EA%B7%B8%EB%A6%BC%20%EC%84%A4%EB%AA%85.jpg)  
- 탑의 꼭대기에 레이저 송신기가 있어, 왼쪽 방향으로 레이저를 발사한다.  
- 레이저 신호를 수신하는 탑의 번호를 출력하는데, 신호를 수신하는 탑이 없다면 0을 출력한다.
![스택을 이용한 풀이](https://github.com/euichanhwang/algorithm/blob/main/img/%EB%B0%B1%EC%A4%80%202493%EB%B2%88%20%EC%8A%A4%ED%83%9D%20%ED%92%80%EC%9D%B4.jpg)  
- 스택과 pair 을 이용해서, 높이와 index를 쌍으로 가지는 stack을 선언한다.  
- 탑의 높이가 1 이상 100,000,000 이하의 정수이므로 100,000,001의 높이,0번 인덱스를 스택에 먼저 삽입한다.  
- 입력된 탑의 높이가 더 낮을 경우, 원래 스택에 있던 인덱스를 출력한 후 입력된 <높이,인덱스>를 push한다.  
- 입력된 탑의 높이가 더 높을 경우, 원래 스택에 있던 인덱스를 출력한 후 <높이,인덱스>를 pop()한다.그 후 입력된 <높이,인덱스>를 push한다.    

```c++
stack<pair<int,int>> st; //height,idx
int number;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    st.push({100000001,0});
    cin >> number;
    for(int i=1;i<=number;i++) //탑의 번호는 1부터 시작
    {
        int height;
        cin >> height;
        while(st.top().X<height)
        {
            st.pop();
        }
        cout << st.top().Y <<" ";
        st.push({height,i});
    }
    return 0;
}

```
