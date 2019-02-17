#include <stdio.h>
#include <stdlib.h>

long double epsilon=1;
long double suma = 1;

int main(int argc, char *argv[])
{
   float machEps = 1.0f;

    printf( "Epsilon inicial, 1 + Epsilon Inicial\n\n\n" );
    do {
       printf( "%G\t%.20f\n", machEps, (1.0f + machEps) );
       machEps /= 2.0f;

    }
    while ((float)(1.0 + (machEps/2.0)) != 1.0);

    printf( "\nEl Epsilon de la maquina es: %G\n", machEps );

  return 0;
}
