#include <unistd.h>
#include <stdio.h>


int main()
{

pid_t x,y;
x = getpid(); //100% succes rate
y = getppid();
printf("%d\n",x);
printf("%d\n",y);

return 0;
}
