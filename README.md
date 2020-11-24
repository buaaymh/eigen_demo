# Eigen

## 基础矩阵库

- [BLAS (Basic Linear Algebra Subprograms)]()：支持基础线性代数运算操作的数值库
- [LAPACK]()：支持高级线性代数运算的数值库，底层是BLAS，用于求解方程组等复杂问题

## 高级矩阵库

- [MKL]()：使用 [OpenMP]() 实现的线程化高性能代数运算数值库，充分利用多核处理器，底层是 BLAS, LAPACK
- [Eigen]()：通过模板方式实现的 header-only 库，底层 BLAS/LAPACK (`EIGEN_USE_BLAS`, `EIGEN_USE_LAPACK`)，支持 MKL 作为底层 (`EIGEN_USE_MKL_ALL`)，支持 [CUDA kernels]() 里使用。

## 性能评价

默认运行速度：Matlab = MKL > Eigen (with MTK only) > python.numpy >> Eigen

原因：Eigen 默认是单线程运算，前几个均支持多线程，单线程相差很小。

Eigen 性能优化技巧：
- 尽量用静态矩阵代替动态矩阵。
- Eigen 性能对编译器优化等级敏感 (`-O3`)，使用 `Release` 模式避免检查。

Eigen 性能评价：
- 优势：
  - 提供了多种矩阵运算库的统一接口，避免了中间变量的内存消耗。
  - 学习成本低，极易上手。
  - 可用于 CUDA 使用。
- 缺点：
  - 默认不采用多线程，运算速度慢。

## 常用语句

### 矩阵初始化

```c++
#include <iostream>
#include <Eigen/Dense>
/* static */
Matrix<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>
typedef Matrix<float, 4, 4> Matrix4f;
typedef Matrix<float, 3, 1> Vector3f;
typedef Matrix<float, 3, 1> Vector3f;
/* dynamic */
typedef Matrix<double, Dynamic, Dynamic> MatrixXd;
typedef Matrix<int, Dynamic, 1> VectorXi;
Matrix<float, 3, Dynamic>

/* initialize size */
/* a is a 10x15 dynamic-size matrix, with allocated but currently uninitialized coefficients. */
MatrixXf a(10,15);
/* b is a dynamic-size vector of size 30, with allocated but currently uninitialized coefficients. */
VectorXf b(30);

/* initialize coefficients */
Vector2d a(5.0, 6.0);
Vector3d b(5.0, 6.0, 7.0);
Vector4d c(5.0, 6.0, 7.0, 8.0);

MatrixXd m(2,2);
m(0,0) = 3;
m(1,0) = 2.5;
m(0,1) = -1;
m(1,1) = m(1,0) + m(0,1);

Matrix3f m;
m << 1, 2, 3,
     4, 5, 6,
     7, 8, 9;

/* resize */
MatrixXd m(2,5);
m.resize(4,3);
std::cout << "The matrix m is of size " << m.rows() << "x" << m.cols() << std::endl;
std::cout << "It has " << m.size() << " coefficients" << std::endl;
VectorXd v(2);
v.resize(5);
std::cout << "The vector v is of size " << v.size() << std::endl;
std::cout << "As a matrix, v is of size " << v.rows() << "x" << v.cols() << std::endl;

/* optional template parameters */
Matrix<typename Scalar,
       int RowsAtCompileTime,
       int ColsAtCompileTime,
       int Options = 0,
       int MaxRowsAtCompileTime = RowsAtCompileTime,
       int MaxColsAtCompileTime = ColsAtCompileTime>

/*
	 convenience typedefs
	 i (meaning int), f (meaning float), d (meaning double), cf (meaning complex<float>), 	 or cd (meaning complex<double>)
*/
using MatrixXi = Matrix<int, Dynamic, Dynamic>;
using Vector2f = Matrix<float, 2, 1>;
using RowVector3d = Matrix<double, 1, 3>;
/* comma initialization */
MatrixXf matA(2, 2);
matA << 1, 2, 3, 4;
MatrixXf matB(4, 4);
matB << matA, matA/10, matA/10, matA;
Matrix3f m;
m.row(0) << 1, 2, 3;
m.block(1,0,2,2) << 4, 5, 7, 8;
m.col(2).tail(2) << 6, 9;   
/* advanced initialization */
Array33f a1 = Array33f::Zero();
ArrayXf a2 = ArrayXf::Zero(3);
ArrayXXf a3 = ArrayXXf::Zero(3, 4);
MatrixXd::Constant(3,3,1.2);
// Zero(), Random(), Identity(), Constant(value), LinSpaced(size, low, high)
```

### 矩阵基本运算

```c++
#include <iostream>
#include <Eigen/Dense>
Matrix2i a; a << 1, 2, 3, 4;
a.transpose()
a.conjugate()
a.adjoint()
  
Vector3d v(1,2,3);
Vector3d w(0,1,2);
v.dot(w);
v.cross(w)
  
Eigen::Matrix2d mat;
mat << 1, 2, 3, 4;
mat.sum();  // 1+2+3+4
mat.prod(); // 1*2*3*4
mat.mean(); // (1+2+3+4)/4
mat.minCoeff()
mat.maxCoeff()
Matrix3f m = Matrix3f::Random();
std::ptrdiff_t i, j;
float minOfM = m.minCoeff(&i,&j); // i, j are position
mat.trace() // sum of the diagonal coefficients
```
