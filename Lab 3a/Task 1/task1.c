/* Lab 3a Task 1
   In each step a-d you are asked to write some
   statements to test your predictions. The solution
   to step a) is given as an example.
*/

#include <stdio.h>

int main (void) {

   /* Step a):
      Declare and assign two variables i=5 and j=3 and
      try to predict the result of: i/j and i%j.
      Test your prediction with suitable printf statements. */
      /* <the solution to this is shown below>  */
      int i=5, j=3;
      printf("i/j=%d i\%%j=%d\n",i/j, i%j);


   /* Step b):
      Next assign i=2 and j=3 and
      try to predict the result of: (i+10)%j.
      Test your prediction with a suitable printf statement. */
      /* <write the code below>   */
      i=2;
      j=3;
      printf("(i+10)\%%j=%d\n", (i+10)%j);
      
      


   /* Step c):
      Next assign i=7 and j=8 and a third int variable k=9.
      Try to predict the result of: (i+10)%k/j.
      Test your prediction with a suitable printf statement. */
      /* <write the code below>    */
      i=7;
      j=8;
      int k=9;
      printf("(i+10\%%k/j=%d\n", ((i+10)%k)/j);
      
      


   /* Step d):
      Next assign i=1 and j=2 and k=3.
      Try to predict the result of: (i+5)%(j+2)/k.
      Test your prediction with a suitable printf statement. */
      /* <write the code below>    */
      i=1;
      j=2;
      k=3;
      printf("(i+5)\%%(j+2)/k=%d\n", ((i+5)%(j+2))/k);
      


  return 0;
} 