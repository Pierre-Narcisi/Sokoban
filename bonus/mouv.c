/*
** mouv.c for mouv.c in /home/pierre/work/Unix_System/PSU_2016_my_sokoban/
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Wed Dec 14 15:18:28 2016 Pierre Narcisi
** Last update Mon Dec 19 15:41:14 2016 Pierre Narcisi
*/

#include "my.h"

void mouv(char **tab, t_var *p, int index, char **tab2)
{
  int i;
  int pos;

  i = 0;
  pos = my_strlen(tab[i]);
  if (index == KEY_LEFT)
    my_mouv_LEFT(tab, p, tab2);
  if (index == KEY_RIGHT)
    my_mouv_RIGHT(tab, p, tab2);
  if (index == KEY_UP)
    my_mouv_UP(tab, p, tab2);
  if (index == KEY_DOWN)
    my_mouv_DOWN(tab, p, tab2);
  while (tab[i] != NULL)
  {
  mvprintw(LINES / 2 + i, COLS / 2  - (pos / 2), "%s", tab[i]);
  i++;
  }
}

void my_mouv_UP(char **tab, t_var *p, char **tab2)
{
  if (tab[p->y - 1][p->x] != '#')
  {
    if (tab[p->y - 1][p->x] != 'X' ||
    (tab[p->y - 2][p->x] != 'X' && tab[p->y - 2][p->x] != '#'))
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

void my_mouv_DOWN(char **tab, t_var *p, char **tab2)
{
  if (tab[p->y + 1][p->x] != '#')
  {
    if (tab[p->y + 1][p->x] != 'X' ||
    (tab[p->y + 2][p->x] != 'X' && tab[p->y + 2][p->x] != '#'))
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

void my_mouv_RIGHT(char **tab, t_var *p, char **tab2)
{
  if (tab[p->y][p->x + 1] != '#')
  {
    if (tab[p->y][p->x + 1] != 'X' ||
    (tab[p->y][p->x + 2] != 'X' && tab[p->y][p->x + 2] != '#'))
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

void my_mouv_LEFT(char **tab, t_var *p, char **tab2)
{
  if (tab[p->y][p->x - 1] != '#')
  {
    if (tab[p->y][p->x - 1] != 'X' ||
    (tab[p->y][p->x - 2] != 'X' && tab[p->y][p->x - 2] != '#'))
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
