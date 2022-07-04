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

void hanoi(int n,int start, int mid, int end) {
    if (n == 1) {
        cout << start << " " << end<< "\n";
    }
    else {
        hanoi(n-1,start,end,mid);
        cout << start << " " << end << "\n";
        hanoi(n-1,mid,start,end);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cout << (int)pow(2, n) - 1 << '\n';
    hanoi(n,1,2,3);
}
