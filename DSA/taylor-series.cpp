#include <iostream>

double Taylor(int x, int n)
{
   double s = 1;
   for (; n > 0; n--)
   {
      s = 1 + ((float)x / (float)n) * s;
   }

   return s;
}

double TaylorRecursion(int x, int n)
{
   static double s = 1;
   if (n == 0)
   {
      return s;
   }
   s = 1 + ((float)x / (float)n) * s;

   return TaylorRecursion(x, n - 1);
}

double TaylorIterative(int x, int n)
{
   double s = 1;
   int i;
   double num = 1;
   double den = 1;

   for (i = 1; i <= n; i++)
   {
      num *= x;
      den *= i;
      s += num / den;
   }

   return s;
}

int main(void)
{
   std::cout << Taylor(1, 10) << std::endl;
   std::cout << TaylorRecursion(1, 10) << std::endl;
   std::cout << TaylorIterative(1, 10) << std::endl;

   return 0;
}