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
const int MX = 1502;
char board[MX][MX];
bool vis[MX][MX];
int meltingDay[MX][MX];
vector<pair<int, int>> swan; // 백조의 좌표
int maxDay = 0; // 얼음이 녹는 데 걸리는 최대 일
int r, c;
/**
 *  얼음에 녹는 날짜를 체크한 후 BFS를 돌리면 ? O(1499 * R * C)
 *  이분 탐색을 이용해서 O(log₂1499 * R * C = 약 (10) * R * C ) 에 해결 가능.
 */
bool canMeetSwan(int day) {
    memset(vis, false, sizeof(vis));
    queue<pair<int,int>> q;
    q.push({swan[0].first,swan[0].second});
    vis[swan[0].first][swan[0].second] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        if (swan[1].first == cur.X && swan[1].second == cur.Y ) {
            return true;
        }
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 1 || ny < 1 || nx > r || ny > c) continue;
            if (vis[nx][ny] || meltingDay[nx][ny] > day) continue;
            q.push({nx,ny});
            vis[nx][ny] = 1;
        }
    }
    return false;
}

// 1일차에 녹일 수 있는 얼음은 1, 2일차에 녹일 수 있는 얼음은 2... 로 마킹
void meltingIce() {
    memset(meltingDay, -1, sizeof(meltingDay));
    queue<pair<int, int>> q;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (board[i][j] == '.' || board[i][j] == 'L') {
                meltingDay[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 1 || ny < 1 || nx > r || ny > c) continue;
            if (meltingDay[nx][ny] >= 0) continue;
            q.push({nx, ny});
            meltingDay[nx][ny] = meltingDay[cur.X][cur.Y] + 1;
            if (maxDay < meltingDay[nx][ny]) maxDay = meltingDay[nx][ny];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'L') swan.push_back({i, j});
        }
    }
    meltingIce();
    // Binary Search
    int start = 0; int end = maxDay;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (canMeetSwan(mid)) end = mid - 1;
        else start = mid + 1;
    }
    cout << start;
    return 0;
}