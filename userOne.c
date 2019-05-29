#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int fd1; 
	char name[30];
      char * myfifo = "/tmp/myfifo"; 
	printf("Enter your name: ");
      fgets(name,30,stdin);
  
  
    mkfifo(myfifo, 0666); 
  
    char str1[80], str2[80]; 
    while (1) 
    {

        fd1 = open(myfifo,O_RDONLY); 
        read(fd1, str1, 80); 
  
        printf("User one said %s\n", str1); 
        close(fd1); 
	printf("%s enter message: ",name);  
        fd1 = open(myfifo,O_WRONLY); 
        fgets(str2, 80, stdin); 
        write(fd1, str2, strlen(str2)+1); 
        close(fd1); 
    } 
    return 0; 
} 
