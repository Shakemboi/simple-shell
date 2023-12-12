#include "shell.h"

/**
 * _myenv - a function which prints the current env
 * @info: a structure that contains potential parameters. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - a func which gets the value of an env var
 * @info: a structure that contains potential parameters. Used to maintain
 * @name: env variable name
 *
 * Return: a given value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - a func tha initializes new environment variable,
 * or rectify an existing one
 * @info: a structure that contains potential parameters. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - a function that remove an environment variable
 * @info: a structure that contains potential parameters. Used to maintain
 * constant function prototype.
 * Return: 0 Always
 */
int _myunsetenv(info_t *info)
{
	int j;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= info->argc; j++)
		_unsetenv(info, info->argv[j]);

	return (0);
}

/**
 * populate_env_list - ia func that populates env linked list
 * @info: a structure that contains potential parameters. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
		add_node_end(&node, environ[j], 0);
	info->env = node;
	return (0);
}

