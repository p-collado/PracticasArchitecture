#include <iostream>
#include <time.h>
#include <Windows.h>

#define MAX_X 20

void ini(char* _board);
void update(char* _board);
void clear();
void draw(char* _board);
int contador = 0;
bool muerto = false;

int main()
{
  srand(time(NULL));
  char board[MAX_X];
  

  ini(board);

  while (!muerto)
  {

    clear();
    //Aparicion de enemigo
    if (rand() % 20 == 0)
    {
      board[MAX_X - 1] = 'E';
    }

   /* SETEO DE DISPAROS*/
    if (GetKeyState('D') < 0)
    {
      board[1] = 'o';
    }

    //UPDATE SITUATION
    update(board); //AVANZA LAS BALAS Y LAS E's


    //FOR PARA LAS COLISIONES
    for (size_t i = 1; i < MAX_X; i++)
    {
      if (board[i] == 'o')
      {
        if (board[i + 1] == 'E')
        {
          board[i + 1] = 32;
          board[i] = 32;
          contador++;
        }
      }
    }

    //DRAW
    draw(board);

    Sleep(100);
  }
}

void ini(char* board)
{
  for (size_t i = 0; i < MAX_X; i++)
  {
    board[i] = ' ';
  }

  board[0] = 'A';
}

void update(char* _board)
{
  //PARADA DE BUCLE ESTADO MUERTO
  if (_board[0] == 'E')
  {
    muerto = true;
  }

  //CASO BASE DE BALA PERDIDA FUERA DEL ARRAY
  if (_board[MAX_X - 1] == 'o')
  {
    _board[MAX_X - 1] == 32;
  }

  //FOR PARA AVANZAR LA E
  for (size_t i = 1; i < MAX_X; i++)
  {
    if (_board[i] == 'E')
    {
      if (_board[i - 1] != 'o')
      {
        _board[i - 1] = _board[i];
        _board[i] = 32;
      }
    }
  }

  //FOR PARA AVANZAR LA BALA
  for (size_t i = MAX_X -1; i > 0; i--)
  {
    if (_board[i] == 'o')
    {
      if (_board[i + 1] != 'E')
      {
        _board[i + 1] = _board[i];
        _board[i] = 32;
      }
    }
  }
}

void clear()
{
  system("cls");
}

void draw(char* _board)
{
  for (size_t i = 0; i < MAX_X; i++)
  {
    printf("%c", _board[i]);
  }

  printf("\n%d", contador);
}