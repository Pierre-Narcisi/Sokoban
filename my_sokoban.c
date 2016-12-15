/*
** my_sokoban.c for my_sokoban.c in /home/pierre/work/Unix_System/PSU_2016_my_
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Tue Dec 13 20:04:17 2016 Pierre Narcisi
** Last update Wed Dec 14 21:47:09 2016 Pierre Narcisi
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
  return (dest);
}

int my_nb_read()
{
  FILE *fp;
  char *line;
  size_t len;
  ssize_t read;
  int i;

  i = 0;
  len = 0;
  line = NULL;
  fp = fopen("tesy", "r");
  while ((read = getline(&line, &len, fp)) != -1)
  {
    i++;
  }
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
  tab = malloc ((1 + my_nb_read()) * sizeof(char *));
  len = 0;
  line = NULL;
  fp = fopen(str, "r");
  while ((read = getline(&line, &len, fp)) != -1)
  {
    tab[i] = malloc (sizeof(char) * my_strlen(line));
    tab[i] = my_strcpy(line, tab[i]);
    i++;
  }
  return (tab);
}

void aff(char **tab)
{
  int i;

  i = 0;
  while (tab[i] != NULL)
  {
    printf("%s", tab[i]);
    i++;
  }
}

t_var find(char **tab)
{
  int i;
  int j;
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

void mouv(char **tab, t_var *p, int index)
{
  int i;

  i = 0;
  if (index == KEY_LEFT)
    my_mouv_LEFT(tab, p);
  if (index == KEY_RIGHT)
    my_mouv_RIGHT(tab, p);
  if (index == KEY_UP)
    my_mouv_UP(tab, p);
  if (index == KEY_DOWN)
    my_mouv_DOWN(tab, p);
  while (tab[i] != NULL)
  {
    mvprintw(LINES / 2 + i, COLS / 2  - (my_strlen(tab[i]) / 2), "%s", tab[i]);
    i++;
  }
}

int main(int ac, char **av)
{
  char **tab;
  WINDOW *win;
  int index;
  t_var p;
  int i;

  i = 0;
  tab = my_read(tab, av[1]);
  while (tab[i] != '\0')
  {
  printf("%s", tab[i]);
  i++;
  }
  p = find(tab);
  index = 0;
  win = initscr();
  keypad(stdscr, TRUE);
  while (index != 32)
  {
    refresh();
    mouv(tab, &p, index);
    index = getch();
    clear();
  }
  endwin();
  return (0);
}
