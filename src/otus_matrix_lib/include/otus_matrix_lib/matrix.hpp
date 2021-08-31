#pragma once
#include <istream>
#include <vector>

namespace otus_matrix
{
	template <class T>
	class matrix
	{
	public:
		T get_element(size_t const& row, size_t const& column) const
		{
			return this->matrix_[row][column];
		}

		void set_element(size_t const& row, size_t const& column, T const& element)
		{
			this->matrix_[row][column] = element;
		}

		void set_size(size_t const& rows, size_t const& columns)
		{
			this->rows_ = rows;
			this->columns_ = columns;

			this->matrix_.clear();
			std::vector<T> matrix_row(this->columns_, 0);

			for (auto i = 0u; i < this->rows_; i++)
			{
				this->matrix_.push_back(matrix_row);
			}
		}

		void remove_row(size_t const& row)
		{
			this->matrix_.erase(this->matrix_.begin() + row);
			--this->rows_;
		}

		void remove_column(size_t const& column)
		{
			for(auto& row : matrix_)
			{
				row.erase(row.begin() + column);
			}
			--this->columns_;
		}

		size_t columns() const
		{
			return this->columns_;
		}

		size_t rows() const
		{
			return this->rows_;
		}

	private:
		size_t columns_{0};
		size_t rows_{0};
		std::vector<std::vector<T>> matrix_;
	};

	template <class T>
	std::istream& operator>>(std::istream& is, matrix<T>& m)
	{
		size_t columns,
		       rows;

		is >> columns >> rows;

		m.set_size(columns, rows);

		for (auto i = 0u; i < m.rows(); i++)
		{
			for (auto j = 0u; j < m.columns(); j++)
			{
				T element;
				is >> element;
				m.set_element(i, j, element);
			}
		}

		return is;
	}

	template <class T>
	std::ostream& operator<<(std::ostream& os, matrix<T> const& m)
	{
		os << m.columns() << " " << m.rows() << std::endl;

		for (auto i = 0u; i < m.rows(); i++)
		{
			for (auto j = 0u; j < m.columns(); j++)
			{
				os << m.get_element(i, j);

				if (j < m.columns() - 1) os << " ";
			}
			os << std::endl;
		}

		return os;
	}
}
