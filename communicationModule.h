#pragma once

#include "numFuncsIntegrations.h"
#include <stdlib.h>
#include <math.h>

/*
 * \brief ��� �������, ����������� � functions.h
*/
typedef enum {
    EXPONENTIAL,
    DEGREES,
    SINUSOIDAL
} ETypeFunction;

/*
 * \brief ��� ������ ��������������, ������������ � numFuncIntegrations.h
*/
typedef enum {
    LEFTRECTANGLES,
    RIGHTRECTANGLES,
    MIDDLERECTANGLES,
    PARABOLAS
} ETypeIntegration;

/*
 * \brief ��� ������ ����������� ��������������, ������������ � numFuncIntegrations.h
*/
typedef enum{
    ADAPTIVE,
    NOADAPTIVE
} ETypeMethod;

/*
 * \brief ����� ������������� ������� ��� ��������������
 * \param [in] func - ��������� ������� � ���� ���������� �������
 * \param [in] length - ����� func (������ �����������) 
 * \return ��� ��������� ������� ��� ETypeFunction
*/
ETypeFunction chooseFunction(const char* funcs[], size_t length);

/*
 * \brief ���� ������������� ���������� �������
 * \param [out] p - ������ ������������
 * \param [in] lenght_p - ����� ������� p
 * \param [in] formula - ������� ��������� �������, ��� ������� �������������� ���� ������������ � ������ p
*/
void getParams(double *p, size_t length_p, const char* formula);

/*
 * \brief ���� ������������� ������ ��������������
 * \param [in] integrationMethods - ��������� ������ �������������� � ���� ���������� �������
 * \param [in] length - ����� integrationMethods (������ �����������) 
 * \return ��� ���������� ������ ��� ETypeIntegration
*/
ETypeIntegration chooseIntegrationMethod(const char* integrationMethods[], size_t length);

/*
 * \brief ���� ������������� ����������� ������
 * \param [in] adaptiveMethods - ��������� ������ ����������� �������������� � ���� ���������� �������
 * \param [in] length - ����� adaptiveMethods (������ �����������) 
 * \return ��� ���������� ������ ��� ETypeMethod
*/
ETypeMethod chooseAdaptiveMethod(const char* adaptiveMethods[], size_t length);

/*
 * \brief ���� ������������� ������ � ����� �������
 * \param [out] a - ������ �������
 * \param [out] b - ����� �������
*/
void enterInterval(double *a, double *b);

/*
 * \brief ���� ������������� ���������� �������� ���������
 * \param [out] n - ���������� �������� ���������
*/
void enterNumSplitSegments(unsigned *n);

/*
 * \brief ���� ������������� �����������
 * \param [out] eps - ����������� 
*/
void enterEps(double *eps);