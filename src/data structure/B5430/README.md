## [백준 5430 : AC](https://www.acmicpc.net/problem/5430)  
### 💡접근 과정  
- 양쪽 방향에서 원소의 삽입과 삭제가 가능한 deque 자료구조를 이용한 문제이다.  
- **[1,2,3,4]와 같은 입력을 deque에 `1 2 3 4`로 push하는 방법**  
```c++
void parse(string &tmp,deque<int> &d) //[1,2,3,4] -> 1 2 3 4로 deque 에 넣기
{
    int cur=0;
    for(int i=1;i+1<tmp.size();i++)
    {
        if(tmp[i]==',')
        {
            d.push_back(cur);
            cur=0;
        }
        else
            cur=10*cur+(tmp[i]-'0');
    }
    //[44] 같은 경우에는, 나중에 deque에 넣어준다. 
    if(cur!=0)
        d.push_back(cur);

}

```

