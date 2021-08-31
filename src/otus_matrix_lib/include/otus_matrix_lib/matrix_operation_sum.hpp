#pragma once

#include "otus_matrix_lib/matrix_operation_base.hpp"
#include "otus_matrix_lib/matrix.hpp"

#include <fstream>

namespace otus_matrix
{
	template <class T>
	class matrix_operation_sum : public matrix_operation_base
	{
	public:
		matrix_operation_sum(std::filesystem::path const& input_path,
		                     std::filesystem::path const& output_path)
			: matrix_operation_base(input_path, output_path)
		{
		}

	protected:
		void read_input() override
		{
			std::ifstream input_stream(this->input_path_);

			input_stream >> this->l_matrix_;
			input_stream >> this->r_matrix_;

			input_stream.close();
		}

		void execute_operation() override
		{
			const auto l_matrix_columns = this->l_matrix_.columns();
			const auto l_matrix_rows = this->l_matrix_.rows();
			const auto r_matrix_columns = this->r_matrix_.columns();
			const auto r_matrix_rows = this->r_matrix_.rows();

			if (l_matrix_columns != r_matrix_columns ||
				l_matrix_rows != r_matrix_rows)
				throw std::runtime_error("Matrices is incompatible");

			const auto columns = l_matrix_columns;
			const auto rows = l_matrix_rows;

			this->result_matrix_.set_size(rows, columns);

			for (auto i = 0u; i < rows; i++)
			{
				for (auto j = 0u; j < columns; j++)
				{
					const auto l_element = this->l_matrix_.get_element(i, j);
					const auto r_element = this->r_matrix_.get_element(i, j);

					this->result_matrix_.set_element(i, j, l_element + r_element);
				}
			}
		}

		void write_output() override
		{
			std::ofstream output_stream(this->output_path_);
			output_stream << this->result_matrix_;
			output_stream.close();
		}

	private:
		matrix<T> l_matrix_;
		matrix<T> r_matrix_;
		matrix<T> result_matrix_;
	};
}
