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
	const	char	*source = "Hello World!\n";
	const	char	*empty_string = "";
	char		*string;
	char		*error_case;

	execution_code = 0;
	printf("Testing gnl_copy() function, please wait...\n");
	printf("The source:%s\n", source);
	string = gnl_copy(source);
	printf("The result:%s\n", string);
	perform_test(test_equals(string, source), "General purpose case test", &execution_code);
	free(string);
	string = gnl_copy(empty_string);
	perform_test(test_equals(string, empty_string), "Empty string case test", &execution_code);
	free(string);
	error_case = gnl_copy(NULL);
	perform_test(!error_case, "Null case test", &execution_code);
	printf("Program execution finished with code %i.\n", execution_code);
	return (execution_code);
}
