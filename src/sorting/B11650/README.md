## [백준 11650 : 좌표 정렬하기](https://www.acmicpc.net/problem/11650)  
### 💡접근 과정  
- pair을 사용해서 sort를 진행하면 되는 문제이다.  
- 페어의 경우 sort함수 자체에서 first가 같으면, second로 비교하게끔 sort함수에서 구현이 되어있다.  
```c++
vector<pii> v;
int number;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> number;
    pair<int,int> temp;
    for(int i=0;i<number;i++)
    {
        cin>>temp.first >> temp.second;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<number;i++)
    {
        cout <<v[i].first << " " << v[i].second << '\n';
    }
    

    return 0;
}
```
