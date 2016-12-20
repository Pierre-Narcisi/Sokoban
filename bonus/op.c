/*
** op.c for op.c in /home/bilyarus/work/Unix/PSU_2016_my_sokoban/bonus/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Dec 20 14:12:23 2016 John Doe
** Last update Tue Dec 20 14:13:07 2016 John Doe
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char	*my_strcpy(char *src, char *dest)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
