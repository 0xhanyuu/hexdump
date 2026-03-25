#include <stdio.h>

void hexdump(FILE * file)
{
	// Define character to use for reading.
	char current_char;

	unsigned long int total = 0;

	// Iterate until EOF reached.
	while (current_char != EOF)
	{
		switch(total % 16)
		{
			case 0:
			printf("%s", "\n");
			printf("%8x\t", total);
			break;

			default:
			break;
		}
		printf("%2x ", current_char);

		total = total + 1;
		current_char = fgetc(file);
	}

	printf("%s", "\n");

	return;
}

int main(int argc, char *argv[])
{
	// Filename argument required.
	if (argc < 2)
	{ return 1; }

	// Assume sane filename.
	FILE * file = fopen(argv[1], "r");

	hexdump(file);
	fclose(file);

	return 0;
}
