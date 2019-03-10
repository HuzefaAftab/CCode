/*
Name= Huzefa Aftab
ID=1001631353
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
char* reading[100];
int y = 0;

/*
This function checks the white space.
*/
char* space(char* l)
{
	while (isspace(*l))
		++l;
	return l;
}

void broke(char* point)
{
	char* other;
	int o = 0;
	point = space(point);
	//looking for ' '
    other = strchr(point, ' ');
	while(other != NULL) 
	{
	other[0] = '\0';
	reading[o] = point;
		++o;
	point = space(other + 1);
	    //looking for ' '
		other = strchr(point, ' ');
	}
	if (point[0] != '\0') 
	{
	reading[o] = point;
	    //looking for '\n'
		other = strchr(point, '\n');
		other[0] = '\0';
		++o; 
	}
 
 reading[o] = NULL;
}
int argument(int enter, int mid, int end)
{
	int pid[2];
	pid_t get;
	pipe( pid );	
	get = fork();
	if (get == 0) 
	{ 
	    if (mid == 0 && end == 0 && enter != 0) 
		{
			dup2(enter, STDIN_FILENO);
			dup2(pid[1], STDOUT_FILENO);
		} 
		else if (mid == 1 && enter == 0 && end == 0)
		{
			
			dup2( pid[1], STDOUT_FILENO );
		} 
		else
		{
			dup2(enter, STDIN_FILENO );
		}
        // if child fails
		if (execvp( reading[0], reading) == -1)
			_exit(EXIT_FAILURE); 
	}
 
	return pid[0];
}
int process(char* point, int enter, int mid, int end)
{
	broke(point);
	if (reading[0] != NULL) 
	{
		// if the user types quit or exit. end the program 
		if (strcmp(reading[0], "quit") == 0 || strcmp(reading[0], "exit") == 0) 
			exit(0);
		y += 1;
		return argument(enter, mid, end);
	}
	return 0;
}
int main(void)
{
	char user[90];
	int enter = 0;
    int mid = 1;
	int o;
	char* point;
	while (1)
	{
		printf("msh>  ");
		//Reads the entire command line
		if (!fgets(user, 100, stdin))
		return 0;
		point = user;
		enter = process(point, enter, mid, 1);
		/*
		wait for the processes to terminate
		*/
	    for (o = 0; o < y; ++o) 
		wait(NULL); 
	}
	return 0;
}
