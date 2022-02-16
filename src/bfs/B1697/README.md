## [백준 1697: 숨바꼭질](https://www.acmicpc.net/problem/1697)  
### 💡접근 과정 : bfs응용-1차원 배열에서의 bfs  
- 수빈이가 X에 있었다고 하면 ,X-1,X+1,2X로 이동하는 것을 bfs로 처리할 수 있다.  
- 5에서 시작했다고 하면 4,6,10을 1로 저장한다.  
- 그 다음에서는 4가 선택되고, 3,5,8을 선택하는데 5는 이미 값이 써져있으니 3,8만 2로 저장한다.  
- 이런식으로 진행하다가, 동생이 있는 위치에 값이 써지게 되면 답을 구할 수 있다.  
```c++
 ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    fill(dist,dist+100001,-1);
    dist[n]=0;
    queue<int> q;
    q.push(n);
    while(dist[k]==-1)
    {
        auto cur=q.front();q.pop();
        for(int nxt:{cur-1,cur+1,2*cur})
        {
            if(nxt<0||nxt>100000)continue;
            if(dist[nxt]!=-1)continue; //이미 방문함.
            dist[nxt]=dist[cur]+1;
            q.push(nxt);
        }
    }
    cout << dist[k];
```


