#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<int, char> pic;
#define X first
#define Y second
//if(nx<0||nx>=n||ny<0||ny>=m) continue;
string board[502];
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
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny]>=0||board[nx][ny]!='1')continue; //이미 방문했거나 1이 아니면 제외
            dist[nx][ny]=dist[cur.X][cur.Y]+1;
            q.push({nx,ny});
        }

    }
    cout << dist[n-1][m-1]+1;

    


    
 
   


    return 0;
}
