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

int number;

void parse(string &tmp, deque<int> &d)
{
    int cur = 0;
    for (int i = 1; i + 1 < tmp.size(); i++)
    {
        if (tmp[i] == ',')
        {
            d.push_back(cur);
            cur = 0;
        }
        else
        {
            cur = 10 * cur + (tmp[i] - '0');
        }
    }
    if (cur != 0)
        d.push_back(cur);
}
void print(deque<int> &d)
{
    cout << '[';
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i];
        if (i + 1 != d.size()) // 0 1 2 3 size=4 i+1!=4
        {
            cout << ',';
        }
    }
    cout << "]\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> number;
    while (number--)
    {
        deque<int> d;
        int rev = 0;
        bool flag = false;
        int repeatNum;
        string func, tmp; //함수, [1,2,3,4] 와 같은 입력
        cin >> func;
        cin >> repeatNum;
        cin >> tmp;
        parse(tmp, d);
        for(char c : func)
    {
      if(c == 'R')
        rev = 1 - rev;
      else{
        if(d.empty()){
          flag = true;
          break;
        }
        if(!rev) d.pop_front();
        else d.pop_back();
      }
    }
    if(flag)
      cout << "error\n";
    else{
      if(rev) reverse(d.begin(), d.end());
      print(d);
    }
  }
}

