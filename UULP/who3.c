/* who3.c - who with buffered reads
 *        - suppresses empty records
 *        - formats time nicely
 *        - buffers input (using utmplib)
 */
#include <stdio.h>
#include <sys/types.h>
#include <utmp.h>
#include <fcntl.h>
#include <time.h>

#define SHOWHOST

void show_info(struct utmp *);
void showtime(time_t);

int main()
{
    struct utmp  *utbufp, *utmp_next();

    if (open(UTMP_FILE, O_RDONLY) == -1)
    {
        perror(UTMP_FILE);
        exit(1);
    }

    while ((utbufp = utmp_next()) != ((struct utmp *)NULL))
        show_info(utbufp);
    utmp_close();
    return 0;
}

 /*
  * show info()
  *             displays contents of the utmp struct
  *             in human readable form
  *             * displays nothing if record has no user name
  */
void show_info(struct utmp * utbufp)
{
    if (utbufp->ut_type != USER_PROCESS)
        return;

    printf("%-8s", utbufp->ut_name);
    printf(" ");
    printf("%-8s", utbufp->ut_line);
    printf(" ");
    showtime(utbufp->ut_time);
#ifdef SHOWHOST
    if (utbufp->ut_host[0] != '\0')
    printf("(%s)", utbufp->ut_host);
#endif
    printf("\n");
}

void showtime(long timeval)
/*
 * displays time in a format fit for human consumption
 * uses ctime to bulid a string then picks out of it
 * Note: %12.12s prints a string 12 chars wide and LIMITS
 * it to 12chars
 */
{
    char * cp;
    cp = ctime(&timeval);
    printf("%12.12s", cp+4);
}

