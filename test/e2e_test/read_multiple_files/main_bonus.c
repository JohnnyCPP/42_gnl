#include "../../../get_next_line_bonus.h"
// printf() for debugging
#include <stdio.h>
// open() to open files
#include <fcntl.h>
// for strcmp() function
#include <string.h>

static	void	local_read(int fd, char *data_obtained, char *file_name)
{
	printf("Reading %s...\n", file_name);
	data_obtained = get_next_line(fd);
	if (data_obtained)
	{
		printf("%s", data_obtained);
		free(data_obtained);
	}
}

int	main(void)
{
	const	char	*file_1 = "../../../reading_files/file_with_content.txt";
	const	char	*file_2 = "../../../reading_files/file_2.txt";
	const	char	*file_3 = "../../../reading_files/file_3.txt";
	int				fd_1;
	int				fd_2;
	int				fd_3;
	char			*data_obtained;

	data_obtained = NULL;
	fd_1 = open(file_1, O_RDONLY);
	if (fd_1 == -1)
	{
		printf("ERROR: the file_1 could not be opened.\n");
		return (0);
	}
	fd_2 = open(file_2, O_RDONLY);
	if (fd_2 == -1)
	{
		printf("ERROR: the file_2 could not be opened.\n");
		close(fd_1);
		return (0);
	}
	fd_3 = open(file_3, O_RDONLY);
	if (fd_3 == -1)
	{
		printf("ERROR: the file_3 could not be opened.\n");
		close(fd_1);
		close(fd_2);
		return (0);
	}
	local_read(fd_1, data_obtained, "file_1");
	local_read(fd_2, data_obtained, "file_2");
	local_read(fd_3, data_obtained, "file_3");
	local_read(fd_1, data_obtained, "file_1");
	local_read(fd_2, data_obtained, "file_2");
	local_read(fd_3, data_obtained, "file_3");
	close(fd_1);
	close(fd_2);
	close(fd_3);
	return (0);
}
