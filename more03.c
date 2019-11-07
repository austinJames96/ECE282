
#include	<stdio.h>

#define	PAGELEN	24
#define	LINELEN	512

void do_more(FILE *);
void total_size(FILE *tty, int* rows, int* cols);
int see_more(FILE *);

int main( int ac , char *av[] )
{
	FILE	*fp;
	
	int n = 0;
	
	if ( ac == 1 )
		do_more( stdin );
	else
		while ( --ac )
			fp = fopen(av[n], "r");	
			if ( (fp != NULL )
			{
				do_more( fp ) ; 
				fclose( fp );
			}
			else
				exit(1);
	return 0;
}

void do_more( FILE *fp )
/*
 *  read PAGELEN lines, then call see_more() for further instructions
 */
{
	char	line[LINELEN];
	int	num_of_lines = 0;
	int	see_more(FILE *), reply;
	FILE	*fp_tty;
	
	int showmore = 1;
	int rows;
	int cols;


	total_size(fp, &rows, &cols)

	fp_tty = fopen( "/dev/tty", "r" );	   /* NEW: cmd stream   */
	if ( fp_tty == NULL )			   /* if open fails     */
		exit(1);                           /* no use in running */

	while ( fgets( line, LINELEN, fp ) && showmore){		/* more input	*/
		if ( num_of_lines == PAGELEN ) {	/* full screen?	*/
			reply = see_more(fp_tty);  /* NEW: pass FILE *  */
			if ( reply == 0 )		/*    n: done   */
				break;
			num_of_lines -= reply;		/* reset count	*/
		}
		if ( fputs( line, stdout )  == EOF )	/* show line	*/
			exit(1);			/* or die	*/
			showmore = 0;
		num_of_lines++;				/* count it	*/
	}
}

int see_more(FILE *cmd)				   /* NEW: accepts arg  */
/*
 *	print message, wait for response, return # of lines to advance
 *	q means no, space means yes, CR means one line
 */
{
	int	c;

	printf("\033[7m more? \033[m");		/* reverse on a vt100	*/
	while( (c=getc(cmd)) != EOF )		/* NEW: reads from tty  */
	{
		if ( c == 'q' )			/* q -> N		*/
			return 0;
		if ( c == ' ' )			/* ' ' => next page	*/
			return PAGELEN;		/* how many to show	*/
		if ( c == '\n' )		/* Enter key => 1 line	*/
			return 1;		
	}
	return 0;
}

void total_size(FILE *tty, int* rows, int* cols)
{
	if ((rows || cols) != NULL)
	{
		rows = windows_arg.ws_row;
		cols = windows_arg.ws_col;
	}
}