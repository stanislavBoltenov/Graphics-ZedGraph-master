#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include "progonka.h"

using namespace std;

double k1(double xi)
{
    return 1.;
}

double k2(double xi)
{
    return exp(xi * xi);
}

double q1(double xi)
{
    return xi * xi;
}

double q2(double xi)
{
    return 1. + xi * xi * xi * xi;
}

double f1(double xi)
{
    return xi * xi - 1.;
}

double f2(double xi)
{
    return 1.;
}

double test_k1(double xi)
{
    return k1(1. / sqrt(3.));
}

double test_k2(double xi)
{
    return k2(1. / sqrt(3.));
}

double test_q1(double xi)
{
    return q1(1. / sqrt(3.));
}

double test_q2(double xi)
{
    return q2(1. / sqrt(3.));
}

double test_f1(double xi)
{
    return f1(1. / sqrt(3.));
}

double test_f2(double xi)
{
    return f2(1. / sqrt(3.));
}

vector<double> calc_ai(double& a, double& b, long long& n, double& psi, double(*k1)(double), double(*k2)(double))
{
    double xi = a;//x0
    double h = (b - a) / n;
    vector<double> ai(n, 0.);
    double t = 2. / sqrt(3.);
    for (int i = 0; i < n; ++i)
    {
        xi += h;
        if (psi > xi || abs(psi - xi) < 1e-14)
        {
            //ai[i] = h / (h / 2. * (k1((2 * xi - h) / 2. - h / t) + k1((2 * xi - h) / 2. + h / t)));
            ai[i] = 5. / (1. / k1(xi - h) + 3. / k1(2 * xi - h) + 1. / k1(xi));
            //ai[i] = k1(xi - 0.5 * h);
            //ai[i] = 2. * k1(xi - h) * k1(xi) / (k1(xi - h) + k1(xi));
        }
        else if (psi > xi - h && psi < xi)
        {
            //ai[i] = h / ((psi - xi + h) / 2. * (k1((xi - h + psi) / 2. - (psi - xi + h) / t) + k1((xi - h + psi) / 2. + (psi - xi + h) / t)) +
            //      (-psi + xi + h) / 2. * (k2((xi + h + psi) / 2. - (-psi + xi + h) / t) + k2((xi + h + psi) / 2. + (-psi - xi + h) / t)));
            ai[i] = (5. * h) / ((psi - xi + h) * (1. / k1(xi - h) + 3. / k1(xi - h + psi) + 1. / k1(psi))
                + (xi - psi) * (1. / k2(psi) + 3. / k2(xi + psi) + 1. / k2(xi)));
            //ai[i] = 1. / ((1. / h) * (((psi - (xi - h)) / k1(((xi - h) + psi) / 2.)) + (xi - psi) / k1((xi + psi) / 2.)));
        }
        else//psi <= xi
        {
            //ai[i] = h / (h / 2. * (k2((2 * xi - h) / 2. - h / t) + k2((2 * xi - h) / 2. + h / t)));
            ai[i] = 5. / (1. / k2(xi - h) + 3. / k2(2 * xi - h) + 1. / k2(xi));
            //ai[i] = k2(xi - 0.5 * h);
            //ai[i] = 2. * k2(xi - h) * k2(xi) / (k2(xi - h) + k2(xi));
        }
    }
    return ai;
}

vector<double> calc_di(double& a, double& b, long long& n, double& psi, double(*q1)(double), double(*q2)(double))
{
    double xi = a;//x0
    double h = (b - a) / n;
    vector<double> di(n - 1, 0.);
    for (int i = 0; i < n - 1; ++i)
    {
        xi += h;
        if (psi > (xi + 0.5 * h) || abs(psi - xi - 0.5 * h) < 1e-14)
        {
            //di[i] = (1. / h) * (h/2.)
            di[i] = (q1(xi - 0.5 * h) + q1(xi + 0.5 * h) + 3. * q1(2. * xi)) / 5.;
            //di[i] = q1(xi);
            //di[i] = (q1(xi - 0.5 * h) + q1(xi + 0.5 * h)) / 2.;
        }
        else if (psi > (xi - 0.5 * h) && psi < (xi + 0.5 * h))
        {
            di[i] = ((psi - xi + 0.5 * h) * (q1(xi - 0.5 * h) + 3. * q1(xi - 0.5 * h + psi) + q1(psi))
                + (xi + 0.5 * h - psi) * (q2(xi + 0.5 * h) + 3. * q2(xi + 0.5 * h + psi) + q2(psi))) / (5. * h);
            //di[i] = (1. / h) * (q1((xi - 0.5 * h + psi) / 2.) * (psi - xi + 0.5 * h) + q2((xi + 0.5 * h + psi) / 2.) * (xi + 0.5 * h - psi));
        }
        else//psi <= xi-0.5
        {
            di[i] = (q2(xi - 0.5 * h) + q2(xi + 0.5 * h) + 3. * q2(2. * xi)) / 5.;
            //di[i] = q2(xi);
            //di[i] = (q2(xi - 0.5 * h) + q2(xi + 0.5 * h)) / 2.;
        }
    }
    return di;
}

vector<double> calc_fi(double& a, double& b, long long& n, double& psi, double(*f1)(double), double(*f2)(double))
{
    double xi = a;
    double h = (b - a) / n;
    vector<double> fi(n - 1, 0.);
    for (int i = 0; i < n - 1; ++i)
    {
        xi += h;
        if (psi > (xi + 0.5 * h) || abs(psi - xi - 0.5 * h) < 1e-14)
        {
            fi[i] = (f1(xi - 0.5 * h) + f1(xi + 0.5 * h) + 3. * f1(2. * xi)) / 5.;
            //fi[i] = f1(xi);
            //fi[i] = (f1(xi - 0.5 * h) + f1(xi + 0.5 * h)) / 2.;
        }
        else if (psi > (xi - 0.5 * h) && psi < (xi + 0.5 * h))
        {
            fi[i] = ((psi - xi + 0.5 * h) * (f1(xi - 0.5 * h) + 3. * f1(xi - 0.5 * h + psi) + f1(psi))
                + (xi + 0.5 * h - psi) * (f2(xi + 0.5 * h) + 3. * f2(xi + 0.5 * h + psi) + f2(psi))) / (5. * h);
            //fi[i] = (1. / h) * (f1((xi - 0.5 * h + psi) / 2.) * (psi - xi + 0.5 * h) + f2((xi + 0.5 * h + psi) / 2.) * (xi + 0.5 * h - psi));
        }
        else//psi <= xi-0.5
        {
            fi[i] = (f2(xi - 0.5 * h) + f2(xi + 0.5 * h) + 3. * f2(2. * xi)) / 5.;
            //fi[i] = f2(xi);
            //fi[i] = (f2(xi - 0.5 * h) + f2(xi + 0.5 * h)) / 2.;
        }
    }
    return fi;
}

vector<double> calc_lower_diagonal(vector<double>& ai, double& h, long long& n)
{
    vector<double> Ai(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        Ai[i] = ai[i] / (h * h);
    }
    return Ai;
}

vector<double> calc_main_diagonal(vector<double>& ai, vector<double>& di, double& h, long long& n)
{
    vector<double> Ci(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        Ci[i] = di[i] + (ai[i] + ai[i + 1]) / (h * h);
    }
    return Ci;
}

vector<double> calc_upper_diagonal(vector<double>& ai, double& h, long long& n)
{
    vector<double> Bi(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        Bi[i] = ai[i + 1] / (h * h);
    }
    return Bi;
}

vector<double> calc_column_b(double mu1, double mu2, vector<double>& fi, long long& n)
{
    vector<double> b(n + 1);
    b[0] = mu1;
    b[n] = mu2;
    for (int i = 1; i < n; ++i)
    {
        b[i] = fi[i - 1];
    }
    return b;
}

// LD,UD,D  - размерности (n-1), rhs - размерности (n+1) 
int SolveTridiagonalSLAE(const std::vector<double>& LD, const std::vector<double>& D, const std::vector<double>& UD, const std::vector<double>& rhs, std::vector<double>& y)
{
    int iterationsCount = 0;
    if (y.size() == 1) {
        y[0] = rhs[0];
        return 0;
    }
    int n = y.size() - 1;
    std::vector<double> Beta(n), Alpha(n);
    Alpha[0] = 0;
    Beta[0] = rhs[0];
    for (int i = 0; i < n - 1; ++i) {
        Alpha[i + 1] = UD[i] / (D[i] - LD[i] * Alpha[i]);
        Beta[i + 1] = (rhs[i + 1] + LD[i] * Beta[i]) / (D[i] - LD[i] * Alpha[i]);
        iterationsCount += 2;
    }
    y[n] = rhs[n];
    for (int i = n - 1; i >= 0; --i) {
        y[i] = Alpha[i] * y[i + 1] + Beta[i];
        iterationsCount++;
    }
    return iterationsCount;
}

double check(const std::vector<double>& LD, const std::vector<double>& D, const std::vector<double>& UD, const std::vector<double>& rhs, std::vector<double>& y)
{
    int n = y.size();
    std::vector<double> lhs(n);
    lhs[0] = y[0];
    for (int i = 1; i < n - 1; ++i) {
        lhs[i] = LD[i - 1] * y[i - 1] - D[i - 1] * y[i] + UD[i - 1] * y[i + 1];
    }
    lhs[n - 1] = y[n - 1];
    std::vector<double> residual(n);
    residual[0] = lhs[0] - rhs[0];
    for (int i = 1; i < n - 1; ++i) {
        residual[i] = lhs[i] + rhs[i];
    }
    residual[n - 1] = lhs[n - 1] - rhs[n - 1];
    double mx = -1.;
    for (int i = 0; i < n; ++i) {
        if (abs(residual[i]) > mx)
            mx = abs(residual[i]);
    }
    return mx;
}

vector<double> calc_test_task(long long n)
{
    double a = 0., b = 1.;
    double h = (b - a) / n;
    double mu1 = 2, mu2 = 1., psi = 1. / sqrt(3.);
    vector<double> ai = calc_ai(a, b, n, psi, test_k1, test_k2);
    vector<double> di = calc_di(a, b, n, psi, test_q1, test_q2);
    vector<double> fi = calc_fi(a, b, n, psi, test_f1, test_f2);
    vector<double> LD = calc_lower_diagonal(ai, h, n);
    vector<double> D = calc_main_diagonal(ai, di, h, n);
    vector<double> UD = calc_upper_diagonal(ai, h, n);
    vector<double> rhs = calc_column_b(mu1, mu2, fi, n), v(n + 1, 0.0);
    cout << SolveTridiagonalSLAE(LD, D, UD, rhs, v) << endl;
    cout << check(LD, D, UD, rhs, v) << endl;
    return v;
}

vector<double> calc_main_task(long long n)
{
    double a = 0., b = 1.;
    double h = (b - a) / n;
    double mu1 = 2, mu2 = 1., psi = 1. / sqrt(3.);
    vector<double> ai = calc_ai(a, b, n, psi, k1, k2);
    vector<double> di = calc_di(a, b, n, psi, q1, q2);
    vector<double> fi = calc_fi(a, b, n, psi, f1, f2);
    vector<double> LD = calc_lower_diagonal(ai, h, n);
    vector<double> D = calc_main_diagonal(ai, di, h, n);
    vector<double> UD = calc_upper_diagonal(ai, h, n);
    vector<double> rhs = calc_column_b(mu1, mu2, fi, n), v(n + 1, 0.0);

    //проверка условий приминимости прогонки, для тестирования
    for (int i = 0; i < n - 1; ++i)
    {
        if (abs(D[i]) < abs(LD[i]) + abs(UD[i]))
        {
            cout << "error " << i << endl;
        }
        if (abs(LD[i]) < 1e-8)
        {
            cout << "error " << i << endl;
        }
        if (UD[i] < 0 || LD[i] < 0 || D[i] < 0)
        {
            cout << "error " << i << endl;
        }
    }

    //cout << SolveTridiagonalSLAE(LD, D, UD, rhs, v) << endl;
    SolveTridiagonalSLAE(LD, D, UD, rhs, v);
    check(LD, D, UD, rhs, v);
    return v;
}

// аналитическое решение тестовой задачи
double A = 0.58713364002861877025803583224850669768296290762799;
double B = 3.412866359971381229741964167751493302317037092372;
double C = -0.11620934500084417511626982342917373525649977045689;
double D = 0.93630688062153035342809225482419632831655290451774;
double alpha = 0.89227008278746162739521688624670878476520943583276;

double u1(double x) // x прин [0; кси)
{
    return A * exp(x / sqrt(3.)) + B * exp(-x / sqrt(3.)) - 2;
}

double u2(double x) // x прин (кси; 1]
{
    return C * exp(alpha * x) + D * exp(-alpha * x) + 0.9;
}

double u(double x)
{
    if (x < (1. / sqrt(3.)))
    {
        return u1(x);
    }
    else if (x > (1. / sqrt(3.)))
    {
        return u2(x);
    }
    else
    {
        return (u1(x) + u2(x)) / 2.0;
    }
}

vector<double> get_true_solution(long long n)
{
    double a = 0., b = 1.;
    double h = (b - a) / n;
    vector<double> true_solution(n + 1);
    for (int i = 0; i < n + 1; ++i)
    {
        double x_i = a + i * h;
        true_solution[i] = u(x_i);
    }
    return true_solution;
}

void compare_test_solutions(long long n, double& max_error_sol, int& max_error_index, double& max_error_x)
{
    double a = 0., b = 1.;
    double h = (b - a) / n;
    double ksi = 1. / sqrt(3.), mu1 = 2., mu2 = 1.;
    vector<double> ai = calc_ai(a, b, n, ksi, test_k1, test_k2);
    vector<double> di = calc_di(a, b, n, ksi, test_q1, test_q2);
    vector<double> fi = calc_fi(a, b, n, ksi, test_f1, test_f2);
    vector<double> LD = calc_lower_diagonal(ai, h, n);
    vector<double> D = calc_main_diagonal(ai, di, h, n);
    vector<double> UD = calc_upper_diagonal(ai, h, n);
    vector<double> rhs = calc_column_b(mu1, mu2, fi, n);
    vector<double> v(n + 1, 0.);
    SolveTridiagonalSLAE(LD, D, UD, rhs, v);
    max_error_sol = 0.;
    max_error_index = 0;
    max_error_x = 0.;
    for (int i = 0; i < n + 1; ++i)
    {
        double x_i = a + i * h;
        double u_i = u(x_i);
        double error = abs(u_i - v[i]);
        if (error > max_error_sol)
        {
            max_error_sol = error;
            max_error_index = i;
            max_error_x = x_i;
        }
    }
}

long long find_optimal_n_test(double target_error = 0.5e-6)
{
    long long n = 10;
    double max_error_sol, max_error_x;
    int max_error_index;
    while (n <= 10000000)
    {
        compare_test_solutions(n, max_error_sol, max_error_index, max_error_x);
        cout << n << "\t" << scientific << max_error_sol << endl;;
        if (max_error_sol <= target_error)
        {
            cout << "accuracy achieved!" << endl;
            break;
        }
        n += 1000;
        /*if (n < 100)
        {
            n += 10;
        }
        else if (n < 1000)
        {
            n += 100;
        }
        else if (n < 10000)
        {
            n += 1000;
        }
        else
        {
            n += 10000;
        }*/
    }
    return n;
}

//int main()
//{
//    const double eps = 0.5e-6;
//    long long n = 100;
//    vector<double> v = calc_main_task(n);
//    vector<double> v2 = calc_main_task(2 * n);
//    double mx = -1.;
//    for (int i = 0; i < v.size(); ++i)
//    {
//        //cout << abs(v[i] - v2[2 * i]) << " ";
//        if (abs(v[i] - v2[2 * i]) > mx)
//        {
//            mx = abs(v[i] - v2[2 * i]);
//        }
//    }
//    cout << "final error:   " << scientific << mx << endl;
//    if (mx <= eps)
//    {
//        cout << "good" << endl;
//    }
//    else
//    {
//        cout << "bad" << endl;
//    }
//    double max_error_sol, max_error_x;
//    int max_error_index;
//    //cout << find_optimal_n_test() << endl;
//    compare_test_solutions(n, max_error_sol, max_error_index, max_error_x);
//    cout << "compare analytical and numerical sol:   " << max_error_sol << endl;
//    cout << max_error_x << endl; // x при котором возникает максимальная ошибка (всегда в районе точки разрыва)
//
//    return 0;
//}