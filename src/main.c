#include <stdio.h>

void hexdump(FILE * file)
{
	// Define character to use for reading.
	char current_char;

	// Total number of characters read.
	unsigned int total = 0;

	// Print first line, iterate over first character, print first character
	// - to avoid unnecessary formatting / empty initial character.
	printf("%08x\t", total);
	current_char = fgetc(file);
	printf("%02x ", current_char);
	total = total + 1;
	current_char = fgetc(file);

	// Iterate until EOF reached.
	while (current_char != EOF)
	{
		switch(total % 16)
		{
			case 0:
			printf("%s", "\n");
			printf("%08x\t", total);
			break;

			default:
			break;
		}
		printf("%02x ", current_char);

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
