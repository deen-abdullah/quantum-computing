# quantum-computing
Implementation of quantum gates and algorithm: Controlled-NOT, Fredkin gate, Deutsch’s algorithm, Grover’s search algorithm

####################################################################

Question-1: Implement a Controlled-NOT as a function and test it.

Solution: Controlled-NOT:  In computing science, the controlled NOT gate also known as C-NOT or CNOT is a quantum gate that is an essential component in the construction of a quantum computer. 
 
This gate has two inputs and two outputs. The top input is the control bit. It controls what the output will be. If |x> = |0>, then the bottom output of |y> will be the same as the input. If |x> = |1>, then the bottom output will be the opposite. If we write the top qubit first and then the bottom qubit, then the controlled-NOT gate takes | x, y > to | x, x ⊕ y >, where ⊕ is the binary exclusive or operation.
The CNOT gate can be represented by the matrix :

 
Data structures: 
Quantum states have been implemented on array as (2 by 1) matrix. Tensor has been done using array operation. Finally the C-Not has been implemented as 2D matrix. Moreover, matrix multiplication has been used to get the output.

Reflection of Learning: 
This gate plays an important role in information flow in entangled quantum systems. Any quantum circuit can be simulated to an arbitrary degree of accuracy using a combination of CNOT gates and single qubit rotations.

Future improvements: 
We will use vector instead of using array to get universal solution.

Issues: 
For observing the final output we have used if-else statement instead of using Hermitian matrix.

Environment:
Program developed in C++ language and run on Linux OS.
Location-      GraduateStd_Deen_Project/cnot$
Run-    ./cnot 

Sample input: 
Insert the first qubit: 1
Insert the second qubit: 0

Sample output:
The output is |1,1>. i.e, flip the value of second qubit 

#########################################################################

Question-2: Implement a Fredkin gate as a function and test it.

Solution: Fredkin Gate:  In computing science, the Fredkin gate is a quantum gate which has three inputs and three outputs.
 

The top |x> input is the control input. The output is always the same |x>. If |x> is set to |0>, then |y’> = |y> and |z’> = |z>, i.e., the values stay the same. If, on the other hand, the control |x> is set to |1>, then the outputs are reversed: |y’> = |z> and |z’> = |y>. In short, |0, y, z> → |0, y, z> and |1, y, z> → |1, z, y>.
The Fredkin gate can be represented by the matrix: 

 

Data structures: 
Quantum states have been implemented on array as (2 by 1) matrix. Tensor has been done using array operation. Finally the Unitary matrix has been implemented as 2D matrix. Moreover, matrix multiplication has been used to get the output.

Reflection of Learning: 
The Fredkin gate is its own inverse. These gates are universal. Matrix of Fredkin gate indicates that it is unitary.

Future improvements: 
We will use vector instead of using array to get dynamic size.

Issues: 
For observing the final output we have used if-else statement instead of using Hermitian matrix.

Environment:
Program developed in C++ language and run on Linux OS.
Location-      GraduateStd_Deen_Project/fredkin$
Run-    ./fredkin

Sample input: 
Insert the first qubit: 1
Insert the second qubit: 0
Insert the third qubit: 1

Sample output:
The output is |1,1,0>. i.e, swap the value between second and third qubits

################################################################################

Question-3: Implement Deutsch’s algorithm and test it.

Solution: Deutsch’s algorithm:  The simplest quantum algorithm is Deutsch’s algorithm, which is a nice algorithm that solves a slightly contrived problem. This algorithm is concerned with functions from the set {0, 1} to the set {0, 1}. There are four such functions that might be visualized as


 


f : {0, 1} → {0, 1} balanced if f (0) = f (1), i.e., it is one to one. In contrast, call a function constant if f (0) = f (1). Of the four functions, two are balanced and two are constant.


Data structures: 
Quantum states have been implemented on array as (2 by 1) matrix. Tensor has been done using array operation. Hadamard matrix has been implemented using 2D matrix array.

Reflection of Learning: 
The Deutsch’s algorithm can be used to show a black box problem that can be solved efficiently by a quantum computer with no error. Deutsch’s algorithm used to determines a property of functions from {0, 1} to {0, 1}. This is also used to generalize the Deutsch–Jozsa algorithm.

Future improvements: 
We will use vector instead of using array to get dynamic size of data.

Issues: 
For observing the final output we have used if-else statement instead of using Hermitian matrix.

Environment:
Program developed in C++ language and run on Linux OS.
Location-      GraduateStd_Deen_Project/deutsch$
Run-    ./deutsch

Sample input: 
Enter the value of f(0): 0
Enter the value of f(1): 1

Sample output:
Answer: As the top bit is |1>, f is balanced


#####################################################################

Question-4: Implement Grover’s search algorithm and test it.

Solution: Grover’s search algorithm: Grover's algorithm is a quantum algorithm that finds with high probability the unique input to a black box function that produces a particular output value, using just O(√N) evaluations of the function, where N is the size of the function's domain.

Data structures: 
H⊗n |0> has been implemented using array. Array operations have been used to calculate the operations during the iteration of the algorithm.

Reflection of Learning: 
Grover’s algorithm has many applications to database theory such as searching a database Grover's algorithm can also be used for estimating the mean and median of a set of numbers, and for solving the collision problem It is also used to inverting a function.

Issues: 
Number of iteration of the algorithm has been controlled by the user.

Environment:
Program developed in C++ language and run on Linux OS.
Location-      GraduateStd_Deen_Project/grover$
Run-    ./grover

Sample input: 
n=: 3
Insert the number from 0 to 7, where f(x)=1:  5

Sample output:
Iteration: 1
0.176777  0.176777  0.176777  0.176777  0.176777  0.883883  0.176777  0.176777  
Next iteration? Press 'y':
