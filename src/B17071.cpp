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
int INF = 1e9 + 7;
//512MB = 1.2억개 int
//if(nx<0||nx>=n||ny<0||ny>=m) continue;
/*int dz[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={0,0,0,0,1,-1};*/ // 3차원 bfs
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n,k;
const int MX = 500000;
int vis[2][MX+2]; // vis[0][MX+2] 라면 짝수 초에 방문. vis[1][MX+2] 라면 홀수 초에 방문

// 수빈이가 짝수(홀수) 초에 n에 방문하고, 동생이 홀수(짝수) 초에 n에 방문하면 서로 만날 수 없음
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    queue<pair<int,int>> q;
    q.push({n,0}); // 위치, 시간
    vis[0][n] = 1;

    while (!q.empty()) {
        int now = q.front().first;
        int time = q.front().second;
        int pos = k + time * (time + 1) / 2;
        q.pop();

        if (pos > MX) {
            cout << -1;
            break;
        }

        if (now == pos || vis[time%2][pos]) {
            cout << time;
            break;
        }

        for (int nxt : {now-1, now+1, 2*now}) {
            if (nxt < 0 || nxt > MX) continue;
            if (vis[(time+1)%2][nxt]) continue;
            vis[(time+1)%2][nxt] = 1;
            q.push({nxt,time+1});
        }
    }

    return 0;
}