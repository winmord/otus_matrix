#pragma once

#include "otus_matrix_lib/matrix_operation_base.hpp"
#include "otus_matrix_lib/matrix.hpp"

#include <fstream>

namespace otus_matrix
{
	template <class T>
	class matrix_operation_det : public matrix_operation_base
	{
	public:
		matrix_operation_det(std::filesystem::path const& input_path,
		                     std::filesystem::path const& output_path)
			: matrix_operation_base(input_path, output_path)
		{
		}

	protected:
		void read_input() override
		{
			std::ifstream input_stream(this->input_path_);
			input_stream >> this->matrix_;
			input_stream.close();
		}

		void execute_operation() override
		{
			const auto columns = this->matrix_.columns();
			const auto rows = this->matrix_.rows();

			this->result_ = calculate_det(this->matrix_);
		}

		T calculate_det(matrix<T> const& matrix)
		{
			T det{0};

			const auto columns = matrix.columns();
			const auto rows = matrix.rows();

			if (rows != columns) throw std::runtime_error("Matrix must be square");

			const auto size = columns;

			if (size == 2)
			{
				return matrix.get_element(0, 0) * matrix.get_element(1, 1) -
					matrix.get_element(0, 1) * matrix.get_element(1, 0);
			}

			for (auto i = 0u; i < size; i++)
			{
				auto reduced_m = matrix;
				reduced_m.remove_row(0);
				reduced_m.remove_column(i);

				det += (i % 2 == 0 ? 1 : -1) * matrix.get_element(0, i) * calculate_det(reduced_m);
			}

			return det;
		}

		void write_output() override
		{
			std::ofstream output_stream(this->output_path_);
			output_stream << this->result_;
			output_stream.close();
		}

	private:
		matrix<T> matrix_;
		size_t result_{0};
	};
}
