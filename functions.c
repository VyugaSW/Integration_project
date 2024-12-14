#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double degrees_func(double x, const double *p){
    if(p == NULL)
        return NAN;

    double res = 0;
    
    for(size_t i = 0; i < PARAMS_DEGREES; ++i)
        res += pow(x,i)*p[i];
    
    
    return res;
}

double exponential_func(double x, const double* p) {
    if(p == NULL)
        return NAN;

    return p[0] * exp(p[1] * x);
}

double sinusoidal_func(double x, const double* p) {
    return p[0] * sin(x + p[1]);
}