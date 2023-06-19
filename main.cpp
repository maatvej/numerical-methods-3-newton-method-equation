#include <iostream>
#include <cmath>
#include<iomanip>
#include<conio.h>
using namespace std;
int k = 0;

float f(float x) //функция по которой вычисляем  нужные нам корни
{
    float y;
    y = x*x+4*sin(x)-2;
    return y;
}

float f1(float x) { //первая производная
    float z;
    z = 2*x+4*cos(x);
    return z;
}

float f2(float x) { //вторая производная
    float u;
    u = 2;
    return u;
}

float function(float a, float b, float e) {// функция вычисляет по методу хорд и касательных
    float c;
    do {
        cout<<"Итерация №"<< k<<" :"<< "[" <<a<<" ; "<<b<<"]"<<endl;

        if (f(a) * f2(a) < 0) {//Условие начальной точки для метода хорд
            a = a + (b - a) / (f(a) - f(b))*f(a); //формулы расчета по методу хорд
            b = b - f(b) / f1(b);
        }
        else if (f(a) * f2(a) > 0) {//Условие начальной точки для метода касательных
            a = a - f(a) / f1(a); //формулы расчета по методу касательных
            b = b + (b - a) / (f(b) - f(a))*f(b);
        }
        else
        {
            cout << "can't solve\n";
            break;
        }
        k++;

    }
    while (fabs(b - a) > e);//Построение хорд и касательных продолжается до достижения необходимой точности решения е
    cout<<"Итерация №"<< k<<" :"<< "[" <<a<<" ; "<<b<<"]"<<endl;
    return (a + b) / 2.0;
}

int main()
{
    setlocale(LC_ALL, "rus");
    double a, b, e = 0.0001, F, pr = 1;
    cout << "Комбинированный метод Ньютона и хорд" << endl;
    cout << endl;
    while (pr != 0) {
        cout << "Введите начало отрезка a" << endl;
        cin >> a;
        cout << "Введите конец отрезка b" << endl;
        cin >> b;
        if (f(a)*f(b) < 0)//отрезок на концах которых функция имеет разный знак
        {
            pr = 0;//находим значение функции от а и b
            cout << setw(40) << "f(a) = " << "f(" << a << ") = " << f(a) << endl;
            cout << setw(40) << "f(b) = " << "f(" << b << ") = " << f(b) << endl;
            cout << endl;
        }
        else cout << setw(75) << "КОРНЕЙ НЕТ! ПОПЫТАЙТЕСЬ ВВЕСТИ ДРУГИЕ ЗНАЧЕНИЯ НАЧАЛА И КОНЦА ОТРЕЗКА!" << endl;
        cout << endl;
    }
    F = function(a, b, e);
    cout << "РЕЗУЛЬТАТ X = "  << F << endl;//выводим результат на экран
    cout << "Количество итераций: " << k << endl;
    cout << "Проверка f(x) = " ;
    cout << setprecision(10) << f(F);
    cout << endl;
    _getch();
    return 0;
}
