#include "shell.h"

/**
 * free_all - a func to free all malloc'd space at end of main loop
 * @tokens: tokens array's pointer
 * @path: path variable's pointer
 * @line: user input's buffer pointer
 * @fullpath: full path's pointer
 * @flag: flag marking if full_path was malloc'd
 * Return: void
 */
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag)
{
	free(path);
	free(tokens);
	free(line);
	if (flag == 1)
		free(fullpath);
}

/**
 * free_dp - func to free double pointer
 * @array: the freed double pointer
 * @length: double pointer's length
 * Return: void
 */
void free_dp(char **array, unsigned int length)
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
