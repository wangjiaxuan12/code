#ifndef MATRIX_HPP
#define MATRIX_HPP
 
#include <vector>
using namespace std;
 
vector<vector<double>> Create_Matrix(int h, int l);
void show_Matrix(const vector<vector<double>> &A);
void Fhud_Matrix(vector<vector<double>> &A);
void Fvlr_Matrix(vector<vector<double>> &A);
void Transpose_Matrix(vector<vector<double>> &A);
vector<vector<double>> Add_Matrix(const vector<vector<double>> &A, const vector<vector<double>> &B);
vector<vector<double>> Sub_Matrix(const vector<vector<double>> &A, const vector<vector<double>> &B);
vector<vector<double>> Mul_Matrix(const vector<vector<double>> &A, const vector<vector<double>> &B);
vector<vector<double>> Mul_num_Matrix(const vector<vector<double>> &A, double num);
vector<vector<double>> Overlaying_below_Matrix(const vector<vector<double>> &A, const vector<vector<double>> &B);
vector<vector<double>> Overlaying_beside_Matrix(const vector<vector<double>> &A, const vector<vector<double>> &B);
vector<vector<double>> Trans_Matrix(const vector<vector<double>> &A);
vector<vector<double>> Inverse_Matrix(const vector<vector<double>> &A);
 
 
#endif