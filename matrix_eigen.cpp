#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

using namespace std;
using namespace Eigen;
 
int main()
{
  MatrixXd m(3,3);
  m << 1, -3, 3,  3, -5, 3,  6, -6, 4;
  cout << "Matrix :\n"  << m << endl;
  auto eigensolver = EigenSolver<MatrixXd>(m, false);
  auto v = eigensolver.eigenvalues();
  cout << "EigenValues :\n"  << v << endl;

  MatrixXf A = MatrixXf::Random(3, 2);
  cout << "Here is the matrix A:\n" << A << endl;
  VectorXf b = VectorXf::Random(3);
  cout << "Here is the right hand side b:\n" << b << endl;
  // SVD decomposition is generally the most accurate but the slowest
  cout << "The least-squares solution is:\n"
      << A.bdcSvd(ComputeThinU | ComputeThinV).solve(b) << endl;
  // a bit slower but more accurate
  cout << "The solution using the QR decomposition is:\n"
     << A.colPivHouseholderQr().solve(b) << endl;
  // normal equations is the fastest but least accurate
  cout << "The solution using normal equations is:\n"
     << (A.transpose() * A).ldlt().solve(A.transpose() * b) << endl;
}