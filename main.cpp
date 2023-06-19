#include <iostream>
#include <cmath>
#include<iomanip>
#include<conio.h>
using namespace std;
int k = 0;

float f(float x) //������� �� ������� ���������  ������ ��� �����
{
    float y;
    y = x*x+4*sin(x)-2;
    return y;
}

float f1(float x) { //������ �����������
    float z;
    z = 2*x+4*cos(x);
    return z;
}

float f2(float x) { //������ �����������
    float u;
    u = 2;
    return u;
}

float function(float a, float b, float e) {// ������� ��������� �� ������ ���� � �����������
    float c;
    do {
        cout<<"�������� �"<< k<<" :"<< "[" <<a<<" ; "<<b<<"]"<<endl;

        if (f(a) * f2(a) < 0) {//������� ��������� ����� ��� ������ ����
            a = a + (b - a) / (f(a) - f(b))*f(a); //������� ������� �� ������ ����
            b = b - f(b) / f1(b);
        }
        else if (f(a) * f2(a) > 0) {//������� ��������� ����� ��� ������ �����������
            a = a - f(a) / f1(a); //������� ������� �� ������ �����������
            b = b + (b - a) / (f(b) - f(a))*f(b);
        }
        else
        {
            cout << "can't solve\n";
            break;
        }
        k++;

    }
    while (fabs(b - a) > e);//���������� ���� � ����������� ������������ �� ���������� ����������� �������� ������� �
    cout<<"�������� �"<< k<<" :"<< "[" <<a<<" ; "<<b<<"]"<<endl;
    return (a + b) / 2.0;
}

int main()
{
    setlocale(LC_ALL, "rus");
    double a, b, e = 0.0001, F, pr = 1;
    cout << "��������������� ����� ������� � ����" << endl;
    cout << endl;
    while (pr != 0) {
        cout << "������� ������ ������� a" << endl;
        cin >> a;
        cout << "������� ����� ������� b" << endl;
        cin >> b;
        if (f(a)*f(b) < 0)//������� �� ������ ������� ������� ����� ������ ����
        {
            pr = 0;//������� �������� ������� �� � � b
            cout << setw(40) << "f(a) = " << "f(" << a << ") = " << f(a) << endl;
            cout << setw(40) << "f(b) = " << "f(" << b << ") = " << f(b) << endl;
            cout << endl;
        }
        else cout << setw(75) << "������ ���! ����������� ������ ������ �������� ������ � ����� �������!" << endl;
        cout << endl;
    }
    F = function(a, b, e);
    cout << "��������� X = "  << F << endl;//������� ��������� �� �����
    cout << "���������� ��������: " << k << endl;
    cout << "�������� f(x) = " ;
    cout << setprecision(10) << f(F);
    cout << endl;
    _getch();
    return 0;
}
