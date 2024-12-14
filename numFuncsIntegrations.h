#pragma once

/*
 * \brief Определяет тип функции, возращающую тип double и принимающую типы double, const double *
*/
typedef double fnc_t (double, const double* );

/*
 * \brief Определяет тип функции метода интегрирования
*/
typedef double qf_t (fnc_t function, const double *p, double a, double b, unsigned n);

/*
 * \brief Функция печатает таблицу интегрирования для методов прямоугольников
 * \param [in] function - функция, что будет интегрирована
 * \param [in] p - параметры, коэффиценты при соответствующих степенях для функции fnc_t
 * \param [in] a - левая граница отрезка
 * \param [in] b - правая граница отрезка
 * \param [in] n - число отрезков разбиения
 * \param [in] offset - определяет тип метода прямоугольников
*/
void print_table_rectangles(fnc_t function, const double *p, double a, double b, unsigned n, double offset);

/*
 * \brief Функция печатает таблицу интегрирования для методов парабол
 * \param [in] function - функция, что будет интегрирована
 * \param [in] p - параметры, коэффиценты при соответствующих степенях для функции fnc_t
 * \param [in] a - левая граница отрезка
 * \param [in] b - правая граница отрезка
 * \param [in] n - число отрезков разбиения
*/
void print_table_parabolas(fnc_t function, const double *p, double a, double b, unsigned n);

/*
 * \brief Функция численного интегрирования методом левых прямоугольников
 * \param [in] function - функция, что будет интегрирована
 * \param [in] p - параметры, коэффиценты при соответствующих степенях для функции fnc_t
 * \param [in] a - левая граница отрезка
 * \param [in] b - правая граница отрезка
 * \param [in] n - число отрезков разбиения
 * \return Вычисленный интеграл
*/
double left_rectangles_integration(fnc_t function, const double *p, double a, double b, unsigned n);

/*
 * \brief Функция численного интегрирования методом правых прямоугольников
 * \param [in] function - функция, что будет интегрирована
 * \param [in] p - параметры, коэффиценты при соответствующих степенях для функции fnc_t
 * \param [in] a - левая граница отрезка
 * \param [in] b - правая граница отрезка
 * \param [in] n - число отрезков разбиения
 * \return Вычисленный интеграл
*/
double right_rectangles_integration(fnc_t function, const double *p, double a, double b, unsigned n);

/*
 * \brief Функция численного интегрирования методом средних прямоугольников
 * \param [in] function - функция, что будет интегрирована
 * \param [in] p - параметры, коэффиценты при соответствующих степенях для функции fnc_t
 * \param [in] a - левая граница отрезка
 * \param [in] b - правая граница отрезка
 * \param [in] n - число отрезков разбиения
 * \return Вычисленный интеграл
*/
double middle_rectangles_integration(fnc_t function, const double *p, double a, double b, unsigned n);

/*
 * \brief Функция численного интегрирования методом парабол
 * \param [in] function - функция, что будет интегрирована
 * \param [in] p - параметры, коэффиценты при соответствующих степенях для функции fnc_t
 * \param [in] a - левая граница отрезка
 * \param [in] b - правая граница отрезка
 * \param [in] n - число отрезков разбиения
 * \return Вычисленный интеграл
*/
double parabolas_integration(fnc_t function, const double *p, double a, double b, unsigned n);

/*
 * \brief Функция численного интегрирования методом итераций
 * \param [in] integrateFunc - функция, с помощью которой будет проводиться интегрирование
 * \param [in] function - функция, что будет интегрирована
 * \param [in] p - параметры, коэффиценты при соответствующих степенях для функции fnc_t
 * \param [in] a - левая граница отрезка
 * \param [in] b - правая граница отрезка
 * \return Вычисленный интеграл
*/
double integration_iter(qf_t integrateFunc, fnc_t function, const double *p, double a, double b, double eps);