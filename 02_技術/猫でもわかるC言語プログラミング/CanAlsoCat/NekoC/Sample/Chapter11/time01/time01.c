/* time01.c */

#include <stdio.h>
#include <time.h>

int main()
{
	time_t orgtime;
	struct tm *lpmytm;
	char *today;

	orgtime = time(NULL);
	lpmytm = localtime(&orgtime);

	printf("Œ»ÝŽž‚Í%02dŽž%02d•ª%02d•b‚Å‚·\n",
		lpmytm->tm_hour, lpmytm->tm_min, lpmytm->tm_sec);
	printf("¡“ú‚Í%d”N%02dŒŽ%02d“ú‚Å‚·\n",
		lpmytm->tm_year + 1900, lpmytm->tm_mon + 1, lpmytm->tm_mday);
	today = asctime(lpmytm);
	printf(today);

	return 0;
}