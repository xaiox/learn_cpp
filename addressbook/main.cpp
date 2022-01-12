#include <iostream>
using namespace std;
#include <string>
#include <cstring>

struct people{
    char sex;
    int age;
    char number[20];
//    string name;
//    string address;
//    string number;
    char name[20];
    char address[100];
};

struct address{
    people data;
    address *next;
};

int menu()
{
    int choice;
    system("cls");
    cout << "--------------------------" << endl;
    cout << "1.添加联系人" << endl;
    cout << "2.显示联系人" << endl;
    cout << "3.删除联系人" << endl;
    cout << "4.查找联系人" << endl;
    cout << "5.修改联系人" << endl;
    cout << "6.清空联系人" << endl;
    cout << "7.退出电话簿" << endl;
    cout << "--------------------------" << endl;
    cout << "请输入您需要的选项:" << endl;
    cin >> choice;
    return choice;
}

void choice_1(address *head)
{
    address *p;
    p = (address *) malloc(sizeof(address));
    cout << "sex(1男0女):";
    cin >> p->data.sex;
    cout << "age:";
    cin >> p->data.age;
    cout << "phone number:";
    cin >> p->data.number;
    cout << "name:";
    cin >> p->data.name;
    cout << "address:";
    cin >> p->data.address;
    p->next = head ->next;
    head->next = p;
    cout << "添加成功！" << endl;
}

void choice_2(address *head)
{
    address *p;
    p = head->next;
    cout << "------------------联系人--------------------" << endl;
    cout << "sex\tage\tnumber\t\tname\taddress\t" << endl;
    while(p != nullptr){
        cout << p->data.sex << "\t" << p->data.age << "\t" << p->data.number << "\t" << p->data.name << "\t" << p->data.address << "\t" << endl;
        p = p->next;
    }
    cout << "------------------联系人--------------------" << endl;
}

void choice_3_4_5(address *head, int choice)
{
    char cname[20];
//    string cname;
    cout << "name:";
    cin >> cname;
    address *p;
    p = head;
    int flag = 0;
    while(p->next != nullptr){
        if(strcmp(p->next->data.name, cname) == 0){
            flag = 1;
            break;
        }
        else
            p = p->next;
    }
    if(flag == 0){
        cout << "查无此人！" << endl;
        return;
    }
    else if(choice == 3){
        address *temp;
        temp = p->next;
        p->next = temp->next;
        free(temp);
        cout << "删除成功！" << endl;
    }
    else if(choice == 4){
        cout << "查找成功！" << endl;
        p = p->next;
        cout << "sex\tage\tnumber\t\tname\taddress\t" << endl;
        cout << p->data.sex << "\t" << p->data.age << "\t" << p->data.number << "\t" << p->data.name << "\t" << p->data.address << "\t" << endl;
    }
    else if(choice == 5){
        p = p->next;
        cout << "sex\tage\tnumber\t\tname\taddress\t" << endl;
        cout << p->data.sex << "\t" << p->data.age << "\t" << p->data.number << "\t" << p->data.name << "\t" << p->data.address << "\t" << endl;
        cout << "请输入修改信息:" << endl;
        cout << "sex(1男0女):";
        cin >> p->data.sex;
        cout << "age:";
        cin >> p->data.age;
        cout << "phone number:";
        cin >> p->data.number;
        cout << "name:";
        cin >> p->data.name;
        cout << "address:";
        cin >> p->data.address;
        cout << "修改成功！" << endl;
    }
}

void choice_6(address *head)
{
    address *p;
    p = head->next;
    while(p != nullptr)
    {
        head->next = p->next;
        free(p);
        p = head->next;
    }
}

int main() {
    int choice;
    address *head;
    head = (address *)malloc(sizeof(address));
    head->next = nullptr;
    while(true){
        choice = menu();
        switch (choice) {
            case 1:
                choice_1(head);
                system("pause");
                break;
            case 2:
                choice_2(head);
                system("pause");
                break;
            case 3:
                choice_3_4_5(head, 3);
                system("pause");
                break;
            case 4:
                choice_3_4_5(head, 4);
                system("pause");
                break;
            case 5:
                choice_3_4_5(head, 5);
                system("pause");
                break;
            case 6:
                int f;
                cout << "是否确认删除?确定请输入1:";
                cin >> f;
                if(f != 1){
                    cout << "取消删除！" << endl;
                }
                else{
                    choice_6(head);
                    cout << "清空成功！" << endl;
                }
                system("pause");
                break;
            case 7:
                break;
            default:
                cout << "输入错误,请重新输入！" << endl;
                system("pause");
        }
        if(choice == 7){
            // 关闭电话簿自动清除内存
            choice_6(head);
            free(head);
            break;
        }
    }

}