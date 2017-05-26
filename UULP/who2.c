/* who2.c - read /var/run/utmp and list info therein
 *        - suppresses empty records
 *        - formats time nicely
 */
#include <stdio.h>
#include <unistd.h>
#include <utmp.h>
#include <fcntl.h>
#include <time.h>

#define SHOWHOST

void showtime(long);
void show_info(struct utmp *);

int main()
{
    struct utmp  current_record;
    int          utmpfd;
    int          reclen = sizeof(current_record);

    if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1)
    {
        perror(UTMP_FILE);
        exit(1);
    }

    while (read(utmpfd, &current_record, reclen) == reclen)
        show_info(&current_record);
    close(utmpfd);
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
