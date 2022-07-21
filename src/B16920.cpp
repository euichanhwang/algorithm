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
int n,m,p; // n은 행, m은 열, p는 플레이어의 수
int arr[10]; // 플레이어 당 확장할 수 있는 칸의 수
int area[10]; // 플레이어가 확장한 영토의 크기
int board[1002][1002]; // 게임판
queue<tuple<int,int,int>> q[10]; // 좌표 , 현재 이동한 칸 수
/**
 * 1 <= 플레이어 <= 9
 * 각 라운드마다 플레이어는 자기 턴이 돌아올 때 마다 성을 확장해야 함. 플레이어 1, 플레이어 2, .... 플레이어 9
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++)
        cin >> arr[i];

    // 게임판에 초기 상태 입력
    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cin >> ch;
          if (ch == '.' ) { // 빈 칸
              board[i][j] = 1;
          }
          else if (ch == '#') { // 벽
              board[i][j] = 0;
          }
          else { // 성 시작
              board[i][j] = 0;
              q[ch - '0'].push({i,j,0});
              area[ch - '0'] += 1;
          }
        }
    }

    // 확장 게임 시작
    // 플레이어 1, 플레이어 2, 플레이어 3.. 플레이어 9 -> 플레이어 1 순서대로 진행
    while (1) {
        bool isExtend = 0;
        queue<tuple<int, int, int>> nextq; // 다음 턴의 이동을 큐로 나타냄
        for (int i = 1; i <= p; i++) {
            while(!q[i].empty()) {
                int curX, curY, curStep;
                tie(curX, curY, curStep) = q[i].front();
                q[i].pop();
                if (curStep >= arr[i]) {
                    nextq.push({curX, curY, 0});
                    continue;
                }
             for (int dir = 0; dir < 4; dir++) {
                 int nx = curX + dx[dir];
                 int ny = curY + dy[dir];
                 if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                 if (!board[nx][ny]) continue; // 벽, 초기 성의 위치를 0으로 세팅
                 q[i].push({nx,ny,curStep+1});
                 board[nx][ny] = 0;
                 isExtend = 1;
                 area[i]++;
             }
            } // while(!q[i].empty)

            q[i] = nextq;
        }
        // 더 이상 확장이 불가능하면 게임을 끝낸다.
        if(!isExtend) break;
    }

    for (int i = 1; i <= p ; i++) {
        cout << area[i] << ' ';
    }
    return 0;
}