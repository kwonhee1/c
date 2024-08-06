//#include <string>
//#include <vector>
//
//using namespace std;
//
//// 점이동으로 알고리즘 변경 => y축 기준으로 점이동 후 거리 측정!
//
//int get(int y1, int x1, int y2, int x2) {
//    return 
//}
//
//vector<int> solution(int x, int y, int startX, int startY
//    , vector<vector<int>> balls /*(x,y)*/ ) {
//    vector<int> answer;
//    int max;
//
//    for (vector<vector<int>>::iterator i = balls.begin(); i != balls.end(); i++) {
//        max = 2e9;
//        
//        //위 변        start     balls[]
//        // y:x = y:x | x 7,y 3 | x 3,y 7
////(x_-balls[0])*(y-startY) = (y-balls[1])*(startX-x_)
//// (2y-startY-balls[1])x_ = balls[0]*(y-startY) + startX*(y-balls[1])
//// (20-3-7)x_ = 3(10-3)+7(10-7) => 10x_=21+21 => x_ = 21/5 == 4.
//// 공의 오른쪽 왼쪽이 바뀌면 식이 바뀜
//
//        // 하
//
//        // 좌
//
//        //우
//
//        //오 위
//
//        // 오 아래
//
//        //왼 위
//
//        //왼 아래
//    }
//
//    return answer;
//}