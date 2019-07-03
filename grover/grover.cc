#include <iostream>
using namespace std;
#include <math.h>
#include "quantum.h"
#define size 1000

void grover(int, int);

int main ()
{
  int n,m, x_i;
  
  cout << "n=:" ; cin >> n ;
  m = pow (2, n);
  cout << "Insert the number from 0 to " << m-1 << ", where f(x)=1: " ; cin >> x_i;

  grover (n, x_i);
  
  return 0;
}

void grover(int n, int x_i)
{
  double a;
  char again = 'y';
  int iteration = 1;
  int m = pow (2, n);
  double output[size];
  
  //Output from here

  cout<<endl<<"(a) |";
  for(int i=0;i<n;i++){
    cout<<"0";
  }
  cout<<">"<<endl;

  H_n_0(output,n);
  cout<<endl<<"(b)="<<endl;
  for(int i=0;i<m;i++)
    {
      cout<<output[i]<<"  ";
    }
  cout<<endl;

  while(again=='y'){
    cout<<"Iteration: "<<iteration++<<endl;
    
    cout<<endl<<"(c)-a="<<endl;
    output[x_i] *= (-1);

    for(int i=0;i<m;i++)
      {
	cout<<output[i]<<"  ";
      }
    cout<<endl;

    cout<<endl<<"(c)-b="<<endl;

    a=0.0;
    for(int i=0;i<m;i++)
      {
	a=a+output[i];
      }
    a=a/m;

    for(int i=0;i<m;i++)
      {
	output[i]=(-1*output[i])+(2*a);
      }

    for(int i=0;i<m;i++)
      {
	cout<<output[i]<<"  ";
      }
    cout<<endl;

    cout<<"Next iteration? Press 'y': ";cin>>again;
  }
}
