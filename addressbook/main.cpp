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
    cout << "1.�����ϵ��" << endl;
    cout << "2.��ʾ��ϵ��" << endl;
    cout << "3.ɾ����ϵ��" << endl;
    cout << "4.������ϵ��" << endl;
    cout << "5.�޸���ϵ��" << endl;
    cout << "6.�����ϵ��" << endl;
    cout << "7.�˳��绰��" << endl;
    cout << "--------------------------" << endl;
    cout << "����������Ҫ��ѡ��:" << endl;
    cin >> choice;
    return choice;
}

void choice_1(address *head)
{
    address *p;
    p = (address *) malloc(sizeof(address));
    cout << "sex(1��0Ů):";
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
    cout << "��ӳɹ���" << endl;
}

void choice_2(address *head)
{
    address *p;
    p = head->next;
    cout << "------------------��ϵ��--------------------" << endl;
    cout << "sex\tage\tnumber\t\tname\taddress\t" << endl;
    while(p != nullptr){
        cout << p->data.sex << "\t" << p->data.age << "\t" << p->data.number << "\t" << p->data.name << "\t" << p->data.address << "\t" << endl;
        p = p->next;
    }
    cout << "------------------��ϵ��--------------------" << endl;
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
        cout << "���޴��ˣ�" << endl;
        return;
    }
    else if(choice == 3){
        address *temp;
        temp = p->next;
        p->next = temp->next;
        free(temp);
        cout << "ɾ���ɹ���" << endl;
    }
    else if(choice == 4){
        cout << "���ҳɹ���" << endl;
        p = p->next;
        cout << "sex\tage\tnumber\t\tname\taddress\t" << endl;
        cout << p->data.sex << "\t" << p->data.age << "\t" << p->data.number << "\t" << p->data.name << "\t" << p->data.address << "\t" << endl;
    }
    else if(choice == 5){
        p = p->next;
        cout << "sex\tage\tnumber\t\tname\taddress\t" << endl;
        cout << p->data.sex << "\t" << p->data.age << "\t" << p->data.number << "\t" << p->data.name << "\t" << p->data.address << "\t" << endl;
        cout << "�������޸���Ϣ:" << endl;
        cout << "sex(1��0Ů):";
        cin >> p->data.sex;
        cout << "age:";
        cin >> p->data.age;
        cout << "phone number:";
        cin >> p->data.number;
        cout << "name:";
        cin >> p->data.name;
        cout << "address:";
        cin >> p->data.address;
        cout << "�޸ĳɹ���" << endl;
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
                cout << "�Ƿ�ȷ��ɾ��?ȷ��������1:";
                cin >> f;
                if(f != 1){
                    cout << "ȡ��ɾ����" << endl;
                }
                else{
                    choice_6(head);
                    cout << "��ճɹ���" << endl;
                }
                system("pause");
                break;
            case 7:
                break;
            default:
                cout << "�������,���������룡" << endl;
                system("pause");
        }
        if(choice == 7){
            // �رյ绰���Զ�����ڴ�
            choice_6(head);
            free(head);
            break;
        }
    }

}