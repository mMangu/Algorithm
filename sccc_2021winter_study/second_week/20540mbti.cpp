#include <cstdio>
int main(void) {
	char input[10];
	scanf("%s", input);
	if (input[0] == 'E')
		input[0] = 'I';
	else if (input[0] == 'I')
		input[0] = 'E';

	if (input[1] == 'S')
		input[1] = 'N';
	else if (input[1] == 'N')
		input[1] = 'S';

	if (input[2] == 'T')
		input[2] = 'F';
	else if (input[2] == 'F')
		input[2] = 'T';

	if (input[3] == 'J')
		input[3] = 'P';
	else if (input[3] == 'P')
		input[3] = 'J';

	printf("%s", input);
	return 0;
}