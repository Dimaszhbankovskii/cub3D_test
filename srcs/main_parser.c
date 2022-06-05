#include "../includes/parser.h"

void	init_input(t_input *input)
{
	input->tokens = NULL;
	input->no_texture = NULL;
	input->so_texture = NULL;
	input->we_texture = NULL;
	input->ea_texture = NULL;
}

void	print_tmp(t_input *input)
{
	t_token	*tmp;

	tmp = input->tokens;
	printf("--------------------------------------------------------------------\n");
	while (tmp)
	{
		printf("-->%s", tmp->str);
		tmp = tmp->next;
	}
	printf("--------------------------------------------------------------------\n");
	printf("NO -->%s\n", input->no_texture);
	printf("SO -->%s\n", input->so_texture);
	printf("WE -->%s\n", input->we_texture);
	printf("EA -->%s\n", input->ea_texture);
}

void	read_file(t_input *input, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error open\n", STDERR_FILENO);
		exit (1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (line)
			add_token(&input->tokens, new_token(line));
	}
	if (line)
		add_token(&input->tokens, new_token(line));
}

void	parsing_tokens(t_input *input)
{
	t_token	*tmp;
	char	**arr;

	tmp = input->tokens;
	while (tmp)
	{
		arr = ft_split(tmp->str, ' ');
		if (!ft_strcmp("NO", arr[0]))
			input->no_texture = ft_strdup(arr[1]);
		else if (!ft_strcmp("SO", arr[0]))
			input->so_texture = ft_strdup(arr[1]);
		else if (!ft_strcmp("WE", arr[0]))
			input->we_texture = ft_strdup(arr[1]);
		else if (!ft_strcmp("EA", arr[0]))
			input->ea_texture = ft_strdup(arr[1]);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_input	input;

	if (argc != 2)
	{
		ft_putstr_fd("Error args\n", STDERR_FILENO);
		exit (1);
	}
	init_input(&input);
	read_file(&input, argv[1]);
	parsing_tokens(&input);
	print_tmp(&input);
	return (0);
}
