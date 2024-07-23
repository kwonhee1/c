#include <string>
#include <vector>

using namespace std;

int strcmp(char* a, char* b) {
    while (*a == *b && *a != 0 && *b != 0) {
        // a와 b가 다르고 둘다 0이 아닐때
        a++; b++;
    }
    // a와 b가 둘다 0일때 끝나면 같은 문자열
    return !*a && !*b; // 같으면 true 1 , 다르면 false 0
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int n1=0, n2=0;
    for (vector<string>::iterator i = goal.begin(); i != goal.end(); i++) {
        if (n1 < cards1.size()) {
            if (strcmp(&i->front(), &cards1[n1].front())) {
                n1++;
                continue;
            }
        }
        if (n2 < cards2.size()) {
            if (strcmp(&i->front(), &cards2[n2].front())) {
                n2++;
                continue;
            }
        }
        return "No";
    }

    return "Yes";
}

int main() {
    // main함수 생략 (통과했음)
}