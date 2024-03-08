#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{

int fd;
//For opening the file
/*
fd = open("/home/vinay/Desktop/Vinay/C_Programs/SysCalls_Test", O_RDONLY);
if(fd == -1)
{
printf("Your file named SysCalls_Test is unable to open\n");
}
printf("fd = %d. Your file named SysCalls_Test is successfully opened\n",fd); 
*/

//If file doesnot exitst fd will return -1
/*
fd = open("/home/vinay/Desktop/Vinay/C_Programs/SysCall_Test", O_WRONLY|O_TRUNC);
if(fd == -1)
{
printf("Your file named SysCall_Test is unable to open\n");
}
else
{
printf("fd = %d. Your file named SysCall_Test is successfully opened\n",fd); 
}
*/
//If file exitsts then the file will be opened for writing and will be truncated 
/*
fd = open("/home/vinay/Desktop/Vinay/C_Programs/SysCalls_Test/Sample.txt", O_WRONLY|O_TRUNC);
if(fd == -1)
{
printf("Your file named Sample.txt is unable to open\n");
}
else
{
printf("fd = %d. Your file named Sample.txt is successfully opened and also truncated\n",fd); 
}
*/
//Using creat flag to create a new file
/*
fd = open("/home/vinay/Desktop/Vinay/C_Programs/SysCalls_Test/Sample1.txt", O_WRONLY|O_CREAT);
if(fd == -1)
{
printf("Your file named Sample1.txt is unable to open\n");
}
else
{
printf("fd = %d. Your file named Sample1.txt is successfully created and opened\n",fd); 
}

//if we open a file without giving permissions then when we read or write it behaves abnormally
*/
//Giving access permissions

fd = open("/home/vinay/Desktop/Vinay/C_Programs/SysCalls_Test/Sample1.txt", O_WRONLY|O_CREAT,S_IRWXU);
if(fd == -1)
{
printf("Your file named Sample1.txt is unable to open\n");
}
else
{
printf("fd = %d. Your file named Sample1.txt is successfully created and opened\n",fd); 
}
const char *buf = "My ship is solid!";
ssize_t nr;
nr = write(fd,buf,strlen(buf));
if(nr == -1)
{
printf("I am unable to write into the file\n");
}



return 0;
}
