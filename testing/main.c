#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	sig_handler(int signum)
{
  printf("\nInside handler function\n");
}

int	main(void)
{
	int	i;

	signal(SIGINT,sig_handler);
	i = 1;
	while (i)
	{
    printf("%d : Inside main function\n",i++);
    sleep(1);
  }
  return (0);
}
