#include <iostream>
#include <otus_matrix_lib/matrix_operation_sum.hpp>
#include <otus_matrix_lib/matrix_operation_trans.hpp>
#include <otus_matrix_lib/matrix_operation_det.hpp>

using namespace otus_matrix;

std::shared_ptr<matrix_operation_base> select_operation(int argc, char** argv)
{
	if (argc < 4)
		throw std::runtime_error("Usage: otus_matrix_exe <input_path> <output_path> <operation_name>");

	const auto input_path = std::filesystem::path(argv[1]);
	const auto output_path = std::filesystem::path(argv[2]);
	const auto operation_name = std::string(argv[3]);

	if (operation_name == std::string("sum"))
	{
		return std::make_shared<matrix_operation_sum<int>>(input_path, output_path);
	}
	if (operation_name == std::string("trans"))
	{
		return std::make_shared<matrix_operation_trans<int>>(input_path, output_path);
	}
	if (operation_name == std::string("det"))
	{
		return std::make_shared<matrix_operation_det<int>>(input_path, output_path);
	}

	throw std::runtime_error("Unknown operation");
}

void start(std::shared_ptr<matrix_operation_base> const& pointer_to_operation)
{
	pointer_to_operation->execute();
}

int main(const int argc, char** argv)
{
	try
	{
		start(select_operation(argc, argv));
	}
	catch (std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
	}

	return 0;
}
