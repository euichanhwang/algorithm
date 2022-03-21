## [백준 17086 : 아기 상어 2](https://www.acmicpc.net/problem/17086)  
### 💡접근 방법 : bfs 기본 문제 
- 상어의 위치를 모두 큐에 저장한 후, bfs를 이용해 안전 거리를 구하면 되는 문제이다.  
- 상어에서의 각 칸의 위치를 모두 구한 후 , for문으로 배열 전체를 돌면서 안전 거리의 최댓값을 구한다.  
 ### 💡TC : 상어는 1, 빈 칸은 0으로 표시  
5 4  
0 0 1 0  
0 0 0 0  
1 0 0 0  
0 0 0 0  
0 0 0 1  
일 때, 상어의 위치를 큐에 넣은 후 거리를 나타내는 dist배열을 0으로 초기화하면 다음과 같다.  
-1-1 0-1  
-1-1-1-1  
 0-1-1-1  
-1-1-1-1  
-1-1-1 0  
이 상태에서, 각각의 상어 좌표에 대한 bfs를 구현하면 다음과 같다.  
2 1 0 1  
1 1 1 1  
0 1 2 2  
1 1 1 1  
2 2 1 0  
마지막으로, 배열을 순회하면서 최댓값을 구한다. 최댓값이 곧 안전 거리이다.  
```c++
queue<pii> q;
    memset(dist,-1,sizeof(dist));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1){ //아기 상어가 있는 칸
                q.push({i,j});
                dist[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        auto cur=q.front();q.pop();
        for(int dir=0;dir<8;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny]>=0)continue;
            dist[nx][ny]=dist[cur.X][cur.Y]+1;
            q.push({nx,ny});
        }
    }
    int max=-0x7f7f7f7f;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j]>=max)
                max=dist[i][j];
        }
     
    }
    cout << max;


```



