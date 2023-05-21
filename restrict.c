// The restrict type qualifier can only be used with pointers "top level". So an ordinary object cannot be restrict.
// Only pointers can be restrict. Where pointers point cannot be restrict, they can only restrict themselves.

    restrict int a;				/* invalid */
    restrict int *pi;			/* invalid! */
    char * restrict pc;			/* valid */

// The restrict keyword is intended to enable an optimization called "pointer aliasing".
// Access to a pointer pointing is done with at least two machine commands:

    a = *pi;

    mov reg1, pi
    mov reg2, [reg1]
    mov a, reg2
    
/*-------------------------------------------------------------------------------------------------------------------------------------------*/

// restrict pointers are also common in function prototypes in C99.

    char *strcpy(char * restrict dest, const char * restrict source);

// What should we understand when we see a restrict pointer here? 
// Where restrict pointers point to is only accessed through those pointers. 
// So the two addresses we give to the function here should not coincide. 
// If these two addresses coincide, "undefined behavior" occurs.
    
    void *memcpy(void * restrict s1, const void * restrict s2, size_t n);

// Here the blocks should not overlap.

    void *memmove(void *s1, const void *s2, size_t n);

// Since the restrict pointer isn't used here, the blocks may be coincident. 
// There is no point in having a restrict pointer in the prototypes of functions that don't update where the pointer points to.

    int strcmp(const char *s1, const char *s2);

/*------------------------------------------------------------------------------------------------------------------------------------------*/

// Some processors have machine instructions that do copying:

	void reverse_copy(void *dest, void *source, size_t n)
	{
		...
	}
	
// This function reverses the string given in the second parameter to the string given in the first parameter.
// A processor can first pull n bytes from source into itself with a single machine instruction and then copy it to dest. 
// But if the blocks are overlapping here, what the function's internal code is trying to do won't be done with this machine instruction. 
// In this case we can give the compiler an assurance:

	void reverse_copy(void * restrict dest, void * restrict source, size_t n)
	{
		...
	}
	
// The locations pointed to by source and dest are no longer accessed by any other means. 
// Therefore, since the arrays that pass the address will not be coincident, the compiler can make any optimization it wants.
// Since there are no restrict pointers in C++, restrict pointers should not be used if the code is to be compatible with C++. 

/*------------------------------------------------------------------------------------------------------------------------------------------*/
