#include <string>
#include <vector>

// 마지막 부분에서 풀이법 봄 => 논리적 오류 수정 => 담에 다시 한번 풀어볼것!

using namespace std;

int compare(const void* a, const void* b) {
    if ((*(const vector<int> *)a)[0] < (*(const vector<int> *)b)[0])
        return 1;
    else if ((*(const vector<int> *)a)[0] > (*(const vector<int> *)b)[0])
        return -1;
    else {
        if ((*(const vector<int> *)a)[1] > (*(const vector<int> *)b)[1])
            return 1;
        else
            return -1;
    }
}

int solution(vector<vector<int>> scores) {
    int re = 1, * arr = new int[scores.size()] {0, }
    , findN, find0 = scores[0][0], find1 = scores[0][1];
    vector<int> old;

    //1. scores[][0]기준 정렬 (동일시 scores[][1]값이 큰게 앞으로)
    qsort(&scores.front(), scores.size(), sizeof(vector<int>), compare);

    // 정렬전 [0]번쨰 찾기!
    for (findN = 0; findN < scores.size() - 1; findN++) {
        if (scores[findN][0] == find0 && scores[findN][1] == find1) {
            break;
        }
    }
    // for(int i = 0; i<scores.size(); i++){
    //     printf("scores[%d] = (%d,%d)\n", i, scores[i][0], scores[i][1]);
    // }
    // printf("find>scores[%d] = (%d,%d)\n", findN, scores[findN][0], scores[findN][1]);

    //첫번쨰 강제 진행
    old = scores[0];
    arr[0] = old[0] + old[1] + 1;

    //2. scores1회 순회 (1 ~ n-1)
    for (int n = 1; n < scores.size(); n++) {
        //printf("input : scores[%d]=(%d,%d) | (%d,%d)", n,scores[n][0], scores[n][1], old[0],old[1]);

        if (old[1] < scores[n][1]) {
            arr[n] = scores[n][0] + scores[n][1] + 1;
            old = scores[n];
        }
        else if (old[1] == scores[n][1] || old[0] == scores[n][0]) {
            arr[n] = scores[n][0] + scores[n][1] + 1;
        }
        //printf(">arr[%d] = %d\n", n, arr[n]);
    }

    //3. [findN]이 비었는지 확인
    if (!arr[findN])
        return -1;
    else
        findN = arr[findN];

    //비지 않았다면 arr 1회순회하면서 [0]보다 큰값들의 개수 구하기
    for (int* i = arr; i < arr + scores.size(); i++) {
        if (*i > findN) {
            re++;
        }
    }

    return re;
}