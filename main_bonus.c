#include "./get_next_line_bonus.h"
// printf() for debugging
#include <stdio.h>
// open() to open files
#include <fcntl.h>

void	local_read(int fd, char *data_obtained)
{
	data_obtained = get_next_line(fd);
	printf("INFO: data_obtained=\"%s\"\n", data_obtained);
	if (data_obtained)
		free(data_obtained);
}

int	main(void)
{
	int	fd;
	char	*data_obtained;

	data_obtained = NULL;
	fd = open("./reading_files/file_with_content.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR: the file could not be opened.\n");
		return (0);
	}
	printf("INFO: file descriptor=%i\n\n", fd);
	local_read(fd, data_obtained);
	local_read(fd, data_obtained);
	local_read(fd, data_obtained);
	local_read(fd, data_obtained);
	local_read(fd, data_obtained);
	local_read(fd, data_obtained);
	local_read(fd, data_obtained);
	local_read(fd, data_obtained);
	close(fd);
	return (0);
}
