#pragma once

/*
 * \brief ���������� ��� �������, ����������� ��� double � ����������� ���� double, const double *
*/
typedef double fnc_t (double, const double* );

/*
 * \brief ���������� ��� ������� ������ ��������������
*/
typedef double qf_t (fnc_t function, const double *p, double a, double b, unsigned n);

/*
 * \brief ������� �������� ������� �������������� ��� ������� ���������������
 * \param [in] function - �������, ��� ����� �������������
 * \param [in] p - ���������, ����������� ��� ��������������� �������� ��� ������� fnc_t
 * \param [in] a - ����� ������� �������
 * \param [in] b - ������ ������� �������
 * \param [in] n - ����� �������� ���������
 * \param [in] offset - ���������� ��� ������ ���������������
*/
void print_table_rectangles(fnc_t function, const double *p, double a, double b, unsigned n, double offset);

/*
 * \brief ������� �������� ������� �������������� ��� ������� �������
 * \param [in] function - �������, ��� ����� �������������
 * \param [in] p - ���������, ����������� ��� ��������������� �������� ��� ������� fnc_t
 * \param [in] a - ����� ������� �������
 * \param [in] b - ������ ������� �������
 * \param [in] n - ����� �������� ���������
*/
void print_table_parabolas(fnc_t function, const double *p, double a, double b, unsigned n);

/*
 * \brief ������� ���������� �������������� ������� ����� ���������������
 * \param [in] function - �������, ��� ����� �������������
 * \param [in] p - ���������, ����������� ��� ��������������� �������� ��� ������� fnc_t
 * \param [in] a - ����� ������� �������
 * \param [in] b - ������ ������� �������
 * \param [in] n - ����� �������� ���������
 * \return ����������� ��������
*/
double left_rectangles_integration(fnc_t function, const double *p, double a, double b, unsigned n);

/*
 * \brief ������� ���������� �������������� ������� ������ ���������������
 * \param [in] function - �������, ��� ����� �������������
 * \param [in] p - ���������, ����������� ��� ��������������� �������� ��� ������� fnc_t
 * \param [in] a - ����� ������� �������
 * \param [in] b - ������ ������� �������
 * \param [in] n - ����� �������� ���������
 * \return ����������� ��������
*/
double right_rectangles_integration(fnc_t function, const double *p, double a, double b, unsigned n);

/*
 * \brief ������� ���������� �������������� ������� ������� ���������������
 * \param [in] function - �������, ��� ����� �������������
 * \param [in] p - ���������, ����������� ��� ��������������� �������� ��� ������� fnc_t
 * \param [in] a - ����� ������� �������
 * \param [in] b - ������ ������� �������
 * \param [in] n - ����� �������� ���������
 * \return ����������� ��������
*/
double middle_rectangles_integration(fnc_t function, const double *p, double a, double b, unsigned n);

/*
 * \brief ������� ���������� �������������� ������� �������
 * \param [in] function - �������, ��� ����� �������������
 * \param [in] p - ���������, ����������� ��� ��������������� �������� ��� ������� fnc_t
 * \param [in] a - ����� ������� �������
 * \param [in] b - ������ ������� �������
 * \param [in] n - ����� �������� ���������
 * \return ����������� ��������
*/
double parabolas_integration(fnc_t function, const double *p, double a, double b, unsigned n);

/*
 * \brief ������� ���������� �������������� ������� ��������
 * \param [in] integrateFunc - �������, � ������� ������� ����� ����������� ��������������
 * \param [in] function - �������, ��� ����� �������������
 * \param [in] p - ���������, ����������� ��� ��������������� �������� ��� ������� fnc_t
 * \param [in] a - ����� ������� �������
 * \param [in] b - ������ ������� �������
 * \return ����������� ��������
*/
double integration_iter(qf_t integrateFunc, fnc_t function, const double *p, double a, double b, double eps);