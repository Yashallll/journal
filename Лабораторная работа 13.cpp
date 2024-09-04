// Лабораторная работа 13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
class Student
{
private:
    string Surname;
    string Name;
    string Birth;
    int Math;
    int Info;
    int Rus;

public:
    void set_Surname()
    {
        cout << "Введите Фамилию студента: ";
        cin >> Surname;
    }
    void set_Name()
    {
        cout << "Введите Имя студента: ";
        cin >> Name;
    }
    void set_Birth()
    {
        cout << "Введите Дату рождения студента: ";
        cin >> Birth;
        int a, b, c;
        string str2;
        string str3;
        a = Birth.find('.', 0);
        str2 = Birth.substr(0, a);
        b = stoi(str2);//день
        Birth.erase(0, a + 1);
        a = Birth.find('.', 0);
        str3 = Birth.substr(0, a);
        c = stoi(str3);//месяц
        if (c == 1 || c == 3 || c == 5 || c == 7 || c == 8 || c == 10 || c == 12) {
            if (b <= 31) {
                cout << "Дата введена верно!"<< endl;
            }
            else {
                cout << "Дата введена неверно! Повторите ввод!"<<endl;
                set_Birth();
            }
        }
        else {
            if (c == 2 || c == 4 || c == 6 || c == 9 || c == 11) {
                if (b <= 30) {
                    cout << "Дата введена верно!"<<endl;
                }
                else {
                    cout << "Дата введена неверно! Повторите ввод!"<<endl;
                    set_Birth();
                }
            }
            else {
                cout << "Дата введена неверно! Повторите ввод!"<<endl;
                set_Birth();
            }
        }
    }
    void set_Math()
    {
        cout << "Введите Отметку по математике студента: ";
        cin >> Math;
    }
    void set_Info()
    {
        cout << "Введите Отметку по информатике студента: ";
        cin >> Info;
    }
    void set_Rus()
    {
        cout << "Введите Отметку по русскому языку студента: ";
        cin >> Rus;
    }

    string get_Surname()
    {
        return Surname;
    }
    string get_Name()
    {
        return Name;
    }
    string get_Birth()
    {
        return Birth;
    }
    int get_Math()
    {
        return Math;
    }
    int get_Info()
    {
        return Info;
    }
    int get_Rus()
    {
        return Rus;
    }

    double Average(int math, int info, int rus)
    {
        return (math + info + rus) / 3.0;
    }
    bool Marks(int math, int info, int rus)
    {
        int n = 0;
        int a, b, c;
        string str2;
        string str3;
        a = Birth.find('.', 0);
        str2 = Birth.substr(0, a);
        b = stoi(str2);//месяц
        Birth.erase(0, a + 1);
        a = Birth.find('.', 0);
        str3 = Birth.substr(0, a);
        c = stoi(str3);//год
        bool x = false;
        if (b == 6 || b == 7 || b == 8)
            if (math < 3 || info < 3 ||  rus < 3)
                x = true;
            else
                x  = false;
        return x;
    }
};


int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    int n = 0;
    cout << "Введите количество студентов: ";
    while (!(cin >> n) || (cin.peek() != '\n') || (n <= 0))
    {
        cin.clear();
        cout << "Введено неверное значение введите еще раз!" << endl;
        cin.ignore(256, '\n');
    }
    vector <Student> mas(n);
    for (int i = 0; i < n; i++)
    {
        mas[i].set_Surname();
        mas[i].set_Name();
        mas[i].set_Birth();
        mas[i].set_Math();
        mas[i].set_Info();
        mas[i].set_Rus();
    }
    cout << "|----------------|--------------------------|------------------------|" << endl;
    cout << "|----Фамилия-----|------------Имя-----------|-----Средняя-отметка----|" << endl;
    cout << "|----------------|--------------------------|------------------------|" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "|" <<setw(15) << fixed << setprecision(4) << mas[i].get_Surname() <<
            " |" << setw(26) << mas[i].get_Name() << "| " << setw(22) << mas[i].Average(mas[i].get_Math(), mas[i].get_Info(), mas[i].get_Rus()) <<
            " |" << endl;
        cout << "|----------------|--------------------------|------------------------|" << endl;
    }

    cout << "Студенты, родиившиеся летом и имеющие неудволетворительные отметки: " << endl;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i].Marks(mas[i].get_Math(), mas[i].get_Info(), mas[i].get_Rus())==true)
        {
            k++;
            cout << mas[i].get_Surname() << endl;
        }
    }
    if (k == 0) cout << "отсутствуют!";
    return 0;
}
