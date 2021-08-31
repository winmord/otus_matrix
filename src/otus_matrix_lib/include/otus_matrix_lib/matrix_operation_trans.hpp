#pragma once

#include "otus_matrix_lib/matrix_operation_base.hpp"
#include "otus_matrix_lib/matrix.hpp"

#include <fstream>

namespace otus_matrix
{
	template <class T>
	class matrix_operation_trans : public matrix_operation_base
	{
	public:
		matrix_operation_trans(std::filesystem::path const& input_path,
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

			this->result_matrix_.set_size(rows, columns);

			for (auto i = 0u; i < rows; i++)
			{
				for (auto j = 0u; j < columns; j++)
				{
					const auto element = this->matrix_.get_element(i, j);
					this->result_matrix_.set_element(j, i, element);
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
		matrix<T> matrix_;
		matrix<T> result_matrix_;
	};
}
