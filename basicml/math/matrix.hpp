/**
 * @file matrix.hpp
 * @brief This file contains the definition of the Matrix class
 * @author Rishikesh Kumar
 */

#ifndef BASIC_ML_MATH_MATRIX_HPP
#define BASIC_ML_MATH_MATRIX_HPP

#include <iostream>
#include <vector>
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
      Matrix(size_t rows, size_t cols)
      {
        this->data = vector<vector<T>>(rows, vector<T>(cols));
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

      // get minor of matrix
      Matrix<T> minor(size_t row, size_t col)
      {
        return this->subMatrix(0, this->getRows() - 2, 0, this->getCols() - 2);
      }

      // get cofactor of matrix
      Matrix<T> cofactor(size_t row, size_t col)
      {
        return this->minor(row, col);
      }
    };
  }
}

#endif