/* 48 to 57 are digits*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)

{
	char ipAddress[30];
	char* ptr;
	short i = 0;
	short counter = 0;
	short dotCounter = 0;
	short k = 0;
	char ch = ' ';
	char* lastThreePtr;
	char* lastTwoPtr;
	char* lastOnePtr;
	short digitCounter = 0;

	char lastOneArray[20];
	char lastTwoArray[20];
	char lastThreeArray[20];

	lastOnePtr = lastOneArray;
	lastTwoPtr = lastTwoArray;
	lastThreePtr = lastThreeArray;

	char* digitCheckPtr;
	char digitCheckArray[30];  

	digitCheckPtr = digitCheckArray;

	puts("Enter the IP address:");
	fgets(ipAddress, 30, stdin);   
	printf("You entered %s\n", ipAddress); // result of printf function, it�s the number of characters 
	                                       //that the printf function 
	                                       //has successfully sent to the output.

	ptr = ipAddress; // pointer pointing to first character of ipAddress.

	k = strlen(ptr);
	// printf("IP address length is %d\n", k);retain

	/* counting the dots in ipaddress */

	for (i = 0; i < 30; i++)
	{
		if (*ptr == '.') // 46 for dot. // putting 46 makes it unicode only for this machine.
		{
			dotCounter++;
		}
		ptr++;
	}

	ptr = ipAddress;

	digitCheckPtr = ptr; 

	/* getting only numerics in array digitCheckArray not dot */

	for (i = 0; i < 30; i++)
	{
		if (*digitCheckPtr == '.')
		{
			digitCheckPtr++;
		}

		digitCheckArray[i] = *digitCheckPtr;
		digitCheckPtr++;	
	}


	printf("digitCheckArray[] is %s\n", digitCheckArray); // retain


	int j = strlen(digitCheckArray);
	// printf("digitCheckArray[] has a length of %d with NULL character.\n",j);retain

	short l = (j - 1); // without Null character.

	/* only taking digits from ASCII chart.*/

	for (i = 0; i < l; i++)
	{
		if (digitCheckArray[i] <= 57 && digitCheckArray[i] >= 48)
		{
			// printf("first element is %c\n", digitCheckArray[0]); test statement

			// printf("%hd element is numeric\n", i+1); retain
			digitCounter++; // counter to check the if statement is executed and digit is within range.
		}
		else
		{
			printf("%c element is non numeric.\n", digitCheckArray[i]);
		}
	}
	printf("digit counter is %d\n", digitCounter); // retain
	printf("l is %d\n", l);


	ptr = ipAddress;

	if (dotCounter == 3 && digitCounter == l)
	{
		/* first block starts here */
		for (i = 0; i < 30; i++)
		{

			if (*ptr == '.')
			{
				// printf("%c", *ptr); // retain, print the dot.
				// puts("    ***We have encountered first dot");retain
				ptr++;
				lastThreePtr = ptr;
				break;
			}
			counter++;
			// printf("%c", *ptr);retain
			ptr++;

		}

		if (counter > 3)
		{
			printf("Invalid IP address as counter is set at %d\n", counter);
		}

		puts("");

		counter = 0;

		/* second block starts here */

		for (i = 0; i < 30; i++)
		{
			if (*ptr == '.')
			{
				// printf("%c", *ptr); // retain, print the dot.
				// puts("    ***We have encountered second dot");retain
				ptr++;
				lastTwoPtr = ptr;
				break;
			}
			// printf("%c", *ptr);retain
			counter++;
			ptr++;
		}
		puts("");



		if (counter > 3)
		{
			printf("Invalid IP address as counter is set at %d\n", counter);
		}
		counter = 0;

		/* third block starts here */

		for (i = 0; i < 30; i++)
		{

			if (*ptr == '.')
			{
				// printf("%c", *ptr); //retain, print the dot.
				
				// puts("    ***We have encountered third dot");retain
				
				ptr++;
				lastOnePtr = ptr;
				break;
			}
			counter++;
			// printf("%c", *ptr);retain
			ptr++;
		}
		puts("");
		if (counter > 3)
		{
			printf("Invalid IP address as counter is %d\n", counter);
		}


		counter = 0;

		//ptr = ptr + 4;
		//printf("...%c\n", *ptr);

		/* fourth block starts here */

		for (i = 0; i < 30; i++)
		{
			if (*ptr == NULL)
			{
				// printf("set to %d\n", counter); retain
				// puts("***Your IP address string has ended.");retain
				// printf("This is null '%d'\n", NULL);retain
				
				break;
			}
			counter++;
			// printf("%c", *ptr); // retain , print one space. maybe null character. 
			ptr++;
			
			//printf("counter is set to %d\n", counter);
		}

		if (counter > 4)  // 4 as we have to count null character in last as well.
		{
			printf("Invalid IP address as counter is set to %d\n", counter);
		}


		//printf("first element of lastOneArray should be %c\n", *lastOnePtr); test statment

		for (i = 0; i < 20; i++)
		{
			
			lastOneArray[i] = *lastOnePtr;
			lastOnePtr++;
		}
		printf("Last 1 part is %s\n", lastOneArray);


		for (i = 0; i < 20; i++)
		{
			
			lastTwoArray[i] = *lastTwoPtr;
			lastTwoPtr++;
		}
		printf("Last 2 part is %s\n", lastTwoArray);

		for (i = 0; i < 20; i++)
		{
			
			lastThreeArray[i] = *lastThreePtr;
			lastThreePtr++;
		}

		printf("Last 3 part is %s\n", lastThreeArray);

		
	}
	else
	{
		puts("Invalid IP address");
	}
	return 0;
}