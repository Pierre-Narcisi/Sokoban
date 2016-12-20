/*
** mouv.c for mouv.c in /home/pierre/work/Unix_System/PSU_2016_my_sokoban/
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Wed Dec 14 15:18:28 2016 Pierre Narcisi
** Last update Tue Dec 20 21:15:15 2016 John Doe
*/

#include "my.h"

void	mouv(char **tab, t_var *p, int index, char **tab2,
   t_pos rbp)
{
  int	i;

  i = 0;
  if (index == KEY_LEFT)
    my_mouv_LEFT(tab, p, tab2, rbp);
  if (index == KEY_RIGHT)
    my_mouv_RIGHT(tab, p, tab2, rbp);
  if (index == KEY_UP)
    my_mouv_UP(tab, p, tab2, rbp);
  if (index == KEY_DOWN)
    my_mouv_DOWN(tab, p, tab2, rbp);
  print_map(tab, tab2);
}

void	my_mouv_UP(char **tab, t_var *p, char **tab2, t_pos rbp)
{
  if (tab[p->y - 1][p->x] == 'r' || tab[p->y - 1][p->x] == 'b')
    my_tel(p, tab, rbp);
  else if (tab[p->y - 1][p->x] != '#')
    {
      if (tab[p->y - 1][p->x] != 'X' ||
	  (tab[p->y - 2][p->x] != 'X' && tab[p->y - 2][p->x] != '#' &&
	   tab[p->y - 2][p->x] != 'b' && tab[p->y - 2][p->x] != 'r'))
	{
	  if (tab[p->y - 1][p->x] == 'X')
	    tab[p->y - 2][p->x] = 'X';
	  tab[p->y - 1][p->x] = 'P';
	  if (tab2[p->y][p->x] == 'O')
	    tab[p->y][p->x] = 'O';
	  else
	    tab[p->y][p->x] = ' ';
	  p->y = p->y - 1;
	}
    }
}

void	my_mouv_DOWN(char **tab, t_var *p, char **tab2, t_pos rbp)
{
  if (tab[p->y + 1][p->x] == 'r' || tab[p->y + 1][p->x] == 'b')
    my_tel(p, tab, rbp);
  else if (tab[p->y + 1][p->x] != '#')
    {
      if (tab[p->y + 1][p->x] != 'X' ||
	  (tab[p->y + 2][p->x] != 'X' && tab[p->y + 2][p->x] != '#' &&
	   tab[p->y + 2][p->x] != 'b' && tab[p->y + 2][p->x] != 'r'))
	{
	  if (tab[p->y + 1][p->x] == 'X')
	    {
	      tab[p->y + 2][p->x] = 'X';
	    }
	  tab[p->y + 1][p->x] = 'P';
	  if (tab2[p->y][p->x] == 'O')
	    tab[p->y][p->x] = 'O';
	  else
	    tab[p->y][p->x] = ' ';
	  p->y = p->y + 1;
	}
    }
}

void	my_mouv_RIGHT(char **tab, t_var *p, char **tab2, t_pos rbp)
{
  if (tab[p->y][p->x + 1] == 'r' || tab[p->y][p->x + 1] == 'b')
    my_tel(p, tab, rbp);
  else if (tab[p->y][p->x + 1] != '#')
    {
      if (tab[p->y][p->x + 1] != 'X' ||
	  (tab[p->y][p->x + 2] != 'X' && tab[p->y][p->x + 2] != '#' &&
	   tab[p->y][p->x + 2] != 'b' && tab[p->y][p->x + 2] != 'r'))
	{
	  if (tab[p->y][p->x + 1] == 'X')
	    {
	      tab[p->y][p->x + 2] = 'X';
	    }
	  tab[p->y][p->x + 1] = 'P';
	  if (tab2[p->y][p->x] == 'O')
	    tab[p->y][p->x] = 'O';
	  else
	    tab[p->y][p->x] = ' ';
	  p->x = p->x + 1;
	}
    }
}

void	my_mouv_LEFT(char **tab, t_var *p, char **tab2, t_pos rbp)
{
  if (tab[p->y][p->x - 1] == 'r' || tab[p->y][p->x - 1] == 'b')
    my_tel(p, tab, rbp);
  else if (tab[p->y][p->x - 1] != '#')
    {
      if (tab[p->y][p->x - 1] != 'X' ||
	  (tab[p->y][p->x - 2] != 'X' && tab[p->y][p->x - 2] != '#' &&
	   tab[p->y][p->x - 2] != 'b' && tab[p->y][p->x - 2] != 'r'))
	{
	  if (tab[p->y][p->x - 1] == 'X')
	    tab[p->y][p->x - 2] = 'X';
	  tab[p->y][p->x - 1] = 'P';
	  if (tab2[p->y][p->x] == 'O')
	    tab[p->y][p->x] = 'O';
	  else
	    tab[p->y][p->x] = ' ';
	  p->x = p->x - 1;
	}
    }
}
