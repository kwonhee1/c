//#include <string>
//#include <vector>
//
//// 24 * 60 = 1440
//
//using namespace std;
//
//int change(string time) {
//    return time[4]-'0' + (time[3]-'0') * 10 + (time[1]-'0') * 60 + (time[0]-'0') * 600;
//}
//
//int minToInt(string time) {
//    int t = 0;
//    char *c = &time.front();
//    while(*c){// c값이 존재한다면
//        t *= 10;
//        t+= *c - '0';
//        c++;
//    }
//    
//    return t;
//}
//
//struct st {
//    int start;
//    int end;
//    char* name;
//    st(vector<string> vector) {
//        // name => n이동
//        name = new char[11] {0, };
//        char* name_ = name, * n = &vector[0].front();
//        while ((*name_++ = *n++)) {
//            // n에 있는 '\0'까지 넣고 끝 => 1칸 더 필요함    
//        }
//
//        // vector => start, end 이동
//        start = change(vector[1]);
//        end = start + minToInt(vector[2]);
//    }
//
//    ~st() {
//        delete[] name;
//    }
//};
//
//
//int compare(const void* a, const void* b) {
//    if ((*(const struct st**)a)->start > (*(const struct st**)b)->start) {
//        return 1;
//    }
//    else
//        return -1;
//}
//
////가장 최근에 멈춘걸 진행 => 선입 후출
//struct stack {
//    int time; //필요한 분만 저장
//    char* name;
//    struct stack* next;
//    stack(int t, char* n, struct stack* ne) {
//        next = ne;
//        time = t; name = n;
//    }
//};
//
//vector<string> solution(vector<vector<string>> plans) {
//    // plans => struct
//    struct st** arr = new struct st*[plans.size()];
//    for (int i = 0; i < plans.size(); i++) {
//        arr[i] = new struct st(plans[i]);
//    }
//
//    vector<string> answer;
//    struct stack stack(0, NULL, NULL), *stack_ = NULL;
//
//    // 시간순 정렬 
//    qsort(arr, plans.size(), sizeof(struct st *), compare);
//
//    // for(struct st** i = arr; i < arr+plans.size(); i++){
//    //     printf("%s %d %d\n", (*i)->name, (*i)->start, (*i)->end);
//    // }
//    // printf("\n");
//    
//    //return answer;
//
//    //첫번재 강제 입력
//    int time = arr[0]->end;
//    char* name = arr[0]->name;
//
//    for (struct st **i = arr+1; i< arr+plans.size(); i++) {
//        printf("start %s|time %d||next %s|time %d\n", name, time, (*i)->name, (*i)->start);
//        //과제가 끝났고 시간이 남을때 => 남아있는 과제 진행
//        if ((*i)->start > time) {
//            answer.push_back(name);
//
//            if (stack.next) {
//                //남아있는 과제를 꺼내서 time과 name에 동기화 후 다시 for문 진행
//                name = stack.next->name;
//                time += stack.next->time;
//                stack.next = (stack_ = stack.next)->next;
//                delete stack_;
//                i--;
//                continue;
//            }
//            //남아있는 과제가 없다면 시간을 버림
//        }
//
//        //과제가 동시에 끝남 바로 다음 과제로 넘어감
//        else if ((*i)->start == time) {
//            answer.push_back(name);
//        }
//
//        // 과제가 끝나지 않음 => 과거를 stack에 넣고 다음꺼 진행
//        else {
//            stack.next = new struct stack(time - (*i)->start, name, stack.next);
//        }
//
//        //*i의 값을 time, name으로 초기화
//        time = (*i)->end;
//        name = (*i)->name;
//
//        // stack_ = stack.next;
//        // while(stack_){
//        //     printf("%s ", stack_->name);
//        //     stack_ = stack_->next;
//        // }
//    }
//    //printf("end");
//    // 마지막 과제는 무조건 성공 처리
//    answer.push_back(arr[plans.size()-1]->name);
//    // stack_ = stack.next;
//    //     while(stack_){
//    //         printf("%s ", stack_);
//    //         stack_ = stack_->next;
//    //     }
//    //     printf("\n");
//    
//    //나머지 과제들 몽땅 완료처리
//    while(stack.next){
//        stack.next = (stack_ = stack.next)->next;
//        answer.push_back(stack_->name);
//        delete stack_;
//    }
//    
//    // stack_ = stack.next;
//    //     while(stack_){
//    //         printf("%s ", stack_);
//    //         stack_ = stack_->next;
//    //     }
//    //     printf("\n");
//
//    return answer;
//}
