## [백준 5430 : AC](https://www.acmicpc.net/problem/5430)  
### 💡접근 과정  
- 양쪽 방향에서 원소의 삽입과 삭제가 가능한 deque 자료구조를 이용한 문제이다.  
- **[1,2,3,4]와 같은 입력을 deque에 `1 2 3 4`로 push_back하는 방법=>일단 string으로 받은 후, ','를 기준으로 deque에 push_back 한다.**        
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
- **R 함수는 배열에 있는 수의 순서를 뒤집는 함수이고 ,D 함수는 첫번째 수를 버리는 함수이다.**  
- 배열이 뒤집혀져 있지 않다면 맨 처음 원소를 빼고(pop_front),뒤집혀져 있다면 맨 뒤의 원소를 빼준다(push_back).  
```c++
 for(auto c:func)
        {
            if(c=='R') //REVERSE
                rev=1-rev;
            else //D . DELETE
            {
                if(d.empty()) // 비어있다면 error 출력
                {
                    flag=true;
                    break;
                }
                else
                {

                    if(!rev) d.pop_front(); //안뒤집어져 있다면 맨처음에서 뺀다.
                    else d.pop_back(); //뒤집힌 상태라면 뒤에서 뺀다.
                }
            }
        }

```

