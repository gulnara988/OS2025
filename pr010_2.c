//Обмен данным через FIFO (именнованые pipe) процесс,читающий информацию
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#define BYTES 63

int main() {
	int fd;
	size_t size;
	char resstring [BYTES];
	char name [] = "fifo.file";
/*	if(mknod(name, S_IFIFO | 0664, 0) < 0) {
		printf("Не удалось создать FIFO\n");
		exit(-1);
	}
	*
	*/
	printf("Процесс_приемник начал работу\n");
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
	printf("Процесс_приемник завершил работу \n");
	return 0;
}
		                                                                        


		                                 
	                                
	                                


