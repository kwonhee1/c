#include <string>
#include <vector>

using namespace std;


struct min {
    int* mins;
    int max;
    min() {
        mins = new int[5] { 0, };
        max = 0;
    }
    ~min() {
        delete[] mins;
    }
};


int compare(const void* a, const void* b) {
    if (((const struct min*)(a))->max < ((struct min*)(b))->max) {
        return 1;
    }
    else
        return -1;
}

int solution(vector<int> picks, vector<string> minerals) {
    int d = picks[0], i = picks[1], s = picks[2], re = 0, pick[3] = { 25,5,1 }, pickn = 0;
    vector<struct min> arr((picks[0] + picks[1] + picks[2]) < minerals.size() / 5 + (bool)(minerals.size() % 5) ? picks[0] + picks[1] + picks[2] : minerals.size() / 5 + (bool)(minerals.size() % 5));

    printf("arr.size() = %d | minerals %d | picks %d \n", arr.size(), minerals.size(), (picks[0] + picks[1] + picks[2]) * 5);

    for (int k = 0; k < minerals.size() && k < (picks[0] + picks[1] + picks[2]) * 5; k++) {
        switch (minerals[k].front()) {
        case 'd':
            arr[k / 5].max += arr[k / 5].mins[k % 5] = 25;
            break;
        case 'i':
            arr[k / 5].max += arr[k / 5].mins[k % 5] = 5;
            break;
        case 's':
            arr[k / 5].max += arr[k / 5].mins[k % 5] = 1;
            break;
        }
    }

    qsort(&arr.front(), arr.size(), sizeof(struct min), compare);

    for (int y = 0; y < arr.size(); y++) {
        for (int x = 0; x < 5; x++) {
            printf("arr[%d][%d] = %d ", y, x, arr[y].mins[x]);
        }
        printf("max : %d \n", arr[y].max);
    }

    for (int k = 0; k < arr.size(); k++) {
        if (picks[pickn]) { //현재 곡굉이가 있다면
            for (int j = 0; j < 5; j++) {
                if (arr[k].mins[j]) {
                    if (arr[k].mins[j] < pick[pickn])
                        re += arr[k].mins[j] / pick[pickn];
                    else
                        re++;
                }
                // 값이 없으면 넘어감
            }
        }
        else { //현재 곡굉이 없다면
            pickn++;
            //picks가 부족해서 넘어갈경우 오류 발생 => 논리적으로 넘어갈수 없어야 함!!
        }
    }

    return re;
}