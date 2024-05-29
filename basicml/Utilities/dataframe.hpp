/**
 * @file dataframe.hpp
 * @brief This file contains the declaration of the DataFrame class.
 * @ingroup Utilities
 * @date 2021-08-29
 * @author Rishikesh Kumar
 */

#ifndef BASICML_DATAFRAME_DATAFRAME_HPP
#define BASICML_DATAFRAME_DATAFRAME_HPP

#include "../math/matrix.hpp"
using namespace basicml::math;

namespace basicml
{
  namespace Utilities
  {
    template <typename T>
    class DataFrame
    {
    private:
      Matrix<T> data;
      vector<string> columns;

    public:
      // constructor
      DataFrame(Matrix<T> data, vector<string> columns)
      {
        this->data = data;
        this->columns = columns;
      }

      // Getters
      Matrix<T> getData()
      {
        return data;
      }

      vector<string> getColumns()
      {
        return columns;
      }

      // Setters
      void setData(Matrix<T> data)
      {
        this->data = data;
      }

      void setColumns(vector<string> columns)
      {
        this->columns = columns;
      }

      // Overloading the << operator
      friend ostream &operator<<(ostream &os, const DataFrame<T> &df)
      {
        os << "DataFrame: " << endl;
        os << "Columns: ";
        for (auto column : df.columns)
        {
          os << column << " ";
        }
        os << endl;
        os << "Data: " << endl;
        os << df.data;
        return os;
      }

      // head method
      DataFrame<T> head(int n = 10)
      {
        vector<vector<T>> head_data;
        for (int i = 0; i < n; i++)
        {
          head_data.push_back(data[i]);
        }
        Matrix<T> m(head_data);
        return DataFrame<T>(m, columns);
      }

      // tail method
      DataFrame<T> tail(int n = 10)
      {
        vector<vector<T>> tail_data;
        for (int i = data.getRows() - n; i < data.getRows(); i++)
        {
          tail_data.push_back(data[i]);
        }
        Matrix<T> m(tail_data);
        return DataFrame<T>(m, columns);
      }

      // remove column
      DataFrame<T> removeColumn(string column)
      {
        int index = -1;
        for (int i = 0; i < columns.size(); i++)
        {
          if (columns[i] == column)
          {
            index = i;
            break;
          }
        }
        if (index == -1)
        {
          throw runtime_error("Column not found");
        }
        vector<string> new_columns;
        vector<vector<T>> new_data;
        for (int i = 0; i < columns.size(); i++)
        {
          if (i != index)
          {
            new_columns.push_back(columns[i]);
          }
        }
        for (int i = 0; i < data.getRows(); i++)
        {
          vector<T> row;
          for (int j = 0; j < data.getCols(); j++)
          {
            if (j != index)
            {
              row.push_back(data[i][j]);
            }
          }
          new_data.push_back(row);
        }
        Matrix<T> m(new_data);
        return DataFrame<T>(m, new_columns);
      }

      // add column
      DataFrame<T> addColumn(vector<T> data, string name)
      {
        if (data.size() != this->data.getRows())
        {
          throw runtime_error("Data size does not match");
        }
        vector<string> new_columns = columns;
        new_columns.push_back(name);
        vector<vector<T>> new_data;
        for (int i = 0; i < this->data.getRows(); i++)
        {
          vector<T> row = this->data[i];
          row.push_back(data[i]);
          new_data.push_back(row);
        }
        Matrix<T> m(new_data);
        return DataFrame<T>(m, new_columns);
      }

      // get column
      DataFrame<T> getColumn(string column)
      {
        int index = -1;
        for (int i = 0; i < columns.size(); i++)
        {
          if (columns[i] == column)
          {
            index = i;
            break;
          }
        }
        if (index == -1)
        {
          throw runtime_error("Column not found");
        }
        vector<string> new_columns;
        vector<vector<T>> new_data;
        new_columns.push_back(column);
        for (int i = 0; i < data.getRows(); i++)
        {
          vector<T> row;
          row.push_back(data[i][index]);
          new_data.push_back(row);
        }
        Matrix<T> m(new_data);
        return DataFrame<T>(m, new_columns);
      }

      // fill missing values
      DataFrame<T> fillna(T value)
      {
        vector<vector<T>> new_data;
        for (int i = 0; i < data.getRows(); i++)
        {
          vector<T> row;
          for (int j = 0; j < data.getCols(); j++)
          {
            if (data[i][j] == "")
            {
              row.push_back(value);
            }
            else
            {
              row.push_back(data[i][j]);
            }
          }
          new_data.push_back(row);
        }
        Matrix<T> m(new_data);
        return DataFrame<T>(m, columns);
      }
    };
  } // namespace Utilities
} // namespace basicml

#endif