#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	out_to_buffer(int *backup_in, int *backup_out)
{
	int	new_pipe[2];

	*backup_in = dup(STDIN_FILENO);
	if (*backup_in == -1)
		return (EXIT_FAILURE);
	*backup_out = dup(STDOUT_FILENO);
	if (*backup_out == -1)
	{
		close(*backup_in);
		return (EXIT_FAILURE);
	}
	if (pipe(new_pipe) == -1)
	{
		close(*backup_in);
		close(*backup_out);
		return (EXIT_FAILURE);
	}
	if (close(STDIN_FILENO) == -1)
	{
		close(new_pipe[0]);
		close(new_pipe[1]);
		close(*backup_in);
		close(*backup_out);
		return (EXIT_FAILURE);
	}
	if (dup2(new_pipe[0], STDIN_FILENO) == -1
		|| close(STDOUT_FILENO) == -1)
	{
		dup2(*backup_in, STDIN_FILENO);
		close(new_pipe[0]);
		close(new_pipe[1]);
		close(*backup_in);
		close(*backup_out);
		return (EXIT_FAILURE);
	}
	if (dup2(new_pipe[1], STDOUT_FILENO) == -1)
	{
		dup2(*backup_in, STDIN_FILENO);
		dup2(*backup_out, STDOUT_FILENO);
		close(new_pipe[0]);
		close(new_pipe[1]);
		close(*backup_in);
		close(*backup_out);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	get_string_from_buffer(int in_size, char in[], int read_fd)
{
	int	count;

	count = read(read_fd, in, in_size);
	in[count] = '\0';
}

void	out_to_std(int backup_out, int read_fd)
{
	close(read_fd);
	dup2(backup_out, STDOUT_FILENO);
}
