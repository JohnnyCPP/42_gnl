#include "../../../get_next_line_bonus.h"
// printf() for debugging
#include <stdio.h>
// open() to open files
#include <fcntl.h>
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
	const	char	*file_to_read = "../../../reading_files/test_nl_files";
	int				fd;
	char			*data_obtained;
	int				*is_readable;

	is_readable = malloc(sizeof(int));
	*is_readable = 1;
	data_obtained = NULL;
	fd = open(file_to_read, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR: the file could not be opened.\n");
		return (0);
	}
	while (*is_readable)
		local_read(fd, data_obtained, is_readable);
	free(is_readable);
	close(fd);
	return (0);
}
