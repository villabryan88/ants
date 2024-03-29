/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:07:39 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/13 17:17:52 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef struct		s_map_nd
{
	void			*key;
	size_t			key_size;
	void			*val;
	struct s_map_nd	*next;
}					t_map_node;
typedef struct		s_map
{
	t_map_node		**map;
	size_t			size;
}					t_map;
typedef struct		s_qnode
{
	void			*content;
	struct s_qnode	*next;
}					t_qnode;
typedef struct		s_queue
{
	struct s_qnode	*first;
	struct s_qnode	*last;
}					t_queue;
typedef struct 		s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	struct s_node	*top;
}					t_stack;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *src, const char *find, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_strnlen(const char *s, size_t maxlen);
int					ft_isspace(int c);
int					ft_wrdcnt(char *s, char c);
void				ft_putnbrendl(int n);
int					ft_iseven(int n);
int					ft_isneg(int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_splitstr(char **src, char **front, int loc);
void				ft_strtoupper(char *s);
char				*ft_strjoin_free(char *s1, char *s2, int f1, int f2);
int					ft_arrlen(void *arr, size_t size);
int					ft_strisnum(char *s);
int					ft_strisint(char *s);
int					ft_elemval(void *arr, size_t size);
t_list				*ft_lstsearch(t_list *list, void *needle, size_t size);
int					ft_printf(char *s, ...);
int					get_next_line(const int fd, char **line);
void				ft_strarrdel(char **str_arr);
void				ft_lstdelnode(void *content, size_t size);
char				**ft_strarrsearch(char **haystack, char *needle);
void				ft_printhex(void *str, size_t n);
t_map				*map_init(size_t size);
void				map_del(t_map *del);
size_t				map_hash(t_map *map, void *key, size_t key_size);
t_map_node			*map_node_new(void *key, size_t key_size, void *val);
char				map_insert(t_map *map, void *key, size_t key_size,
															void *val);
void				**map_find(t_map *map, char *key, size_t key_size);
unsigned int		fnv_hash(unsigned char *buffer, size_t n);
int					q_isempty(struct s_queue *queue);
struct s_queue		*q_init(void);
void				q_push(struct s_queue *queue, void *content);
void				*q_pop(struct s_queue *queue);
void				*q_peek(struct s_queue *queue);
struct s_stack		*stack_init(void);
void				*stack_pop(struct s_stack *stack);
void				stack_push(struct s_stack *stack, void *content);
void				*stack_peek(struct s_stack *stack);
int					stack_isempty(struct s_stack *stack);
#endif
