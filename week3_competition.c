/* Week 3 Group A Competition Problem*/

/*
      Goal: the goal is to identify the first three digits after the decimal point of the solution to part d).
      To solve the problem you must complete the following tasks:
      a) The first digit is the number of letters in the solution to the following puzzle:
         "How I wish I could calculate!"
      b) The second digit is the most significant digit of the total floor area of the room you are
         now sitting in. Note: the room length = 30.53 m.
      c) Insert a decimal point between the digits found in a) and b) and divide the resulting number by 2
         -this is the value to use in the next step.
      d) In the final step, write a program to calculate the Maclaurin series expansion of cos(x) up to and
         including the 8th power of x, where x is the result found in c).
*/

#include <stdio.h>
#include <math.h>
int main (void) {


   printf("----------------PART A----------------\n");
   char *letter= "How I wish I could calculate!"; //input the sentence.
   int i;                //Init the number of the FOR loop
   double lettercount = 0;  //At the beginning, the # of letter is 0
   for (i=0; letter[i]; i++)
//for loop: for(init; condition; increment) 
//init首先被执行，允许你控制并初始化控制变量；
//接下来判断condition，如果为true则执行循环；如果为false则不执行循环，且会直接跳到for循环的下一个语句。
//运行完循环主体之后控制流会跳转到increment语句，increment允许你更新循环控制变量，即init里的变量。
//condition再次被判断，如为true，则再运行一遍循环主体。如为false，则直接跳转到for下面的语句。
   {
      if (letter[i] >= 'a' && letter[i] <= 'z') //letter[i]应该指letter的第i个字符，i在上文中指FOR loop的第i个loop，所以能实现逐个字符判断。
      {
         lettercount++;
      }
      else if (letter[i] >= 'A' && letter[i] <= 'z') 
      {
         lettercount++;
      }
   } //FOR loop exit until the "!" has been judge.
   printf("The number of sentence has %.0lf letters\n", lettercount);
//End of Part A


   printf("----------------PART B----------------\n");
   double length=30.53;
   double area=length*length;
   printf("The length of the room is %.2lf.The area is %.2f metersquere.Assume the room is suqare.\n", length, area);
   int MSD=area;
   while(MSD>=10) //while(statement) expression.当满足statement的条件时，运行loop。
   {
      MSD=MSD/10; //因为是integer，所以integer大于10的时候除以10的输出是integer/10的结果的整数，所以可以用此去计算MSD。同理，计算LSD的时候可以用余数的方法。
   }
   printf("The MSD of the area is %d\n", MSD);
//End of Part A


   printf("----------------PART C----------------\n");
   float MSDinc=MSD; //Beacuse MSD in part B is interger, so if we calculate MSD/10, the result will be an integer. This step in order to convert MSD to floating number.
   double x = (lettercount + MSDinc / 10) / 2; 
   printf("The result of part C is %.2f\n", x);
//End of Part C


   printf("----------------PART D----------------\n");
   double result=1-(x*x)/(2*1)+(x*x*x*x)/(4*3*2*1)-(x*x*x*x*x*x)/(6*5*4*3*2*1)+
   (x*x*x*x*x*x*x*x)/(8*7*6*5*4*3*2*1);
   printf("The result of Tylor expansion of cos(x) up to and include the 8th power of x, which x=%.2lf, is %.lf\n", x, result);
   return 0;
}
