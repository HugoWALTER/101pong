/*
** pong.c for  in /home/da-pur_c/delivery/Maths/101pong/bonus
** 
** Made by Clem Da
** Login   <da-pur_c@epitech.net>
** 
** Started on  Mon Nov 14 13:04:13 2016 Clem Da
** Last update Fri Nov 18 17:45:32 2016 Hugo WALTER
*/

#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/System/Vector2.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define BIT 5

sfRenderWindow* create_window(char* name, int width, int height)
{
  sfRenderWindow* window;
  sfVideoMode mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    exit(EXIT_FAILURE);
  return window;
}

void	draw_pixel(sfUint8* pixels, int x, int y, sfColor *color)
{
  pixels[(SCREEN_WIDTH * y + x) * 4] = sfBlue.r;
  pixels[(SCREEN_WIDTH * y + x) * 4 + 1] = sfBlue.g;
  pixels[(SCREEN_WIDTH * y + x) * 4 + 2] = sfBlue.b;
  pixels[(SCREEN_WIDTH * y + x) * 4 + 3] = sfBlue.a;
}

void	draw_line(sfUint8* pixels)
{
  int	y;

  y = 0;
  while (y != SCREEN_HEIGHT * 2)
    {
      if (y > 20 && y < 40 || y > 60 && y < 80 || y > 270 && y < 290 || y > 100 && y < 250 || y > 310 && y < 330 || y > 350 && y < 370 || y > 390 && y < 410 || y > 430 && y < 450 || y > 470 && y < 490 || y > 510 && y < 530 || y > 550 && y < 570 || y > 590 && y < 610 || y > 630 && y < 650 || y > 670 && y < 690 || y > 710 && y < 730 || y > 750 && y <= 790 || y > 720 && y < 810 || y > 830 && y < 850 || y > 870 && y < 890 || y > 910 && y < 930 || y > 950 && y < 970 || y > 990 && y < 1010 || y > 1030 && y < 1050 || y > 1070 && y < 1090 || y > 1110 && y < 1130 || y > 1150 && y < 1170 || y > 1190 && y < 1210 || y > 1230 && y < 1250 || y > 1270 && y < 1290 || y > 1310 && y < 1320 || y > 1340 && y < 1360 || y > 1380 && y < 1400 || y > 1420 && y < 1440 || y > 1460 && y < 1480 || y > 1500)
	y++;
      else
	{
	  pixels[((SCREEN_WIDTH / 2) * y ) * 4 + 2] = sfWhite.b;
	  pixels[((SCREEN_WIDTH / 2) * y ) * 4 + 3] = sfWhite.a;
	  y++;
	}
    }
}

void    draw_circle(sfUint8* pixels, float x_dep, float y_dep, sfColor *color)
{
  float		x;
  float		y;

  y = -BIT;
  while (y < BIT)
    {
      x = -BIT;
      while (x < BIT)
	{
	  if (sqrt(pow(x, 2) + pow(y, 2)) < BIT && x + x_dep >= 0 && x + x_dep < SCREEN_WIDTH && y + y_dep >= 0 && y + y_dep < SCREEN_HEIGHT)
	    draw_pixel(pixels, x + x_dep, y + y_dep, color);
	  x++;
	}
      y++;
    }
}

void    draw_pixelfin(sfUint8* pixels, int x, int y, sfColor *color)
{
  pixels[(SCREEN_WIDTH * y + x) * 4] = sfBlack.r;
  pixels[(SCREEN_WIDTH * y + x) * 4 + 1] = sfBlack.g;
  pixels[(SCREEN_WIDTH * y + x) * 4 + 2] = sfBlack.b;
  pixels[(SCREEN_WIDTH * y + x) * 4 + 3] = sfBlack.a;
}

void    draw_circlefin(sfUint8* pixels, float x_dep, float y_dep, sfColor *color)
{
  float         x;
  float         y;

  y = -BIT;
  while (y < BIT)
    {
      x = -BIT;
      while (x < BIT)
	{
	  if (sqrt(pow(x, 2) + pow(y, 2)) < BIT && x + x_dep >= 0 && x + x_dep < SCREEN_WIDTH\
	      && y + y_dep >= 0 && y + y_dep < SCREEN_HEIGHT)
	    draw_pixelfin(pixels, x + x_dep, y + y_dep, color);
	  x++;
	}
      y++;
    }
}

void	draw_stickleft(sfUint8* pixels, int y)
{
  int		x;
  int		y2;

  y2 = y;
  x = 10;
  while (x < 30)
    {
      y = y2;
      pixels[(SCREEN_WIDTH * (y - 1) + x) * 4] = 0;
      pixels[(SCREEN_WIDTH * (y - 1) + x) * 4 + 1] = 0;
      pixels[(SCREEN_WIDTH * (y - 1) + x) * 4 + 2] = 0;
      pixels[(SCREEN_WIDTH * (y - 1) + x) * 4 + 3] = 0;
      while (y < y2 + 140)
	{
	  pixels[(SCREEN_WIDTH * y + x) * 4] = sfRed.r;
	  pixels[(SCREEN_WIDTH * y + x) * 4 + 1] = sfRed.g;
	  pixels[(SCREEN_WIDTH * y + x) * 4 + 2] = sfRed.b;
	  pixels[(SCREEN_WIDTH * y + x) * 4 + 3] = sfRed.a;
	  y++;
	}
      pixels[(SCREEN_WIDTH * y + x) * 4] = 0;
      pixels[(SCREEN_WIDTH * y + x) * 4 + 1] = 0;
      pixels[(SCREEN_WIDTH * y + x) * 4 + 2] = 0;
      pixels[(SCREEN_WIDTH * y + x) * 4 + 3] = 0;
      x++;
    }
}

void    draw_stickright(sfUint8* pixels, int z)
{
  int           x;
  int           z2;

  z2 = z;
  x = 994;
  while (x < 1014)
    {
      z = z2;
      pixels[(SCREEN_WIDTH * (z - 1) + x) * 4] = 0;
      pixels[(SCREEN_WIDTH * (z - 1) + x) * 4 + 1] = 0;
      pixels[(SCREEN_WIDTH * (z - 1) + x) * 4 + 2] = 0;
      pixels[(SCREEN_WIDTH * (z - 1) + x) * 4 + 3] = 0;
      while (z < z2 + 140)
	{
	  pixels[(SCREEN_WIDTH * z + x) * 4] = sfRed.r;
	  pixels[(SCREEN_WIDTH * z + x) * 4 + 1] = sfRed.g;
	  pixels[(SCREEN_WIDTH * z + x) * 4 + 2] = sfRed.b;
	  pixels[(SCREEN_WIDTH * z + x) * 4 + 3] = sfRed.a;
	  z++;
	}
      pixels[(SCREEN_WIDTH * z + x) * 4] = 0;
      pixels[(SCREEN_WIDTH * z + x) * 4 + 1] = 0;
      pixels[(SCREEN_WIDTH * z + x) * 4 + 2] = 0;
      pixels[(SCREEN_WIDTH * z + x) * 4 + 3] = 0;
      x++;
    }
}

sfUint8* create_pixel_buffer(int width, int height)
{
  int i;
  sfUint8* pixels;

  pixels = malloc(width * height * 4 * sizeof(*pixels));
  if (pixels == NULL)
    exit(EXIT_FAILURE);
  i = 0;
  while (i < width * height * 4)
    {
      pixels[i] = 0;
      i++;
    }
  return pixels;
}

int	scoregauche0(int nbgauche,sfRenderWindow *window, sfFont *font)
{
  sfText		*score0g;
  sfText		*score1g;
  sfText		*score2g;
  sfText		*score3g;
  sfText		*score4g;
  sfText		*score5g;
  sfText		*score6g;
  sfText		*score7g;
  sfText		*score8g;
  sfText		*score9g;
  sfText		*score10g;
  sfVector2f		s0g;

  score0g = sfText_create();
  score1g = sfText_create();
  score2g = sfText_create();
  score3g = sfText_create();
  score4g = sfText_create();
  score5g = sfText_create();
  score6g = sfText_create();
  score7g = sfText_create();
  score8g = sfText_create();
  score9g = sfText_create();
  score10g = sfText_create();
  s0g.x = 200;
  s0g.y = 15;
  if (nbgauche == 0)
    {
      sfText_setString(score0g, "0");
      sfText_setFont(score0g, font);
      sfText_setCharacterSize(score0g, 60);
      sfText_setPosition(score0g, s0g);
      sfRenderWindow_drawText(window, score0g, NULL);
    }
  if (nbgauche == 1)
    {
      sfText_destroy(score0g);
      sfText_setString(score1g, "1");
      sfText_setFont(score1g, font);
      sfText_setCharacterSize(score1g, 60);
      sfText_setPosition(score1g, s0g);
      sfRenderWindow_drawText(window, score1g, NULL);
    }
  if (nbgauche == 2)
    {
      sfText_destroy(score1g);
      sfText_setString(score2g, "2");
      sfText_setFont(score2g, font);
      sfText_setCharacterSize(score2g, 60);
      sfText_setPosition(score2g, s0g);
      sfRenderWindow_drawText(window, score2g, NULL);
    }
  if (nbgauche == 3)
    {
      sfText_destroy(score2g);
      sfText_setString(score3g, "3");
      sfText_setFont(score3g, font);
      sfText_setCharacterSize(score3g, 60);
      sfText_setPosition(score3g, s0g);
      sfRenderWindow_drawText(window, score3g, NULL);
    }
  if (nbgauche == 4)
    {
      sfText_destroy(score3g);
      sfText_setString(score4g, "4");
      sfText_setFont(score4g, font);
      sfText_setCharacterSize(score4g, 60);
      sfText_setPosition(score4g, s0g);
      sfRenderWindow_drawText(window, score4g, NULL);
    }
 if (nbgauche == 5)
    {
      sfText_destroy(score4g);
      sfText_setString(score5g, "5");
      sfText_setFont(score5g, font);
      sfText_setCharacterSize(score5g, 60);
      sfText_setPosition(score5g, s0g);
      sfRenderWindow_drawText(window, score5g, NULL);
    }
  if (nbgauche == 6)
    {
      sfText_destroy(score5g);
      sfText_setString(score6g, "6");
      sfText_setFont(score6g, font);
      sfText_setCharacterSize(score6g, 60);
      sfText_setPosition(score6g, s0g);
      sfRenderWindow_drawText(window, score6g, NULL);
    }
  if (nbgauche == 7)
    {
      sfText_destroy(score6g);
      sfText_setString(score7g, "7");
      sfText_setFont(score7g, font);
      sfText_setCharacterSize(score7g, 60);
      sfText_setPosition(score7g, s0g);
      sfRenderWindow_drawText(window, score7g, NULL);
    }
  if (nbgauche == 8)
    {
      sfText_destroy(score7g);
      sfText_setString(score8g, "8");
      sfText_setFont(score8g, font);
      sfText_setCharacterSize(score8g, 60);
      sfText_setPosition(score8g, s0g);
      sfRenderWindow_drawText(window, score8g, NULL);
    }
  if (nbgauche == 9)
    {
      sfText_destroy(score8g);
      sfText_setString(score9g, "9");
      sfText_setFont(score9g, font);
      sfText_setCharacterSize(score9g, 60);
      sfText_setPosition(score9g, s0g);
      sfRenderWindow_drawText(window, score9g, NULL);
    }
  if (nbgauche == 10)
    {
      sfText_destroy(score9g);
      sfText_setString(score10g, "10");
      sfText_setFont(score10g, font);
      sfText_setCharacterSize(score10g, 60);
      sfText_setPosition(score10g, s0g);
      sfRenderWindow_drawText(window, score10g, NULL);
    }
   return (0);
}

int	scoredroite0(int nbdroite, sfRenderWindow *window, sfFont *font)
{
  sfText	*score0d;
  sfText	*score1d;
  sfText	*score2d;
  sfText	*score3d;
  sfText	*score4d;
  sfText	*score5d;
  sfText	*score6d;
  sfText	*score7d;
  sfText	*score8d;
  sfText	*score9d;
  sfText	*score10d;
  sfVector2f	s0;

  score0d = sfText_create();
  score1d = sfText_create();
  score2d = sfText_create();
  score3d = sfText_create();
  score4d = sfText_create();
  score5d = sfText_create();
  score6d = sfText_create();
  score7d = sfText_create();
  score8d = sfText_create();
  score9d = sfText_create();
  score10d = sfText_create();
  s0.x = 800;
  s0.y = 15;
  if (nbdroite == 0)
    {
      sfText_setString(score0d, "0");
      sfText_setFont(score0d, font);
      sfText_setCharacterSize(score0d, 60);
      sfText_setPosition(score0d, s0);
      sfRenderWindow_drawText(window, score0d, NULL);
    }
  if (nbdroite == 1)
    {
      sfText_destroy(score0d);
      sfText_setString(score1d, "1");
      sfText_setFont(score1d, font);
      sfText_setCharacterSize(score1d, 60);
      sfText_setPosition(score1d, s0);
      sfRenderWindow_drawText(window, score1d, NULL);
    }
  if (nbdroite == 2)
    {
      sfText_destroy(score1d);
      sfText_setString(score2d, "2");
      sfText_setFont(score2d, font);
      sfText_setCharacterSize(score2d, 60);
      sfText_setPosition(score2d, s0);
      sfRenderWindow_drawText(window, score2d, NULL);
    }
  if (nbdroite == 3)
    {
      sfText_destroy(score2d);
      sfText_setString(score3d, "3");
      sfText_setFont(score3d, font);
      sfText_setCharacterSize(score3d, 60);
      sfText_setPosition(score3d, s0);
      sfRenderWindow_drawText(window, score3d, NULL);
    }
  if (nbdroite == 4)
    {
      sfText_destroy(score3d);
      sfText_setString(score4d, "4");
      sfText_setFont(score4d, font);
      sfText_setCharacterSize(score4d, 60);
      sfText_setPosition(score4d, s0);
      sfRenderWindow_drawText(window, score4d, NULL);
    }
  if (nbdroite == 5)
    {
      sfText_destroy(score4d);
      sfText_setString(score5d, "5");
      sfText_setFont(score5d, font);
      sfText_setCharacterSize(score5d, 60);
      sfText_setPosition(score5d, s0);
      sfRenderWindow_drawText(window, score5d, NULL);
    }
  if (nbdroite == 6)
    {
      sfText_destroy(score5d);
      sfText_setString(score6d, "6");
      sfText_setFont(score6d, font);
      sfText_setCharacterSize(score6d, 60);
      sfText_setPosition(score6d, s0);
      sfRenderWindow_drawText(window, score6d, NULL);
    }
  if (nbdroite == 7)
    {
      sfText_destroy(score6d);
      sfText_setString(score7d, "7");
      sfText_setFont(score7d, font);
      sfText_setCharacterSize(score7d, 60);
      sfText_setPosition(score7d, s0);
      sfRenderWindow_drawText(window, score7d, NULL);
    }
  if (nbdroite == 8)
    {
      sfText_destroy(score7d);
      sfText_setString(score8d, "8");
      sfText_setFont(score8d, font);
      sfText_setCharacterSize(score8d, 60);
      sfText_setPosition(score8d, s0);
      sfRenderWindow_drawText(window, score8d, NULL);
    }
  if (nbdroite == 9)
    {
      sfText_destroy(score8d);
      sfText_setString(score9d, "9");
      sfText_setFont(score9d, font);
      sfText_setCharacterSize(score9d, 60);
      sfText_setPosition(score9d, s0);
      sfRenderWindow_drawText(window, score9d, NULL);
    }
  if (nbdroite == 10)
    {
      sfText_destroy(score9d);
      sfText_setString(score10d, "10");
      sfText_setFont(score10d, font);
      sfText_setCharacterSize(score10d, 60);
      sfText_setPosition(score10d, s0);
      sfRenderWindow_drawText(window, score10d, NULL);
    }
  return (0);
}
int			main()
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfUint8		*pixels;
  sfMusic		*music;
  sfEvent		event;
  sfFont		*font;
  sfText		*text;
  sfText		*text2;
  sfText		*text3;
  sfText		*text4;
  sfText		*text5;
  sfText		*text6;
  sfVector2f		positiondep;
  sfVector2f		s3;
  sfVector2f		s4;
  sfVector2f		s5;
  sfVector2f		s6;
  sfVector2f		s7;
  sfVector2f		positionfin;
  float			x_dep;
  float			y_dep;
  sfColor		*color;
  int			y;
  int			z;
  float			dx;
  float			dy;
  int			oui;
  int			nbgauche;
  int			nbdroite;

  oui = 0;
  nbgauche = 0;
  nbdroite = 0;
  positiondep.x = 380;
  positiondep.y = 15;
  s3.x = 100;
  s3.y = 200;
  s4.x = 100;
  s4.y = 300;
  s5.x = 100;
  s5.y = 400;
  s6.x = 100;
  s6.y = 500;
  s7.x = 250;
  s7.y = 600;
  positionfin.x = 380;
  positionfin.y = 15;
  dx = 0.5;
  dy = -0.1;
  x_dep = SCREEN_WIDTH / 2;
  y_dep = SCREEN_HEIGHT / 2;
  window = create_window("Pong", SCREEN_WIDTH, SCREEN_HEIGHT);
  sprite = sfSprite_create();
  texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  pixels = create_pixel_buffer(SCREEN_WIDTH, SCREEN_HEIGHT);
  music = sfMusic_createFromFile("addon/oui.ogg");
  font = sfFont_createFromFile("addon/Pokelol.ttf");
  if (!font)
    return EXIT_FAILURE;
  if (!music)
    return EXIT_FAILURE;
  text = sfText_create();
  text2 = sfText_create();
  text3 = sfText_create();
  text4 = sfText_create();
  text5 = sfText_create();
  text6 = sfText_create();
  sfText_setString(text, "Pong");
  sfText_setString(text2, "E : move up the left bat");
  sfText_setString(text3, "D : move down the left bat");
  sfText_setString(text4, "Up : move up the right bat");
  sfText_setString(text5, "Down : move up the right bat");
  sfText_setString(text6, "Press Space to play");
  sfText_setFont(text, font);
  sfText_setFont(text2, font);
  sfText_setFont(text3, font);
  sfText_setFont(text4, font);
  sfText_setFont(text5, font);
  sfText_setFont(text6, font);
  sfText_setCharacterSize(text, 100);
  sfText_setCharacterSize(text2, 50);
  sfText_setCharacterSize(text3, 50);
  sfText_setCharacterSize(text4, 50);
  sfText_setCharacterSize(text5, 50);
  sfText_setCharacterSize(text6, 50);
  sfText_setPosition(text, positiondep);
  sfText_setPosition(text2, s3);
  sfText_setPosition(text3, s4);
  sfText_setPosition(text4, s5);
  sfText_setPosition(text5, s6);
  sfText_setPosition(text6, s7);
  sfSprite_setTexture(sprite, texture, sfTrue);
  //draw_line(pixels); Affiche ligne du milieu
  sfMusic_play(music);
  sfMusic_setLoop(music, sfTrue);
  y = 190;
  z = 190;
  while (sfRenderWindow_isOpen(window))
    {
      if (oui == 0)
	{
	  while (sfKeyboard_isKeyPressed(sfKeySpace) != sfTrue)
	    {
	      sfRenderWindow_clear(window, sfBlack);
	      sfRenderWindow_drawSprite(window, sprite, NULL);
	      sfRenderWindow_drawText(window, text, NULL);
	      sfRenderWindow_drawText(window, text2, NULL);
	      sfRenderWindow_drawText(window, text3, NULL);
	      sfRenderWindow_drawText(window, text4, NULL);
	      sfRenderWindow_drawText(window, text5, NULL);
	      sfRenderWindow_drawText(window, text6, NULL);
	      sfRenderWindow_display(window);
	    }
	  oui++;
	}
      draw_circlefin(pixels, x_dep, y_dep, color);
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(window);
	  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	    sfRenderWindow_close(window);
	}
      if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
	y--;
      if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue)
	y++;
      if (y <= 0)
	y++;
      if (y >= SCREEN_HEIGHT - 140)
	y--;
      draw_stickleft(pixels, y);
      if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
	z--;
      if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
	z++;
      if (z <= 0)
	z++;
      if (z >= SCREEN_HEIGHT - 140)
	z--;
      draw_stickright(pixels, z);
      if (y_dep <= 0)
	dy = -dy;
      if (y_dep >= SCREEN_HEIGHT)
	dy = -dy;
      if (x_dep <= 0)
	{
	  pixels = create_pixel_buffer(SCREEN_WIDTH, SCREEN_HEIGHT);
	  x_dep = SCREEN_WIDTH / 2;
	  y_dep = SCREEN_HEIGHT / 2;
	  dx = -0.4;
	  dy = 0.1;
	  nbdroite = nbdroite + 1;
	}
      if (x_dep >= SCREEN_WIDTH)
	{
	  pixels = create_pixel_buffer(SCREEN_WIDTH, SCREEN_HEIGHT);
	  x_dep = SCREEN_WIDTH / 2;
	  y_dep = SCREEN_HEIGHT / 2;
	  dx = 0.4;
	  dy = -0.1;
	  nbgauche = nbgauche + 1;
	}
      if (x_dep < 36 && y_dep >= y && y_dep <= y + 140)
	dx = -dx * 1.05;
      if (x_dep > 994 && y_dep >= z && y_dep <= z + 140)
	dx = -dx * 1.05;
      x_dep += dx;
      y_dep += dy;
      draw_circle(pixels, x_dep, y_dep, color);
      sfRenderWindow_clear(window, sfBlack);
      sfTexture_updateFromPixels(texture, pixels, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      scoregauche0(nbgauche, window, font);
      scoredroite0(nbdroite, window, font);
      sfRenderWindow_display(window);
      if (nbdroite == 10 || nbgauche == 10)
	{
	  sfMusic_destroy(music);
	  sfRenderWindow_destroy(window);
	  sfText_destroy(text);
	  sfFont_destroy(font);
	  return (EXIT_SUCCESS);
	}
    }
  sfMusic_destroy(music);
  sfRenderWindow_destroy(window);
  sfText_destroy(text);
  sfFont_destroy(font);
  return (EXIT_SUCCESS);
}
