// 1차

#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

/*
패널티 : 
해결한 시간
실패한 횟수 : (해결한 문제만) -20
*/
int main(){
    int buffer[26] = {0, };
    int alpa[26] = {0, };

    int solve;
    char num;
    string answer;

    int temp;
    while (true){
        cin >> solve;
        if (solve == -1) break;
        cin >> num >> answer;

        if (answer == "right"){
            temp = buffer[num - 'A'] == 0?0:buffer[num-'A'];
            alpa[num-'A'] = temp + solve;
        }
        else{
            buffer[num - 'A'] += 20;
        }
    }
    int solved_problem = 0;
    int result = 0;
    for (const auto &k : alpa){
        solved_problem += k==0?0:1;
        result += k;
    }
    cout << solved_problem << " " << result;
}