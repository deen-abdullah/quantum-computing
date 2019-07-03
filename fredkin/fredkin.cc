#include <iostream>
using namespace std;
#include "quantum.h"

void fredkin (qubit, qubit, qubit);

int main ()
{
  qubit q1,q2,q3;
  int x;

  // input of first qubit
  cout<<"Insert the first qubit: "; cin>>x;
  q1.setValue(x);

  // input of second qubit
  cout<<"Insert the second qubit: "; cin>>x;
  q2.setValue(x);

  // input of third qubit
  cout<<"Insert the third qubit: "; cin>>x;
  q3.setValue(x);  

  fredkin(q1,q2,q3);
  
  return 0;
}

void fredkin (qubit q1, qubit q2, qubit q3)
{
  int input[8][1];
  
  cout<<"First qubit:"<<endl;
  q1.printState();
  cout<<"Second qubit:"<<endl;
  q2.printState();
  cout<<"Third qubit:"<<endl;
  q3.printState();
  
  q1.tensor(q2,q3,input);

  matrix m;
  cout<<"The tensor product of three qubits: "<<endl;
  m.print(input);
  
  int u[8][8]={{1,0,0,0,0,0,0,0},
	       {0,1,0,0,0,0,0,0},
	       {0,0,1,0,0,0,0,0},
	       {0,0,0,1,0,0,0,0},
	       {0,0,0,0,1,0,0,0},
	       {0,0,0,0,0,0,1,0},
	       {0,0,0,0,0,1,0,0},
	       {0,0,0,0,0,0,0,1}};
  
  int output[8][1];
  
  m.multiplication(u,input,output);
  
  cout<<"After applying the Controlled-Not, the output: "<<endl;
  m.print(output);

  if(output[0][0]==1){
    cout<<endl<<"The output is |0,0,0>. i.e, keep the value of second and third qubits"<<endl;
  }
  else if(output[1][0]==1){
    cout<<endl<<"The output is |0,0,1>. i.e, keep the value of second and third qubits"<<endl;
  }
  else if(output[2][0]==1){
    cout<<endl<<"The output is |0,1,0>. i.e, keep the value of second and third qubits"<<endl;
  }
  else if(output[3][0]==1){
    cout<<endl<<"The output is |0,1,1>. i.e, keep the value of second and third qubits"<<endl;
  }
  else if(output[4][0]==1){
    cout<<endl<<"The output is |1,0,0>. i.e, swap the value between second and third qubits"<<endl;
  }
  else if(output[5][0]==1){
    cout<<endl<<"The output is |1,0,1>. i.e, swap the value between second and third qubits"<<endl;
  }
  else if(output[6][0]==1){
    cout<<endl<<"The output is |1,1,0>. i.e, swap the value between second and third qubits"<<endl;
  }
  else{
    cout<<endl<<"The output is |1,1,1>. i.e, swap the value between second and third qubits"<<endl;
  }
}
