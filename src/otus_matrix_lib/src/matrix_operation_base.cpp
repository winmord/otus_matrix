#include "otus_matrix_lib/matrix_operation_base.hpp"

#include <iostream>
#include <utility>

namespace otus_matrix
{
	matrix_operation_base::matrix_operation_base(std::filesystem::path input_path,
	                                             std::filesystem::path output_path)
		: input_path_(std::move(input_path)), output_path_(std::move(output_path))
	{
	}

	void matrix_operation_base::execute()
	{
		this->read_input();
		this->execute_operation();
		this->write_output();
	}
}
