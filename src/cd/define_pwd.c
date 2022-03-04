/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** define_pwd
*/
#include "../../include/my.h"

char **define_old_env_pwd(char **env, char *pwd)
{
    char **temp;
    char *old_pwd = "OLDPWD";
    int lines = count_line_double_array(env);
    char **new_env = malloc(sizeof(char *) * lines);

    old_pwd = my_strcat(old_pwd, "=");
    old_pwd = my_strcat(old_pwd, pwd);

    for (int i = 0; i < lines; i++) {
        temp = my_split(env[i], '=');
        if (my_strcmp(temp[0], "OLDPWD") == 0) {
            new_env[i] = malloc(sizeof(old_pwd) + 1);
            new_env[i] = old_pwd;
            continue;
        }
        new_env[i] = malloc(sizeof(env[i]) + 1);
        new_env[i] = env[i];
    }
    return new_env;
}

char **define_new_env_pwd(char **env, char *pwd)
{
    char **temp;
    char *new_pwd = "PWD";
    int lines = count_line_double_array(env);
    char **new_env = malloc(sizeof(char *) * lines);

    new_pwd = my_strcat(new_pwd, "=");
    new_pwd = my_strcat(new_pwd, pwd);

    for (int i = 0; i < lines; i++) {
        temp = my_split(env[i], '=');
        if (my_strcmp(temp[0], "PWD") == 0) {
            new_env[i] = malloc(sizeof(new_pwd) + 1);
            new_env[i] = new_pwd;
            continue;
        }
        new_env[i] = malloc(sizeof(env[i]) + 1);
        new_env[i] = env[i];
    }
    return new_env;
}
