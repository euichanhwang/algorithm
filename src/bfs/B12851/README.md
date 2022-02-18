## [백준 12851: 숨바꼭질2](https://www.acmicpc.net/problem/12851)  
### 💡접근 과정 : bfs응용- 가중치가 동일하기 때문에 bfs를 이용할 수 있는 문제.  
- 0-1bfs와는 다르게 가중치가 동일하므로 bfs를 이용할 수 있다.  
- <위치,시간>을 저장할 큐를 통해 구현한다.  
- **큐에서 pop()할 때 방문배열을 true로 체크해서 방문지점을 표시하면 구현 가능하다.**  
### TC: N=1, K=4
수빈이의 위치를 1, 동생의 위치를 4라고 할 때 **1(+1)=2, 2(×2)=4 인 방법과, 1(×2)=2,2(×2)=4** 인 두가지 방법이 존재하며, 가장 빠른 시간도 2이다.  
vis배열을 방문했을 때 true를 대입한 것을 그림상에서 1을 표시한 것으로 표현하였다.  
![큐에 담기는 순서](https://github.com/euichanhwang/algorithm/blob/main/img/%EB%B0%B1%EC%A4%80%2012851%EB%B2%88%20%EC%88%A8%EB%B0%94%EA%BC%AD%EC%A7%88%20%ED%81%90%EC%97%90%20%EB%8B%B4%EA%B8%B0%EB%8A%94%20%EC%88%9C%EC%84%9C.jpg)  
```c++
 cin >> n >> k;
    queue<pii> q; //위치,시간
    q.push({n,0});
    int ans=0;//가장 빠른 시간
    int cnt=0;//찾는 방법의 수 
    while(!q.empty())
    {
        int now=q.front().first; //현재 위치
        int time=q.front().second; //시간
        q.pop();
        vis[now]=true;
        //처음 찾았을 때
        if(!cnt&&now==k)
        {
            ans=time;
            cnt++;
        }
        //그 이후에 찾았을 때
        else if(cnt&&now==k&&ans==time)
            cnt++;    


        for(int nxt:{now-1,now+1,2*now})
        {
            if(nxt<0||nxt>100000)continue;
            if(!vis[nxt])
            {
                q.push({nxt,time+1});
            }
        }
    }
    cout << ans << '\n';
    cout << cnt << '\n';
```




