#define _CRT_SECURE_NO_WARNINGS //scanf_s, gets_s 渠褐 scanf, gets煎 餌辨й熱氈紫煙 п輿朝 貲滄橫. 醞蹂X
#define MAX_SIZE 100 // 橾薑 Щ煎斜極縑 盪濰й熱氈朝 貲滄曖 譆渠 熱 100偃歜擊 曖嘐ж朝 衙觼煎 滲熱/ C, 棻艇樹橫曖 const 酈錶萄 籀歲 高擊 滲唳й 熱 橈棻.
#include <stdio.h> //standard input/output header (殮轎溘 塽 斜諼 晦獄瞳檣 晦棟曖 ④渦だ橾)
#include <string.h> // string header (僥濠翮 ④渦だ橾)
#include <windows.h> // windows headr 醞蹂X
typedef struct _CALENDAR { //C 樹橫曖 掘褻羹 僥徹. year, month, day, 橾薑data 曖 薑爾蒂 氬堅 氈堅, 掘褻羹寡翮煎 100蘊曖 奢除擊 й渡
	int year;
	int month;
	int day;
	char* to_do;
}CALENDAR;
void initiallize(CALENDAR* calendar); // 100蘊曖 掘褻羹蒂 й渡ж堅 斜 高擊 蟾晦�� п輿朝 л熱.
int ShowMenu(); //詭景蒂 轎溘п輿朝 л熱
void SerchCalendar(CALENDAR* calendar, int cnt); //褻�� 晦棟 л熱.
int GetDayOfMonth(int year, int num);
int GetLeafYear(int year);
int GetDay(int year, int month);
void PrintCalendar(CALENDAR* calendar, int, int, int year, int month); //15 ~ 18 褻�� 晦棟 л熱頂縑憮 ��轎ж朝 褻�萵漺劦� 嬪и 睡陛瞳檣 л熱
int main() {
	int menu_number = 0;
	int data_cnt_index = 0;  //⑷營 盪濰脹 橾薑 等檜攪曖 熱蒂 曖嘐. 譆渠 100偃檜貊 鳶殮衛 +1螢溥輿堅, 餉薯衛 -1 п邀.
	CALENDAR calendar[100]; //CALENDAR 寡翮 掘褻羹 摹樹 (100蘊)
	initiallize(calendar);
	while (1) {
		menu_number = ShowMenu();
		if (menu_number != 0) {
			switch (menu_number) {
			case 1:
				SerchCalendar(calendar, data_cnt_index);
				break;
			case 2:
				//Insert л熱��轎
				break;
			case 3:
				//update л熱��轎
				break;
			case 4:
				//Delete л熱��轎
				break;
			case 5:
				printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
				printf("弛                          謙猿                          弛\n");
				printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n\n");
				return 0;
			}
		}
	}
}
void initiallize(CALENDAR* calendar) {
	for (int i = 0; i < MAX_SIZE; i++) {
		calendar[i].to_do = (char*)malloc(sizeof(char) * 100); //100蘊曖 僥濠 奢除擊 to_do 滲熱縑 й渡. 闊, 橾薑擊 100濠 檜鼻 殮溘й 熱 橈擠.
		calendar[i].to_do[0] = '\0'; //
	}
}
int ShowMenu() {
	int menu_number;
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n");
	printf("弛                     1.   褻�� ж晦                     弛\n");
	printf("弛                     2.   橾薑 蹺陛                     弛\n");
	printf("弛                     3.   橾薑 熱薑                     弛\n");
	printf("弛                     4.   橾薑 餉薯                     弛\n");
	printf("弛                     5.   謙猿                          弛\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("\n 詭景 摹鷗 : ");
	scanf("%d", &menu_number);
	if (menu_number > 5 || menu_number < 1) {
		system("cls"); //轎溘璽曖 頂辨菟擊 梟荻ж啪 雖錶邀
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛         !!  詭景 廓�ㄧ� 澀跤 殮溘ж樟蝗棲棻.  !!       弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
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
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // printf л熱煎 轎溘й 陽 旋濠儀擊 夥脯輿朝 л熱. 醞蹂X
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
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("                      喇紫 殮溘 : ");
	scanf("%d", &year);
	printf("                      錯 殮溘 : ");
	scanf("%d", &month);
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n\n");
	int start_day = GetDay(year, month);
	int total_day = GetDayOfMonth(year, month);
	PrintCalendar(calendar, start_day, total_day, cnt, year, month);
	printf("\n\n");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式瞪羹橾薑式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	for (int i = 0; i < cnt; i++) {
		printf("弛  喇紫 : %d, 錯 : %d, 橾 %d, 橾薑 : %s  \n", calendar[i].year, calendar[i].month, calendar[i].day, calendar[i].to_do);
	}
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n\n");
}

int InsertCalendar(CALENDAR* calendar, int cnt) {
	int year, month, day;
	char* plan;
	int day_of_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("                      喇紫 殮溘 : ");
	scanf("%d", &year);
	printf("                      錯 殮溘 : ");
	scanf("%d", &month);
	printf("                      橾 殮溘 : ");

	scanf("%d", &day);
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n\n");
	if ((day_of_month[month] < day || day < 0) || (month < 1 || month > 12)) {
		system("cls");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛                陳瞼蒂 澀跤 殮溘ц蝗棲棻.               弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n\n");
	}
	else {
		calendar[cnt].year = year;
		calendar[cnt].month = month;
		calendar[cnt].day = day;
		printf("橾薑 殮溘 : ");
		rewind(stdin);
		gets_s(calendar[cnt].to_do, 100);
		cnt++;
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛                        蹺陛諫猿                        弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n\n");
	}
	return cnt;
}