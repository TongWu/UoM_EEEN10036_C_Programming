/* Lab 3a Task 2
   In each step a-h you are asked to write some
   statements to test your predictions.
*/

#include <stdio.h>

int main (void) {

   /* Step a):
      Declare and assign two int variables i=7 and j=8 and
      try to predict the result of: i *= j + 1;
      Test your prediction with a suitable printf statement. */
      /* <write the code below>    */
      int i=7, j=8;
      printf("i *= j+1= %d\n", i*=j+1);

      /* Note: a *= b + c is equivalent to
               a = a * (b + c)
               and not
               a = a * b + c
      */

   /* Step b):
      Declare a third int variable k; assign 1 to i, j and k.
      try to predict the result of: i += j += k;
      Test your prediction with a suitable printf statement. */
      /* <write the code below>    */
      i=1;
      j=1;
      int k=1;
      printf("i += j+= k = %d\n", i+=j+=k);




   /* Step c):
      Next assign i=1, j=2 and k=3.
      Try to predict the result of: i -= j -= k;
      Test your prediction with a suitable printf statement. */
      /* <write the code below>    */
      i=1;
      j=2;
      k=3;
      printf("i-=j-=k=%d\n", i-=j-=k);



      
   /* Step d):
      Next assign i=2 and j=1 and k=0.
      Try to predict the result of: i *= j *= k;
      Test your prediction with a suitable printf statement. */
      /* <write the code below>    */
      i=2;
      j=1;
      k=0;
      printf("i*=j*=k=%d\n", i*=j*=k);




      
   /* Step e):
      Next assign i=6 and try to predict the result of:
      j = i += i;
      Test your prediction with a suitable printf statement. */
      /* <write the code below>    */
      i=6;
      printf("j=i+=i=%d\n", i+=i);



      
   /* Step f):
      Next assign i=5 and try to predict the result of:
      j = (i -= 2) + 1;
      Test your prediction with a suitable printf statement. */
      /* <write the code below>    */
      i=5;
      printf("j=(i-=2)+1=%d\n", (i-=2)+1);




   /* Step g):
      Next assign i=7 and try to predict the result of:
      j = 6 + (i = 2.5);
      Test your prediction with a suitable printf statement. */
      /* <write the code below>    */
      i=7;
      printf("j=6+(i=2.5)=%d\n", 6+(i=2.5));



      
   /* Step h):
      Finally assign i=2 and j=8, and try to predict the result of:
      j = (i = 6) + (j = 3);
      Test your prediction with a suitable printf statement. */
      /*<write the code below>    */
      i=2;
      j=8;
      printf("j=(i=6)+(j=3)=%d", (i=6)+(j=3));






  return 0;
}