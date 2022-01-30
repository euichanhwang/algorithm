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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int number;
    cin >> number;
    vector<int> v(number); 
    
    for (int i = 0; i < number; i++)
    {
        cin >> v[i];
    }
    vector<int> cv(v); 
    sort(cv.begin(), cv.end()); 
    cv.erase(unique(cv.begin(), cv.end()), cv.end()); 
    for (int i = 0; i < number; i++)
    {
        
        auto it = lower_bound(cv.begin(), cv.end(), v[i]);
        cout << it - cv.begin() << ' ';

    }

    
    
    
    return 0;
}
