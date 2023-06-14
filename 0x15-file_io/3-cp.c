#include "main.h"

/**
 * buffer_handling - copies the buffer string to file
 * @argv: argument vector
 * @argc: argument count
 * @fp: 1st file descriptor
 * @fp1: 2nd file descriptor
 * @f1: file 1
 * @f2: file 2
 * @buffer: string to copy
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	int fp, fp1;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fp = open(argv[1], O_RDONLY);
	if (fp < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fp1 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fp1 < 0)
        {
                dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
                exit(99);
        }
	buffer_handling(fp, fp1, buffer, argv[1], argv[2]);

	return (0);
}

void buffer_handling(int fp, int fp1, char *buffer, char *f1, char *f2)
{
	int read_buffer_count, write_buffer_count;

	while ((read_buffer_count = read(fp, buffer, 1024)) > 0)
	{
		write_buffer_count = write(fp1, buffer, read_buffer_count);
		if ((write_buffer_count != read_buffer_count) || (write_buffer_count < 0))
		{
			dprintf(STDERR_FILENO, "Error: Can't write from file %s\n",f2);
			exit(99);
		}
	}

	 if (read_buffer_count < 0)
                {
                        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",f1);
                        exit(98);
                }
	 if (close(fp))
                {
                        dprintf(STDERR_FILENO, "Error: Can't close fp FP_VALUE %d\n",fp);
                        exit(100);
                }
	 if (close(fp1))
                {
                        dprintf(STDERR_FILENO, "Error: Can't close fp FP_VALUE %d\n",fp1);
                        exit(100);
                }
}
