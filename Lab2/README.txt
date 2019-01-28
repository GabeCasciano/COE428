Gabriel Casciano, 500744076, 01/28/2019

towersMain is the main program file used to solve the Towers of Hanoi. 

towers is a user defined Tower of Hanoi engine, it implements a recursive 
algorithm to solve the towers.

To use a custom amount of disks, n, execute the program as follows:

"./towersMain <n>" 

Also, if you would like to use a custom amount of disks,n , and starting 
location, from, to, execute the program as follows:

"./towersMain <n> <from> <to>"

Question 1:

1) towers(5,2,3) will recursively call: towers(4,2,1)

2) towers() will be called 5 times before returning to the intial invocation

3) the first disk will move from tower 2 to tower 3

4) the second recursive call will be: towers(0,3,2)

Question 2)

the program will output 255 lines
