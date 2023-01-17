#include <stdio.h>
#include <stdlib.h>
#include <string.h>    //used in read_data_from_file()
#include <math.h>
//declare other #includes below, as you deem necessary:

//program constants -don't change these. Do not add any further constants or global variables.
#define N 11  //size of arrays & vectors  (N=11 for the assignment).
#define TOL 1e-6 //'tolerance' value -the limit used to test for convergence.

//function prototypes:
void read_data_from_file(double A[N][N], double v[N]); //reads circuit data from "input.txt".
void JacobiMethod(double T[N][N], double c[N], double x_new[N], double x_prev[N], int num[1]); //perform Jacobi method iterations.
void printArray(double N_by_N_array[N][N]); //utility function for printing out 2-D arrays.
void printVector(double x[N]);  //utility function for printing out vectors.
double magnitudeVectorDiff(double x_new[N], double x_prev[N]); //utility function to assist in
                                                          //determining convergence.
// define any other functions below, as you deem necessary
// -for example, splitting A into D, L, U, and D-inverse, etc.

int main()
{
  //first declare matrices and vectors, such as A, v and i, and any others needed:
  double A[N][N];
  double  v[N] ;
  //read circuit data from "input.txt" and 'populate' A and v:
  read_data_from_file( A, v);
  //(if necessary) check that the data was read correctly:
  printArray(A);
  printVector(v);

  //manipulate data into the form needed to set up Jacobi iteration,
  //for example splitting A into matrices D, L and U, and establishing D-inverse:
  //(note all this could be placed in a separate function)
int i,j;
double D[N][N],LandU[N][N];
double X[N][N],Dnew[N][N];
   /* printf("\nL\n");*/
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      X[i][j]=A[i][j];
    }
  }
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        if(i==j){
          A[i][j]=0;

        }
          LandU[i][j]=A[i][j];
    }
  }
   /*for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        printf("%lf\t",LandU[i][j]);
        }
    }
    printf("\nD\n");*/
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        if(i!=j){
          X[i][j]=0;

        }
          D[i][j]=X[i][j];
    }
  }
  /* for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        printf("%lf\t",D[i][j]);
        }
    }
    printf("\nDnew\n");*/
      for(i=0;i<N;i++){
      for(j=0;j<N;j++){
        if(D[i][j]!=0){
       Dnew[i][j]=1/D[i][j];
        }
        else{
          Dnew[i][j]=D[i][j];
        }
        }
    }
      /* for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        printf("%lf\t",Dnew[i][j]);
        }
    }

    printf("\nT\n");*/
    double Dnew_LandU[N][N],T[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
              T[i][j]+=(-Dnew[i][k])*LandU[k][j];


            }
        }
    }

      /* for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        printf("%lf\t",T[i][j]);
        }
    }
    printf("\nc\n");*/
    double c[N];
for(i=0;i<N;i++){
  c[i]=0;
  for(j=0;j<N;j++){
    c[i]+=Dnew[i][j]*v[j];
  }
}
      /* for(i=0;i<N;i++){
        printf("%lf\t",c[i]);
    }*/
double x_new[N], x_prev[N];
int num[1];
  JacobiMethod(T, c, x_new, x_prev, num);
  printf("\nCompleted %d iterations (for tolerance = %lf)\n", num[0], TOL);
  printf("Final values rounded to 4 dp:\n");
       for(i=0;i<N;i++){
        printf("i%d = %.4f\n",i,x_new[i]);
    }
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

/* void JacobiMethod(...) {
  /* Complete by writing the code below.
    (note that the convergence test utilises magnitudeVectorDiff()).  */
void JacobiMethod(double T[N][N],double c[N],double x_new[N], double x_prev[N],int num[1]){
  int i,j,k;
  double T_X[N];
  double differences;
  for(k=0;differences>0 ;k++){
  for(i=0;i<N;i++){
    T_X[i]=0;
  for(j=0;j<N;j++){
    T_X[i]+= T[i][j] * x_prev[j];
  }
}
//Ëã³öT*X

  for(i=0;i<N;i++){
    x_new[i]=T_X[i]+c[i];
  }//ËãX_new

differences = magnitudeVectorDiff(x_new,x_prev);
            for (i = 0; i < N; i++)
            {
                x_prev[i] = x_new[i];
            }


}

  num[0]=k;

}



 //end JacobiMethod


double magnitudeVectorDiff(double x_new[N], double x_prev[N]) {
/* Returns a value based on the expression given in the section
   'Jacobi Method Description' of the Assignment document.
   This function must use the TOL constant defined earlier. */

double a = 0;
int i;
for (i = 0; i < N; i++)
{
  a +=fabs(x_prev[i]-x_new[i])*fabs(x_prev[i]-x_new[i]);
}
a = sqrt(a) - TOL;

return a;
}  //end magnitudeVectorDiff

//utility function for printing a 2-D array:
void printArray(double N_by_N_array[N][N]) {
  //complete by writing the code below
  printf("\nA:\n");
 int row, col;
 for(row=0;row<N;row++){
     for(col=0;col<N;col++){
         printf("%lf\t",N_by_N_array[row][col]);
     }
 }

} //end printArray

//utility function for printing a vector:
void printVector(double x[N]) {
  //complete by writing the code below
printf("\nv:\n");
 int row_of_v;
 for(row_of_v=0; row_of_v<N; row_of_v++){
        printf("%lf\t",x[row_of_v]);
 }


}  //end printVector*/

