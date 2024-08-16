#include "../../get_next_line.h"
// for strcmp() function
#include <string.h>

static	int	test_equals(const char *string, const char *reference)
{
	if (!string || !reference)
		return (0);
	return (strcmp(string, reference) == 0);
}

static	void	perform_test(int expression, const char *test_name, int *execution_code)
{
	if (expression)
		printf("%s passed successfully.\n", test_name);
	else
	{
		printf("%s failed.\n", test_name);
		*execution_code = 1;
	}
}

int	main(void)
{
	int		execution_code;
	const	char	*destination = "Hello ";
	const	char	*source = "World!\n";
	const	char	*expected_result = "Hello World!\n";
	const	char	*empty_string = "";
	char		*result;
	char		*error_case;

	execution_code = 0;
	printf("Testing gnl_concat() function, please wait...\n");
	printf("The source:\"%s\"\n", source);
	printf("The destination:\"%s\"\n", destination);
	printf("The expected_result:\"%s\"\n", expected_result);
	result = gnl_concat(destination, source);
	printf("The result:\"%s\" (expected \"%s\")\n", result, expected_result);
	perform_test(test_equals(result, expected_result), "General purpose case test", &execution_code);
	free(result);
	result = gnl_concat(empty_string, source);
	perform_test(test_equals(result, source), "Empty string case test 1", &execution_code);
	free(result);
	result = gnl_concat(destination, empty_string);
	perform_test(test_equals(result, destination), "Empty string case test 2", &execution_code);
	free(result);
	error_case = gnl_concat(NULL, source);
	perform_test(!error_case, "Null case test 1", &execution_code);
	error_case = gnl_concat(destination, NULL);
	perform_test(!error_case, "Null case test 2", &execution_code);
	printf("Program execution finished with code %i.\n", execution_code);
	return (execution_code);
}
