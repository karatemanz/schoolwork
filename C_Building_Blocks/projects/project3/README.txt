This is a readme comprised of elaborations of the errors within my program:

test1: this test is inconsistent in how the program reacts at runtime, depending on the location of the random inserts the insert will occassionally cause the program to infinitely recurse at the when trying to printtree. Due to this the output varies as follows:
	(1) Prints 254, 255, 253, etc. untill segmentation fault
	(2) Prints combo of 254 0 254 254 etc.
	(3) Instantly Segmentation Faults	

test2: runs fine but with a segmentation fault at the end that I believe is due to test1.

Please if you would run this multiple times to verify that my program works to a degree minus the problems it is experiencing with test1. When the random insert works in a way that allows test2 to run the brk values between test2 and test1 are the same like the project asks.

When commenting test1 out, test2 will run with no segmentation fault, but the brk values are incorrect. But test2 runs successfully.
