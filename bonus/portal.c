/*
** portal.c for portal.c in /home/pierre/work/Unix_System/PSU_2016_my_sokoban/bonus/
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Mon Dec 19 14:15:55 2016 Pierre Narcisi
** Last update Mon Dec 19 16:12:19 2016 Pierre Narcisi
*/

#include "my.h"

void del_port(t_var *incr, char **tab)
{
  int i;
  int j;

  j = 0;
  while (tab[j] != NULL)
  {
    i = 0;

    while (tab[j][i + 1] != '\0')
    {
      if (tab[j][i] == 'r')
      {
        tab[j][i] = '#';
      }
      i++;
    }
    j++;
  }
}

void portal(t_var *incr, char **tab, t_var p)
{
  while (tab[p.y][p.x] != '#')
  {
    p.y += -1;
    p.x += 0;
  }
  tab[p.y][p.x] = 'r';
}

void lalala(int index, char **tab, t_var p)
{
  t_var *incr;

  incr = (t_var*)malloc(sizeof(t_var));
  if (index == 'r')
    incr->c = 'r';
  else if (index == 'b')
    incr->c = 'b';
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
  else if (index == 'z')
  {
    incr->y = 0;
    incr->x = -1;
  }
  if (index == 'p')
  {
    del_port(incr, tab);
    portal(incr, tab, p);
  }
}
