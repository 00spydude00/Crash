#include <stdio.h>
#include <string.h>

int readLine(void) {
	char command[32];
	char exit[] = "exit\n";
	printf("CRUSH> ");
	fgets(command, sizeof(command), stdin);
	size_t lengthOfCommand = strlen(command);
	if (lengthOfCommand > 30) {
		printf("ERROR: command too long. Must be 30 chars or less.");
		return 1;
	}
	int cmp = strncmp(command, exit, lengthOfCommand);

	if (cmp == 0) {
		return 0;
	}
	char* token = strtok(command, " ");
	while(token) {
		printf("you said: %s\n", token);
		token = strtok(0, " ");
	}
	return -1;
}
int main() {
	while(1) {
		int result = readLine();
		if (result != -1) {
			return result;
		}
	}
	return 0;
}
