#define _CRT_SECURE_NO_WARNINGS //scanf_s, gets_s ��� scanf, gets�� ����Ҽ��ֵ��� ���ִ� ��ɾ�. �߿�X
#define MAX_SIZE 100 // ���� ���α׷��� �����Ҽ��ִ� ����� �ִ� �� 100������ �ǹ��ϴ� ��ũ�� ����
#include <stdio.h> //standard input/output header
#include <string.h> // string header (���ڿ�)
#include <windows.h> // windows headr �߿�X
typedef struct _CALENDAR { //C ����� ����ü ����. year, month, day, ����data �� ������ ��� �ְ�, ����ü�迭�� 100ĭ�� ������ �Ҵ�
	int year; 
	int month;
	int day;
	char* to_do;
}CALENDAR;
void initiallize(CALENDAR* calendar); 
int ShowMenu();
void SerchCalendar(CALENDAR* calendar, int cnt);
int GetDayOfMonth(int year, int num);
int GetLeafYear(int year);
int GetDay(int year, int month);
void PrintCalendar(CALENDAR* calendar, int, int, int year, int month);
int main() {
	int menu_number = 0; 
	int data_cnt_index = 0;  //���� ����� ���� �������� ���� �ǹ�. �ִ� 100���̸� ���Խ� +1�÷��ְ�, ������ -1 ����.
	CALENDAR calendar[100]; //CALENDAR �迭 ����ü ���� (100ĭ)
	initiallize(calendar);
	while (1) {
		menu_number = ShowMenu();
		if (menu_number != 0) {
			switch (menu_number) {
			case 1:
				SerchCalendar(calendar, data_cnt_index);
				break;
			case 2:
				//Insert �Լ�ȣ��
				break;
			case 3:
		        //update �Լ�ȣ��
				break;
			case 4:
				//delete �Լ�ȣ��
				break;
			case 5:
				printf("��������������������������������������������������������������������������������������������������������������������\n");
				printf("��                          ����                          ��\n");
				printf("��������������������������������������������������������������������������������������������������������������������\n\n");
				return 0;
			}
		}
	}
}
void initiallize(CALENDAR* calendar) {
	for (int i = 0; i < MAX_SIZE; i++) {
		calendar[i].to_do = (char*)malloc(sizeof(char) * 100);
		calendar[i].to_do[0] = '\0';
	}
}
int ShowMenu() {
	int menu_number;
	printf("��������������������������������������������������������������������������������������������������������������������\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                     1.   ��ȸ �ϱ�                     ��\n");
	printf("��                     2.   ���� �߰�                     ��\n");
	printf("��                     3.   ���� ����                     ��\n");
	printf("��                     4.   ���� ����                     ��\n");
	printf("��                     5.   ����                          ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������\n");
	printf("\n �޴� ���� : ");
	scanf("%d", &menu_number);
	if (menu_number > 5 || menu_number < 1) {
		system("cls"); //���â�� ������� �����ϰ� ������
		printf("��������������������������������������������������������������������������������������������������������������������\n");
		printf("��         !!  �޴� ��ȣ�� �߸� �Է��ϼ̽��ϴ�.  !!       ��\n");
		printf("��������������������������������������������������������������������������������������������������������������������\n");
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
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
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
	printf("��������������������������������������������������������������������������������������������������������������������\n");
	printf("                      �⵵ �Է� : ");
	scanf("%d", &year);
	printf("                      �� �Է� : ");
	scanf("%d", &month);
	printf("��������������������������������������������������������������������������������������������������������������������\n\n");
	int start_day = GetDay(year, month);
	int total_day = GetDayOfMonth(year, month);
	PrintCalendar(calendar, start_day, total_day, cnt, year, month);
	printf("\n\n");
	printf("��������������������������������������������������ü��������������������������������������������������������\n");
	for (int i = 0; i < cnt; i++) {
		printf("��  �⵵ : %d, �� : %d, �� %d, ���� : %s  \n", calendar[i].year, calendar[i].month, calendar[i].day, calendar[i].to_do);
	}
	printf("��������������������������������������������������������������������������������������������������������������������\n\n");
}
/* 
   ���Խÿ� ����ü �迭�� data_cnt_index ��°�� �����͸� �����Ѵ�.
   ������ ���� ������ ������ data_cnt_index�� ���� +1 ����.
*/

/*
   ������ �����ÿ� �Է��� ��,��,���� ���� ��ġ�� ����ü�� ã�� �� ����ü�� ������ �ִ� to_do ������ ù��° index�� '\0'�� �־��ش�. 
   �� �� data_cnt_index�� ���� -1����.
   �����Ͱ� ������ �����Ͱ� ������ �ش� �޽����� ���
*/
