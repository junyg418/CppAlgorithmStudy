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

    cout << "���� ID : "; cin >> acc_id;
    cout << "�� �� : "; cin >> name;
    cout << "�Աݾ� : "; cin >> money;

    Account temp_coustom {name, money};
    arr.insert(make_pair(acc_id, temp_coustom));
}

void deposit(){
    cout << "[��    ��]" << '\n';
    int id;
    int money;

    cout << "���� ID : "; cin >> id;
    cout << "�Աݾ� : "; cin >> money;
    try
    {
        arr[id].money += money;
        cout << "�Ա� �Ϸ�" << '\n';
    }
    catch(const std::exception& e)
    {
        cout << "�Ա� ����" << '\n';
    }
}

void withdraw(){
    cout << "[��    ��]" << '\n';
    int id;
    int money;

    cout << "���� ID : "; cin >> id;
    cout << "�Աݾ� : "; cin >> money;
    try
    {
        if (money > arr[id].money){
            cout << "��� ����" << '\n';
            return;
        }
        arr[id].money -= money;
        cout << "��� �Ϸ�" << '\n';
    }
    catch(const std::exception& e)
    {
        cout << "��� ����" << '\n';
    }
}

void print_acc(){
    for (auto data : arr){
        cout << "����ID : " << data.first << '\n';
        cout << "�� �� : " << data.second.name << '\n';
        cout << "�� �� : " << data.second.money << '\n';

        cout << "\n\n\n";
    }
}

int main(){
    int choice;
    while(true){
        cout << "------ MENU ------" << '\n';
        cout <<"1. ���°���\n2. �� ��\n3. �� ��\n4. �������� ��ü ���\n5. ���α׷� ����\n���� : ";
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