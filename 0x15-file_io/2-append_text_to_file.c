#include "main.h"

/**
 * append_text_to_file - append text to the end of a file
 * _strlen - for string length
 * @s: string
 * @filename: file to work on
 * @text_content: the sting to aend and write to the file
 * Return: length of the string
 * Return: 1 if successful and -1 if failed
 */
int _strlen(char *s)
{
	int length = 0, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		length++;
	}
	return (length);
}

int append_text_to_file(const char *filename, char *text_content)
{
	int fp, bytesWrite;
	if (filename == NULL)
	{
		return (-1);
	}

	fp = open(filename, O_WRONLY, O_APPEND, 0644);

	if (fp < 0)
	{
		return (-1);
	}

	if (text_content)
	{
		bytesWrite = write(fp, text_content, _strlen(text_content));
		if (bytesWrite < 0)
		{
			close(fp);
			return (-1);
		}
	}

	close(fp);
	return (-1);
}
