//Программа, иллюстрирующая создание процесса-ребенка при помощи fork()
#include <stdio.h>
#include <sys/types>
#include <unistd.h>
#include <stdlib.h>
int main() {
	pid_t prid, parprid;
	int a = 0, c;
	prid = getpid();
	parprid = getppid();
	printf("До выполнения fork():\n");
	printf("Ид. текущего процесса: %d\n", prid);
	printf("Ид. родительского процесаа  %d\n",parprid);
        printf("начальное значение переменной а: %d",а);	
	c = fork();
	a = a+1;
	prid = getpid();
	        parprid = getppid();
		        printf("После выполнения fork():\n");
			        printf("Ид. текущего процесса: %d\n", prid);
				        printf("Ид. родительского процесаа  %d\n",parprid);
					        printf("Значение переменной а: %d",а)

	return 0;
						
						^}
