#include "numFuncsIntegrations.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void print_table_rectangles(fnc_t function, const double *p, double a, double b, unsigned n, double offset){
    if(function != NULL && p != NULL){
        double dx = (b-a)/n;
        double x = 0;

        printf("x\t\tf(x)\n");
        printf(" \t\t    \n");
        for(int i = 0; i < n; ++i){
            x = a + (i+offset) * dx;
            printf("%le\t%le\n",x,function(x,p));
        }

        printf("\n");
    }
    else
        printf("\nФункция или массив параметров пустой!\n");
}

void print_table_parabolas(fnc_t function, const double *p, double a, double b, unsigned n){
    if(function != NULL && p != NULL){
        if (n % 2 != 0) 
            n++; // n должно быть четным

        double dx = (b - a) / n; 
        double x = 0;

        printf("i\tx\t\tf(x)\n");
        printf(" \t \t\t    \n");
        for (int i = 1; i < n; i++) {
            x = a + i * dx;     
            printf("%d\t%lf\t%lf\n",i, x, function(x,p));
        }
    }
    else
        printf("\nФункция или массив параметров пустой!\n");
}



double left_rectangles_integration(fnc_t function, const double *p, double a, double b, unsigned n){
    if(function == NULL || p == NULL)
        return NAN;

    double dx = (b-a)/n;
    double area = 0;
    double x = 0;

    for (int i = 0; i < n; i++) {
        x = a + i * dx; 
        area += function(x, p); 
    }

    return area * dx;
}

double right_rectangles_integration(fnc_t function, const double *p, double a, double b, unsigned n){
    if(function == NULL || p == NULL)
        return NAN;

    double dx = (b-a)/n;
    double area = 0;
    double x = 0;

    for (int i = 0; i < n; i++) {
        x = a + (i+1) * dx; 
        area += function(x, p); 
    }

    return area * dx;
}

double middle_rectangles_integration(fnc_t function, const double *p, double a, double b, unsigned n){
    if(function == NULL || p == NULL)
        return NAN;

    double dx = (b-a)/n;
    double area = 0;
    double x = 0;

    for (int i = 0; i < n; i++) {
        x = a + (i + 0.5) * dx; 
        area += function(x, p); 
    }

    return area * dx;
}

double parabolas_integration(fnc_t function, const double *p, double a, double b, unsigned n){
    if(function == NULL || p == NULL)
        return NAN;

    if (n % 2 != 0) 
        n++; // n должно быть четным

    double dx = (b - a) / n; 
    double area = function(a,p) + function(b,p);
    double x = 0;

    for (int i = 1; i < n; i++) {
        x = a + i * dx;
        area += (i % 2 == 0 ? 2 : 4) * function(x,p);
    }

    return (dx / 3) * area; 
}

double integration_iter(qf_t integrateFunc, fnc_t function, const double *p, double a, double b, double eps){
    unsigned n = 1; // Начальное кол-во отрезков разбиения
    double previous_res = integrateFunc(function,p,a,b,n);
    double current_res = 0;

    unsigned iters = 0;
    
    do{
        ++iters;
        n*=2;
        previous_res = current_res;
        current_res = integrateFunc(function,p,a,b,n);

        if(iters >= 50)
            break;

    } while(fabs(current_res - previous_res) > eps);

    return current_res;
}