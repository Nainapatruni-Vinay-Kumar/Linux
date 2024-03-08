#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
int Sample_fd;
Sample_fd = open("/home/vinay/Desktop/Vinay/C_Programs/SysCalls_Test/Sample.txt", O_WRONLY|O_APPEND);
if(Sample_fd == -1)
{
printf("Sorry, I can't open this file\n");
}
else
{
printf("Your file with id: %d, is opened for WRITING WITH APPEND\n",Sample_fd);

}



return 0;
}
