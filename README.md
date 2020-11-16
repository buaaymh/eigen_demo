# Eigen

**基础矩阵运算库**

BLAS(Basic Linear Algebra Subprograms)：支持基础线性代数运算操作的数值库

LAPACK：支持高级线性代数运算的数值库，底层是BLAS，用于求解方程组等复杂问题

**高级矩阵运算库**

MKL：使用OpenMP实现的线程化高性能代数运算数值库，充分利用多核处理器，底层是BLAS, LAPACK

Eigen：通过模板方式实现的head-only库，底层BLAS/LAPACK(EIGEN_USE_BLAS, EIGEN_USE_LAPACK)，支持MKL作为底层(EIGEN_USE_MKL_ALL)，支持CUDA kernels里使用。



默认运行速度：Matlab = MKL > Eigen(with MTK only) > python.numpy >> Eigen

原因：Eigen默认是单线程运算，前几个均支持多线程，单线程相差很小。

Eigen性能优化技巧，尽量用静态矩阵代替动态矩阵，Eigen性能对编译器优化等级敏感(o3)，使用release模式避免检查。



Eigen优势：提供了多种矩阵运算库的统一接口，避免了中间变量的内存消耗。学习成本低，极易上手。可用于CUDA使用。

Eigen缺点：默认不采用多线程，运算速度慢。