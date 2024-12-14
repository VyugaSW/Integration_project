#pragma once

#include "numFuncsIntegrations.h"
#include <stdlib.h>
#include <math.h>

/*
 * \brief тип функции, определённой в functions.h
*/
typedef enum {
    EXPONENTIAL,
    DEGREES,
    SINUSOIDAL
} ETypeFunction;

/*
 * \brief тип метода интегрирования, определённого в numFuncIntegrations.h
*/
typedef enum {
    LEFTRECTANGLES,
    RIGHTRECTANGLES,
    MIDDLERECTANGLES,
    PARABOLAS
} ETypeIntegration;

/*
 * \brief тип метода адаптивного интегрирования, определённого в numFuncIntegrations.h
*/
typedef enum{
    ADAPTIVE,
    NOADAPTIVE
} ETypeMethod;

/*
 * \brief Выбор пользователем функции для интегрирования
 * \param [in] func - доступные функции в виде строкового массива
 * \param [in] length - длина func (вторая размерность) 
 * \return тип выбранной функции как ETypeFunction
*/
ETypeFunction chooseFunction(const char* funcs[], size_t length);

/*
 * \brief Ввод пользователем параметров функции
 * \param [out] p - массив коэффицентов
 * \param [in] lenght_p - длина массива p
 * \param [in] formula - формула выбранной фукнции, для которой осуществляется ввод коэффицентов в массив p
*/
void getParams(double *p, size_t length_p, const char* formula);

/*
 * \brief Ввод пользователем метода интегрирования
 * \param [in] integrationMethods - доступные методы интегрирования в виде строкового массива
 * \param [in] length - длина integrationMethods (вторая размерность) 
 * \return тип выбранного метода как ETypeIntegration
*/
ETypeIntegration chooseIntegrationMethod(const char* integrationMethods[], size_t length);

/*
 * \brief Ввод пользователем адаптивного метода
 * \param [in] adaptiveMethods - доступные методы адаптивного интегрирования в виде строкового массива
 * \param [in] length - длина adaptiveMethods (вторая размерность) 
 * \return тип выбранного метода как ETypeMethod
*/
ETypeMethod chooseAdaptiveMethod(const char* adaptiveMethods[], size_t length);

/*
 * \brief Ввод пользователем начала и конца отрезка
 * \param [out] a - начало отрезка
 * \param [out] b - конец отрезка
*/
void enterInterval(double *a, double *b);

/*
 * \brief Ввод пользователем количество отрезков разбиения
 * \param [out] n - количество отрезков разбиения
*/
void enterNumSplitSegments(unsigned *n);

/*
 * \brief Ввод пользователем погрешности
 * \param [out] eps - погрешность 
*/
void enterEps(double *eps);