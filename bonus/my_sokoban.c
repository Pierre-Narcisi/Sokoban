/*
** my_sokoban.c for my_sokoban.c in /home/pierre/work/Unix_System/PSU_2016_my_
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Tue Dec 13 20:04:17 2016 Pierre Narcisi
** Last update Tue Dec 20 22:00:57 2016 John Doe
*/

#include "my.h"

int my_nb_read(char *str)
{
  FILE *fp;
  char *line;
  size_t len;
  ssize_t read;
  int i;

  i = 0;
  len = 0;
  line = NULL;
  fp = fopen(str, "r");
  while ((read = getline(&line, &len, fp)) != -1)
  {
    i++;
  }
  fclose (fp);
  return (i);
}

char **my_read(char **tab, char *str)
{
  FILE *fp;
  char *line;
  size_t len;
  ssize_t read;
  int i;

  i = 0;
  tab = (char**)malloc ((1 + my_nb_read(str)) * sizeof(char *));
  len = 0;
  line = NULL;
  fp = fopen(str, "r");
  while ((read = getline(&line, &len, fp)) != -1)
  {
    tab[i] = (char*)malloc (sizeof(char) * (my_strlen(line) + 1));
    tab[i] = my_strcpy(line, tab[i]);
    i++;
  }
  tab[i] = NULL;
  fclose (fp);
  return (tab);
}

void boucl(t_var p, char **tab, char **tab2, int a)
{
  t_pos rbp;
  t_var rb;
  t_var incr;
  int index;

  index = 0;
  incr.c = 'r';
  incr.x = 0;
  incr.y = -1;
  while (a != 1)
    {
      refresh();
      rb = lalala(index, tab, p, &incr);
      my_port_pos(rb, &rbp);
      mouv(tab, &p, index, tab2, rbp);
      a = Win(tab, tab2);
      index = getch();
      clear();
      endwin();
    }
}

void game(int ac, char **av)
{
  char **tab;
  t_var p;
  int a;
  char **tab2;

  a = 0;
  tab = my_read(tab, av[1]);
  tab2 = tab_cpy(tab, tab2);
  p = find(tab);
  initscr();
  my_init();
  keypad(stdscr, TRUE);
  boucl(p, tab, tab2, a);
}

int main(int ac, char **av)
{
  game(ac, av);
  return (0);
}
