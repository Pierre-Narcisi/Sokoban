/*
** portal.c for portal.c in /home/pierre/work/Unix_System/PSU_2016_my_sokoban
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Mon Dec 19 14:15:55 2016 Pierre Narcisi
** Last update Tue Dec 20 21:45:08 2016 John Doe
*/

#include "my.h"

void	del_port(t_var *incr, char **tab)
{
  int	i;
  int	j;

  j = 0;
  while (tab[j] != NULL)
    {
      i = 0;
      
      while (tab[j][i + 1] != '\0')
	{
	  if (tab[j][i] == incr->c)
	    {
	      tab[j][i] = '#';
	    }
	  i++;
	}
      j++;
    }
}

t_var	portal(t_var *incr, char **tab, t_var p)
{
  while (tab[p.y][p.x] != '#' && tab[p.y][p.x] != 'b' && tab[p.y][p.x] != 'r')
    {
      p.y += incr->y;
      p.x += incr->x;
    }
  if (tab[p.y][p.x] == '#')
    {
      tab[p.y][p.x] = incr->c;
      p.y -= incr->y;
      p.x -= incr->x;
      p.c = incr->c;
    }
  return (p);
}

void	dir(int index, t_var *incr)
{
  if (index == 'z')
    {
      incr->y = -1;
      incr->x = 0;
    }
  else if (index == 's')
    {
      incr->y = 1;
      incr->x = 0;
    }
  else if (index == 'q')
    {
      incr->y = 0;
      incr->x = -1;
    }
  else if (index == 'd')
    {
      incr->y = 0;
      incr->x = 1;
    }
}

t_var	lalala(int index, char **tab, t_var p, t_var *incr)
{
  t_var rb;
  
  rb.x = 0;
  rb.y = 0;
  rb.c = 0;
  dir (index, incr);
  if (index == 'r')
    incr->c = 'r';
  else if (index == 'b')
    incr->c = 'b';
  if (index == 'p')
    {
      del_port(incr, tab);
      rb = portal(incr, tab, p);
    }
  return (rb);
}
