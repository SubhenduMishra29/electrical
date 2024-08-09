#include "lib/matrix_utils.h"
#include <stdexcept>
#include <cmath>
#include <limits>

namespace MatrixUtils {

    std::vector<std::vector<double>> multiply(const std::vector<std::vector<double>>& A,
                                              const std::vector<std::vector<double>>& B) {
        if (A.empty() || B.empty() || A[0].empty() || B[0].empty()) {
            throw std::invalid_argument("Matrices cannot be empty.");
        }

        if (A[0].size() != B.size()) {
            throw std::invalid_argument("Matrix dimensions do not match for multiplication.");
        }

        std::vector<std::vector<double>> result(A.size(), std::vector<double>(B[0].size(), 0.0));
        for (size_t i = 0; i < A.size(); ++i) {
            for (size_t j = 0; j < B[0].size(); ++j) {
                for (size_t k = 0; k < B.size(); ++k) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return result;
    }

    std::vector<std::vector<double>> transpose(const std::vector<std::vector<double>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            throw std::invalid_argument("Matrix cannot be empty.");
        }

        std::vector<std::vector<double>> transposed(matrix[0].size(), std::vector<double>(matrix.size()));
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[0].size(); ++j) {
                transposed[j][i] = matrix[i][j];
            }
        }
        return transposed;
    }

    std::vector<std::vector<double>> invert(const std::vector<std::vector<double>>& matrix) {
        if (matrix.size() != matrix[0].size()) {
            throw std::invalid_argument("Matrix must be square for inversion.");
        }

        size_t n = matrix.size();
        std::vector<std::vector<double>> augmentedMatrix(n, std::vector<double>(2 * n));

        // Create the augmented matrix [A | I]
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                augmentedMatrix[i][j] = matrix[i][j];
            }
            augmentedMatrix[i][n + i] = 1.0;
        }

        // Perform Gauss-Jordan elimination
        for (size_t i = 0; i < n; ++i) {
            double maxElement = std::abs(augmentedMatrix[i][i]);
            size_t maxRow = i;

            // Search for maximum in this column
            for (size_t k = i + 1; k < n; ++k) {
                if (std::abs(augmentedMatrix[k][i]) > maxElement) {
                    maxElement = std::abs(augmentedMatrix[k][i]);
                    maxRow = k;
                }
            }

            // Swap maximum row with current row
            std::swap(augmentedMatrix[maxRow], augmentedMatrix[i]);

            // Make sure the pivot element is non-zero
            double pivot = augmentedMatrix[i][i];
            if (std::abs(pivot) < std::numeric_limits<double>::epsilon()) {
                throw std::runtime_error("Matrix is singular and cannot be inverted.");
            }

            // Normalize the pivot row
            for (size_t j = 0; j < 2 * n; ++j) {
                augmentedMatrix[i][j] /= pivot;
            }

            // Eliminate all other entries in this column
            for (size_t k = 0; k < n; ++k) {
                if (k != i) {
                    double factor = augmentedMatrix[k][i];
                    for (size_t j = 0; j < 2 * n; ++j) {
                        augmentedMatrix[k][j] -= factor * augmentedMatrix[i][j];
                    }
                }
            }
        }

        // Extract the right half of the augmented matrix as the inverse
        std::vector<std::vector<double>> inverseMatrix(n, std::vector<double>(n));
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                inverseMatrix[i][j] = augmentedMatrix[i][n + j];
            }
        }

        return inverseMatrix;
    }

} // namespace MatrixUtils
