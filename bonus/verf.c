/*
** verf.c for verif.c in /home/pierre/work/Unix_System/PSU_2016_my_sokoban/
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Thu Dec 15 11:05:56 2016 Pierre Narcisi
** Last update Fri Dec 16 16:25:40 2016 Pierre Narcisi
*/

#include "my.h"

int	Win(char **tab, char **tab2)
{
  int	i;
  int	j;
  int	n;

  n = 1;
  j = 0;
  while (tab[j] != NULL)
    {
      i = 0;
      while (tab[j][i] != '\0')
	{
	  if (tab2[j][i] == 'O')
	    {
	      if (tab[j][i] != 'X')
		n = 0;
	    }
	  i++;
	}
      j++;
    }
  return (n);
}

int	my_nb_line(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

char	**tab_cpy(char **tab, char **tab2)
{
  int	i;

  i = 0;
  tab2 = (char **)malloc (sizeof(char *) * (my_nb_line(tab) + 1));
  while (tab[i] != NULL)
    {
      tab2[i] = (char *)malloc (sizeof(char) * (my_strlen(tab[i]) + 1));
      my_strcpy(tab[i], tab2[i]);
      i++;
    }
  return (tab2);
}

t_var	find(char **tab)
{
  int	i;
  int	j;
  t_var p;

  j = 0;
  while (tab[j] != NULL)
    {
      i = 0;
      while (tab[j][i] != '\0')
	{
	  if (tab[j][i] == 'P')
	    {
	      p.x = i;
	      p.y = j;
	    }
	  i++;
	}
      j++;
    }
  return (p);
}
