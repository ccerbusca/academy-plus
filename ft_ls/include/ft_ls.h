/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 19:36:11 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/19 16:17:31 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "libft.h"
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/acl.h>

# define FLAGS "lRart"

# define SIXMONTHS ((365 / 2) * 86400)

typedef struct		s_folder
{
	char			*name;
	char			*path;
	struct s_folder	*rec;
	struct stat		*buf;
	struct s_folder	*next;
	int				special;
	int				link;
}					t_folder;

typedef	struct		s_timp
{
	char			*year;
	char			*month;
	char			*day;
	char			*hour;
}					t_timp;

typedef struct		s_ls
{
	int				l;
	int				r_m;
	int				a;
	int				r;
	int				t;
	int				f;
	int				g;
	int				o;
	int				fm;
	int				p;
	int				d;
	int				tm;
	int				am;
	int				argc;
	int				index;
	int				ok;
	int				ff;
	int				dd;
	struct stat		*buf;
	t_folder		*file;
	t_folder		*fd;
	int				max_size;
	int				max_nlink;
	int				max_user;
	int				max_group;
	int				max_minor;
	int				max_major;
	struct passwd	*aux;
	struct group	*aux2;
	int				special;
	char			*str;
	int				hueta;
}					t_ls;

void				create_node(t_folder **fd, char *name);
t_folder			*dir_reading(t_folder *fd);
void				ls_no_attr(t_ls *ls, t_folder *fd);
void				print_error_flag(char c);
t_ls				*check_flags(t_ls *ls, char **argv);
t_ls				*checker(t_ls *ls, char c);
t_ls				*checker_aux(t_ls *ls, char c);
t_ls				*fututi_normineta(t_ls *ls);
void				print_error_folder(char *str);
t_ls				*get_dirs(t_ls *ls, char **argv);
void				gem_to_folder(t_ls *ls, t_folder **fd);
void				put_file_name(t_ls *ls, t_folder *file);
void				ls_r_m(t_ls *ls, t_folder *fd, char *str);
void				afficher(t_ls *ls, t_folder *fd, char *str);
void				aff_name(t_ls *ls, t_folder *fd, int endl);

t_folder			*sorted_merge(t_ls *ls, t_folder *a, t_folder *b);
void				front_back_split(t_folder *source, t_folder **front,
		t_folder **back);
void				merge_sort(t_ls *ls, t_folder **headref);
int					compare_r(t_ls *ls, t_folder *a, t_folder *b);
void				swap_params(char **str1, char **str2);
char				**sort_params(int i, int argc, char **str);
void				ls_check_a(t_ls *ls, t_folder *aux);
void				calc_stdblocks(t_ls *ls, t_folder *fd);
void				ls_l(t_ls *ls, t_folder *fd, int file);
void				fill_the_buf(t_folder **fd);
t_ls				*len_max_size(t_folder *fd, t_ls *ls);
t_ls				*calc_max_check(t_folder *fd, t_ls *ls);
void				put_size(t_folder *fd, t_ls *ls);
void				ls_l_all(t_folder *fd, t_ls *ls);
void				calc_stdblocks(t_ls *ls, t_folder *fd);
void				entry_type_chr(t_folder **fd, t_ls **ls);
void				put_perm(t_folder *fd);
void				put_perm_gr(t_folder *fd);
void				put_perm_oth(t_folder *fd);
void				put_name(t_folder *fd, t_ls *ls);
void				put_xattr(t_folder *fd);
char				*get_hour(char *str);
void				get_time(char *str, t_timp *t, int tm);
int					check_time(time_t sec);
void				put_time(t_folder *fd, int tm);
void				annex_path(t_folder **fd, char *path);
void				put_symlink(t_folder *fd);
void				put_ws(int ws);
int					check_inv_and_a(t_folder *fd, t_ls *ls);
void				gem_to_folder2(t_folder **fd);
char				**sort_params(int i, int argc, char **str);
char				*extract_name(char *path);
int					file_exists(char *file);
void				put_nlink(t_folder *fd, t_ls *ls);
void				put_mm(t_folder *fd, t_ls *ls, int ok);
int					count_files(t_ls *ls, t_folder *fd);

#endif
