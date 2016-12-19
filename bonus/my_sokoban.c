/*
** my_sokoban.c for my_sokoban.c in /home/pierre/work/Unix_System/PSU_2016_my_
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Tue Dec 13 20:04:17 2016 Pierre Narcisi
** Last update Mon Dec 19 15:41:04 2016 Pierre Narcisi
*/

#include "my.h"

int my_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char *my_strcpy(char *src, char *dest)
{
  int i;

  i = 0;
  while (src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return (dest);
}

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

int main(int ac, char **av)
{
  char **tab;
  int index;
  t_var p;
  int a;
  char **tab2;

  if (ac > 1)
  {
    a = 0;
    tab = my_read(tab, av[1]);
    tab2 = tab_cpy(tab, tab2);
    p = find(tab);
    index = 0;
    initscr();
    keypad(stdscr, TRUE);
    while (a != 1)
    {
      refresh();
      lalala(index, tab, p);
      mouv(tab, &p, index, tab2);
      a = Win(tab, tab2);
      index = getch();
      clear();
    }
    endwin();
  }
  return (0);
}
