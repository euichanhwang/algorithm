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
int n;
int allMinus,allZero,allOne;
int board[2200][2200];
void func(int n,int x,int y){
    int number = board[x][y];
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(number != board[i][j]){
                for(int i=0;i<3;i++)
                    for(int j=0;j<3;j++)
                        func(n/3,x+i*n/3,y+j*n/3);
                return;
            }
        }
    }
    if(number == -1) allMinus++;
    else if(number == 0) allZero++;
    else allOne++;
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
    cout << allMinus << '\n' << allZero << '\n' << allOne;
    return 0;
}