/*
** print_map.c for print_map.c in /home/bilyarus/work/Unix/PSU_2016_my_sokoban/bonus/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Dec 20 14:07:01 2016 John Doe
** Last update Tue Dec 20 22:01:16 2016 John Doe
*/

#include "my.h"

void	my_init()
{
  curs_set(0);
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  init_pair(2, COLOR_WHITE, COLOR_RED);
  init_pair(3, COLOR_WHITE, COLOR_YELLOW);
  init_pair(4, COLOR_WHITE, COLOR_GREEN);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);
  init_pair(6, COLOR_WHITE, COLOR_CYAN);
  init_pair(7, COLOR_WHITE, COLOR_MAGENTA);
}

int	wich(char **tab, int i, int j)
{
  int	p;

  p = 0;
  if (tab[i][j] == '#')
    p = 5;
  else if (tab[i][j] == ' ')
    p = 1;
  else if (tab[i][j] == 'P')
    p = 7;
  else if (tab[i][j] == 'r')
    p = 2;
  else if (tab[i][j] == 'b')
    p = 6;
  else if (tab[i][j] == 'X')
    p = 4;
  else if (tab[i][j] == 'O')
    p = 3;
  return (p);
}

void    print_map(char **tab, char **tab2)
{
  t_pos pos;
  int	p;

  pos.bx = 0;
  pos.rx = my_nb_line(tab);
  pos.ry = my_strlen(tab[pos.bx]);
  while (tab[pos.bx] != NULL)
    {
      pos.by = 0;
      while (tab[pos.bx][pos.by] != '\0')
	{
	  p = wich(tab, pos.bx, pos.by);
          if (tab[pos.bx][pos.by] == '\n')
            printw("%c", '\n');
          else
	    {
	      attron(COLOR_PAIR(p));
	      mvprintw(LINES / 2 + pos.bx - pos.rx / 2 ,
		       COLS / 2 + pos.by - pos.ry / 2, "%c", 'x');
	      attroff(COLOR_PAIR(p));
	    }
	  pos.by++;
	}
      pos.bx++;
    }
}
