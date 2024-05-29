/**
 * @file vector.hpp
 * @brief This file contains the declaration of the Vector class.
 * @ingroup Math
 * @date 2021-08-29
 * @author Rishikesh Kumar
 */

#ifndef BASICML_MATH_VECTOR_HPP
#define BASICML_MATH_VECTOR_HPP

namespace basicml
{
  namespace math
  {
    template <typename T>
    class Vector
    {
    private:
      T *_data;
      int _size;

    public:
      // Constructor
      Vector(int size, T value = 0)
      {
        _size = size;
        _data = new T[_size];
        for (int i = 0; i < _size; i++)
        {
          _data[i] = value;
        }
      }

      // Destructor
      ~Vector()
      {
        delete[] _data;
      }

      // Copy Constructor
      Vector(const Vector &v)
      {
        _size = v._size;
        _data = new T[_size];
        for (int i = 0; i < _size; i++)
        {
          _data[i] = v._data[i];
        }
      }

      // Getters
      int size() const
      {
        return _size;
      }

      T *data() const
      {
        return _data;
      }

      // Setters
      void set(int index, T value)
      {
        _data[index] = value;
      }

      // Overloading the [] operator
      T &operator[](int index)
      {
        return _data[index];
      }

      // Overloading the << operator
      friend std::ostream &operator<<(std::ostream &os, const Vector &v)
      {
        os << "Vector: [";
        for (int i = 0; i < v._size; i++)
        {
          os << v._data[i];
          if (i != v._size - 1)
          {
            os << ", ";
          }
        }
        os << "]";
        return os;
      }

      // Overloading the + operator
      friend Vector<T> &operator+(const Vector &v1, const Vector &v2)
      {
        if (v.size() != v2.size())
        {
          throw invalid_argument("Dimensions does not match");
        }

        Vector<T> result(v1.size());
        for (size_t i = 0; i < v1.size(); i++)
        {
          result[i] = v1[i] + v2[i];
        }

        return result;
      }

      // Overloading the - operator
      friend Vector<T> &operator-(const Vector &v1, const Vector &v2)
      {
        if (v.size() != v2.size())
        {
          throw invalid_argument("Dimensions does not match");
        }

        Vector<T> result(v1.size());
        for (size_t i = 0; i < v1.size(); i++)
        {
          result[i] = v1[i] - v2[i];
        }

        return result;
      }

      // Overloading the += operator
      Vector<T> &operator+=(const Vector &v1)
      {
        *this = *this + v1;
        return *this;
      }

      // Overloading the -=
      Vector<T> &operator-=(const Vector &v)
      {
        *this = *this - v;
        return *this;
      }

      // dot function
      T dot(const Vector &v)
      {
        if (_size != v.size())
        {
          throw invalid_argument("Dimensions does not match");
        }

        T result = 0;
        for (size_t i = 0; i < _size; i++)
        {
          result += _data[i] * v[i];
        }

        return result;
      }

      // magnitude function
      T magnitude()
      {
        T result = 0;
        for (size_t i = 0; i < _size; i++)
        {
          result += _data[i] * _data[i];
        }

        return std::sqrt(result);
      }

      // finding angle between two vectors
      double angle(Vector &v)
      {
        return acos(dot(v) / (magnitude() * v.magnitude()));
      }
        };
  } // namespace math
} // namespace basicml

#endif // BASICML_MATH_VECTOR_HPP