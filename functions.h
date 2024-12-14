#pragma once

// Кол-во параметров степенной функции
#define PARAMS_DEGREES 6

// Кол-во параметров экспоненциальной функции
#define PARAMS_EXPONENTIAL 2

// Кол-во параметров синусоидовой функции
#define PARAMS_SINUSOIDAL 2

/*
 * \brief Описывает многочлен степени 5.
 * \param [in] x - значение переменной
 * \param [in] p - параметры, коэффиценты при соответствующих степенях
*/
double degrees_func(double x, const double *p);

/*
 * \brief Описывает экспоненциальную функцию вида: a*e^{b*x}
 * \param [in] x - значение переменной
 * \param [in] p - параметры, коэффиценты a и b
*/
double exponential_func(double x, const double* p);

/*
 * \brief Описывает синусоидувую  функцию вида: A*sin(x+phi)
 * \param [in] x - значение переменной
 * \param [in] p - параметры, коэффиценты A и phi
*/
double sinusoidal_func(double x, const double* p);
