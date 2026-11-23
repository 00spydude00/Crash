#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

int forkAndExecute(char * argc, char * argv[]) {
	pid_t pid;
	int status;
	pid = fork();
	if (pid == 0) {
		execvp(argc, argv);
		perror("execvp");
	}
	else if (pid < 0) {
		perror("fork");
	}
	else {
		do {
		  waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return -1;
}
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

	char *argv[10];
	int i = 0;
	char* token = strtok(command, " \n\t");
	while(token != NULL && i < 9) {
		// printf("you said: %s\n", token);
		argv[i] = token;
		token = strtok(0, " \n\t");
		i++;
	}
	return forkAndExecute(argv[0], argv);
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
