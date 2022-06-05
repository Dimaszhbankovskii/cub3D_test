# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_token
{
	char			*str;
	struct s_token	*next;
}				t_token;

typedef struct s_input
{
	t_token	*tokens;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
}				t_input;

t_token	*new_token(char *str);
void	add_token(t_token **file, t_token *new);
