#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char input[1000006];
char boom[37];
char output[1000006];

int main(void) {
	scanf("%s", input);
	scanf("%s", boom);
	int boom_len = strlen(boom);
	int input_len = strlen(input);
	int top = 0, check = -1;
	for (int i = 0; input[i] != 0; i++) {
		output[top++] = input[i];
		if(input[i] == boom[boom_len-1] && i>= boom_len -1)
		{
			check = -1;
			for (int j=0; j < boom_len; j++) {
				if (output[top - j -1] != boom[boom_len - j -1]) {
					check = 1;
					break;
				}
			}
			if (check == -1)
				top = top - boom_len;
		}
	}
	
	if (top == 0)
		printf("FRULA");
	else
		for(int i=0;i<top;i++)
			printf("%c", output[i]);
	
	return 0;
}

