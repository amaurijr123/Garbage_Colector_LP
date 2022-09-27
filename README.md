# Garbage_Collector_LP

This project was made as an exercise of the discipline "Linguagens de Programação". The objective is to create a static library with the goal to implement a memory garbage collector using the C language. It was made by Amauri da Silva Junior and Sarah Santos da Silva, using the IDE CodeBlocks. It was used a Singly Linked List as a simulation of the Memory for educational reasons. 

## Structure
The structure of the Singly Linked List is basically made with a "void" pointer used to store the variable memory adress; an "int" counter to reference the current amount of variables pointing at the current address; and a pointer to the next element of the list. 

## Functions 

### void *malloc2(int size) 
Used to dynamically allocate the memory with a given size. This function creates a new list element, allocates a part of the memory with the variable "size" and add 1 to the counter inside the new element, because this address is going to be used by 1 new variable. It returns the memory address allocated. 

### void atrib2(void **end1, void *end2)
Used to assign the current "end2" address to the "end1" address, i.e. the pointer of "end1" will point to the address of "end2". It also searches for the "end1" address inside the Memory(List) and subtract 1 from the counter. Also searches for the "end2" element and adds up 1 in the counter.

### void dump()
It searches for elements inside the Memory(Linked List) that has the counter variable equal to 0. If it's found, then it's freed and deleted from the List.

### void Imprimir_Mem()
Exclusively used to print the current state of the Memory(Linked List). It also verifies the elements inside the list to find any with the counter equal to 0, if it's found the function 'dump()' is called to eliminate the element. 

### void Imprimir_Int(int *v)
Used to print the number inside the address of the given "int" pointer variable.

### void Imprimir_Char(char *v)
Used to print the character inside the address of the given "char" pointer variable.
