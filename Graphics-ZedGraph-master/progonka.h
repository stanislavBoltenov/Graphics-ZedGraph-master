#pragma once
#include <vector>

void compare_test_solutions(long long n, double& max_error_sol, int& max_error_index, double& max_error_x);

std::vector<double> calc_main_task(long long n);

std::vector<double> calc_test_task(long long n);

std::vector<double> get_true_solution(long long n);
