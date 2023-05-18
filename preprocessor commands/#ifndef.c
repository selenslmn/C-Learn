// It does exactly the opposite of the #ifdef command.

/* If the sambolic constant next to the #ifndef command is not defined, the preprocessor gives the part up to #else, 
and if it is, the part between #else and #endif to the compilation module. */

// The #else part of the command may not exist.

// #ifndef command is frequently used for "include guard". 
// The include protection is called the structure created "to avoid problems when a file is directly or indirectly included more than once". 
// Declaring the same structure twice with the same name will cause an error during compilation.

// With the #ifndef command, include protection is done as follows:

	#ifndef <symbolic_constant_name>
	#define <symbolic_constant_name>

	<file content>	

	#endif

/* Here's how the include protection works: 
When the preprocessor sees the file for the first time, it will detect that the macro is not defined 
and thus give the contents of the file to the compilation module. 
However, at this time, the relevant macro is defined. 
In this case, the preprocessor will no longer give the contents of the file to the build module a second time. */

/*-------------------------------------------------------------------------------------------------------------------------------------------*/
