#include<stdio.h>

int f(int n){
    if(n==0)return 1;
    int sum = 0;
    for(int i=0; i<n; i++)
        sum+=f(i);
    return sum % 13;
}

int main(){
    char ans[]="rgjgmbuyh bfcx";
    for(int i = 0; i<13; i++)
        ans[i]^=f(13+i*i*i);
    puts(ans);	
    // result : "secondtragedy"
}																															

// 문제 코드가 너무 비효율적이기에 메모제이션으로 해결
// #include <bits/stdc++.h>

// int f(int n, std::unordered_map<int, int>& memo) {
//     if (n == 0) return 1;
//     if (memo.count(n) > 0) return memo[n];
//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         sum += f(i, memo);
//     }
//     memo[n] = sum % 13;
//     return memo[n];
// }

// int main() {
//     std::unordered_map<int, int> memo;
//     int i = 12;
//     char c = 'x';
//     int r = f(13+i*i*i, memo);
//     printf("f(n) = %d\n", r);

//     char result = c^r;
//     printf("%c" , result);
//     // "secondtragedy"
//   return 0;
// }