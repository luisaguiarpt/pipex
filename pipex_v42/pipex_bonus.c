/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:12:17 by ldias-da          #+#    #+#             */
/*   Updated: 2025/07/27 12:53:07 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **ep)
{
	int		i;
	int		status;
	int		pid;
	t_pipex	px;

	if (ac < 5)
		ft_exit(USE_ERR);
	init_pipex(&px, ac, av);
	i = -1;
	while (++i < px.nr_cmds)
		pipeline(&px, av, ep, i);
	i = -1;
	while (++i < px.nr_cmds)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == px.last_pid)
			px.last_status = status;
	}
	if (px.here_d)
		unlink(".heredoc_tmp");
	if (WIFEXITED(px.last_status))
		return (WEXITSTATUS(px.last_status));
}

void	pipeline(t_pipex *px, char **av, char **ep, int i)
{
	int	pid;

	if (i < px->nr_cmds - 1)
		if (pipe(px->fd) == -1)
			ft_exit(PIPE_ERR);
	pid = fork();
	if (pid == -1)
		ft_exit(FORK_ERR);
	else if (!pid)
		exec_child(px, av, ep, i);
	close(px->prev_fd);
	if (i < px->nr_cmds - 1)
	{
		close(px->fd[1]);
		px->prev_fd = px->fd[0];
	}
	if (i == px->nr_cmds - 1)
		px->last_pid = pid;
}

void	exec_child(t_pipex *px, char **av, char **ep, int i)
{
	if (i == 0)
		px->prev_fd = get_input(px, av, ep);
	dup2(px->prev_fd, STDIN_FILENO);
	close(px->prev_fd);
	if (i == px->nr_cmds - 1)
	{
		px->out_fd = get_output(px, av, ep);
		dup2(px->out_fd, STDOUT_FILENO);
		close(px->out_fd);
	}
	else
	{
		dup2(px->fd[1], STDOUT_FILENO);
		close(px->fd[0]);
		close(px->fd[1]);
	}
	exec_cmd(px, av, ep, i);
}

void	exec_cmd(t_pipex *px, char **av, char **ep, int i)
{
	char	*cmd_path;
	char	**cmds;
	int		cmd_i;

	cmd_i = i + 2 + px->here_d;
	if (!ft_strlen(av[cmd_i]))
		ft_exit(CMD_NA);
	cmd_path = get_path(av[cmd_i], ep);
	cmds = ft_split(av[cmd_i], ' ');
	if (execve(cmd_path, cmds, ep) == -1)
	{
		ft_free_tab(cmds);
		free(cmd_path);
		ft_exit(CMDEXEC_ERR);
	}
}

void	init_pipex(t_pipex *px, int ac, char **av)
{
	if (!ft_strcmp(av[1], "here_doc"))
		px->here_d = 1;
	else
		px->here_d = 0;
	px->nr_cmds = ac - 3 - px->here_d;
	px->prev_fd = -1;
}
