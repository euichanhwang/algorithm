## [백준 1431번 : 시리얼 번호](https://www.acmicpc.net/problem/1431)
### 💡 접근 과정
- sort함수를 이용해 string 배열을 정렬할 때 **compare** 함수를 통해 정렬할 때의 기준을 구현한다.  
- 문자 중에서 숫자만 더해주는 경우, 아스키 코드를 활용해서 string 배열에서 '0'을 빼주면 숫자만 추출 가능하다.
```c++
//문자열 중 숫자인 것만 더한다
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
//정렬할 때의 기준 
bool compare(string a, string b)
{
    //길이가 다른 경우는 짧은 것이 먼저 온다
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


```
