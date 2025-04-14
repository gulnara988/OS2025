//Программа, иллюстрирующая создание процесса-ребенка при помощи fork()
//с разнымы действиями процесса-ребенка и процесса_родителя
#include <stdio.h>
#include <sys/types.h>
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
        printf("начальное значение переменной a: %d", a);	
	c = fork();
	if(c<0){
	printf("Ошибка при вызове fork()");
		exit(-1);
	}
	else if (c==0) {
		printf("выполнение дочернегг процесса");
		a = a+1;
		prid = getpid();
	        parprid = getppid();
  		printf("После выполнения fork():\n");		
		printf("Ид. текущего процесса: %d\n", prid);
		printf("Ид. родительского процесаа  %d\n",parprid);
		printf("Значение переменной а: %d",a);
	}
	else{
		printf("Выполнение родительского процесса, порождён процесс с ид.%d",c);
		a = a+1000;
				prid = getpid();
		parprid = getppid();
		printf("После выполнения fork() для родительского процесса:\n");
		printf("Ид.текущего процесса:%d\nИд. родительского процесса::%d\n", prid,parprid);
		printf("Значение переменной a:%d\n", a);
	}
	return 0;
}
						
						
