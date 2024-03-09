#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define		BUF_SIZE	1024


int main(int argc, const char *argv[]) //argc will count the program name also so ./a.out Vinay --> argc = 2;
{
int sfileFd,dfileFd,openFlags;
mode_t filePerms;
ssize_t numRead;
char buf[BUF_SIZE];


//We are suggesting the format to the user if he types --help as the first argument

if(argc !=3 || strcmp(argv[1],"--help") == 0)

	printf("copy <source-file> <destination-file>\n");
else	
{
//Open source file .Source file is opened for read only.
sfileFd = open(argv[1], O_RDONLY);

//Check whether sfile opened successfully
if(sfileFd == -1)
	printf("Unable to open the file %s\n",argv[1]);
else
printf("%s opened for copying\n",argv[1]);

//Open destination file with permissions

dfileFd = creat(argv[2], S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);

//Check whether dfile opened successfuly

if(dfileFd == -1)
	printf("Unable to open the file %s\n",argv[2]);
else
	printf("%s opened for copying\n",argv[2]);

//Transfer data until we get end of input or an error
while((numRead = read(sfileFd,buf,BUF_SIZE)) > 0)
	if(write(dfileFd,buf,numRead) != numRead)
		printf("Cannot write whole buffer\n");
if(numRead == -1)
	printf("Unable to read\n");
else
	printf("Copying Done\n");


//Close both the files

if(close(sfileFd) == -1)
	printf("Unable to the close the %s file\n",argv[1]);
else
	printf("%s is closed\n",argv[1]);
	
if(close(dfileFd) == -1)
	printf("Unable to the close the %s file\n", argv[2]);
else
	printf("%s is closed\n",argv[2]);

}


return 0;
}
