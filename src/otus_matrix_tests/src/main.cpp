#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "layout.hpp"

#include <otus_matrix_lib/matrix_operation_sum.hpp>
#include <otus_matrix_lib/matrix_operation_trans.hpp>

std::filesystem::path get_test_file(std::filesystem::path const& filename)
{
	if (filename.is_absolute()) return filename;
	return std::filesystem::path(test_folder_path()) / filename;
}

TEST_CASE("sum test")
{
	const std::filesystem::path input_path(get_test_file("in.txt"));
	const std::filesystem::path output_path("out.txt");
	otus_matrix::matrix_operation_sum<int> operation(input_path, output_path);
	operation.execute();

	otus_matrix::matrix<int> required_matrix;
	required_matrix.set_size(3, 3);

	required_matrix.set_element(0, 0, 10);
	required_matrix.set_element(0, 1, 8);
	required_matrix.set_element(0, 2, 7);

	required_matrix.set_element(1, 0, 6);
	required_matrix.set_element(1, 1, 7);
	required_matrix.set_element(1, 2, 4);

	required_matrix.set_element(2, 0, 3);
	required_matrix.set_element(2, 1, 2);
	required_matrix.set_element(2, 2, 4);
}

TEST_CASE("trans test")
{
	const std::filesystem::path input_path(get_test_file("in.txt"));
	const std::filesystem::path output_path("out.txt");
	otus_matrix::matrix_operation_trans<int> operation(input_path, output_path);
	operation.execute();
}

TEST_CASE("det test")
{
	const std::filesystem::path input_path(get_test_file("in.txt"));
	const std::filesystem::path output_path("out.txt");
	otus_matrix::matrix_operation_sum<int> operation(input_path, output_path);
	operation.execute();
}
