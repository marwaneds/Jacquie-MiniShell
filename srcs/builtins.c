/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:14:37 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/05/23 14:43:57 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_echo(char **args)
{
    int i = 1;
    while (args[i] != NULL)
    {
        printf("%s ", args[i]);
        i++;
    }
    printf("\n");
}

void execute_cd(char **args)
{
    if (args[1] == NULL)
    {
        // Pas d'argument, revenir au répertoire personnel de l'utilisateur
        chdir(getenv("HOME"));
    }
    else
    {
        if (chdir(args[1]) == -1)
        {
            // Erreur de changement de répertoire
            perror("cd");
        }
    }
}

void execute_pwd()
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s\n", cwd);
    }
    else
    {
        // Erreur lors de l'obtention du répertoire de travail actuel
        perror("pwd");
    }
}

void execute_env()
{
    extern char **environ;
    int i = 0;
    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
}

void execute_unset(char **args)
{
    if (args[1] != NULL)
    {
        int i = 1;
        while (args[i] != NULL)
        {
            unsetenv(args[i]);
            i++;
        }
    }
    else
    {
        // Aucun argument fourni
        fprintf(stderr, "unset: argument manquant\n");
    }
}

void execute_exit()
{
    exit(0);
}