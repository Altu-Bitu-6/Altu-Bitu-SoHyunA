#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;
typedef pair<int, int> ci;

int playGame(int n, vector<vector<int>>& board, map<int, char>& cmd) {
    //우, 상, 좌 , 하
    int dr[4] = { 0,-1,0,1 };
    int dc[4] = { 1,0,-1,0 };

    //뱀 정보 초기화
    deque <ci> snake;
    snake.push_front(ci(0, 0));
    board[0][0] = 1;

    int t = 0, head = 0; //시간, 뱀의 머리 방향
    while (true) {
        t++;
        //뱀의 머리가 위치하게 될 칸
        int nr = snake.front().first + dr[head];
        int nc = snake.front().second + dc[head];

        //게임 종료 - 벽에 부딪히거나 뱀의 몸과 부딪힐때
        if (nr < 0 or nr >= n or nc < 0 or nc >= n or board[nr][nc] == 1) {
            break;
        }

        //사과 x -> 몸 길이를 줄여서 꼬리가 위치한 칸을 비워줌
        if (board[nr][nc] != 2) {
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        
        //몸길이를 늘려 머리를 다음 칸에 위치시킴
        snake.push_front(ci(nr, nc));
        board[nr][nc] = 1;

        //방향 변환 확인
        if (cmd[t] == 'L') {
            head = (head + 1) % 4;
        }
        if (cmd[t] == 'D') {
            head = (head + 3) % 4;
        }
    }
    return t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k; cin >> n >> k; 
    vector<vector<int>> board(n, vector<int>(n));//n*n 벡터 생성
    int x, y;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        board[x-1][y-1] = 2; //사과 위치 표시
    }

    int l; cin >> l; //뱀의 변환 횟수
    map <int, char> cmd; //시간,방향
    int t; char c;
    //시간, 회전 정보 저장
    for (int i = 0; i < l; i++) {
        cin >> t >> c;
        cmd[t] = c;
    }

    cout << playGame(n, board, cmd);
    
    return 0;
}