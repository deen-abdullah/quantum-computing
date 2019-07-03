#include <iostream>
using namespace std;

#include<math.h>

void H_n_0 (double output[], int n)
{
  int m = pow(2,n);

  for(int i=0;i<m;i++)
    {
      output[i]=1/sqrt(m);
    }
}

class matrix{

  
 public:
  void multiplication(int a[4][4],int b[4][1], int mult[4][1]){
      int i,j,k;
      int r1,c1,r2,c2; r1=c1=r2=4; c2=1;
      // Initializing elements of matrix mult to 0.
      for(i = 0; i < r1; ++i)
	for(j = 0; j < c2; ++j)
        {
            mult[i][j]=0;
        }

      // Multiplying matrix a and b and storing in array mult.
      for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }
    }
  void print(int mult[4][1]){
      // Displaying the multiplication of two matrix.
    int i,j,k;
    int r1,c2; r1=4; c2=1;
      for(i = 0; i < r1; ++i)
	for(j = 0; j < c2; ++j)
	  {
	    cout << " " << mult[i][j];
	    if(j == c2-1)
	      cout << endl;
	  }
    }
};
