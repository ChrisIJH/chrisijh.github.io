#include <stdio.h>

int my_strlen(char *s)
{
   char *p = s;

   while (*p)
      ++p;

   return (p - s);
}

int main(void)
{
   int i;
   char *s[] = 
   {
      "Git tutorials",
      "Tutorials Point"
   };

   for (i = 0; i < 2; ++i)
      
   printf("string lenght of %s = %d\n", s[i], my_strlen(s[i]));


// to be added in stash


// did at develop branch state 1

// did at develop branch state 2

//did at feature1 branch state 1
//did at feature1 branch state 2
//did at release_1_2 branch state 1 
   return 0;
}