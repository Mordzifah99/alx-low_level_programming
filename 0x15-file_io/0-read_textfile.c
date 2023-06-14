#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - a function that reads a text file and prints it
 * @letters: number of letters to read and print
 * @filename: name of text file
 * Return: actual number of letters it could read and print
 * if file cannot be opened and read, return 0
 * if filename is NULL, return 0
 * if write fails, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fp;
	char *buffer;
        int bytesRead;
        int bytesWrite;

	if (filename == NULL)
        {
                return (0);
        }

	fp = open(filename, O_RDONLY);
        buffer = malloc(sizeof(buffer) * letters);
        if (buffer == NULL)
        {
                return (0);
        }

	if (fp != -1)
        {
                bytesRead = read(fp, buffer, letters);
                bytesWrite = write(STDOUT_FILENO, buffer, bytesRead);
                if (bytesWrite < 0 || bytesRead < 0 || bytesRead !=bytesWrite)
                {
			free(buffer);
                        close(fp);
                        return (0);
                }
	}

	free(buffer);
	close(fp);
	return (bytesWrite);
}
