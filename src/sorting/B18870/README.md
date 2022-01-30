## [백준 18870 : 좌표 압축](https://www.acmicpc.net/problem/18870)
### 💡접근 과정  
- 좌표가 주어지면, 해당 좌표보다 작은 좌표의 수를 반환해야 한다.  
- 벡터를 정렬한 후, 정렬된 순서의 index를 활용하면 현재 좌표보다 작은 좌표의 수를 알 수 있다.  
- ⭐️중복을 제거하기 위해 vector의 unique,erase 함수와 lower_bound를 사용한다.  
### unique 함수와 erase 함수
- unique 함수는 연속으로 중복 되는 원소를 vector의 제일 뒷부분으로 보낸다.  
**이 때,연속으로 중복되는 원소를 없애기 때문에 반드시 정렬을 시행해줘야 한다.**  
중복되지 않은 원소들을 앞에서부터 채워나간 후, 남은 뒷부분은 그대로 원래의 vector 원소값이 존재한다.  
`1 1 2 3 3 4 5 5 5 6`을 unique 함수를 적용하면, 중복된 원소를 제거하며 앞에서부터 원소를 채우면  
순서대로 1,2,3,4,5,6 이 들어가고 남은 4자리는 원래 vector의 5,5,5,6이 들어가서 `1 2 3 4 5 6 5 5 5 6`이라는 결과가 나온다.  
**이때 중요한 점은, unique함수의 반환 주소는 원본이 유지된 원소들의 첫번째 주소 값을 반환한다는 것이다.**  
따라서, `5 5 5 6`의 첫 5가 unique 함수의 반환 주소이다.  
- erase함수는 vector 배열에서 특정 원소를 삭제하는 함수이다.  
v.erase(v.begin()+s, v.begin()+e) 명령어를 입력하면 [s,e) 원소가 삭제된다.  
따라서, erase 함수와 unique 함수를 함께 사용해서 벡터에서 필요한 원소만 뽑아낼 수 있다.  
v.erase(unique(v.begin(), v.end()), v.end()); 를 사용하면 unique 함수를 실행 한 후 반환 위치가 원본이 유지된 원소들의  
첫번째 주소 값이므로, 벡터의 마지막까지 지우면 중복이 없는 값을 얻을 수 있다.  
###  lower_bound와 upper_bound 함수 : 이진 탐색으로 원소 탐색 
- lower_bound 함수는 찾으려는 **key값보다 같거나 큰 숫자가** 배열 몇 번째에서 처음 등장하는지 찾기 위해 사용한다.  
⭐️탐색을 진행할 배열 혹은 벡터는 오름차순 정렬되어 있어야 한다.  
**원소의 수가 number개 일때,lower_bound(arr,arr+number,6)-arr** //첫 주소부터 끝까지 탐색, 6 이상의 숫자가 처음으로 나오는 위치의  
인덱스 번호. **lower_bound의 반환형은 Iterator이므로 실제로 몇 번째 인덱스인지 알고 싶으면 첫번째 주소를 빼준다.**  
- upper_bound 함수는 찾으려는 **key값을 초과하는 숫자가** 배열 몇 번째에서 처음 등장하는지 찾기 위해 사용한다.  
⭐️탐색을 진행할 배열 혹은 벡터는 오름차순 정렬되어 있어야 한다.     
**원소의 수가 number개 일때,upper_bound(arr,arr+number,3)-arr**//첫 주소부터 끝까지 탐색, 3을 처음으로 초과하는 숫자가 나오는 위치의  
인덱스 번호를 반환. **lower_bound와 마찬가지로 반환형이 Iterator이므로 실제 몇 번째 인덱스인지 알고 싶으면 첫번째 주소를 빼준다.**  
### lower_bound 함수와 upper_bound 함수의 활용
- 오름차순 정렬된 자료에서 특정 범위에 속하는 숫자가 몇 개 있는지 탐색하고자 할 때
```c++
int main() {

	vector<int> arr = { 1,3,5,5,7,8,8,10,10,11,13 };
	cout << "5 이상 11 이하의 갯수 : " << upper_bound(arr.begin(), arr.end(), 11) - lower_bound(arr.begin(), arr.end(), 5);
    //11을 초과하는 13의 인덱스 번호는 10. 5보다 같거나 큰 숫자는 인덱스 2에서 처음 등장. 10-2=8이다.
	return 0;
}
```  
- 오름차순 정렬된 자료에서 특정한 숫자가 몇 번 나오는지 탐색하고자 할 때  
이 경우 **O(logN)**으로 탐색 가능하다.  
```c++
int main() {

	vector<int> arr = { 1,3,5,5,5,8,8,10,10,11,13 };
	cout << "5의 갯수 : " << upper_bound(arr.begin(), arr.end(), 5) - lower_bound(arr.begin(), arr.end(), 5);
    //5를 초과하는 숫자가 처음 나오는 위치-5이상의 수가 처음 나오는 위치
	return 0;
}
```  
### 18870번 소스 코드
```c++
    int number;
    cin >> number;
    vector<int> v(number); 
    
    for (int i = 0; i < number; i++)
    {
        cin >> v[i];
    }
    vector<int> cv(v);  //원본 배열을 복사할 벡터 선언
    sort(cv.begin(), cv.end()); //오름차순 정렬
    cv.erase(unique(cv.begin(), cv.end()), cv.end()); // unique함수 이용 중복되는 원소 뒤로 보낸 후 erase로 정렬되지 않은 부분 삭제 
    for (int i = 0; i < number; i++)
    {
        
        auto it = lower_bound(cv.begin(), cv.end(), v[i]); //원본 배열에서 v[i]보다 같거나 큰 숫자의 인덱스 반환 
        cout << it - cv.begin() << ' '; // 반환형은 iterator이므로 실제 위치를 알고 싶으면 첫 주소를 빼준다

    }
```
