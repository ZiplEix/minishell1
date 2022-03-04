/*
** EPITECH PROJECT, 2022
** my_h
** File description:
** my_h
*/

#ifndef MY_H_
    #define MY_H_

//define
    #define NOT_FOUND_COMMANDE 0
    #define TOO_MANY_ARGUMENTS 1
    #define TOO_FEW_ARGUMENTS 2

//include
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <signal.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include <sys/time.h>
    #include <sys/resource.h>
    #include <sys/types.h>
    #include <sys/stat.h>

//lib
int my_getnbr(char const *str);
int my_put_nbr(int nb);
int my_putstr(int channel, char const *str);
char **my_str_to_word_array(char *str);
char *my_strcat(char *src, char *to_add);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strncpy(char *dest , char const *src , int n);
char **my_split(char *str, char split);
int count_line_double_array(char **double_array);

//error
int error(int argc, char **argv);
void print_error(char **commande, int error);
void error_execve(int status);

//code
int minishell(int argc, char **argv, char **env);
void print_promp(void);
void path_commande(char **commande, char **env);

//exit
void fonc_exit(char **commande);

//path
void path_commande(char **commande, char **env);

//env
void env_commande(char **env, char **commande);
char **func_setenv(char **env, char **commande);
char **func_unsetenv(char **env, char **commande);

//cd
char **func_cd(char **env, char **commande);
char **define_old_env_pwd(char **env, char *pwd);
char **define_new_env_pwd(char **env, char *pwd);

//binary
void binary_commande(char **env, char **commande);

#endif /* !MY_H_ */
