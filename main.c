#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

/* Задание 13.1
 *  Реализовать функции численного интегрирования указанным методом. Аргументом функции
 *  должны выступать границы промежутка, указатель на функцию (одного аргумента типа
 *  double с возвращаемым значением типа double и входного массива параметров double*) и
 *  число точек разбиения промежутка
 *
 * 
 * Задание 13.2. Реализовать функцию, которая с помощью функции 13.1 проводит интегрирование методом
 *  итераций, увеличивая число разбиений промежутка в 2 раза на каждом шаге до тех пор, пока
 *  два последовательных результата не окажутся отличающимися менее, чем на ? (относительная погрешность) 
 *  Аргументом функции должны выступать границы промежутка, указатель на функцию 
 *  (одного аргумента типа double с возвращаемым значением типа double и
 *  входного массива параметров double*), относительная погрешность и указатель на функцию
 *  численного интегрирования 13.1.
 * 
 * Задание 13.3. Протестировать функцию 13.2 на различных функциях и промежутках. 
 *  Функции интегрирования, интегрируемые функции и интерфейс должны быть реализованы в отдельных единицах
 *  трансляции.
 * 
 *  Входные параметры: function - функция, что будет интегрирована, 
 *                     p - параметры, коэффиценты при соответствующих степенях для функции fnc_t
 *                     a - левая граница отрезка 
 *                     b - правая граница отрезкаn
 *                     n - число отрезков разбиения 
 * 
 *  Выходные параметры: значение интеграла
 * 
 *  Выполнил: Мальгин Анатолий Иванович
*/

#include "numFuncsIntegrations.h"
#include "functions.h"
#include "communicationModule.h"


#define LENGTH_AVAILABLE_FUNCTIONS 3
#define LENGTH_AVAILABLE_INTEGRATIONS_METHODS 4
#define LENGTH_AVAILABLE_ADAPTIVE_METHODS 2

int main(){
    setlocale(LC_CTYPE,"Russian");

    /*
     * Различные перечисления enum, реализованные в communicationModule.h,
     * соответствуют индексам массивов available - доступными функция/методами интегрирования/адаптивными методами
    */
    const char *avalaibleFunctions[LENGTH_AVAILABLE_FUNCTIONS] = {
        "a*e^{b*x}",
        "a+b*x+c*x^{2}+...+f*x^{9}",
        "A*sin(x+phi)"
    };

    const char *availableIntegrationsMethods[LENGTH_AVAILABLE_INTEGRATIONS_METHODS] = {
        "Метод левых прямоугольников",
        "Метод правых прямоугольников",
        "Метод средних прямоугольников",
        "Метод парабол"
    };

    const char *availableAdaptiveMethods[LENGTH_AVAILABLE_ADAPTIVE_METHODS] = {
        "Адаптивный метод",
        "Неадаптивный метод"
    };

    ETypeFunction choosenTypeFunction = chooseFunction(avalaibleFunctions,LENGTH_AVAILABLE_FUNCTIONS);

    size_t length_p = 0;
    fnc_t *choosenFunction = NULL;

    switch (choosenTypeFunction)
    {
        case SINUSOIDAL:
            length_p = PARAMS_SINUSOIDAL;
            choosenFunction = sinusoidal_func;
            break;
        case EXPONENTIAL:
            length_p = PARAMS_EXPONENTIAL;
            choosenFunction = exponential_func;
            break;
        case DEGREES:
            length_p = PARAMS_DEGREES;
            choosenFunction = degrees_func;
            break;
        default:
            break;
    }

    double p[length_p];
    getParams(p,length_p,avalaibleFunctions[choosenTypeFunction]);

    ETypeIntegration choosenTypeIntegration = chooseIntegrationMethod(availableIntegrationsMethods,LENGTH_AVAILABLE_INTEGRATIONS_METHODS);

    qf_t *choosenIntegration = NULL;
    switch (choosenTypeIntegration)
    {
        case LEFTRECTANGLES:
            choosenIntegration = left_rectangles_integration;
            break;
        case RIGHTRECTANGLES:
            choosenIntegration = right_rectangles_integration;
            break;
        case MIDDLERECTANGLES:
            choosenIntegration = middle_rectangles_integration;
            break;
        case PARABOLAS:
            choosenIntegration = parabolas_integration;
            break;
        default:
            break;
    }

    ETypeMethod choosenAdaptiveMethod = chooseAdaptiveMethod(availableAdaptiveMethods, LENGTH_AVAILABLE_ADAPTIVE_METHODS);
    double result = 0;
    double a = 0;
    double b = 0;
    unsigned n = 0;
    double eps = 0;

    switch (choosenAdaptiveMethod)
    {
        case NOADAPTIVE:
            enterInterval(&a,&b);
            enterNumSplitSegments(&n);
            result = choosenIntegration(choosenFunction,p,a,b,n);

            printf("\nРезультат: %lf\n", result);
            printf("\nТаблица интегрирования:\n");
            switch (choosenTypeIntegration)
            {
                case LEFTRECTANGLES:
                    print_table_rectangles(choosenFunction,p,a,b,n,0);
                    break;
                case RIGHTRECTANGLES:
                    print_table_rectangles(choosenFunction,p,a,b,n,0.5);
                    break;
                case MIDDLERECTANGLES:
                    print_table_rectangles(choosenFunction,p,a,b,n,1);
                    break;
                case PARABOLAS:
                    print_table_parabolas(choosenFunction,p,a,b,n);
                    break;
                default:
                    break;
            }

            break;

        case ADAPTIVE:
            enterInterval(&a,&b);
            enterEps(&eps);
            result = integration_iter(choosenIntegration,choosenFunction,p,a,b,eps);
            printf("\nРезультат: %lf\n", result);
            break;

        default:
            break;
    }

    return 0;
}