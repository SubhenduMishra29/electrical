#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#include <vector>

/**
 * @brief Namespace for matrix utility functions.
 */
namespace MatrixUtils {

/**
 * @brief Multiplies two matrices.
 * 
 * @param A The first matrix.
 * @param B The second matrix.
 * @return The product matrix.
 * @throw std::invalid_argument If the number of columns in A does not equal the number of rows in B.
 */
std::vector<std::vector<double>> multiply(const std::vector<std::vector<double>>& A,
                                          const std::vector<std::vector<double>>& B);

/**
 * @brief Transposes a matrix.
 * 
 * @param matrix The matrix to transpose.
 * @return The transposed matrix.
 */
std::vector<std::vector<double>> transpose(const std::vector<std::vector<double>>& matrix);

/**
 * @brief Computes the inverse of a matrix using Gaussian elimination.
 * 
 * @param matrix The matrix to invert.
 * @return The inverted matrix.
 * @throw std::invalid_argument If the matrix is not square or is singular.
 */
std::vector<std::vector<double>> invert(const std::vector<std::vector<double>>& matrix);

} // namespace MatrixUtils

#endif // MATRIX_UTILS_H
