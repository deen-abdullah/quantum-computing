#include <iostream>
using namespace std;

class qubit {
  int x;
  
 public:
  int state[2][1];
  qubit(){
    x=0;
    state[0][0]=1;state[1][0]=0;//matrix representation of |0>
  }
  
  void setValue(int a){
    x=a;
    if(x==1){
      state[0][0]=0;state[1][0]=1;
    }
    else{
      state[0][0]=1;state[1][0]=0;
    }
  }
  
  void tensor (qubit q, int result[][1])
  {
    result[0][0]=state[0][0]*q.state[0][0];
    result[1][0]=state[0][0]*q.state[1][0];
    result[2][0]=state[1][0]*q.state[0][0];
    result[3][0]=state[1][0]*q.state[1][0];
  }

  void printState ()
  {
    cout<<state[0][0]<<endl;
    cout<<state[1][0]<<endl;
  }

};

class quantumOp{
 public:
  void Hadamard (int a[2][1], int result[2][1])
  {
    int i,j,k;
    // consider without (1/(Root 2))
    int H[2][2]={{1,1},{1,-1}};

    for(i = 0; i < 2; ++i)
	for(j = 0; j < 1; ++j)
        {
            result[i][j]=0;
        }

     
      for(i = 0; i < 2; ++i)
        for(j = 0; j < 1; ++j)
            for(k = 0; k < 2; ++k)
            {
                result[i][j] += H[i][k] * a[k][j];
            }
      if(result[0][0]==2 || result[1][0]==2)
	{
	  result[0][0] /=2;
	  result[1][0] /=2;
	}
  }
  
  void printHadamard (int a[2][1])
  {
    if(a[0][0]==0) cout<<"|1>";
    else if(a[1][0]==0) cout<<"|0>";
    else if(a[0][0]==a[1][0]) cout<<"(|0> + |1>)";
    else cout<<"(|0> - |1>)";
  }

  void printMatrix(int a[2][1])
  {
    cout<<a[0][0]<<endl;
    cout<<a[1][0]<<endl;
  }
};


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
