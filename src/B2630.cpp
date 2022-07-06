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
/**
 * 전체 종이의 크기가 N*N
 * 전체 종이가 모두 같은 색으로 칠해져 있지 않으면 가로와 세로로 중간 부분을 잘라서 네 개의 N/2 * N/2 색종이로 나눈다.
 * 최종적으로 나누어진 색종이의 상태에서 하얀색 색종이와 파란색 색종이의 개수를 구하라.
 */
int n;
int board[130][130];
int w,b; //하얀색 색종이, 파란색 색종이
void func(int n,int x,int y){
    int color = board[x][y];
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(color != board[i][j]){
                func(n/2,x,y);
                func(n/2,x+n/2,y);
                func(n/2,x,y+n/2);
                func(n/2,x+n/2,y+n/2);
                return;
            }
        }
    }
    if(color==1) b++;
    else w++;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    func(n,0,0);
    cout << w << '\n' << b;
    return 0;
}