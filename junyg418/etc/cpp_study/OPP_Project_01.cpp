#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef struct{
    string name;
    int money;
}Account;
map<int, Account>arr;

enum class MENU{
    MAKE = 1, DEPOSIT, WITHDRAW, INQURE, EXIT
};

void make_account(){
    int acc_id;
    string name;
    int money;

    cout << "계좌 ID : "; cin >> acc_id;
    cout << "이 름 : "; cin >> name;
    cout << "입금액 : "; cin >> money;

    Account temp_coustom {name, money};
    arr.insert(make_pair(acc_id, temp_coustom));
}

void deposit(){
    cout << "[입    금]" << '\n';
    int id;
    int money;

    cout << "계좌 ID : "; cin >> id;
    cout << "입금액 : "; cin >> money;
    try
    {
        arr[id].money += money;
        cout << "입금 완료" << '\n';
    }
    catch(const std::exception& e)
    {
        cout << "입금 실패" << '\n';
    }
}

void withdraw(){
    cout << "[입    금]" << '\n';
    int id;
    int money;

    cout << "계좌 ID : "; cin >> id;
    cout << "입금액 : "; cin >> money;
    try
    {
        if (money > arr[id].money){
            cout << "출금 실패" << '\n';
            return;
        }
        arr[id].money -= money;
        cout << "출금 완료" << '\n';
    }
    catch(const std::exception& e)
    {
        cout << "출금 실패" << '\n';
    }
}

void print_acc(){
    for (auto data : arr){
        cout << "계좌ID : " << data.first << '\n';
        cout << "이 름 : " << data.second.name << '\n';
        cout << "잔 액 : " << data.second.money << '\n';

        cout << "\n\n\n";
    }
}

int main(){
    int choice;
    while(true){
        cout << "------ MENU ------" << '\n';
        cout <<"1. 계좌개설\n2. 입 금\n3. 출 금\n4. 계좌정보 전체 출력\n5. 프로그램 종료\n선택 : ";
        cin >> choice;
        
        switch (MENU(choice))
        {
        case MENU::MAKE:
            make_account();
            break;
        case MENU::DEPOSIT:
            deposit();
            break;
        case MENU::WITHDRAW:
            withdraw();
            break;
        case MENU::INQURE:
            print_acc();
            break;
        case MENU::EXIT:
            return 0;
        default:
            return 0;
        }
    }
}