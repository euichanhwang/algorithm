## [백준 2665 : 미로만들기](https://www.acmicpc.net/problem/2665)  
### 💡접근 방법 : bfs응용 
- 검은 방을 흰 방으로 최소한의 수로 바꿔, 시작 지점에서 끝 지점으로 도달하는 문제이다. 
- 문제를 해결하기 위해서, 검은 방의 개수를 세면 된다. 
- **검은 방일 땐 현재까지의 검은 방 개수에서 1을 더해주고, 흰 방일땐 그 수를 그대로 유지하면 된다.**  
- **검은 방의 좌표가 곧, 몇개의 검은 방을 흰색으로 바꾸고 그 지점까지 도달했는 지의 수를 나타낸다.** 
### 그림 설명
![2665번 설명](https://github.com/euichanhwang/algorithm/blob/main/img/%EB%B0%B1%EC%A4%80%202665%20bfs%20%EA%B2%B0%EA%B3%BC.jpeg) 
- (1,5) 의 좌표 2를 기준으로 보면, 2의 의미는 (1,4)와 (1,5) 검은 방 두개를 흰 방으로 수정 후 그 좌표에 도달했다는 의미이다.  
- 따라서, 마지막 끝 방의 좌표를 구하면 끝 좌표까지 도달할 때 몇 개의 방을 바꿔 도달했는지 알 수 있다.  
```c++
 if(board[nx][ny]=='1'){ //다음 방이 흰 방
                if(dist[nx][ny]==-1||dist[nx][ny]>dist[cur.X][cur.Y]){ //흰 방은 유지. 다음 흰 방이 값이 더 크면 현재 값 대입
                    dist[nx][ny]=dist[cur.X][cur.Y];
                    q.push({nx,ny});
                }
            }
            else{ //다음 방이 검은 방
                if(dist[nx][ny]==-1||dist[nx][ny]>dist[cur.X][cur.Y]+1){ 
                    dist[nx][ny]=dist[cur.X][cur.Y]+1;   
                    q.push({nx,ny});
                    
                }
            }
```












