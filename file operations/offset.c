// The first byte of the file is at the 0th offset. Each byte has an offset number so that the next byte is at the 1st offset.
// Here, the operating system keeps an offset that indicates the "current processing position" for each open file. This is called a "file pointer". 
// When the file is opened, the file pointer is at the 0th offset.

// Here x represents the bytes in the file. Let the file pointer be at the 2nd offset. 
// If we read two bytes from this offset, we read the bytes at the 2nd and 3rd offset. 
// Since we read two bytes, the file pointer will be advanced by 2 and now it will show the 4th offset.

/*  
      01234
      xxxxx
*/


/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// The situation where the file pointer displays the byte that is not after the last byte of the file is called EOF (End of File):

/* 
  	012345
	  xxxxx
*/

// Cannot read from EOF status. However, writing is possible. In the case of EOF, bytes are added to the file when writing to the file. 
// If the file pointer is not in EOF, the file is not enlarged at the time of writing. Bytes where the file pointer points to are squashed and written.

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// The only way to increase the length of a file is to pull the file pointer to EOF and write.

// Here the file pointer is located at 2.offset. If we write 5 bytes to the file here, the file is enlarged by 2 bytes:

/*
	  01234567
	  xxyyyyy
*/

// The file pointer will now be at the 7th offset. This is again the EOF state.

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
