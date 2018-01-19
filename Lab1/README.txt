Gabriel Casciano, 500744076, 01/19/2018

mySort is a user generated library that implements the insertion sort algorithm.

sortMain is the main program that test the mySort library, it works by generating six random numbers
and sorting them using mySort, if an error occurs after the sorting process the program will check that and throw an error,
as well as exit the program. If mySort sorts the array correctly the sorted array is printed and the program exits.

cmdLineDemo is used to demonstrate how command line arguments work, essentially if you pass in any amount of arguments it will send print them out, in varying formats

sortMain2 is very similar to sortMain except if you pass in command line arguments the program will sort the arguments you passed in rather than the randomly generated numbers.
You can pass in any integer values number, as long as there is less than: 100000 arguments.

QUESTION:

Simply since the mySort has the signature (array[], numOfElements), you would make the last the number of elements and first would be 0. It would look like this:

mySort(int array[], int numOfElements){
	betterSort(array[], 0, numOfElements);
}

