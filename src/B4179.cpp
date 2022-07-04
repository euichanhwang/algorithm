#include <bits/stdc++.h>
using namespace std;
typedef long long ll;  //-2^63 ~ 2^63-1
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<int, char> pic;
//512MB = 1.2억개 int
//if(nx<0||nx>=n||ny<0||ny>=m) continue;
/*int dz[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={0,0,0,0,1,-1};*/ // 3차원 bfs용
#define X first
#define Y second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int r,c;
string board[1002];
int dist1[1002][1002]; //불에 대한 dist1배열
int dist2[1002][1002]; //지훈이에 대한 dist2배열
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c;
    for(int i=0;i<r;i++){
        cin >> board[i];
    }
    for(int i=0;i<r;i++)
    {
        fill(dist1[i],dist1[i]+c,-1);
        fill(dist2[i],dist2[i]+c,-1);
    }
    queue<pii> q1;
    queue<pii> q2;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j]=='F')//불일 경우
            {
                dist1[i][j]=0;
                q1.push({i,j});
            }
            if(board[i][j]=='J')//지훈이일 경우
            {
                dist2[i][j]=0;
                q2.push({i,j});
            }
        }
    }
    //불에 대한 bfs
    while(!q1.empty())
    {
        auto cur=q1.front();q1.pop();
        for(int dir=0;dir<4;dir++)
        {
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||nx>=r||ny<0||ny>=c) continue;
            if(dist1[nx][ny]>=0||board[nx][ny]=='#')continue;
            dist1[nx][ny]=dist1[cur.X][cur.Y]+1;
            q1.push({nx,ny});
        }
    }
    //지훈이에 대한 bfs
    while(!q2.empty())
    {
        auto cur=q2.front();q2.pop();
        for(int dir=0;dir<4;dir++)
        {
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||nx>=r||ny<0||ny>=c) //탈출에 성공했다
            {
                cout << dist2[cur.X][cur.Y]+1;
                return 0;
            }
            if(dist2[nx][ny]>=0||board[nx][ny]=='#')continue;
            if(dist1[nx][ny]!=-1&&dist1[nx][ny]<=dist2[cur.X][cur.Y]+1) continue; //불의 전파조건
            dist2[nx][ny]=dist2[cur.X][cur.Y]+1;
            q2.push({nx,ny});
        }
    }
    cout <<"IMPOSSIBLE";

}