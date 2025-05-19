//Обмен данным через FIFO процесс 1
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#define BYTES 71

int main() {
	int fd;
	size_t size;
	char resstring [BYTES];
	char name [] = "fifo.file";
/*	if(mknod(name, S_IFIFO | 0664, 0) < 0) {
		printf("Не удалось создать FIFO\n");
		exit(-1);
	}
*/	
	printf("процесс-отправитель начал работу\n");
        if ((fd = open(name, O_WRONLY)) <0) {
		 printf("Не удалось открытьт FIFO на запись \n");
		                 exit(-1);
	}
	size = write(fd,"строка для чтения процесс-получателем", BYTES);
	if(size != BYTES) {
		printf("Не удалось записать всю строку в FIFO \n");
		                                 exit(-1);
	}
	printf("Строка запсиана в FIFO процессом отправителем \n");
	if (close(fd)<0) {
		printf("Не удалось открытьт FIFO для процесса роджителя \n");
		                                 exit(-1);
	}
	printf("Отправитель завершил работу \n");
		                                                                       
        return 0;
}
       	       


		                                 
	                                
	                                


