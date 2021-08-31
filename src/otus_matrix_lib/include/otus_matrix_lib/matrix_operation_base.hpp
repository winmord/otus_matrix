#pragma once
#include <filesystem>
#include <string>

namespace otus_matrix
{
	class matrix_operation_base
	{
	public:
		virtual ~matrix_operation_base() = default;
		matrix_operation_base(std::filesystem::path input_path,
		                      std::filesystem::path output_path);

		void execute();

	protected:
		virtual void read_input() = 0;
		virtual void execute_operation() = 0;
		virtual void write_output() = 0;

		std::filesystem::path input_path_;
		std::filesystem::path output_path_;
	};
}
