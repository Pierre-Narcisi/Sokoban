/*
** mouv.c for mouv.c in /home/pierre/work/Unix_System/PSU_2016_my_sokoban/
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Wed Dec 14 15:18:28 2016 Pierre Narcisi
** Last update Wed Dec 14 21:30:28 2016 Pierre Narcisi
*/

#include "my.h"

void my_mouv_UP(char **tab, t_var *p)
{
  if (tab[p->y - 1][p->x] != '#')
  {
    if (tab[p->y - 1][p->x] != 'X' || (tab[p->y - 1][p->x] != 'X' && tab[p->y - 2][p->x] != '#'))
    {
      if (tab[p->y - 1][p->x] == 'X')
      {
        tab[p->y - 2][p->x] = 'X';
      }
      tab[p->y - 1][p->x] = 'P';
      tab[p->y][p->x] = ' ';
      p->y = p->y - 1;
    }
  }
}

void my_mouv_DOWN(char **tab, t_var *p)
{
  if (tab[p->y + 1][p->x] != '#')
  {
    if (tab[p->y + 1][p->x] != 'X' && (tab[p->y + 1][p->x] != 'X' || tab[p->y + 2][p->x] != '#'))
      {
        if (tab[p->y + 1][p->x] == 'X')
        {
          tab[p->y + 2][p->x] = 'X';
        }
        tab[p->y + 1][p->x] = 'P';
        tab[p->y][p->x] = ' ';
        p->y = p->y + 1;
      }
  }
}

void my_mouv_RIGHT(char **tab, t_var *p)
{
  if (tab[p->y][p->x + 1] != '#')
  {
    if (tab[p->y][p->x + 1] != 'X' && (tab[p->y][p->x + 2] != 'X' || tab[p->y][p->x + 2] != '#'))
    {
      if (tab[p->y][p->x + 1] == 'X')
      {
        tab[p->y][p->x + 2] = 'X';
      }
      tab[p->y][p->x + 1] = 'P';
      tab[p->y][p->x] = ' ';
      p->x = p->x + 1;
    }
  }
}

void my_mouv_LEFT(char **tab, t_var *p)
{
  if (tab[p->y][p->x - 1] != '#')
  {
    if (tab[p->y][p->x - 1] != 'X' || (tab[p->y][p->x - 2] != 'X' && tab[p->y][p->x - 2] != '#'))
    {
      if (tab[p->y][p->x - 1] == 'X')
      {
        tab[p->y][p->x - 2] = 'X';
      }
      tab[p->y][p->x - 1] = 'P';
      tab[p->y][p->x] = ' ';
      p->x = p->x - 1;
    }
  }
}
