#include <bits/types/idtype_t.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <linux/limits.h>

int forkAndExecute(char * args[]) {
	pid_t pid;
	int status;
	pid = fork();
	if (pid == 0) {
		execvp(args[0], args);
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
	char cwd[PATH_MAX];
	printf("[%s] CRASH>", getcwd(cwd, sizeof(cwd)));
	fgets(command, sizeof(command), stdin);
	size_t lengthOfCommand = strlen(command);
	if (lengthOfCommand > 30) {
		printf("ERROR: command too long. Must be 30 chars or less.");
		return 1;
	}

	// "exit" command
	char exit[] = "exit\n";
	if (strncmp(command, exit, lengthOfCommand) == 0) {
		return 0;
	}

	char *args[10];
	int i = 0;
	char* token = strtok(command, " \n");
	// token != NULL && i < 9
	while(token) {
		// printf("you said: %s\n", token);
		args[i] = token;
		token = strtok(NULL, " \n");
		// printf("args at %d: %s\n", i, args[i]);
		i += 1;
		// printf("args at %d: %s\n", i, args[i]);
	}
	args[i] = NULL;
	// "cd" command
	char * cd = "cd";
	if(strcmp(args[0], cd) == 0) {
		if(args[1] == NULL) {
			fprintf(stderr, "cd: unexpected argument\n");
		}
		else if (chdir(args[1]) != 0) {
			perror("CRASH");
		}
		return -1;
	}

	else {
		return forkAndExecute(args);
	}
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
