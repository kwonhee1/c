#include <string>
#include <vector>

using namespace std;

int check(vector<string> name, char* photo, int e) {
    // 존재하지 않을시 return ;
    // 존재할시        return 해당 인덱스 반환;
    char* n, * p;
    //printf("check %s >> ", photo);
    for (int i = 0; i < name.size(); i++) {
        n = &name[i].front(); p = photo;
        while (*n++ == *p++) {
            if (!*n && !*p) {
                //           printf("%d\n", i);
                return i;
            }
        }
    }
    //printf("not found\n");
    return e;
}

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int ans;
    int e = yearning.size();
    yearning.push_back(0);

    for (vector<vector<string>>::iterator i = photo.begin(); i != photo.end(); i++) {
        ans = 0;
        for (vector<string>::iterator j = i->begin(); j != i->end(); j++) {
            ans += yearning.at(check(name, &j->front(), e));
        }
        answer.push_back(ans);
    }

    return answer;
}

int main() {
    vector<string> name;
    name.push_back( "kali");
    name.push_back( "mari");
    name.push_back( "don");
    
    //printf("check name\n");
    /*for (vector<char*>::iterator i = name.begin(); i != name.end(); i++) {
        printf("%s ", *i);
    }*/

    vector<int> yearning = { 11,1,55 };

    vector<vector<string>> photo(
        //{ {"may", "kein", "kain", "radi"},{"may", "kein", "brin", "deny"},{"kon", "kain", "may", "coni"} }
        { {"kali", "mari", "don"},{"pony", "tom", "teddy"},{"con", "mona", "don"} }
    );
    
    vector <int> sol = solution(name, yearning, photo);

    printf("end solution\n");
    for (vector<int>::iterator i = sol.begin(); i != sol.end(); i++) {
        printf("%d ", *i);
    }
}