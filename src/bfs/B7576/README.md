## [백준 7576 : 토마토](https://www.acmicpc.net/problem/7576)  
### 💡bfs응용 : 시작점이 여러개일 때  
- 시작점이 여러개인 bfs를 구현할 때는, **모든 시작점을 큐에 넣고 bfs를 돌리면 된다.**    
- 익은 토마토인 경우와 토마토가 비어있을 때, dist배열을 0을 넣어주고 익지 않은 토마토인 경우 dist배열에 -1을 넣어준다.  
- 익은 토마토인 경우 큐에 넣고 bfs를 돌린다. 이때, bfs를 다 돌렸는데 -1인 원소가 dist배열에 있다면, 토마토가 모두 익지 못하는 상황이다.  
```c++

    queue<pii> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1)// 익은 토마토인경우
            {
                dist[i][j]=0;
                q.push({i,j}); //여기서부터 시작한다.

            }
            if(board[i][j]==0)// 익지않은 토마토인경우
            {
                dist[i][j]=-1;
            }
        }
    }
    //익은 토마토와 토마토가 없을 때 는 0, 익지 않은 토마토일때는 -1이 들어간다.
    while(!q.empty())
    {
        auto cur=q.front();q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny]>=0)continue;
            dist[nx][ny]=dist[cur.X][cur.Y]+1;
            q.push({nx,ny});
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            if(dist[i][j]==-1) //bfs를 다 돌았는데 익지 않은 토마토가 있다면
            {
                cout << -1;
                return 0;
            }
            ans=max(ans,dist[i][j]);
        }
    }
    cout << ans;
```  




