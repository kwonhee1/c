#include <string>
#include <vector>
#include <iostream>

using namespace std;

int strcmp(char* a, char* b) {
    printf("strcmp :: %s %s\n", a, b);
    while (*a == *b && *a && *b) { a++; b++; }
    return !*a && !*b; //같으면 true 1, 다르면 false 0
}

vector<int> solution(int num, vector<string> words) {
    int n = 1; //첫번째 단어 무조건 건너띄기

    for (; n < words.size(); n++) {
        // n번째 단어 확인중
        if (words[n - 1][words[n - 1].size() - 1] != words[n].front()) { //단어가 올바른지 확인
            printf("단어 틀림 : %s || %s\n", &words[n - 1].front(), &words[n].front());
            // 틀렸음 해당 n에 대하여 return 진행
            return { n % num + 1,n / num + 1 };
        }
        for (int i = 0; i < n; i++) { // 이전 단어와 같은지 확인
            if (strcmp(&words[n].front(), &words[i].front())) {
                printf("중복 확인 %s %s", &words[i].front(), &words[n].front());
                // 틀렸음 해당 n에 대하여 return 진행
                return { n % num + 1,n / num + 1 };
            }
        }
    }

    return { 0,0 };
}