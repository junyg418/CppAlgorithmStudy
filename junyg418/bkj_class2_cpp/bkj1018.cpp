// 1차 성공

#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, y;
    int min = 2600;
    cin >> x >> y;
    cin.ignore();

    string buffer;
    char input_data[x][y];
    for (int line=0; line<x; line++){
        getline(cin, buffer, '\n');
        for (int col=0; col<y; col++){
            input_data[line][col] = buffer.at(col); 
        }
    }

    char B_first[8][8] = {
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
    };
    char W_first[8][8] = {
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
    };

    int b_temp, w_temp, turn_min;
    // 체스 위치 옮김
    for (int x_shift=0; x_shift<x-7; x_shift++){
        for (int y_shift=0; y_shift<y-7; y_shift++){
            b_temp = 0;
            w_temp = 0;
            // 체스판과 비교만
            for (int row_idx=0; row_idx<8; row_idx++){
                
                for (int col_idx=0; col_idx<8; col_idx++){
                    if (B_first[row_idx][col_idx] != input_data[row_idx+x_shift][col_idx+y_shift]) b_temp++;
                    if (W_first[row_idx][col_idx] != input_data[row_idx+x_shift][col_idx+y_shift]) w_temp++;   
                }
            }
            turn_min = b_temp>=w_temp?w_temp:b_temp;
            min = turn_min>=min?min:turn_min;

        }
    }
    cout << min;
}