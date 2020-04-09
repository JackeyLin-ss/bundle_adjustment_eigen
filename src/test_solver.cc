#include <Eigen/Dense>
#include <ctime>
#include <iostream>

const int kMatrixSize = 1000;

int main(int argc, char **argv) {
  Eigen::MatrixXd A, B, X1, X2;
  A = Eigen::MatrixXd::Random(kMatrixSize, kMatrixSize);
  B = Eigen::MatrixXd::Random(kMatrixSize, 1);

  clock_t start_time = clock();
  X1 = A.fullPivHouseholderQr().solve(B);
  std::cout << " use QR : "
            << (1000 * (clock() - start_time)) / (double)CLOCKS_PER_SEC << "ms"
            << std::endl;

  start_time = clock();

  X2 = A.llt().solve(B);
  std::cout << " use Cholesky : "
            << (1000 * (clock() - start_time)) / (double)CLOCKS_PER_SEC << "ms"
            << std::endl;

  return 1;
}
