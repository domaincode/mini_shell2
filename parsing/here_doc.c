#include "parsing.h"

static bool	read_in_stdin(t_data *data, int fd, char *word)
{
	char	*buf;

	while (1)
	{
		buf = NULL;
		buf = readline("> ");
		if (!buf)
		{
			print_error("warning: here-document delimited by end-of-file ");
			print_error("(wanted '");
			print_error(word);
			print_error("')\n");
			break ;
		}
		if (!ft_strncmp(word, buf, INT_MAX))
			break ;
		if (!replace_dollar(&buf, data))
			free_all(data, "malloc error\n", 1);
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
		free(buf);
	}
	free(buf);
	return (true);
}

int	here_doc(t_data *data, char *word)
{
	int	fd;

	fd = open("/tmp/.heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);
	if (!read_in_stdin(data, fd, word))
	{
		unlink("/tmp/.heredoc.tmp");
		return (-1);
	}
	close(fd);
	fd = open("/tmp/.heredoc.tmp", O_RDONLY, 0644);
	return (fd);
}
