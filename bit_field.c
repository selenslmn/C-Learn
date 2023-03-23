// Here the a and b elements of the structure are of type double and int, respectively. 
// However, element c denotes a 3-bit int object and element d denotes a 5-bit int object.

struct SAMPLE {
		double a;
		int b;
		int c: 3;		
		int d: 5;		
	};

// n-bit objects can only be created as struct elements. Such a notification cannot be made outside the structure.
