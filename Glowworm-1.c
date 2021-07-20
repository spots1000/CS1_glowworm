/*
*     Anthony Dalia - an694448
*     Szulumanski
*     COP 3502C - Computer Science 1
*     August 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Glowworm.h"

//Prototypes
void printGlowworm(int tail, int neck, int head, int maxLength, _Bool dead);
//End Prototypes

int main(int argc, char **argv)
{
  //Ensure the required cmd line args are given before we move forward
  if (argv[1] == NULL || argv[2] == NULL)
  {
    //printf("The Arguments were not properly inputted, ending program.\n");
    return 1;
  }

  //Create integers for us to track the position of major pieces
  int maxLen = atoi(argv[1]);
  int stringLen = strlen(argv[2]);
  int tail = 0;
  int head = 2;
  int neck = 1;
  _Bool dead = 0;
  int i;

  //Initial Glowworm Printing
  printf("%s\n\n", argv[2]);

  printf("Glowworm appears! Hooray!\n");
  printGlowworm(tail, neck, head, maxLen, dead);

  //Charecter Processing Loop
  for (i = 0; i < stringLen; i++)
  {
      if (argv[2][i] == 'o' || argv[2][i] == 'O' || argv[2][i] == '@')
      {
        //Grow glowworm
        if ((head + 1) == tail || head == maxLen-1 && tail == 0)
        {
          printf("Glowworm chills:\n");
        }
        else
        {
          printf("Glowworm grows:\n");

          //Determine if we need to wrap or move the head
          if ( head == maxLen -1)
          {
            head = 0;
          }
          else
          {
            head++;
          }

          //Do the same for the neck
          if ( neck == maxLen -1)
          {
            neck = 0;
          }
          else
          {
            neck++;
          }
        }
      }
      else if (argv[2][i] == 's' || argv[2][i] == 'S')
      {
        if ((neck-1) == tail)
        {
          printf("Glowworm chills:\n");
        }
        else
        {
          printf("Glowworm shrinks:\n");

          //Determine if we need to wrap or move the head
          if ( head == 0 )
          {
            head = maxLen -1;
          }
          else
          {
            head--;
          }

          //Do the same for the neck
          if ( neck == 0)
          {
            neck = maxLen -1;
          }
          else
          {
            neck--;
          }
        }
      }
      else if (argv[2][i] == '-' || argv[2][i] == '=')
      {
        printf("Glowworm inches forward:\n");

        //Determine if we need to wrap or move the head
        if ( head == maxLen -1)
        {
          head = 0;
        }
        else
        {
          head++;
        }

        //Do the same for the neck
        if ( neck == maxLen -1)
        {
          neck = 0;
        }
        else
        {
          neck++;
        }

        //Do the same for the tail
        if ( tail == maxLen -1)
        {
          tail = 0;
        }
        else
        {
          tail++;
        }

      }
      else if (argv[2][i] == 'x' || argv[2][i] == 'X' || argv[2][i] == '%')
      {
        printf("Glowworm meets its demise. SAD.\n");
        dead = 1;
      }
      else
      {
        printf("Glowworm chills:\n");
      }

      //Print out the updated glowworm
      printGlowworm(tail, neck, head, maxLen, dead);

      //Stop the program if the glowworm dies
      if ( dead == 1 )
        return 0;
  }
  return 0;
}

void printGlowworm(int tail, int neck, int head, int maxLength, _Bool dead)
{
  //Tail - Refers to the position along the X axis of the tail ~
  //Head - Refers to the position along the X axis of the head "G"
  //        Note: There will always be an "O" before the head on the x axis
  //maxLength - Refers to how many "=" we will print below the Glowworm
  //Note: The X axis starts at 0 and ends at (maxLength - 1)
  int i = 0;
  int j = 0;
  int maxO;

  //Caclulate the maximum value we should print an "o" at beyond the tail
  maxO = ( tail + ((head - tail) - 2) );

  //Print out the actual glowworm in pieces
  for(i = 0; i < maxLength; i++)
  {
    //Check if we should print the tail here
    if (i == tail)
    {
      printf("~");
    }
    else if (i == neck)
    {
      if (dead == 1)
      {
        printf("X");
      }
      else
        printf("O");
    }
    else if (i == head)
    {
      if (dead == 1)
      {
        printf("x");
      }
      else
        printf("G");
    }
    else if (head > tail)
    {
      if (i > tail && i <= maxO)
      {
        printf("o");
      }
      else if (i < head && i < tail)
      {
        printf(" ");
      }
    }
    else if (head < tail)
    {
      if (i > tail && i < maxLength)
      {
        printf("o");
      }
      else if (i >= 0 && i < neck)
      {
        if (i < head)
        {
          printf("o");
        }
        else
          printf(" ");
      }
      else
      {
        printf(" ");
      }
    }
    else
    {
      printf(" ");
    }
  }

  printf("\n");

  //Print out the ledge
  for(j = 0; j < maxLength; j++)
  {
    printf("=");
  }
  printf("\n\n");
}

double difficultyRating(void)
{
  return 2;
}

double hoursSpent(void)
{
  return 8;
}
