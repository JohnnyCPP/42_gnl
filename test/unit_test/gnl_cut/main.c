#include "../../../get_next_line.h"
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
	const	char	*string = "Hello World!\n";
	const	char	*expected_string = "World";
	const	char	*empty_string = "";
	char		*result;
	char		*error_case;
	size_t	start = 6;
	size_t	length = 5;

	execution_code = 0;
	printf("Testing gnl_cut() function, please wait...\n");
	printf("The string:\"%s\"\n", string);
	printf("The start:\"%zu\"\n", start);
	printf("The length:\"%zu\"\n", length);
	result = gnl_cut(string, start, length);
	printf("The result:\"%s\" (expected \"%s\")\n", result, expected_string);
	perform_test(test_equals(result, expected_string), "General purpose case test", &execution_code);
	free(result);
	result = gnl_cut(empty_string, start, length);
	perform_test(test_equals(result, empty_string), "Empty string case test", &execution_code);
	free(result);
	error_case = gnl_cut(NULL, start, length);
	perform_test(!error_case, "Null case test", &execution_code);
	printf("Program execution finished with code %i.\n", execution_code);
	return (execution_code);
}
