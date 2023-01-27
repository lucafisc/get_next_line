<h1 align="center">get_next_line</h1>

<p align="center">
<img src="https://i.imgur.com/hOxMLtT.png" alt="drawing" width="120"/>
</p>

This function returns one line at a time from a given file descriptor. It can be compiled with any `BUFFER_SIZE`. 

It uses static variables and the following external functions: `read` `malloc` `free`

Functions ending with `_bonus.c` can be used to read simultaneously from multiple file descriptors.

[![lde-ross's 42 get_next_line Score](https://badge42.vercel.app/api/v2/clcrkbbp700300fkxp8nykj3n/project/2916842)](https://github.com/JaeSeoKim/badge42)

- [How to use](#how-to-use)
- [How to test](#how-to-test)
- [Read from multiple files](#read-from-multiple-files)

## How to use

First clone this repository:

```
git clone git@github.com:lucafisc/get_next_line.git
```

Enter the directory:

```
cd get_next_line
```

The function can be used in any program written in `C`. You can create a `main.c` file to test it.

## How to test

Create a `main.c` file:

```c
// Include the header
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*pt;

	// Open .txt file and protect from errors
	fd = open("./text_file.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "error opening file", 18);
		return (0);
	}

	// Define number of lines to be read
	i = 5;
	while (i--)
	{
		pt = get_next_line(fd);
		printf("%s", pt);
		free(pt);
	}
	return (0);
}
```

Compile the `main.c` file with the `C` files `get_next_line.c` and `get_next_line_utils.c`. You can also override the default `BUFFER_SIZE` when compiling:

```
cc -D BUFFER_SIZE=10 -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c && ./a.out
```

In the terminal you should see the defined amount of lines printed.

## Read from multiple files

To read from multiple files compile with the `C` files ending with `_bonus.c`

To test it use a `main.c` function that opens different files:

```c
// Include the header
#include "get_next_line_bonus.h"

int main(void)
{
	int		fd1;
	int		fd2;
	char	*pt;

	// Open .txt files and protect from errors
	fd1 = open("./first_file.txt", O_RDONLY);
	fd2 = open("./second_file.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
	{
		write(2, "error opening file", 18);
		return (0);
	}

	// Get first line from the first file
	pt = get_next_line(fd1);
	printf("%s\n", pt);
	free(pt);

	// Get first line from the second file
	pt = get_next_line(fd2);
	printf("%s\n", pt);
	free(pt);

	return (0);
}
```

