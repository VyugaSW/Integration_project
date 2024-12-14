#include "communicationModule.h"
#include <stdio.h>

ETypeFunction chooseFunction(const char* funcs[], size_t length){
    printf("\n��������� �������:\n");
    for(size_t i = 0; i < length; ++i)
        printf("%zu. %s\n",i+1,funcs[i]);

    printf("������� ����� ��������� �������: ");
    unsigned choose = 0;
    scanf("%u",&choose);

    return choose-1;
}

void getParams(double *p,  size_t length_p, const char* formula){
    printf("\n��������� �������: %s\n", formula);

    for (size_t i = 0; i < length_p; i++) {
        printf("\n������� �������� ��� %zu-�� �����������: \n", i+1);
        scanf("%lf",&p[i]);
    }
}

ETypeIntegration chooseIntegrationMethod(const char* integrationMethods[], size_t length){
    printf("\n��������� ������ ����������:\n");
    for(size_t i = 0; i < length; ++i)
        printf("%zu. %s\n",i+1,integrationMethods[i]);

    printf("������� ����� ���������� ������: ");
    unsigned choose = 0;
    scanf("%u",&choose);

    return choose-1;
}

ETypeMethod chooseAdaptiveMethod(const char* adaptiveMethods[], size_t length){
    printf("\n�������� ���������� �����:\n");
    for(size_t i = 0; i < length; ++i)
        printf("%zu. %s\n",i+1,adaptiveMethods[i]);

    printf("������� ����� ���������� ������: ");
    unsigned choose = 0;
    scanf("%u",&choose);

    return choose-1;
}

void enterInterval(double *a, double *b){
    printf("\n������� ������ � ����� ������� (����� ������): \n");
    scanf("%lf %lf",*&a, *&b);
}

void enterNumSplitSegments(unsigned *n){
    printf("\n������� ���������� �������� ���������: \n");
    scanf("%u",*&n);
}

void enterEps(double *eps){
    printf("\n������� ����������� ��� ���������� ������: \n");
    scanf("%lf",*&eps);
}