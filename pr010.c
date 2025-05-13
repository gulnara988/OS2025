//Обмен данным через FIFO (именнованые pipe)
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#define BYTES 63

int main() {
	int fd, result;
	size_t size;
	char resstring [BYTES];
	char name [] = "fifo.file";
	if(mknod(name, S_IFIFO | 0664, 0) < 0) {
		printf("Не удалось создать FIFO\n");
		exit(-1);
	}
	if((result = fork())<0) {
		printf("Не удалось создать дочерний пролцесс\n");
		exit(-1);
	}
	else if (result >0) {
	printf("Родительский процесс начал работу\n");
        if ((fd = open(name, O_WRONLY)) <0) {
		 printf("Не удалось открытьт FIFO на запись \n");
		                 exit(-1);
	}
	size = write(fd,"строка для чтения процесс-ребенка", BYTES);
	if(size != BYTES) {
		printf("Не удалось записать всю строку в FIFO \n");
		                                 exit(-1);
	}
	printf("Строка запсиана в FIFO процессом родителем \n");
	if (close(fd)<0) {
		printf("Не удалось открытьт FIFO для процесса роджителя \n");
		                                 exit(-1);
	}
	printf("Родитель завершил работу \n");
	}
	else {
		printf("Процесс-ребенок начал работу \n");
		if ((fd = open(name, O_RDONLY)) <0) {
			                 printf("Не удалось открытьт FIFO на чтение \n");
					                                  exit(-1);
		}
		size = read (fd, resstring, BYTES);
		if(size < 0) {
			printf("Не удалось прочитатьь сьтроку из FIFO \n");
			                                                 exit(-1);
		}
		printf("прочитанная строка %s\n",resstring);
		if (close(fd)<0) {
			printf("Не удалось закрыть FIFO для процесса-ребенка \n");
			exit(-1);
		}
		printf("Процесс ребенок завершил работу \n");
	}
	return 0;
}
		                                                                        


		                                 
	                                
	                                


