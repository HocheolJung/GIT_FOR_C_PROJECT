#define _CRT_SECURE_NO_WARNINGS //scanf_s, gets_s ´ë½Å scanf, gets·Î »ç¿ëÇÒ¼öÀÖµµ·Ï ÇØÁÖ´Â ¸í·É¾î. Áß¿äX
#define MAX_SIZE 100 // ÀÏÁ¤ ÇÁ·Î±×·¥¿¡ ÀúÀåÇÒ¼öÀÖ´Â ¸í·ÉÀÇ ÃÖ´ë ¼ö 100°³ÀÓÀ» ÀÇ¹ÌÇÏ´Â ¸ÅÅ©·Î º¯¼ö/ C, ´Ù¸¥¾ð¾îÀÇ const Å°¿öµå Ã³·³ °ªÀ» º¯°æÇÒ ¼ö ¾ø´Ù.
#include <stdio.h> //standard input/output header (ÀÔÃâ·Â ¹× ±×¿Ü ±âº»ÀûÀÎ ±â´ÉÀÇ Çì´õÆÄÀÏ)
#include <string.h> // string header (¹®ÀÚ¿­ Çì´õÆÄÀÏ)
#include <windows.h> // windows headr Áß¿äX
typedef struct _CALENDAR { //C ¾ð¾îÀÇ ±¸Á¶Ã¼ ¹®¹ý. year, month, day, ÀÏÁ¤data ÀÇ Á¤º¸¸¦ ´ã°í ÀÖ°í, ±¸Á¶Ã¼¹è¿­·Î 100Ä­ÀÇ °ø°£À» ÇÒ´ç
	int year;
	int month;
	int day;
	char* to_do;
}CALENDAR;
void initiallize(CALENDAR* calendar); // 100Ä­ÀÇ ±¸Á¶Ã¼¸¦ ÇÒ´çÇÏ°í ±× °ªÀ» ÃÊ±âÈ­ ÇØÁÖ´Â ÇÔ¼ö.
int ShowMenu(); //¸Þ´º¸¦ Ãâ·ÂÇØÁÖ´Â ÇÔ¼ö
void SerchCalendar(CALENDAR* calendar, int cnt); //Á¶È¸ ±â´É ÇÔ¼ö.
int GetDayOfMonth(int year, int num);
int GetLeafYear(int year);
int GetDay(int year, int month);
void PrintCalendar(CALENDAR* calendar, int, int, int year, int month); //15 ~ 18 Á¶È¸ ±â´É ÇÔ¼ö³»¿¡¼­ È£ÃâÇÏ´Â Á¶È¸±â´ÉÀ» À§ÇÑ ºÎ°¡ÀûÀÎ ÇÔ¼ö
int main() {
	int menu_number = 0;
	int data_cnt_index = 0;  //ÇöÀç ÀúÀåµÈ ÀÏÁ¤ µ¥ÀÌÅÍÀÇ ¼ö¸¦ ÀÇ¹Ì. ÃÖ´ë 100°³ÀÌ¸ç »ðÀÔ½Ã +1¿Ã·ÁÁÖ°í, »èÁ¦½Ã -1 ÇØÁÜ.
	CALENDAR calendar[100]; //CALENDAR ¹è¿­ ±¸Á¶Ã¼ ¼±¾ð (100Ä­)
	initiallize(calendar);
	while (1) {
		menu_number = ShowMenu();
		if (menu_number != 0) {
			switch (menu_number) {
			case 1:
				SerchCalendar(calendar, data_cnt_index);
				break;
			case 2:
				//Insert ÇÔ¼öÈ£Ãâ
				break;
			case 3:
				//update ÇÔ¼öÈ£Ãâ
				break;
			case 4:
				//Delete ÇÔ¼öÈ£Ãâ
				break;
			case 5:
				printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
				printf("¦¢                          Á¾·á                          ¦¢\n");
				printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n\n");
				return 0;
			}
		}
	}
}
void initiallize(CALENDAR* calendar) {
	for (int i = 0; i < MAX_SIZE; i++) {
		calendar[i].to_do = (char*)malloc(sizeof(char) * 100); //100Ä­ÀÇ ¹®ÀÚ °ø°£À» to_do º¯¼ö¿¡ ÇÒ´ç. Áï, ÀÏÁ¤À» 100ÀÚ ÀÌ»ó ÀÔ·ÂÇÒ ¼ö ¾øÀ½.
		calendar[i].to_do[0] = '\0'; //
	}
}
int ShowMenu() {
	int menu_number;
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                     1.   Á¶È¸ ÇÏ±â                     ¦¢\n");
	printf("¦¢                     2.   ÀÏÁ¤ Ãß°¡                     ¦¢\n");
	printf("¦¢                     3.   ÀÏÁ¤ ¼öÁ¤                     ¦¢\n");
	printf("¦¢                     4.   ÀÏÁ¤ »èÁ¦                     ¦¢\n");
	printf("¦¢                     5.   Á¾·á                          ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
	printf("\n ¸Þ´º ¼±ÅÃ : ");
	scanf("%d", &menu_number);
	if (menu_number > 5 || menu_number < 1) {
		system("cls"); //Ãâ·ÂÃ¢ÀÇ ³»¿ëµéÀ» ±ú²ýÇÏ°Ô Áö¿öÁÜ
		printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
		printf("¦¢         !!  ¸Þ´º ¹øÈ£¸¦ Àß¸ø ÀÔ·ÂÇÏ¼Ì½À´Ï´Ù.  !!       ¦¢\n");
		printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
	}
	else return menu_number;
}
int GetDayOfMonth(int year, int month) {
	int day_of_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	day_of_month[2] += GetLeafYear(year);
	return day_of_month[month];
}
int GetLeafYear(int year) {
	if (year % 400 == 0)
		return 1;
	if ((year % 100 != 0) && (year % 4 == 0))
		return 1;
	return 0;
}
int GetDay(int year, int month) {
	int past_day = 0;
	for (int y = 1; y < year; y++)
		past_day = past_day + 365 + GetLeafYear(y);
	for (int m = 1; m < month; m++)
		past_day = past_day + GetDayOfMonth(year, m);
	return (1 + past_day) % 7;
}
void PrintCalendar(CALENDAR* calendar, int start_day, int total_day, int cnt, int year, int month) {
	printf("     Sun     Mon     Tue     Wed     Thu     Fri     Sat\n");
	for (int i = 0; i < start_day; i++)
		printf("        ");
	for (int day = 1, ke = start_day; day <= total_day; day++, ke++) {
		for (int i = 0; i < cnt; i++) {
			if (calendar[i].year == year && calendar[i].month == month && calendar[i].day == day) {
				if (calendar[i].to_do[0] != '\0')
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // printf ÇÔ¼ö·Î Ãâ·ÂÇÒ ¶§ ±ÛÀÚ»öÀ» ¹Ù²ãÁÖ´Â ÇÔ¼ö. Áß¿äX
			}
		}
		printf("%8d", day);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		if (ke % 7 == 6)
			printf("\n");
	}
}
void SerchCalendar(CALENDAR* calendar, int cnt) {
	system("cls");
	int year, month;
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("                      ³âµµ ÀÔ·Â : ");
	scanf("%d", &year);
	printf("                      ¿ù ÀÔ·Â : ");
	scanf("%d", &month);
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n\n");
	int start_day = GetDay(year, month);
	int total_day = GetDayOfMonth(year, month);
	PrintCalendar(calendar, start_day, total_day, cnt, year, month);
	printf("\n\n");
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡ÀüÃ¼ÀÏÁ¤¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	for (int i = 0; i < cnt; i++) {
		printf("¦¢  ³âµµ : %d, ¿ù : %d, ÀÏ %d, ÀÏÁ¤ : %s  \n", calendar[i].year, calendar[i].month, calendar[i].day, calendar[i].to_do);
	}
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n\n");
}

int InsertCalendar(CALENDAR* calendar, int cnt) {
	int year, month, day;
	char* plan;
	int day_of_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	system("cls");
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("                      ³âµµ ÀÔ·Â : ");
	scanf("%d", &year);
	printf("                      ¿ù ÀÔ·Â : ");
	scanf("%d", &month);
	printf("                      ÀÏ ÀÔ·Â : ");

	scanf("%d", &day);
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n\n");
	if ((day_of_month[month] < day || day < 0) || (month < 1 || month > 12)) {
		system("cls");
		printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
		printf("¦¢                ³¯Â¥¸¦ Àß¸ø ÀÔ·ÂÇß½À´Ï´Ù.               ¦¢\n");
		printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n\n");
	}
	else {
		calendar[cnt].year = year;
		calendar[cnt].month = month;
		calendar[cnt].day = day;
		printf("ÀÏÁ¤ ÀÔ·Â : ");
		rewind(stdin);
		gets_s(calendar[cnt].to_do, 100);
		cnt++;
		printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
		printf("¦¢                        Ãß°¡¿Ï·á                        ¦¢\n");
		printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n\n");
	}
	return cnt;
}