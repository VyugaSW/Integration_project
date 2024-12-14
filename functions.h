#pragma once

// ���-�� ���������� ��������� �������
#define PARAMS_DEGREES 6

// ���-�� ���������� ���������������� �������
#define PARAMS_EXPONENTIAL 2

// ���-�� ���������� ������������ �������
#define PARAMS_SINUSOIDAL 2

/*
 * \brief ��������� ��������� ������� 5.
 * \param [in] x - �������� ����������
 * \param [in] p - ���������, ����������� ��� ��������������� ��������
*/
double degrees_func(double x, const double *p);

/*
 * \brief ��������� ���������������� ������� ����: a*e^{b*x}
 * \param [in] x - �������� ����������
 * \param [in] p - ���������, ����������� a � b
*/
double exponential_func(double x, const double* p);

/*
 * \brief ��������� ������������  ������� ����: A*sin(x+phi)
 * \param [in] x - �������� ����������
 * \param [in] p - ���������, ����������� A � phi
*/
double sinusoidal_func(double x, const double* p);
