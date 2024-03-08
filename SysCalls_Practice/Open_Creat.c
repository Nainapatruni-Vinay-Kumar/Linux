#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
int Sample_fd;
Sample_fd = open("/home/vinay/Desktop/Vinay/C_Programs/SysCalls_Test/Sample2.txt", O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
//When we use creat and if the file is not available then kernel will create a new file and permission for the file is must.
if(Sample_fd == -1)
{
printf("Sorry, I can't open this file\n");
}
else
{
printf("Your file with id: %d, is opened using CREAT and with RWX permissions to the user\n",Sample_fd);

}



return 0;
}
