#include <cassert>
#include <iostream>
#include <vector>

template <typename T>

void print_vector(const std::vector<T> &vec, bool print_vector_header = true)
{
    /*
     * Print vectors with elements of type T. Note
     * that this only works for objects of type
     * T for which "std::cout << object" would work.
     */

    if (print_vector_header)
    {
        std::cout << "Vector of size " << vec.size() << "\n";
    }

    std::cout << "[ ";
    // for each element in vector
    for (const auto &elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << " ]\n";
}

template <typename T>
void print_matrix(const std::vector<std::vector<T>> &matrix)
{

    std::cout << matrix.size() << " x " << matrix.at(0).size() << " Matrix: " << '\n';
    // for each row in matrix
    for (const auto &row : matrix)
    {
        print_vector(row, false);
    }
}

std::vector<double> operator+(const std::vector<double> &vec_a, const std::vector<double> &vec_b)
{
    /*
     * Overload operator+ to allow addition of two double vectors
     * of the same size. The return value is another vector formed by
     * adding the corresponding elements of vec_a and vec_b.
     */

    assert(vec_a.size() == vec_b.size());

    std::vector<double> vec_sum(vec_a.size(), 0.0);

    for (auto i = 0u; i < vec_a.size(); i++)
    {
        vec_sum[i] = vec_a[i] + vec_b[i];
    }
    return vec_sum;
}

std::vector<double> operator*(const std::vector<std::vector<double>> &matrix, const std::vector<double> &vec)
{
    /*
     * Overload of operator* for matrix vector multiplication
     * where a matrix is a vector of vector of doubles:
     * std::vector<std::vector<double>>
     * and vector is std::vector<double>
     */
    auto N = vec.size();
    assert(N == matrix.at(0).size());
    std::vector<double> res(N, 0.0);

    for (auto i = 0u; i < N; i++)
    {
        for (auto j = 0u; j < N; j++)
        {
            res[i] += vec[j] * matrix[i][j];
        }
    }
    return res;
}

void mat_times_vec(
    double *matrix, size_t matrix_rows, size_t matrix_columns, double *vec, size_t vec_size, double *res)
{
    /*
     * C/old-C++ way of multiplying matrix * vector.
     * We need to also pass the sizes of each
     */
    assert(matrix_columns == vec_size);
    // By the way, C only has malloc instead of new.

    for (size_t i = 0; i < matrix_rows; i++)
    {
        res[i] = 0;
        for (size_t j = 0; j < matrix_columns; j++)
        {
            res[i] += vec[j] * matrix[i * matrix_columns + j];
        }
    }
}

double *mat_times_vec(double *matrix, size_t matrix_rows, size_t matrix_columns, double *vec, size_t vec_size)
{
    /*
     * C/old-C++ way of multiplying matrix * vector.
     * We need to also pass the sizes of each
     */
    assert(matrix_columns == vec_size);
    double *res = new double[matrix_rows];

    // To avoid duplication, we can reuse the alternative version of mat_times_vec
    mat_times_vec(matrix, matrix_rows, matrix_columns, vec, vec_size, res);
    return res;
}

bool test_matrix_vector_product()
{
    /*
     * Test implementation of operator* for Matrix-vector product.
     */
    bool tests_passed = true;

    std::vector<std::vector<double>> matrix = {{1., 2.}, {3., 4.}};
    std::vector<double> vec = {1., 1.};

    std::vector<double> mat_vec = matrix * vec;

    // Alternative implementation with raw pointers.
    // matrix_raw is a pointer to an 1D array of 2x2 elements
    // vec_raw    is a pointer to an 1D array of 2   elements
    // res_raw    is a pointer without destination at the moment
    double *matrix_raw = new double[2 * 2];
    double *vec_raw = new double[2];
    double *res_raw;

    // TInitialize matrix_raw and vec_raw with values
    matrix_raw[0] = 1;
    matrix_raw[1] = 2;
    matrix_raw[2] = 3;
    matrix_raw[3] = 4;
    vec_raw[0] = 1;
    vec_raw[1] = 1;

    // Compute matrix-vector product using mat_times_vec(...)
    res_raw = mat_times_vec(matrix_raw, 2, 2, vec_raw, 2);

    std::vector<double> reference = {3., 7.};

    double tol = 1e-8;
    for (auto i = 0u; i < reference.size(); i++)
    {
        // floating point values are "equal" if their
        // difference is small
        if ((reference.at(i) - mat_vec.at(i)) > tol)
        {
            tests_passed = false;
        }
    }
    for (auto i = 0; i < 2; i++)
    {
        if ((reference.at(i) - res_raw[i]) > tol)
        {
            tests_passed = false;
        }
    }

    if (tests_passed)
    {
        std::cout << "Tests passed!\n";
    }
    else
    {
        std::cout << "Tests failed \n";
        std::cout << "Reference: ";
        print_vector(reference, false);
        std::cout << "Computed (operator*): ";
        print_vector(mat_vec, false);
        std::cout << "Computed (mat_times_vec()): ";
        std::cout << res_raw[0] << " " << res_raw[1] << std::endl;
    }

    // TODO: Delete all memory allocated with new
    delete[] matrix_raw;
    delete[] vec_raw;

    return tests_passed;
}

int main()
{
    std::vector<std::vector<double>> matrix = {{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}};

    std::vector<double> vec_a = {1., 2., 3.};
    std::vector<double> vec_b = {4., 5., 6.};

    // adding two vectors
    auto vec_sum = vec_a + vec_b;
    print_vector(vec_sum);

    test_matrix_vector_product();
}
