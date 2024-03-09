#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>



int main()
{
int Sample_fd;
//Opening a file
Sample_fd = open("/home/vinay/Desktop/Vinay/C_Programs/Linux/SysCalls_Practice/Sample.txt",O_RDONLY);
if(Sample_fd == -1)
{
printf("Sorry, I can't open this file\n");
}
else
{
printf("Your file with id: %d, is opened for reading\n",Sample_fd);

}

//Reading 8 bytes in word
 unsigned long word;
 char buf[sizeof(word)];
 ssize_t ret;
 ret = read(Sample_fd,buf,sizeof(word));
 
 printf("This is taken from the file:\n");
 for(word =0;word < ret;word++)
 {
 printf("%c",buf[word]);
  
 }
 printf("\n");
 printf("%ld",ret);
 printf("\n");
 
 //Reading next 8 bytes in word
 ret = read(Sample_fd,buf,sizeof(word));
  for(word =0;word < ret;word++)
 {
 printf("%c",buf[word]);
  
 }
 printf("\n");
 printf("%ld",ret);
 printf("\n");


return 0;
}

