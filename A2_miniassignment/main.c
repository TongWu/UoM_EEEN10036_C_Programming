/* EEEN10036 Mini Assignment 2019-20 'Skeleton'. A2 version.

   The comments provided are step-by-step suggestions of how to proceed.

   Note that the following function definitions must *not* be changed:
   read_data_from_file(..);
   JacobiMethod(...);
   printArray(...);
   printVector(...);
   magnitudeVectorDiff(...);

   However, you may define other functions as you deem appropriate.

   The matrix and vector size is defined by 'N' -do not change.
   The test for convergence is determined by the value of 'TOL' -do not change.

*/

/*
Student name:Tong Wu
Student ID:10497665
*/

//#includes:
#include <stdio.h>
#include <stdlib.h>    //used in read_data_from_file()
#include <string.h>    //used in read_data_from_file()
//declare other #includes below, as you deem necessary:
#include <math.h>

//program constants -don't change these. Do not add any further constants or global variables.
#define N 11  //size of arrays & vectors  (N=11 for the assignment).
#define TOL 1e-6 //'tolerance' value -the limit used to test for convergence.

//function prototypes:
void read_data_from_file(double A[N][N], double v[N]); //reads circuit data from "input.txt".
void JacobiMethod(double T[N][N], double c[N], double x_new[N], double x_prev[N], int iteration[1]); //perform Jacobi method iterations.
void printArray(double N_by_N_array[N][N]); //utility function for printing out 2-D arrays.
void printVector(double x[N]);  //utility function for printing out vectors.
double magnitudeVectorDiff(double x_new[N], double x_prev[N]); //utility function to assist in
                                                          //determining convergence.
// define any other functions below, as you deem necessary
// -for example, splitting A into D, L, U, and D-inverse, etc.
void split_reciprocal_D(double D[N][N]);
void splitL(double L[N][N]);
void splitU(double U[N][N]);
void multiplyMatrix(double first[N][N], double second[N][N], double mult[N][N]);
void multiplyMatrix_Vector(double first[N][N], double second[N], double mult[N]);
void add_Vector(double first[N], double second[N], double result[N]);
void negativeMatrix(double input[N][N], double output[N][N]);
void convientform(double T[N][N], double c[N]);
void printFinalResult(double x[N]);


int main()
{
//first declare matrices and vectors, such as A, v and i, and any others needed:
  double A[N][N], v[N], T[N][N], c[N], x_new[N], x_prev[N];
  int iteration[1];

  //read circuit data from "input.txt" and 'populate' A and v:
  read_data_from_file(A, v);

  //(if necessary) check that the data was read correctly:
  printf("A = \n");
  printArray(A);
  printf("\nv = \n");
  printVector(v);

  //manipulate data into the form needed to set up Jacobi iteration,
  //for example splitting A into matrices D, L and U, and establishing D-inverse:
  //(note all this could be placed in a separate function)
  convientform(T, c);


  //Once everything is set up, call JacobiMethod to iterate until we converge on a solution:
  JacobiMethod(T, c, x_new, x_prev, iteration);    //define an appropriate list of parameters.

  //Once a solution has been found, print out the final values in the expected format using
  //e.g. printArray(), printVector(): (see the example output in the Appendix)

  printf("\nCompleted %d iterations (for tolerance = %lf)\n", iteration[0], TOL);
  printf("Final values rounded to 4 dp:\n");
  printFinalResult(x_new);
  return 0;


}
void read_data_from_file(double A[N][N], double v[N]) {
  //You may, if you wish, rewrite this function in a different way,
  //according to your preferences. If so, it must accomplish the same result!

  /*The data is expected in the following format:
    (no spaces between values)
    8,-14,27,...     //values of vector v
    4,2,3,...        //values of matrix A
    3,-5,2,...       //values of matrix A
    -2,3,8,...       //values of matrix A
     etc...
  */

  //Try to open the file "input.txt" for reading.
  FILE *fp; //file pointer
  if ((fp = fopen("input.txt", "r")) == NULL) {
    printf("input.txt can't be opened\n");
    exit(EXIT_FAILURE);
  }
  //Next read the data into the array.
  //use strtok to deal with the comma-separated values:
  const char s[2] = ",";  //the separator
  char *token;
  int i=0,j;
  char line[100]; //should be long enough!

  //process the first line (the values of vector v):
  if (fgets(line, sizeof(line), fp) != NULL) {
    token = strtok(line, s); //",");
    for (i=0;i<N;i++) {
      if (token != NULL) {
        v[i]=atof(token);
        token = strtok(NULL, s);  //null the token before starting again
      }
    } //end for loop
  } //end first line processing

  //process the remaining lines (the values of A):
  i=0,j=0; //reset loop counters
  while (fgets(line, sizeof(line), fp) != NULL) {
    token = strtok(line, s); //",");
    while (token != NULL)   {
      A[i][j] = atof(token);
      token = strtok(NULL, ",");  //null the token before starting again
      j++;
    }
    i++; //inc. i
    j=0; //reset j
  } //end fgets loop
  fclose(fp);
}

void split_reciprocal_D(double D[N][N])//in order to convert array A to reciprocal of array D, which is D^(-1).
{
  int i, j;
  for (i = 0; i < N; ++i)  //initialize array D
  {
    for (j = 0; j < N; ++j)
    {
      D[i][j] = 0;
    }
  }
  double A[N][N], v[N];
  read_data_from_file(A, v);

  for (i = 0; i < N; i++)  /*copy all the values lie on the diagonal line of array A to array D,
                             and convert them to reciprocal value*/
  {
    D[i][i] = 1 / A[i][i];
  }
} //end split_reciprocal_D


void splitL(double L[N][N])
{
  int i, j;
  for (i = 0; i < N; ++i)  //initialize array L
  {
    for (j = 0; j < N; ++j)
    {
      L[i][j] = 0;
    }
  }
  double A[N][N], v[N];
  read_data_from_file(A, v);
  for (i = 1; i < N; i++) /*copy values in array D which are at the lower
                            position of the diagonal line to array L*/
  {
    j = 0;
    for (; j != i; j++)  //do the copy process until touch the diagonal line
    {
      L[i][j] = A[i][j];
    }
  }
}//end spiltL


void splitU(double U[N][N])
{
  int i, j;
  for (i = 0; i < N; ++i)  //initialize U
  {
    for (j = 0; j < N; ++j)
    {
      U[i][j] = 0;
    }
  }
  double A[N][N], v[N];
  read_data_from_file(A, v);
  for (i = 0; i < N; i++)
  {
    j = i + 1;                     /*It means that, copy the value of i + 1 to j,
                                     when i = 0, j = 1, U[0][1]=A[0][1] and so on.
                                     This can copy the upper value from diagonal
                                     line in array A to array U*/
    for (; j < N; j++)
    {
      U[i][j] = A[i][j];
    }
  }
}//end splitU


void multiplyMatrix(double first[N][N], double second[N][N], double mult[N][N])  //This function in order to multiply matrix and matrix
{
  int i, j, k;
  for (i = 0; i < N; ++i)  //initialize mult
  {
    for (j = 0; j < N; ++j)
    {
      mult[i][j] = 0;
    }
  }

  for (i = 0; i < N; ++i)  //Multiply first and second matrix and store in mult and so on
  {
    for (j = 0; j < N; ++j)
    {
      for (k = 0; k < N; ++k)
      {
        mult[i][j] += first[i][k] * second[k][j];
      }
    }
  }
} //end multiplyMatrix


void multiplyMatrix_Vector(double first[N][N], double second[N], double mult[N])  /*This function is in order to multiply matrix
                                                                                    and vector to output an 1-D array*/
{
  int i, j;
  for (i = 0; i < N; ++i) //initialize mult
  {
    mult[i] = 0;
  }
  for (i = 0; i < N; ++i) //multiply the vector and the matrix one by one
  {
    for (j = 0; j < N; ++j)
    {
      mult[i] = mult[i] + first[i][j] * second[j];
    }
  }
} //end multiplyMatrix_Vector


void add_Vector(double first[N], double second[N], double result[N])  //This function is in order to add two vectors
{
  int i;
  for (i = 0; i < N; ++i)  //initialize result
  {
    result[i] = 0;
  }

  for (i = 0; i < N; i++)
  {
    result[i] = first[i] + second[i];
  }
}//and add_Vector


void negativeMatrix(double input[N][N], double output[N][N])  //This function is in order to turn all values in a matrix to negative
{
  int i, j;
  for (i = 0; i < N; ++i) //initialize output
  {
    for (j = 0; j < N; ++j)
    {
      output[i][j] = 0;
    }
  }

  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      output[i][j] = -input[i][j];
    }
  }
}//end negativeMatrix


void convientform(double T[N][N], double c[N])
{
  double D[N][N], L[N][N], U[N][N];
  double L_U[N][N]; //declare array for L+U
  int i, j;
  double negativeD[N][N]; //declare array for negative reciprocal array D, which is -D^(-1)
  double A[N][N], v[N];
  read_data_from_file(A, v);
  split_reciprocal_D(D);
  negativeMatrix(D, negativeD);
  splitL(L);
  splitU(U);
  //initialize T and c
  for (i = 0; i < N; ++i)
  {
    for (j = 0; j < N; ++j)
    {
      T[i][j] = 0;
      c[i] = 0;
    }
  }
  //start adding L and U
  for (i = 0; i < N; i++)
  {
    j = 0;
    for (; j < N; j++)
    {
      L_U[i][j] = L[i][j] + U[i][j];
    }
  }

  //start multiply -D^(-1) and L+U
  multiplyMatrix(negativeD, L_U, T);
  //output the result T

  //start multiply d^(-1) and v
  multiplyMatrix_Vector(D, v, c);
  //output the result c, which is an 1-D array
} //end convient form


void JacobiMethod(double T[N][N], double c[N], double x_new[N], double x_prev[N], int iteration[1]) {
  /* Complete by writing the code below.
    (note that the convergence test utilises magnitudeVectorDiff()).  */

  double result1[N];  //declare result1 is the result of T multiply x_prev
  int num, i;  //num is the number of iterations
  double diff = 1; //declare the difference between x_new and x_previous to 1, in order to enter the loop
  for (num = 0; diff > 0; num++)
  {
    multiplyMatrix_Vector(T, x_prev, result1);
    add_Vector(result1, c, x_new);
    diff = magnitudeVectorDiff(x_new, x_prev);
    //put x_new and x_prev to the function, note that in the first iteration, value of x_prev is 0
    //copy the value of x_new to x_prev
    for (i = 0; i < N; i++)
    {
      x_prev[i] = x_new[i];
    }
  }
  iteration[0]=num;  //put the number of iterations to an array which can output
} //end JacobiMethod


double magnitudeVectorDiff(double x_new[N], double x_prev[N]) {
/* Returns a value based on the expression given in the section
   'Jacobi Method Description' of the Assignment document.
   This function must use the TOL constant defined earlier. */

double d = 0; //declare and initialize the "distance" to zero
int i;
for (i = 0; i < N; i++)
{
  d = d + (x_new[i] - x_prev[i]) * (x_new[i] - x_prev[i]);  //according the equation of Jacobi distance d^k
}
d = sqrt(d) - TOL; //according the equation of Jacobi distance d^k

return d;

} //end magnitudeVectorDiff

void printFinalResult(double x[N])
{
  //complete by writing the code below
  for (int i = 0; i < N; ++i)
  {
    printf("i%-2d = %4.4lf\n", i, x[i]);
  }

} //end printVector

//utility function for printing a 2-D array:
void printArray(double N_by_N_array[N][N]) {
  //complete by writing the code below
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      printf("%10.4lf\t", N_by_N_array[i][j]);
      if (j == N - 1)
        printf("\n");
    }
  }

} //end printArray

//utility function for printing a vector:
void printVector(double x[N]) {
  //complete by writing the code below
  for (int i = 0; i < N; ++i)
  {
    printf("%10.4lf\n", x[i]);
  }

}  //end printVector
