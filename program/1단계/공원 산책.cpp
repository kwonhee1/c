#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int px, py, directX[4] = { 1,-1,0,0 }, directY[4] = { 0,0,1,-1 }, direct, x_, y_, flag;
    //         동 서 남 북
    // park.size() <= 0 or 1 인경우 따로 잡아줘야함
    vector<vector<int>> arr(park.size(), vector<int>(park[0].size(), 0));
    for (int y = 0; y < park.size(); y++) {
        for (int x = 0; x < park[y].size(); x++) {
            switch (park[y][x]) {
            case 'S':
                px = x; py = y;
                break;
            case 'X':
                arr[y][x] = 1;
                break;
            }
        }
    }

    // 시간 복잡도 : 2500
    /*printf("check arr\n");
    for (int y = 0; y < park.size(); y++) {
        for (int x = 0; x < park[y].size(); x++) {
            printf("%d ", arr[y][x]);
        }
        printf("\n");
    }*/

    for (vector<string>::iterator i = routes.begin(); i != routes.end(); i++) {
        flag = 1;
        x_ = px; y_ = py;
        switch (i->front()) {
            // 동 서 남 북
        case 'E':
            direct = 0;
            break;
        case 'W':
            direct = 1;
            break;
        case 'S':
            direct = 2;
            break;
        case 'N':
            direct = 3;
            break;
        }

      //  printf(" j : %d\n", (*i)[2] - '0');
        for (int j = (*i)[2] - '0'; j; j--) {
            x_ += directX[direct]; y_ += directY[direct];
            // 현재 위치 가능한 공간인지 확인
          //  printf("y_ : %d < %d || x_ : %d < %d\n", y_, arr.size(), x_, arr[0].size());
            if (y_ < arr.size() && x_ < arr[0].size()) {
                if (!arr[y_][x_]) {
                  //  printf("pass : %d,%d\n", y_, x_);
                    continue;
                }
            }
            flag = 0;
            //printf("fail arr[%d][%d] = %d\n", y_,x_,arr[y_][x_]);
            break;
        }

        if (flag) {
         //   printf("change %d,%d\n", py, px);
            px = x_; py = y_;
        }
    }
   // printf("\nresult %d,%d", py, px);
    return { py, px };
}

int main() {
    vector<string> park;
    park.push_back("SOO");
    park.push_back("OOO");
    park.push_back("OOO");

    vector<string> routes;
    routes.push_back("E 2");
    routes.push_back("S 2");
    routes.push_back("W 1");

    solution(park, routes);
}

// just for commit test erase me!
