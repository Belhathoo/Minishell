/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:15:25 by belhatho          #+#    #+#             */
/*   Updated: 2022/01/18 22:15:26 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
// # include "../libft/libft.h"

extern char **g_env;

void prompt(void);

void parser(char **input);
char *parse_home(char *path);
char *do_path(char *name, char *d_name);

int print_env(void);
void init_environment(int ac, char **av, char **env);
char **realloc_env(int size);

int execution(char ***commands);
int check_one_cmd(char ***input);
int check_exec(char *path, struct stat st, char ***in);
int is_bin(char ***input);
int is_builtin(char ***input);
int run(char *cmd, char **input);

int run_cd(char **input);
void ft_chdir(char *path, int print);
int run_echo(char **input);
int run_setenv(char **input);
int run_unsetenv(char **input);
void set_env_var(char *key, char *value);
char *get_var(char *name);
int find_var_index(char *var);

void ft_signal(int sig);
void ft_child_signal(int sig);

char *strreplace(char *haystack, char *needle, char *str);
int isspce(char c);
void free_exit(void);

///// UTILS ///////

void			ft_putchar(char c);
void ft_putstr(char const *s);
void ft_put2str(char const *s, char const *s1);
void ft_put3str(char const *s, char const *s1, char const *s2);
void ft_put4str(char const *s, char const *s1, char const *s2, char const *s3);
void ft_putnstr(char *str, int n);
void ft_putendl(char const *s);

size_t ft_strlen(const char *s);
size_t ft_strlen2(char **s);
int ft_strstartswith(char *s1, char *s2);
int ft_strendswith(char *s1, char *s2);
int is_first_word(char *s1, char *s2);
int ft_strcmp(const char *s1, const char *s2);
int ft_strequ(char const *s1, char const *s2);
char *ft_strchr(const char *s, int c);
char *ft_strechr(const char *s, int c);
int ft_isempty(char **str);
char **ft_strsplit(char const *s, char c);
char **ft_strsplits(char const *s);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strjoin2(char *s1, char *s2, int tofree);
char *ft_strchjoin(const char *s1, char c);
char *ft_strchjoinf(char *s1, char c);
char *ft_strstr(const char *str, const char *to_find);
char *ft_strsub(char const *s, unsigned int start, size_t len);

char *ft_strdup(const char *src);
void *ft_memset(void *b, int c, size_t len);
char *ft_strnew(size_t size);
void *ft_realloc(void **ptr, size_t old, size_t len);
void ft_strdel(char **as);
void ft_free(char ***to);

#endif