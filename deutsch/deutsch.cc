#include <iostream>
using namespace std;
#include<math.h>
#include "quantum.h"

void deutsch(qubit, qubit, int, int);

int main ()
{
  int f_0,f_1;
  cout<<"Enter the value of f(0): ";
  cin>>f_0;
  cout<<"Enter the value of f(1): ";
  cin>>f_1;

  qubit q1,q2;
  q1.setValue(0);
  q2.setValue(1);

  deutsch(q1,q2,f_0,f_1);
  
  return 0;
}

void deutsch(qubit q1, qubit q2, int f_0, int f_1)
{
  cout<<"First qubit:"<<endl;
  q1.printState();
  cout<<"Second qubit:"<<endl;
  q2.printState();

  int input[4][1];
  cout<<"(a) = |0 1> ="<<endl;
  q1.tensor(q2,input);

  matrix m;
  m.print(input);
  
  cout<<endl<<"(b) After applyning the Hadamard in both top and bottom qubit:"<<endl;

  quantumOp op;
  int top[2][1];
  int bottom[2][1];
  op.Hadamard(q1.state,top);
  op.Hadamard(q2.state,bottom);
  //cout<<"The top bit:"<<endl;
  //op.printMatrix(top);
  //cout<<"The bottom bit:"<<endl;
  //op.printMatrix(bottom);

  cout<<"i.e., (b) = 1/sqrt(2) * "; op.printHadamard(top); cout<<"  Tensor  1/sqrt(2) * "; op.printHadamard(bottom); cout<<endl;


  cout<<endl<<"(c) = 1/sqrt(2) * ( (-1)^f(0) |0>  + (-1)^f(1) |1>)  tensor  1/sqrt(2) * "; op.printHadamard(bottom); cout<<endl;

  top[0][0] = top[0][0]*pow(-1,f_0);
  top[1][0] = top[1][0]*pow(-1,f_1);
  cout<<"or, (c) = ";
  if(f_0==1) cout<<" - ";
  cout<<"1/sqrt(2) * ";op.printHadamard(top);  cout<<"  Tensor  1/sqrt(2) * "; op.printHadamard(bottom); cout<<endl;

  cout<<endl<<"(d) apply H to the top qubit: ";

  int finalTop[2][1];
  op.Hadamard(top,finalTop);
  cout<<"(d) = ";
  if(f_0==1) cout<<" - ";
  op.printHadamard(finalTop);  cout<<"  Tensor  1/sqrt(2) * "; op.printHadamard(bottom); cout<<endl;

  cout<<endl<<"Answer: ";
  if(finalTop[0][0]!=0){cout<<"As the top bit is |0>, f is constant"<<endl;}
  else{cout<<"As the top bit is |1>, f is balanced"<<endl;}
}
