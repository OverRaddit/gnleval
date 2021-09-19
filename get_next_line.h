#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define SUCCESS 1
# define END 0
# define ERROR -1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

char	*get_next_line(int fd);
int		ft_strlcpy(char *dest, const char *src, size_t d_size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
int		ft_strchr(const char *str, int c);
#endif
