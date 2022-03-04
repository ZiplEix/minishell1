/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** cd_commande
*/
#include "../../include/my.h"

char *get_var_env(char **env, char *desired_var)
{
    int i = 0;
    char **temp;

    while (env[i]) {
        temp = my_split(env[i], '=');
        if (my_strcmp(temp[0], desired_var) == 0) {
            return temp[1];
        }
        i++;
    }
}

char **exec_cd(char **env, char **commande)
{
    char pwd[10000];
    errno = 0;
    if (commande[1][0] == '~' && commande[1][1] == '/') {
        commande[1] =
        my_strcat(my_strcat(get_var_env(env, "HOME"), "/"), &commande[1][2]);
    }
    if (commande[1][0] == '~' && !commande[1][1])
        commande[1] = get_var_env(env, "HOME");
    getcwd(pwd, 10000);
    env = define_old_env_pwd(env, pwd);
    if (chdir(commande[1]) != 0) {
        my_putstr(2, commande[1]);
        my_putstr(2, ": ");
        my_putstr(2, strerror(errno));
        my_putstr(2, ".\n");
        return env;
    }
    getcwd(pwd, 10000);
    env = define_new_env_pwd(env, pwd);
    return env;
}

char **cd_home(char **env)
{
    char pwd[10000];

    getcwd(pwd, 10000);
    env = define_old_env_pwd(env, pwd);
    chdir(get_var_env(env, "HOME"));
    getcwd(pwd, 10000);
    env = define_new_env_pwd(env, pwd);

    return env;
}

char **func_cd(char **env, char **commande)
{
    char pwd[10000];
    int nb_arg = count_line_double_array(commande);

    if (nb_arg > 2) {
        print_error(commande, TOO_MANY_ARGUMENTS);
        return env;
    } else if (nb_arg == 1) {
        env = cd_home(env);
        return env;
    } else if (my_strcmp(commande[1], "-") == 0) {
        chdir(get_var_env(env, "OLDPWD"));
        getcwd(pwd, 10000);
        env = define_new_env_pwd(env, pwd);
        return env;
    } else if (nb_arg == 2) {
        env = exec_cd(env, commande);
        return env;
    }
}
