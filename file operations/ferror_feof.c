// There are two standard C functions that give the reason the last commit failed: ferror and feof.

// Both take the file information pointer from the fopen function as a parameter.

// The ferror function returns a nonzero value if the last operation failed due to an IO error, or 0 otherwise. 

// The feof function, on the other hand, returns a non-zero value if the last operation failed due to the EOF condition, otherwise it returns 0.

/*

	012345
	xxxxx

*/

// Here the file pointer is at the 4th offset. Let's read 1 byte from the file with the fgetc function. 
// If we query it with the feof function, it will give the value 0. However, the file pointer is in the EOF state.
// The misunderstanding in the feof function is that it is as if the feof function is doing due diligence based on the location of the current file pointer. 
// Whereas feof looks at whether the "last commit" failed because of EOF.

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
