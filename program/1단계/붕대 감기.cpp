#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int maxhealth, vector<vector<int>> attacks) {
    int health = maxhealth - attacks[0][1], time = attacks[0][0] + 1;
    // 첫번째 공격 받고 시작

    // 첫번째 공격에 죽을 경우 : 쓰래기
    if (health <= 0) {
        printf("end :: %d\n", time);
        return -1;
    }
    printf("ok :: health %d, time %d\n", health, time);

    for (vector<vector<int>>::iterator i = attacks.begin() + 1; i != attacks.end(); i++) {
        // 다음 공격 전까지 피회복 계산 초당 회복량 + 추가 회복량
        health += bandage[1] * ((*i)[0] - time)
            + bandage[2] * (((*i)[0] - time) / bandage[0]);

        if (health > maxhealth) {
            health = maxhealth;
        }

        health -= (*i)[1];
        if (health <= 0) {
            printf("end :: %d\n", time);
            return -1;
        }
        time = (*i)[0] + 1;
        printf("ok :: health %d, time %d\n", health, time);
    }

    return health;
}