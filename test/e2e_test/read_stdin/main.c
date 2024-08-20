#include "../../../get_next_line.h"
// printf() for debugging
#include <stdio.h>
// for strcmp() function
#include <string.h>

static	void	local_read(int fd, char *data_obtained, int *is_readable)
{
	data_obtained = get_next_line(fd);
	if (data_obtained)
	{
		printf("%s", data_obtained);
		free(data_obtained);
	}
	else
		*is_readable = 0;
}

int	main(void)
{
	char			*data_obtained;
	int				*is_readable;

	is_readable = malloc(sizeof(int));
	*is_readable = 1;
	data_obtained = NULL;
	while (*is_readable)
		local_read(0, data_obtained, is_readable);
	free(is_readable);
	return (0);
}
