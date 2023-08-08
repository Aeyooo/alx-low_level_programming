#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters) {
  if (filename == NULL) {
    return 0;
  }

  int fd = open(filename, O_RDONLY);
  if (fd == -1) {
    return 0;
  }

  char *buf = malloc(letters * sizeof(char));
  ssize_t t = read(fd, buf, letters);
  ssize_t w = write(STDOUT_FILENO, buf, t);

  free(buf);
  close(fd);

  return w;
}
