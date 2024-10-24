#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "libs/ft_printf/ft_printf.h"
#include "libs/ft_printf/libft/libft.h"

// Arguments: file1 cmd1 cmd2 file2

typedef struct	cmd
{
	char		**argv;			//	Arguments for command
	char const	*pathname;		//	Path to executable
	char		**envp;			//	Environment variables
	int			infile_fd;		//	File descriptor for input redir or pipe read
	int			outfile_fd;		//	File descriptor for output redir or pipe write
	struct cmd	*next;			//	Pointer to the next command
}				t_cmd;

//		TEST FUNCTIONS
void	err(char *str);
void	status(char *str);
void	execute_pipeline(t_cmd *cmd, int num_cmd);

//		ARG FUNCTIONS
int			ft_wordcount(const char *str, char c);
int			array_size(char **array);
char		**str_to_array(char *str);
char		*get_path (t_cmd *cmd, size_t argv_i);

//		LST FUNCTIONS

int				lst_size(t_cmd *lst);
void			append_node(t_cmd **head, char *arg);
t_cmd			*create_cmd_node(char *arg);
void			print_list(t_cmd *lst);
void			free_lst(t_cmd *lst);


//		STRUCT FUNCTIONS
int				_init_io_fd(t_cmd *cmd, char *infile, char *outfile);
t_cmd			*_init_default_cmd();
t_cmd			*_init_cmd(const char *path, char **args, char **env);
t_cmd			*_init_argv(const char *path, char **args);
t_cmd			*args_to_cmd(char **args, int size);
//void		append_node(t_cmd **head, char *arg, int infile, int outfile);
void		exec_pipe(t_cmd *head, int infile_fd, int outfile_fd);
void		exec_child(t_cmd *current, int infile_fd, int outfile_fd, int *pipefd);


#endif
