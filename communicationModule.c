#include "communicationModule.h"
#include <stdio.h>

ETypeFunction chooseFunction(const char* funcs[], size_t length){
    printf("\nДоступные функции:\n");
    for(size_t i = 0; i < length; ++i)
        printf("%zu. %s\n",i+1,funcs[i]);

    printf("Введите номер выбранной функции: ");
    unsigned choose = 0;
    scanf("%u",&choose);

    return choose-1;
}

void getParams(double *p,  size_t length_p, const char* formula){
    printf("\nВыбранная функция: %s\n", formula);

    for (size_t i = 0; i < length_p; i++) {
        printf("\nВведите значение для %zu-го коэффицента: \n", i+1);
        scanf("%lf",&p[i]);
    }
}

ETypeIntegration chooseIntegrationMethod(const char* integrationMethods[], size_t length){
    printf("\nДоступные методы интеграции:\n");
    for(size_t i = 0; i < length; ++i)
        printf("%zu. %s\n",i+1,integrationMethods[i]);

    printf("Введите номер выбранного метода: ");
    unsigned choose = 0;
    scanf("%u",&choose);

    return choose-1;
}

ETypeMethod chooseAdaptiveMethod(const char* adaptiveMethods[], size_t length){
    printf("\nВыберите адаптивный метод:\n");
    for(size_t i = 0; i < length; ++i)
        printf("%zu. %s\n",i+1,adaptiveMethods[i]);

    printf("Введите номер выбранного метода: ");
    unsigned choose = 0;
    scanf("%u",&choose);

    return choose-1;
}

void enterInterval(double *a, double *b){
    printf("\nВведите начало и конец отрезка (через пробел): \n");
    scanf("%lf %lf",*&a, *&b);
}

void enterNumSplitSegments(unsigned *n){
    printf("\nВведите количество отрезков разбиения: \n");
    scanf("%u",*&n);
}

void enterEps(double *eps){
    printf("\nВведите погрешность при адаптивном методе: \n");
    scanf("%lf",*&eps);
}