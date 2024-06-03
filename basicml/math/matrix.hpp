/**
 * @file matrix.hpp
 * @brief This file contains the definition of the Matrix class
 * @ingroup Math
 * @date 2021-08-29
 * @author Rishikesh Kumar
 */

#ifndef BASIC_ML_MATH_MATRIX_HPP
#define BASIC_ML_MATH_MATRIX_HPP

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

namespace basicml
{
  namespace math
  {
    template <typename T>
    class Matrix
    {
    private:
      vector<vector<T>> data;

    public:
      // creating matrix with given vector
      Matrix(vector<vector<T>> data)
      {
        this->data = data;
      }

      // creating matrix with given size and value
      Matrix(size_t rows, size_t cols, T val)
      {
        this->data = vector<vector<T>>(rows, vector<T>(cols, val));
      }

      // creating matrix with given size
      Matrix(size_t rows, size_t cols, bool random = false)
      {
        this->data = vector<vector<T>>(rows, vector<T>(cols));
        if (random)
        {
          for (size_t i = 0; i < rows; i++)
          {
            for (size_t j = 0; j < cols; j++)
            {
              this->data[i][j] = rand() % 100;
            }
          }
        }
      }

      // creating matrix with given rows
      Matrix(size_t rows)
      {
        this->data = vector<vector<T>>(rows);
      }

      // creating empty matrix
      Matrix()
      {
        this->data = vector<vector<T>>();
      }

      // copy constructor
      Matrix(const Matrix<T> &m)
      {
        this->data = m.data;
      }

      // getting shape of matrix
      pair<size_t, size_t> shape() const
      {
        return {this->data.size(), this->data[0].size()};
      }

      // getting number of rows
      size_t getRows() const
      {
        return this->data.size();
      }

      // getting number of columns
      size_t getCols() const
      {
        return this->data[0].size();
      }

      // Identity Matrix
      static Matrix<T> Identity(size_t n)
      {
        Matrix<T> result(n, n);
        for (size_t i = 0; i < n; i++)
        {
          result.data[i][i] = 1;
        }
        return result;
      }

      // overloading = operator to assign matrix
      Matrix<T> &operator=(const Matrix<T> &m)
      {
        this->data = m.data;
        return *this;
      }

      // overloading << operator to print matrix
      friend ostream &operator<<(ostream &os, const Matrix<T> &matrix)
      {
        for (size_t i = 0; i < matrix.getRows(); i++)
        {
          for (size_t j = 0; j < matrix.getCols(); j++)
          {
            os << matrix.data[i][j] << " ";
          }
          os << endl;
        }
        return os;
      }

      // overloading + operator to add two matrix
      friend Matrix<T> operator+(const Matrix<T> &m1, const Matrix<T> &m2)
      {
        if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols())
        {
          throw invalid_argument("Matrix dimensions do not match");
        }

        Matrix<T> result(m1.getRows(), m1.getCols());
        for (size_t i = 0; i < m1.getRows(); i++)
        {
          for (size_t j = 0; j < m1.getCols(); j++)
          {
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
          }
        }
        return result;
      }

      // overloading - operator to subtract two matrix
      friend Matrix<T> operator-(const Matrix<T> &m1, const Matrix<T> &m2)
      {
        if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols())
        {
          throw invalid_argument("Matrix dimensions do not match");
        }

        Matrix<T> result(m1.getRows(), m1.getCols());
        for (size_t i = 0; i < m1.getRows(); i++)
        {
          for (size_t j = 0; j < m1.getCols(); j++)
          {
            result.data[i][j] = m1.data[i][j] - m2.data[i][j];
          }
        }
        return result;
      }

      // overloading * operator to multiply two matrix
      friend Matrix<T> operator*(const Matrix<T> &m1, const Matrix<T> &m2)
      {
        if (m1.getCols() != m2.getRows())
        {
          throw invalid_argument("Matrix dimensions do not match");
        }

        Matrix<T> result(m1.getRows(), m2.getCols());
        for (size_t i = 0; i < m1.getRows(); i++)
        {
          for (size_t j = 0; j < m2.getCols(); j++)
          {
            for (size_t k = 0; k < m1.getCols(); k++)
            {
              result.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }
          }
        }
        return result;
      }

      // overloading * operator to multiply matrix with scalar
      friend Matrix<T> operator*(const Matrix<T> &m, T scalar)
      {
        Matrix<T> result(m.getRows(), m.getCols());
        for (size_t i = 0; i < m.getRows(); i++)
        {
          for (size_t j = 0; j < m.getCols(); j++)
          {
            result.data[i][j] = m.data[i][j] * scalar;
          }
        }
        return result;
      }

      // overloading * operator to multiply scalar with matrix
      friend Matrix<T> operator*(T scalar, const Matrix<T> &m)
      {
        return m * scalar;
      }

      // overloading / operator to divide matrix with scalar
      friend Matrix<T> operator/(const Matrix<T> &m, T scalar)
      {
        Matrix<T> result(m.getRows(), m.getCols());
        for (size_t i = 0; i < m.getRows(); i++)
        {
          for (size_t j = 0; j < m.getCols(); j++)
          {
            result.data[i][j] = m.data[i][j] / scalar;
          }
        }
        return result;
      }

      // overloading / operator to divide scalar with matrix
      friend Matrix<T> operator/(T scalar, const Matrix<T> &m)
      {
        Matrix<T> result(m.getRows(), m.getCols());
        for (size_t i = 0; i < m.getRows(); i++)
        {
          for (size_t j = 0; j < m.getCols(); j++)
          {
            result.data[i][j] = scalar / m.data[i][j];
          }
        }
        return result;
      }

      // overloading == operator to compare two matrix
      friend bool operator==(const Matrix<T> &m1, const Matrix<T> &m2)
      {
        if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols())
        {
          return false;
        }

        for (size_t i = 0; i < m1.getRows(); i++)
        {
          for (size_t j = 0; j < m1.getCols(); j++)
          {
            if (m1.data[i][j] != m2.data[i][j])
            {
              return false;
            }
          }
        }
        return true;
      }

      // overloading != operator to compare two matrix
      friend bool operator!=(const Matrix<T> &m1, const Matrix<T> &m2)
      {
        return !(m1 == m2);
      }

      // overloading += operator to add two matrix
      Matrix<T> &operator+=(const Matrix<T> &m)
      {
        *this = *this + m;
        return *this;
      }

      // overloading -= operator to subtract two matrix
      Matrix<T> &operator-=(const Matrix<T> &m)
      {
        *this = *this - m;
        return *this;
      }

      // overloading *= operator to multiply two matrix
      Matrix<T> &operator*=(const Matrix<T> &m)
      {
        *this = *this * m;
        return *this;
      }

      // overloading *= operator to multiply matrix with scalar
      Matrix<T> &operator*=(T scalar)
      {
        *this = *this * scalar;
        return *this;
      }

      // overloading /= operator to divide matrix with scalar
      Matrix<T> &operator/=(T scalar)
      {
        *this = *this / scalar;
        return *this;
      }

      // overloading [] operator to access matrix element
      vector<T> &operator[](size_t i)
      {
        return this->data[i];
      }

      // overloading () operator to access matrix element
      T &operator()(size_t i, size_t j)
      {
        return this->data[i][j];
      }

      // transpose of matrix
      Matrix<T> transpose()
      {
        Matrix<T> result(this->getCols(), this->getRows());
        for (size_t i = 0; i < this->getRows(); i++)
        {
          for (size_t j = 0; j < this->getCols(); j++)
          {
            result.data[j][i] = this->data[i][j];
          }
        }
        return result;
      }

      // inplace transpose of matrix
      void inplaceTranspose()
      {
        *this = this->transpose();
      }

      // get submatrix of matrix
      Matrix<T> subMatrix(size_t rowStart, size_t rowEnd, size_t colStart, size_t colEnd)
      {
        if (rowStart < 0 || rowEnd >= this->getRows() || colStart < 0 || colEnd >= this->getCols())
        {
          throw invalid_argument("Index out of range");
        }

        Matrix<T> result(rowEnd - rowStart + 1, colEnd - colStart + 1);
        for (size_t i = rowStart; i <= rowEnd; i++)
        {
          for (size_t j = colStart; j <= colEnd; j++)
          {
            result.data[i - rowStart][j - colStart] = this->data[i][j];
          }
        }
        return result;
      }

      // remove row from matrix
      Matrix<T> removeRow(size_t row)
      {
        if (row < 0 || row >= this->getRows())
        {
          throw invalid_argument("Index out of range");
        }

        Matrix<T> result(this->getRows() - 1, this->getCols());
        for (size_t i = 0; i < this->getRows(); i++)
        {
          if (i < row)
          {
            result.data[i] = this->data[i];
          }
          else if (i > row)
          {
            result.data[i - 1] = this->data[i];
          }
        }
        return result;
      }

      // remove column from matrix
      Matrix<T> removeCol(size_t col)
      {
        if (col < 0 || col >= this->getCols())
        {
          throw invalid_argument("Index out of range");
        }

        Matrix<T> result(this->getRows(), this->getCols() - 1);
        for (size_t i = 0; i < this->getRows(); i++)
        {
          for (size_t j = 0; j < this->getCols(); j++)
          {
            if (j < col)
            {
              result.data[i][j] = this->data[i][j];
            }
            else if (j > col)
            {
              result.data[i][j - 1] = this->data[i][j];
            }
          }
        }
        return result;
      }

      // get minor of matrix
      Matrix<T> minor(size_t row, size_t col)
      {
        return this->removeRow(row).removeCol(col);
      }

      // get determinant of matrix
      T determinant()
      {
        if (this->getRows() != this->getCols())
        {
          throw invalid_argument("Matrix is not square");
        }

        if (this->getRows() == 1)
        {
          return this->data[0][0];
        }

        T det = 0;
        for (size_t i = 0; i < this->getCols(); i++)
        {
          det += ((i & 1) ? -1 : 1) * this->data[0][i] * this->minor(0, i).determinant();
        }
        return det;
      }

      // get cofactor of matrix
      Matrix<T> cofactor()
      {
        Matrix<T> result(this->getRows(), this->getCols());
        for (size_t i = 0; i < this->getRows(); i++)
        {
          for (size_t j = 0; j < this->getCols(); j++)
          {
            result.data[i][j] = (((i + j) & 1) ? -1 : 1) * this->minor(i, j).determinant();
          }
        }
        return result;
      }

      // get adjoint of matrix
      Matrix<T> adjoint()
      {
        return this->cofactor().transpose();
      }

      // get inverse of matrix
      Matrix<T> inverse()
      {
        T det = this->determinant();
        if (det == 0)
        {
          throw invalid_argument("Matrix is singular");
        }
        return this->adjoint() / det;
      }

      // multiply two matrices at corresponding positions
      Matrix<T> hadamardProduct(const Matrix<T> &m)
      {
        if (this->getRows() != m.getRows() || this->getCols() != m.getCols())
        {
          throw invalid_argument("Matrix dimensions do not match");
        }

        Matrix<T> result(this->getRows(), this->getCols());
        for (size_t i = 0; i < this->getRows(); i++)
        {
          for (size_t j = 0; j < this->getCols(); j++)
          {
            result.data[i][j] = this->data[i][j] * m.data[i][j];
          }
        }
        return result;
      }

      // join two matrices horizontally
      Matrix<T> hstack(const Matrix<T> &m)
      {
        if (this->getRows() != m.getRows())
        {
          throw invalid_argument("Matrix dimensions do not match");
        }

        Matrix<T> result(this->getRows(), this->getCols() + m.getCols());
        for (size_t i = 0; i < this->getRows(); i++)
        {
          for (size_t j = 0; j < this->getCols(); j++)
          {
            result.data[i][j] = this->data[i][j];
          }
          for (size_t j = 0; j < m.getCols(); j++)
          {
            result.data[i][this->getCols() + j] = m.data[i][j];
          }
        }
        return result;
      }

      // join two matrices vertically
      Matrix<T> vstack(const Matrix<T> &m)
      {
        if (this->getCols() != m.getCols())
        {
          throw invalid_argument("Matrix dimensions do not match");
        }

        Matrix<T> result(this->getRows() + m.getRows(), this->getCols());
        for (size_t i = 0; i < this->getRows(); i++)
        {
          for (size_t j = 0; j < this->getCols(); j++)
          {
            result.data[i][j] = this->data[i][j];
          }
        }
        for (size_t i = 0; i < m.getRows(); i++)
        {
          for (size_t j = 0; j < m.getCols(); j++)
          {
            result.data[this->getRows() + i][j] = m.data[i][j];
          }
        }
        return result;
      }

      // sum of all elements of matrix
      T sum()
      {
        T s = 0;
        for (size_t i = 0; i < this->getRows(); i++)
        {
          for (size_t j = 0; j < this->getCols(); j++)
          {
            s += this->data[i][j];
          }
        }
        return s;
      }

      // get column of the matrix
      Matrix<T> getColumn(size_t col)
      {
        if (col < 0 || col >= this->getCols())
        {
          throw invalid_argument("Index out of range");
        }

        Matrix<T> result(this->getRows(), 1);
        for (size_t i = 0; i < this->getRows(); i++)
        {
          result.data[i][0] = this->data[i][col];
        }
        return result;
      }

      // get row of the matrix
      Matrix<T> getRow(size_t row)
      {
        if (row < 0 || row >= this->getRows())
        {
          throw invalid_argument("Index out of range");
        }

        Matrix<T> result(1, this->getCols());
        for (size_t i = 0; i < this->getCols(); i++)
        {
          result.data[0][i] = this->data[row][i];
        }
        return result;
      }

      // get mean of the matrix
      T mean()
      {
        return this->sum() / (this->getRows() * this->getCols());
      }

      // get sum of the matrix along axis
      Matrix<T> sum(int axis)
      {
        if (axis == 0)
        {
          Matrix<T> result(1, this->getCols());
          for (size_t i = 0; i < this->getCols(); i++)
          {
            for (size_t j = 0; j < this->getRows(); j++)
            {
              result.data[0][i] += this->data[j][i];
            }
          }
          return result;
        }
        else if (axis == 1)
        {
          Matrix<T> result(this->getRows(), 1);
          for (size_t i = 0; i < this->getRows(); i++)
          {
            for (size_t j = 0; j < this->getCols(); j++)
            {
              result.data[i][0] += this->data[i][j];
            }
          }
          return result;
        }
        else
        {
          throw invalid_argument("Invalid axis");
        }
      }

      // get mean of the matrix along axis
      Matrix<T> mean(int axis)
      {
        if (axis == 0)
        {
          return this->sum(0) / this->getRows();
        }
        else if (axis == 1)
        {
          return this->sum(1) / this->getCols();
        }
        else
        {
          throw invalid_argument("Invalid axis");
        }
      }

      // get standard deviation of the matrix
      T std()
      {
        T m = this->mean();
        T s = 0;
        for (size_t i = 0; i < this->getRows(); i++)
        {
          for (size_t j = 0; j < this->getCols(); j++)
          {
            s += (this->data[i][j] - m) * (this->data[i][j] - m);
          }
        }
        return std::sqrt(s / (this->getRows() * this->getCols()));
      }

      // find square root of each element in the matrix
      Matrix<T> sqrt()
      {
        Matrix<T> result(this->getRows(), this->getCols());
        for (size_t i = 0; i < this->getRows(); i++)
        {
          for (size_t j = 0; j < this->getCols(); j++)
          {
            result.data[i][j] = std::sqrt(this->data[i][j]);
          }
        }
        return result;
      }

      // get standard deviation of the matrix along axis
      Matrix<T> std(int axis)
      {
        if (axis > 1 || axis < 0)
        {
          throw invalid_argument("Invalid axis");
        }

        Matrix<T> m = this->mean(axis);
        Matrix<T> s(this->getRows(), this->getCols());
        if (axis == 0)
        {
          for (size_t i = 0; i < this->getCols(); i++)
          {
            for (size_t j = 0; j < this->getRows(); j++)
            {
              s.data[j][i] = (this->data[j][i] - m.data[0][i]) * (this->data[j][i] - m.data[0][i]);
            }
          }
          return s.mean(0).sqrt();
        }
        else
        {
          for (size_t i = 0; i < this->getRows(); i++)
          {
            for (size_t j = 0; j < this->getCols(); j++)
            {
              s.data[i][j] = (this->data[i][j] - m.data[i][0]) * (this->data[i][j] - m.data[i][0]);
            }
          }
          return s.mean(1).sqrt();
        }
      }
    };

  }
}

#endif