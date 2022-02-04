## [백준 1406 : 에디터](https://www.acmicpc.net/problem/1406)  
### 💡접근 과정  
- 이중 연결리스트를 이용한 문제이며,c++에는 list라는 stl로 구현되어 있다.
- list의 insert와 erase함수를 활용한다.
- list의 iterator는 주소로 현재 가리키고 있는 원소의 위치를 저장할 수 있다.
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
