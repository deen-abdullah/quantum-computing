#include <iostream>
using namespace std;
#include "quantum.h"

void cnot(qubit, qubit);

int main ()
{
  qubit q1,q2;
  int x;

  // input of first qubit
  cout<<"Insert the first qubit: "; cin>>x;
  q1.setValue(x);

  // input of second qubit
  cout<<"Insert the second qubit: "; cin>>x;
  q2.setValue(x);

  cnot(q1,q2);
  
  return 0;
}


void cnot(qubit q1, qubit q2)
{
  int input[4][1];
  cout<<"First qubit:"<<endl;
  q1.printState();
  cout<<"Second qubit:"<<endl;
  q2.printState();
  
  q1.tensor(q2,input);

  matrix m;
  cout<<"The tensor product of two qubits: "<<endl;
  m.print(input);
  
  int u[4][4]={{1,0,0,0},
	       {0,1,0,0},
	       {0,0,0,1},
	       {0,0,1,0}};
  
  int output[4][1];

  m.multiplication(u,input,output);
  
  cout<<"After applying the Controlled-Not, the output: "<<endl;
  m.print(output);

  if(output[0][0]==1){
    cout<<endl<<"The output is |0,0>. i.e, keep the value of second qubit"<<endl;
  }
  else if(output[1][0]==1){
    cout<<endl<<"The output is |0,1>. i.e, keep the value of second qubit"<<endl;
  }
  else if(output[2][0]==1){
    cout<<endl<<"The output is |1,0>. i.e, flip the value of second qubit"<<endl;
  }
  else{
    cout<<endl<<"The output is |1,1>. i.e, flip the value of second qubit"<<endl;
  } 
}
