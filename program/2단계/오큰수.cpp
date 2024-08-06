#include <string>
#include <vector>

using namespace std;

struct stack {
    int value;
    struct stack* next;
    stack(int v, struct stack* n) {
        value = v; next = n;
    }
};

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    struct stack stack = { 0, new struct stack(-1,NULL)}; //첫번째 스텍에 -1삽입
    //int last = numbers[numbers.size()-1];

    //첫번째값 강제 -1 진행
    answer[numbers.size() - 1] = -1;

    for (int i = numbers.size() - 2; i; i--) {
        if (numbers[i] >= numbers[i + 1]) {
            answer[i] = stack.next->value;
        }
        else if (numbers[i] < numbers[i + 1]) {

        }
    }

    return answer;
}