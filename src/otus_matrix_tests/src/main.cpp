#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "layout.hpp"

#include <otus_matrix_lib/matrix_operation_sum.hpp>
#include <otus_matrix_lib/matrix_operation_trans.hpp>
#include <otus_matrix_lib/matrix_operation_det.hpp>

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
	required_matrix.set_element(0, 1, 10);
	required_matrix.set_element(0, 2, 10);

	required_matrix.set_element(1, 0, 10);
	required_matrix.set_element(1, 1, 10);
	required_matrix.set_element(1, 2, 10);

	required_matrix.set_element(2, 0, 10);
	required_matrix.set_element(2, 1, 10);
	required_matrix.set_element(2, 2, 10);

	std::ifstream output_stream(output_path);

	otus_matrix::matrix<int> result_matrix;
	output_stream >> result_matrix;

	REQUIRE(required_matrix == result_matrix);
}

TEST_CASE("trans test")
{
	const std::filesystem::path input_path(get_test_file("in.txt"));
	const std::filesystem::path output_path("out.txt");
	otus_matrix::matrix_operation_trans<int> operation(input_path, output_path);
	operation.execute();

	otus_matrix::matrix<int> required_matrix;
	required_matrix.set_size(3, 3);

	required_matrix.set_element(0, 0, 1);
	required_matrix.set_element(0, 1, 4);
	required_matrix.set_element(0, 2, 7);

	required_matrix.set_element(1, 0, 2);
	required_matrix.set_element(1, 1, 5);
	required_matrix.set_element(1, 2, 8);

	required_matrix.set_element(2, 0, 3);
	required_matrix.set_element(2, 1, 6);
	required_matrix.set_element(2, 2, 9);

	std::ifstream output_stream(output_path);

	otus_matrix::matrix<int> result_matrix;
	output_stream >> result_matrix;

	REQUIRE(required_matrix == result_matrix);
}

TEST_CASE("det test")
{
	const std::filesystem::path input_path(get_test_file("in.txt"));
	const std::filesystem::path output_path("out.txt");
	otus_matrix::matrix_operation_det<int> operation(input_path, output_path);
	operation.execute();

	std::ifstream output_stream(output_path);

	const auto required_det{0};

	int result_det;
	output_stream >> result_det;

	REQUIRE(required_det == result_det);
}
