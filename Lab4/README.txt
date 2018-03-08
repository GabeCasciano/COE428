Ignore the CMake file, this is just so I can use a nicer IDE.

The picture of the FSM is in the image titled "FSM_IMAGE.jpggit s"

Does not work, I am struggling to get rid od Segmentation Faults.
This lab is also not complete and I plan on submitting it late,

node_t is the struct used to contain the state as well as the next
states

buildlist is used to initialize all of my node_t based variables.
It will also intiialize some other global pointers

updateCurrent updates the current state based on the users input

change allows users to change the specified next state to any given
state.

print as it sounds, prints out the fsm

garbage_collector is used to detect if an states are not reachable.
This does not account for multiple states going missing at once.
This is simply based on a checksum.

ASCIIAdder is a method used to simply convert the pre-assigned state
numbers into their corresponding ascii chatacters.