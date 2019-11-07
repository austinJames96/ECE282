

#include	<stdio.h>
#include	<signal.h>

main()
{
	void	f(int);			
	int	i;
	
	signal( SIGINT, f );			
	for(i=0; i<5; i++ ){	
		printf("hello\n");
		if(
		sleep(1);
	}
}

void f(int signum)		
{
	printf("Interrupted! OK to quit (y/n): \n");
	char answer;
	scanf("%c", answer);
	if(answer == 'y'){
		exit(0);
	}
	else {
		return;
	}
}