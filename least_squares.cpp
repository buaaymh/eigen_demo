#include <ctime>
#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;
 
int main()
{
  MatrixXf A = MatrixXf::Random(3, 2);
  cout << "Here is the matrix A:\n" << A << endl;
  VectorXf b = VectorXf::Random(3);
  cout << "Here is the right hand side b:\n" << b << endl;
  // SVD decomposition is generally the most accurate but the slowest
  clock_t start = clock();
  cout << "The least-squares solution is:\n"
      << A.bdcSvd(ComputeThinU | ComputeThinV).solve(b) << endl;
  clock_t end = clock();
  double time_used = (double) (end - start) / CLOCKS_PER_SEC * 1000;
  cout << "Time used is "  << time_used << " ms" << endl;
  // a bit slower but more accurate
  start = clock();
  cout << "The solution using the QR decomposition is:\n"
     << A.colPivHouseholderQr().solve(b) << endl;
  end = clock();
  time_used = (double) (end - start) / CLOCKS_PER_SEC * 1000;
  cout << "Time used is "  << time_used << " ms" << endl;
  // normal equations is the fastest but least accurate
  start = clock();
  cout << "The solution using normal equations is:\n"
     << (A.transpose() * A).ldlt().solve(A.transpose() * b) << endl;
  end = clock();
  time_used = (double) (end - start) / CLOCKS_PER_SEC * 1000;
  cout << "Time used is "  << time_used << " ms" << endl;
}