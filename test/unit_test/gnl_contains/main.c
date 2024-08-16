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
	const	char	*expected_substring = "o World!\n";
	const	char	*empty_string = "";
	char		*string;
	char		character;
	char		missing_character;
	char		*substring;
	char		*error_case;

	execution_code = 0;
	character = 'o';
	missing_character = 'z';
	printf("Testing gnl_contains() function, please wait...\n");
	string = gnl_copy(source);
	printf("The source:\"%s\"\n", string);
	substring = gnl_contains(string, character);
	printf("The substring:\"%s\" (expected \"%s\")\n", substring, expected_substring);
	perform_test(test_equals(substring, expected_substring), "General purpose case test", &execution_code);
	substring = gnl_contains(string, missing_character);
	perform_test(!substring, "True negative case test", &execution_code);
	substring = gnl_contains(empty_string, character);
	perform_test(!substring, "Empty string case test", &execution_code);
	error_case = gnl_contains(NULL, character);
	perform_test(!error_case, "Null case test", &execution_code);
	printf("Program execution finished with code %i.\n", execution_code);
	free(string);
	return (execution_code);
}
