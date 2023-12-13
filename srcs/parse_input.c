#include "minishell.h"

/**
 * parse_home - parse_home programm
 * @path: path
 * @env: env
 * Return: char
 */
char *parse_home(char *path, char **env)
{
	char *home_path;
	char *ret;

	if (!path)
		return (NULL);
	home_path = get_var("HOME", env);
	if ((!ft_strstartswith(path, "~")) ||
		(!ft_strstartswith(path, home_path)))
		return (ft_strdup(path));
	if (*(path + ft_strlen(home_path)) == '\0')
		ret = ft_strdup("~");
	else
		ret = do_path("~", path + ft_strlen(home_path));
	return (ret);
}

/**
 * parse_dollar - parse_dollar programm
 * @input: input
 * @index: index
 * @env: env
 * Return: char
 */
char *parse_dollar(char *input, int index, char **env)
{
	char *key;
	char *val;
	char c;

	key = ft_strnew(0);
	while (input[index] && !isspce(input[index]) &&
		   input[index] != ';' && input[index] != '$')
	{
		c = input[index];
		key = ft_strchjoinf(key, c);
		index++;
	}
	val = get_var(key, env);
	free(key);
	return (val);
}

/**
 * parsetilde - parsetilde programm
 * @rt: rt
 * @env: env
 * Return: char
 */
char *parsetilde(char *rt, char **env)
{
	char *tmp;
	char *ret;

	tmp = do_path(get_var("HOME", env), "/");
	if (rt)
		ret = do_path(rt, tmp);
	else
		ret = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (ret);
}

/**
 * parse_expansions - parse_expansions programm
 * @rt: argc
 * @in: argv
 * @n: environment the parameter
 * @env: env
 * Return: Always 0 (Success)!
 */

char *parse_expansions(char *rt, char *in, int *n, char **env)
{
	char *ret;
	int i;

	i = *n;
	ret = NULL;
	if (in[i] == '$' && in[i + 1])
	{
		ret = ft_strjoin(rt, parse_dollar(in, i + 1, env));
		while (in[i + 1] && !isspce(in[i + 1]) &&
			   in[i + 1] != '$' && in[i + 1] != ';')
			i++;
	}
	else if (in[i] == '~' && ((i != 0 && isspce(in[i - 1])) || i == 0))
		ret = parsetilde(rt, env);
	else
		ret = ft_strchjoin(rt, in[i]);
	free(rt);
	*n = i;
	return (ret);
}

/**
 * parser - parser
 * @input: input
 * @env: env
 */

void parser(char **input, char **env)
{
	char *ret;
	int i;

	i = -1;
	ret = NULL;
	while ((*input) && (*input)[++i])
		ret = parse_expansions(ret, *input, &i, env);
	free(*input);
	*input = ft_strdup(ret);
	ft_strdel(&ret);
}
