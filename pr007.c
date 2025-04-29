//Изменение пользовательского контекста процесса
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]){
	int result;
	pid_t pid, ppid;
	pid = getpid();
	ppid = getppid();
	printf("Ид. текуущего процесса:%d, ид. родительского процесса:%d\n",pid, ppid);
        printf("Выполняем fork()n");
	result = fork();
	if (result >0){
		pid =  getpid();
		ppid = getppid();
	printf("Работает процесс-родитель\n");
	printf("После запуска fork():\n");
	printf("Ид.текущего процесса: %d, ид. родительского процесса:%d\n", pid, ppid);
	printf("Родитель завершил работу\n");
	}	
	else if (result == 0){
	printf("Заменяем пользовательский контекст процесса-ребенка\n");
	(void)execle ("./pr002.out","/pr002.out", 0, envp);
	printf("Ошибка при выполнении системного вызова exes\n");
	exit(-1);
	}
	else{
		printf("Ошибка при ваыполнении fork()\n");
		 exit (-1);
	}
	return 0;	
}
