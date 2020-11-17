#include <ctime>
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

using namespace std;
using namespace Eigen;
 
int main()
{
  cout << "Dynamic matrix decompositions" << endl;
  MatrixXf A(3,3);
  A << 1, -3, 3,  3, -5, 3,  6, -6, 4;
  cout << "Here is the matrix A:\n" << A << endl;
  cout << "Solve EigenValues" << endl;
  auto eigensolver1 = EigenSolver<MatrixXf>(A, false);
  clock_t start = clock();
  auto values_A = eigensolver1.eigenvalues();
  clock_t end = clock();
  double time_used = (double) (end - start) / CLOCKS_PER_SEC * 1000;
  cout << "The eigenvalues of A are:\n"  << values_A << endl;
  cout << "Time used is "  << time_used << " ms" << endl;
  cout << endl;
  
  cout << "Solve EigenValues and EigenVectors" << endl;
  auto eigensolver2 = EigenSolver<MatrixXf>(A, true);
  start = clock();
  values_A = eigensolver2.eigenvalues();
  auto vectors_A = eigensolver2.eigenvectors();
  end = clock();
  time_used = (double) (end - start) / CLOCKS_PER_SEC * 1000;
  cout << "The eigenvalues of A are:\n"  << values_A << endl;
  cout << "The eigenvectors of A are:\n"  << vectors_A << endl;
  cout << "Time used is "  << time_used << " ms" << endl;
  cout << endl;
}
