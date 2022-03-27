## [백준 16509 : 장군](https://www.acmicpc.net/problem/16509)  
### 💡접근 방법 : 시뮬레이션 + bfs
- 일반적인 bfs에 시뮬레이션 구현이 추가된 문제이다.  
- 상의 좌표에서 중간에 다른 기물이 있다면 이동할 수 없기 때문에, 그점을 고려해야 한다.  
### 그림 설명
![장군](https://github.com/euichanhwang/algorithm/blob/main/img/%EB%B0%B1%EC%A4%80%2016509%20%EC%9E%A5%EA%B5%B0%20%EA%B2%BD%EB%A1%9C%20%EA%B7%B8%EB%A6%BC.jpeg) 
- 파란색 점으로 표시된 부분은 상이 이동할 수 있는 좌표이다.  
- 빨간색 점으로 표시된 부분에 기물이 존재한다면, 파란색 좌표로 이동할 수 없다.  
- **일반적인 bfs를 구현 후, 가고자 하는 좌표에 기물이 존재하는지 추가로 확인한다.**  
```c++
bool check(int index,int nx,int ny){ //경로에 왕이 있으면 0, 없으면 1 반환
    if(index==0||index==1){
        for(int i=1;i<=2;i++){
            if (nx - i == k1 && ny - i == k2) return 0;
        }
    }
    if(index==2||index==3){
        for(int i=1;i<=2;i++){
            if (nx + i == k1 && ny - i == k2) return 0;
        }
    }
    if(index==4||index==5){
        for(int i=1;i<=2;i++){
            if (nx + i == k1 && ny + i == k2) return 0;
        }
    }
    if(index==6||index==7){
        for(int i=1;i<=2;i++){
            if (nx - i == k1 && ny + i == k2) return 0;
        }
    }
    return 1; // 경로에 기물이 없을 때
}

```




