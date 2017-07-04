/*
** 101pong.c for  in /home/da-pur_c/delivery/Maths/101pong
** 
** Made by Clem Da
** Login   <da-pur_c@epitech.net>
** 
** Started on  Mon Nov  7 09:35:36 2016 Clem Da
** Last update Tue Nov 15 15:06:39 2016 Hugo WALTER
*/

#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int     my_str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= '9' && str[i] >= '0' || str[i] == '-' || str[i] == '.')
	{
	  i = i + 1;
	}
      else
	return (0);
    }
  if (str[i] == '\0')
    return (1);
}

int     my_str_isnum2(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= '9' && str[i] >= '0' || str[i] == '-')
	{
	  i = i + 1;
	}
      else
	return (0);
    }
  if (str[i] == '\0')
    return (1);
}

int	main(int ac, char **av)
{
  if (ac != 8)
    {
      write(2, "USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n", strlen("USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n"));
      exit(84);
    }
  else
    {
      if (atoi(av[7]) <= 0)
	{
	  write(2, "n time shift (greater than or equal to zero, integer)\n", strlen("n time shift (greater than or equal to zero, integer)\n"));
	  exit (84);
	}
      if (my_str_isnum(av[1]) == 0)
	{
	  write(2, "USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n", strlen("USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n"));
	  exit (84);
	}
      if (my_str_isnum(av[2]) == 0)
	{
	  write(2, "USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n", strlen("USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n"));
	  exit (84);
	}
      if (my_str_isnum(av[3]) == 0)
	{
	  write(2, "USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n", strlen("USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n"));
	  exit (84);
	}
      if (my_str_isnum(av[4]) == 0)
	{
	  write(2, "USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n", strlen("USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n"));
	  exit (84);
	}
      if (my_str_isnum(av[5]) == 0)
	{
	  write(2, "USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n", strlen("USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n"));
	  exit (84);
	}
      if (my_str_isnum(av[6]) == 0)
	{
	  write(2, "USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n", strlen("USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n"));
	  exit (84);
	}
      if (my_str_isnum2(av[7]) == 0)
	{
	  write(2, "USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n", strlen("USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\nDESCRIPTION\n\tx0 ball abscissa at time t−1\n\ty0 ball ordinate at time t−1\n\tz0 ball altitude at time t−1\n\tx1 ball abscissa at time t\n\ty1 ball ordinate at time t\n\tz1 ball altitude at time t\n\tn time shift (greater than or equal to zero, integer)\n"));
	  exit (84);
	}
      float	x0 = atof(av[1]);
      float	y0 = atof(av[2]);
      float	z0 = atof(av[3]);
      float	x1 = atof(av[4]);
      float	y1 = atof(av[5]);
      float	z1 = atof(av[6]);
      int	n = atof(av[7]);
      float	speedx;
      float	speedy;
      float	speedz;
      float	nspeedx;
      float	nspeedy;
      float	nspeedz;
      float	timenx;
      float	timeny;
      float	timenz;
      float	normen;
      float	normev;
      float	cosbeta;
      float	angle;
      
      speedx = x1 - x0;
      speedy = y1 - y0;
      speedz = z1 - z0;
      printf("The speed vector coordinates are :\n");
      printf("(%.2f;%.2f;%.2f)\n", speedx, speedy, speedz);
      printf("At time t+%d, ball coordinates will be :\n", n);
      nspeedx = n * speedx;
      nspeedy = n * speedy;
      nspeedz = n * speedz;
      timenx = (x1) + (nspeedx);
      timeny = (y1) + (nspeedy);
      timenz = (z1) + (nspeedz);
      printf("(%.2f;%.2f;%.2f)\n", timenx, timeny, timenz);
      normen = sqrt(pow(speedx, 2) + pow(speedy, 2) + pow(speedz, 2));
      normev = sqrt(pow(speedx, 2) + pow(speedy, 2));
      cosbeta = normev / normen;
      angle = acos(cosbeta) * (180 / M_PI);
      if ((z1 - z0) == 0 && (z1 != 0))
	{
	  printf("The ball won't reach the bat.\n");
	  return (0);
	}
      if (-z1/(z1 - z0) < 0)
	{
	  printf("The ball won't reach the bat.\n");
	  return (0);
	}
      if (angle < 0 || angle > 90)
	{
	  printf("The ball won't reach the bat.\n");
	  return (0);
	}
      else
	{
	  printf("The incidence angle is :\n");
	  printf("%.2f degrees\n", angle);
	  return (0);
	}
    }
  return (0);
}
