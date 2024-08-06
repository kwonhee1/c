#include <string>
#include <vector>

using namespace std;

struct stack {
    int x;
    int y;
    struct stack* next;
    stack(int y_, int x_) {
        x = x_; y = y_;
        next = NULL;
    }
};

int solution(vector<string> board) {
    //stack 선언 선입 선출
    struct stack* start, * end = start = new struct stack(-1, -1), *buff;
    int x, y, value, directX[4] = { 1,-1,0,0 }, directY[4] = { 0,0,1,-1 }, gx = -1, gy = -1;
    //                      동 서 남 북

    // board+2 * board+2 배열 선언
    vector<vector<int>> arr(board.size() + 2, vector<int>(board[0].length() + 2, -1)); //몽땅다 장애물 처리

    for (int y = 0; y < board.size(); y++) { // 0 ~ size()-1
        for (int x = 0; x < board[0].length(); x++) {
            switch (board[y][x]) {
            case 'R':
                end = end->next = new struct stack(y + 1, x + 1);
                arr[y + 1][x + 1] = 1;
                break;
            case '.':
                arr[y + 1][x + 1] = 0;
                break;
            case 'G':
                gy = y + 1; gx = x + 1;
                arr[y + 1][x + 1] = 0;
                break;
            }
        }
    }
    // for(int y = 0; y<board.size()+2; y++){ // 0 ~ size()-1
    //     for(int x = 0; x< board[0].length()+2; x++){
    //         printf("%2d ", arr[y][x]);
    //     }
    //     printf("\n");
    // }
    //return 1;

    while (start != end) { //stack 이 빌때까지
        buff = start;
        start = start->next;
        y = start->y; x = start->x;
        value = arr[y][x];
        delete buff;

        printf("stack pop :: y:%d x:%d value:%d\n", y, x, value);

        //해당 y,x값에 대하여 상하 좌우 값 구하기
        for (int direct = 0; direct < 4; direct++) {
            y = start->y; x = start->x;
            while (arr[(y += directY[direct])][(x += directX[direct])] >= 0) {
                // arr[][] < 0인 값 => 장애물이 나올때까지 진행
            }
            y -= directY[direct]; x -= directX[direct];
            //해당 지점이 목표 지점인지 확인
            if (y == gy && x == gx) {
                return value;
            }
            printf("check :: y:%d x:%d arr:%d\n", y, x, arr[y][x]);

            // 해당 값이 빙공간이면 => 해당 값에 value+1저장 + stack에 y,x값 넣기
            if (!arr[y][x]) {
                arr[y][x] = value + 1;
                end = end->next = new struct stack(y, x);
            }

            // 빙공간이 아니라면 => 이미 계산 완료된 지점 => 아무것도 하지 않음
        }
    }
    return -1;
}