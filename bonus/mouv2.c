/*
** mouv2.c for mouv2.c in /home/bilyarus/work/Unix/PSU_2016_my_sokoban/bonus/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Dec 20 14:42:31 2016 John Doe
** Last update Tue Dec 20 16:32:11 2016 John Doe
*/

#include "my.h"

void my_port_pos(t_var rb, t_pos *rbp)
{
  if (rb.c == 'r')
  {
    rbp->rx = rb.x;
    rbp->ry = rb.y;
  }
  else if (rb.c == 'b')
  {
    rbp->bx = rb.x;
    rbp->by = rb.y;
  }
}

void my_tel(t_var *p, char **tab, t_pos rbp)
{
  if (tab[rbp.by][rbp.bx] != 'X' && tab[rbp.ry][rbp.rx] != 'X')
  {
    if (tab[p->y + 1][p->x] == 'r' || tab[p->y - 1][p->x] == 'r' ||
    tab[p->y][p->x + 1] == 'r' || tab[p->y][p->x - 1] == 'r')
    {
      tab[p->y][p->x] = ' ';
      tab[rbp.by][rbp.bx] = 'P';
      p->y = rbp.by;
      p->x = rbp.bx;
    }
    else if (tab[p->y + 1][p->x] == 'b' || tab[p->y - 1][p->x] == 'b' ||
    tab[p->y][p->x + 1] == 'b' || tab[p->y][p->x - 1] == 'b')
    {
      tab[p->y][p->x] = ' ';
      tab[rbp.ry][rbp.rx] = 'P';
      p->y = rbp.ry;
      p->x = rbp.rx;
    }
  }
}
