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
int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int num=0; // 그림의 개수
    int mx=0; // 가장 넓은 그림의 넓이

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(vis[i][j]||board[i][j]==0)continue; // 방문했거나 0번인 경우는 제외
            num++;
            int area=0;
            queue<pii> q;
            q.push({i,j});
            vis[i][j]=1;

            while (!q.empty())
            {
                area++;
                pii cur=q.front(); q.pop();
                for(int dir=0;dir<4;dir++)
                {
                    int nx=cur.X+dx[dir];
                    int ny=cur.Y+dy[dir];
                    if(nx<0||nx>=n||ny<0||ny>=m)continue; //범위 안
                    if(vis[nx][ny]||board[nx][ny]==0)continue; // 이미 방문했거나 0인경우
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
            mx=max(mx,area);
        }
    }
    cout << num << '\n' << mx;

    return 0;
}
