/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 06:49:53 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/04/14 10:08:12 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	newprompt(int sig)
{
	(void) sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	c_handler(int sig)
{
	(void) sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	c_handler_fork(int sig)
{
	(void) sig;
	rl_on_new_line();
}

void	q_handler_fork(int sig)
{
	(void) sig;
	printf("^\\\n");
	rl_on_new_line();
}

void	q_handler(int sig)
{
	(void)sig;
	printf("^\\Quit");
	printf("\n");
	rl_on_new_line();
}

void	here_doc_sig2(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	exit(0);
}

void	c_handler_2(int sig)
{
	(void) sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	d_handler(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
}

// int	g_status;

// void	handle_sigint(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		g_status = 130;
// 		ioctl(STDIN_FILENO, TIOCSTI, "\n");
// 		// rl_replace_line("", 0);
// 		rl_on_new_line();
// 	}
// }

// void	handle_sigquit(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		g_status = 130;
// 		ioctl(STDIN_FILENO, TIOCSTI, "\n");
// 		// rl_replace_line("", 0);
// 		rl_on_new_line();
// 	}
// }
