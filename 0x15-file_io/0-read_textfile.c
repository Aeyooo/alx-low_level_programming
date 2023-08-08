#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *letter;
	ssize_t f;
	ssize_t wr;
	ssize_t tr;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	letter = malloc(sizeof(char) * letters);
	tr = read(f, letter, letters);
	wr = write(STDOUT_FILENO, letter, tr);

	free(letter);
	close(f);
	return (wr);
}

