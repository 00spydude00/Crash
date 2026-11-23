#include <stdio.h>
#include <string.h>
#include <unistd.h>

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

	if (strncmp(command, exit, lengthOfCommand) == 0) {
		return 0;
	}

	// int numberOfArgs = 1;
	// for (int i = 1; i < lengthOfCommand; i++) {
	// 	if 
	// }
	char *argv[10];
	int i = 0;
	char* token = strtok(command, " \n\t");
	while(token != NULL && i < 9) {
		// printf("you said: %s\n", token);
		argv[i] = token;
		token = strtok(0, " \n\t");
		i++;
	}
	execvp(argv[0], argv);
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
