# Get Next Line
## This is the GNL project from the 42 cursus

![42](./resources/42_madrid.jpg "42")

> 42 Madrid is an academy for values, attitude and learning "hard and soft skills" in the digital environment.
<br>
The aim of this project is to program a function that returns a line read from a file descriptor.

## Mandatory part

<br>

- **Function name:** get_next_line
- **Function prototype:** char *get_next_line(int fd);
- **Return value:**
    - Ideally: the line read
    - In case of failure: NULL
- **Expected files:**
    1. get_next_line.c
    2. get_next_line_utils.c
    3. get_next_line.h
- **Authorised functions:**
    1. read
    2. malloc
    3. free
- **More details:**
    - The program must compile with and without the "-D BUFFER_SIZE=n" flag
        - Where 'n' represents the amount of bytes read for each "read" call
        - This parameter will be modified by the evaluators
    - The program is considered to have an indeterminate behaviour if:
        - The file whose file descriptor is pointed to has changed since the last time it was read, if the "read" function didn't reach the end of file
        - The file is a binary
    - The "libft" is not allowed
    - The global variables are forbidden

<br>

## Bonus part

<br>

> The bonus part is only evaluated if the mandatory part is absolutely perfect.

<br>

- **Expected files:**
    1. get_next_line_bonus.c
    2. get_next_line_utils_bonus.c
    3. get_next_line_bonus.h
- Develop the get_next_line function with a single static variable
- The get_next_line function must be able to manage multiple file descriptors simultaneously, during the same execution, without losing the reading thread

<br>

## Reading files

<br>

I've added specific files to perform different use cases through tests, located in the "reading_files" directory:

<br>

- **"create_no_nl_file.c":** creates the "file_with_no_nl.txt" file at the same directory
- **test_nl_files.c:** acts similar to a "cat" command, replacing '\n' characters for a "<br>" string. I used it to verify the content of the files
- **file_with_content.txt**, **file_2.txt**, **file_3.txt:** standard files to read
- **file_nocontent.txt:** an empty file
- **file_with_no_nl.txt:** a file containing a single line without an ending '\n' character

<br>

## Tests

<br>

I've developed my own unit and end-to-end tests to make sure I cover the quality requisits:

<br>

- **Unit tests** in the "./test/unit_test/" directory, covering the functions in "get_next_line_utils.c"
    - gnl_concat
    - gnl_contains
    - gnl_copy
    - gnl_cut
    - gnl_length
- **End-to-end tests** in the "./test/e2e_test/" directory
    - read_a_file: standard case of reading a file
    - read_binary: read a binary file
    - read_implicit_buffer: read a file without a declared buffer
    - read_modify_buffer: read a file modifying the buffer value
    - read_multiple_files: read multiple files simultaneously without losing the reading threads
    - read_no_content: read an empty file
    - read_no_nl: read a file containing a single line without an ending '\n' character
    - read_no_perm: read a file without reading permissions
    - read_stdin: read from standard input stream
    - read_urandom: read the "/dev/urandom" file
