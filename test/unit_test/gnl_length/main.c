#include "../../../get_next_line.h"
#include <stdio.h>

static	int	test_equals(int value, int reference)
{
	return (value == reference);
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
	int		empty_length;
	ssize_t		source_length;
	ssize_t		string_length;
	ssize_t		error_case;

	execution_code = 0;
	empty_length = 0;
	source_length = 13;
	printf("Testing gnl_length() function, please wait...\n");
	printf("The source:%s\n", source);
	string_length = gnl_length(source);
	printf("The length:%li (expected %li)\n", string_length, source_length);
	perform_test(test_equals(string_length, source_length), "General purpose case test", &execution_code);
	string_length = gnl_length(empty_string);
	perform_test(test_equals(string_length, empty_length), "Empty string test", &execution_code);
	error_case = gnl_length(NULL);
	perform_test(!error_case, "Null value test", &execution_code);
	printf("Program execution finished with code %i.\n", execution_code);
	return (execution_code);
}
