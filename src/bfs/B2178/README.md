## [백준 2178 : 미로](https://www.acmicpc.net/problem/2178)  
### 💡접근 과정  
- 거리를 저장할 dist라는 이차원 배열을 만든 후, fill 함수를 이용해서 전부 -1로 초기화한다.  
- 시작점(0,0)에 0을 대입한 후, 미로의 상하좌우 거리에 따라 값을 +1 시킨다.  
- ** bfs 구현 시이미 방문했거나(dist배열의 값이 0 이상), 원본 배열의 값이 '1'이 아닐 경우에는 제외시킨다.**  
```c++
string board[502]; //미로를 string 배열에 저장
int dist[502][502];
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n; i++)
    {
        cin >> board[i];
        fill(dist[i],dist[i+m],-1);
    }
    queue<pii> q;
    dist[0][0]=0;
    q.push({0,0});
    while(!q.empty())
    {
        pii cur=q.front(); q.pop();
        for(int dir=0;dir<4;dir++)
        {
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue; //범위에 들어가지 않으면 제외
            if(dist[nx][ny]>=0||board[nx][ny]!='1')continue; //이미 방문했거나 1이 아니면 제외
            dist[nx][ny]=dist[cur.X][cur.Y]+1;
            q.push({nx,ny});
        }

    }
    cout << dist[n-1][m-1]+1;


```


