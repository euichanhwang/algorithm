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
string a[50];
int number;
int getSum(string a)
{
    int length = a.length();
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        if (a[i] - '0' <= 9 && a[i] - '0' >= 0)
        {
            sum += a[i] - '0';
        }
    }
    return sum;
}
bool compare(string a, string b)
{

    if (a.length() < b.length())
        return 1;
    else if (a.length() > b.length())
        return 0;
    else //길이가 같은 경우
    {
        int aSum = getSum(a);
        int bSum = getSum(b);
        if (aSum != bSum)
        {
            return aSum < bSum;
        }
        return a<b;
    }
   
   
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        cin >> a[i];
    }
    sort(a, a + number, compare);
    for (int i = 0; i < number; i++)
    {
        cout << a[i] << '\n';
    }

    return 0;
}
