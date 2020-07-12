#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#define NAME_LEN 20
#define TEL_LEN 20
#define POINT_LEN 30
#define MAX 100
#define Stock_MAX 100
#define MAX_USER_DATA  100
#define UI_NAME  16
#define UI_ADDR  40
#define UI_PASSWORD  16
#define UI_PHONE 24

#include <stdio.h> //������� stdio.h���� 
#include <string.h>//������� string.h����
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <time.h>
#include <conio.h>
#include "TeamProject.h"


//- ���ϸ��� Member.txt , Stock.txt
//- fprintf()�� fscanf() �Լ��� �̿��Ͽ� Member.txt , Stock.txt�� ���� �а�, ���� ��� 
//- ��, ���α׷� ������ ��, ���Ϸκ��� DB�� �о����, ���α׷� ����� ���Ͽ� DB�� ����. 

void finish() {   //�޴��� ���ư��� ���� �Լ� ����
	char key;
	printf("=============================================\n");
	printf(" ���� ȭ������ ���ư��÷��� �ƹ� Ű�� �Է��Ͻÿ�  \n");
	scanf(" %c", &key);
	fflush(stdin);
	system("cls");
}

void PrintMenu() {  //�޴� �Լ� ���� 
	system("cls");
	mainlogo();
	printf("                Cven eleven                  \n");
	printf("=============================================\n");
	printf(" 1. ȸ�� ����\n");
	printf(" 2. ���ϸ��� ����\n");
	printf(" 3. ��� ����\n");
	printf(" 4. ����(Exit)\n");
	printf("=============================================\n");
	printf(" � ������ ���ðڽ��ϱ�?\n");
}

void MPrintMenu() { // ȸ�� ���� �޴� �Լ� ���� 
	system("cls");
	mainlogo();
	printf("              ȸ������ ���α׷�              \n");
	printf("=============================================\n");
	printf(" 1. ȸ������(Insert)\n");
	printf(" 2. ȸ��ã��(Search)\n");
	printf(" 3. ȸ������(Delete)\n");
	printf(" 4. ȸ�����(Print)\n");
	printf(" 5. ����(Save)\n");
	printf(" 6. ����(Exit)\n");
	printf(" 7. ó������\n");
	printf("=============================================\n");
	printf("  �ؿ��Ͻô� ������ ��ȣ�� �Է� :   ");
}

void PPrintMenu() { // ���ϸ��� ���� �޴� �Լ� ����
	system("cls");
	mainlogo();
	printf("              ���ϸ��� ���� ���α׷�              \n");
	printf("=============================================\n");
	printf(" 1. ���ϸ��� �߰�\n");
	printf(" 2. ���ϸ��� �谨\n");
	printf(" 3. ���ϸ��� ��ȸ\n");
	printf(" 4. ����(Save)\n");
	printf(" 5. ����(Exit)\n");
	printf(" 6. ó������\n");
	printf("=============================================\n");
	printf("  �ؿ��Ͻô� ������ ��ȣ�� �Է� :   ");
}

void SPrintMenu() { // ���ϸ��� ���� �޴� �Լ� ����
	mainlogo();
	printf("           ����� ���� �������á� \n");
	printf("==============================================\n");
	printf("  1. ��� ���\n");
	printf("  2. ��� �߰�\n");
	printf("  3. ��� ����\n");
	printf("  4. �ֹ��ؾ��� ��ǰ\n");
	printf("  5. ��ü ��� ���\n");
	printf("  6. ����\n");
	printf("  7. ���� \n");
	printf("  8. ó������ \n");
	printf("==============================================\n");
	printf("  �ؿ��Ͻô� ������ ��ȣ�� �Է� :   ");
}

void InsertSupply() { // �����
	system("cls");
	mainlogo();
	printf("             ����� ��� �޴���\n");
	printf("==============================================\n");
	printf(" ��ǰ�� : ");
	scanf("%s", list_s[s].name);
	fflush(stdin);
	printf(" �߰��� : ");
	scanf("%s", list_s[s].rest);
	fflush(stdin);
	printf(" �Ǹ� ����(��) : ");
	scanf("%s", list_s[s].price);
	fflush(stdin);
	printf(" �������(yyyymmdd) : ");
	scanf("%s", list_s[s].exp);
	fflush(stdin);
	printf("������������ �����\n");
	s++;
}

void InsertMember() { //ȸ�� ��� �Լ� ���� 
	system("cls");
	mainlogo();
	printf("             ��ȸ�� ��� �޴���\n");
	printf("==============================================\n");
	printf(" �̸� �Է� : ");
	scanf("%s", list[x].name);
	fflush(stdin);
	printf(" ���ϸ��� �Է� : ");
	scanf("%s", list[x].point);
	fflush(stdin);
	printf(" ��ȭ��ȣ �Է� : ");
	scanf("%s", list[x].number);
	fflush(stdin);
	printf("������������ �����\n");
	x++;
}

void DeleteMember() { //ȸ�� ���� �Լ� ���� 
	system("cls");
	mainlogo();
	char del[TEL_LEN];

	int count = 0;
	int n, i;

	printf("             ��ȸ�� ���� �޴���\n");
	printf("==============================================\n");
	printf("��ȭ��ȣ �Է� : ");
	scanf("%s", del);
	fflush(stdin);

	for (n = 0; n < x; n++) {
		if (strcmp(list[n].number, del) == 0) { //strcmp ���ϴ� �Լ� 
			count++;
			printf(" ���������� �����Ǿ����ϴ�\n");
			for (i = n; i < x; i++)
				list[i] = list[i + 1];
			x--;
		}
	}
	if (count == 0) {
		printf(" ã�� �̸��� �����ϴ�.\n");
	}
}

void AddSupply() { // ��� �߰� �Լ� ���� 
	system("cls");
	mainlogo();
	char sname[20];
	char s_num[20];
	int count = 0;
	int h;
	int addnum = 0, befnum = 0, complenum = 0;
	printf("            ����� �߰� �޴���\n");
	printf("==============================================\n\n");
	printf("�߰��� ��ǰ���� �Է� : ");
	scanf("%s", sname);
	fflush(stdin);
	printf("�߰��� ���޷��� �Է� : ");
	scanf("%s", s_num);
	fflush(stdin);
	for (h = 0; h < s; h++) {
		if (strcmp(list_s[h].name, sname) == 0) {
			count++;
			addnum = atoi(s_num);
			befnum = atoi(list_s[h].rest);
			complenum = addnum + befnum;
			snprintf(list_s[h].rest, Stock_MAX, "%d", complenum);
			printf(" ��� �߰��Ǿ����ϴ�.: ");
			printf("��ǰ�� : %s / ��� : %s / �ǸŰ��� : %s / ������� : %s\n", list_s[h].name, list_s[h].rest, list_s[h].price, list_s[h].exp);
		}
	}
	if (count == 0) {
		printf(" ã�� ��ǰ�� �����ϴ�.\n������ֽʼ�~!\n");
	}
}

void AddPoint() { // ���ϸ��� �߰� �Լ� ���� 
	system("cls");
	mainlogo();
	char snumber[20];
	char spoint[20];
	int count = 0;
	int h;
	int addpoint = 0, befpoint = 0, complepoint = 0;
	printf("           �ظ��ϸ��� �߰� �޴���\n");
	printf("==============================================\n");
	printf("ȸ������ ��ȭ��ȣ �Է� : ");
	scanf("%s", snumber);
	fflush(stdin);
	printf("�߰��� ���ϸ��� �Է� : ");
	scanf("%s", spoint);
	fflush(stdin);
	for (h = 0; h < x; h++) {
		if (strcmp(list[h].number, snumber) == 0) {
			count++;
			addpoint = atoi(spoint);
			befpoint = atoi(list[h].point);
			complepoint = addpoint + befpoint;
			snprintf(list[h].point, 30, "%d", complepoint);
			printf(" ���ϸ����� �߰��Ǿ����ϴ�.: ");
			printf("�̸� : %s / ���ϸ��� : %s / ��ȭ��ȣ : %s\n", list[h].name, list[h].point, list[h].number);
		}
	}
	if (count == 0) {
		printf(" ã�� �̸��� �����ϴ�.\n");
	}
}

void SubSupply() { // ��� ���� �Լ� ���� 
	system("cls");
	mainlogo();
	char sname[20];
	int s_num = 0;
	int count = 0;
	int h;
	int befnum = 0, complenum = 0;
	printf("            ����� �谨 �޴���\n");
	printf("==============================================\n\n");
	printf("�谨�� ��ǰ�� �Է� : ");
	scanf("%s", sname);
	fflush(stdin);
	printf("�谨�� ��� �Է� : ");
	scanf("%d", &s_num);
	fflush(stdin);
	for (h = 0; h < s; h++) {
		if (strcmp(list_s[h].name, sname) == 0) {
			count++;
			befnum = atoi(list_s[h].rest);
			if (befnum <= 0) {
				printf(" ����� ��� �����ϴ�.\n ��� ��Ϻ��� �ϼ���.\n");
			}
			else {
				complenum = befnum - s_num;
				snprintf(list_s[h].rest, Stock_MAX, "%d", complenum);
				printf(" ��� �谨�Ǿ����ϴ�.: ");
				printf("��ǰ�� : %s / ��� : %s / �ǸŰ��� : %s / ������� : %s\n", list_s[h].name, list_s[h].rest, list_s[h].price, list_s[h].exp);
			}
		}
	}
	if (count == 0) {
		printf(" ã�� ��ǰ�� �����ϴ�.\n������ֽʼ�~!\n");
	}
}

void SubPoint() { // ���ϸ��� �谨 �Լ� ���� 
	system("cls");
	mainlogo();
	char snumber[20];
	char spoint[20];
	int count = 0;
	int h;
	int addpoint = 0, befpoint = 0, complepoint = 0;
	printf("           �ظ��ϸ��� �谨 �޴���\n");
	printf("==============================================\n");
	printf(" ȸ������ ��ȭ��ȣ �Է� : ");
	scanf("%s", snumber);
	fflush(stdin);
	printf(" �谨�� ���ϸ��� �Է� : ");
	scanf("%s", spoint);
	fflush(stdin);
	for (h = 0; h < x; h++) {
		if (strcmp(list[h].number, snumber) == 0) {
			count++;
			addpoint = atoi(spoint);
			befpoint = atoi(list[h].point);
			complepoint = befpoint - addpoint;
			snprintf(list[h].point, 30, "%d", complepoint);
			printf(" ���ϸ����� �谨�Ǿ����ϴ�.: ");
			printf("�̸� : %s / ���ϸ��� : %s / ��ȭ��ȣ : %s\n", list[h].name, list[h].point, list[h].number);
		}
	}
	if (count == 0) {
		printf(" ã�� �̸��� �����ϴ�.\n");
	}
}

void SearchPoint() { // ���ϸ��� ��ȸ �Լ� ���� 
	system("cls");
	mainlogo();
	char snumber[20];
	int count = 0;
	int h;
	printf("           �ظ��ϸ��� ��ȸ �޴���\n");
	printf("==============================================\n");
	printf(" ã�� ��ȭ��ȣ �Է� : ");
	scanf("%s", snumber);
	fflush(stdin);
	for (h = 0; h < x; h++) {
		if (strcmp(list[h].number, snumber) == 0) {
			count++;
			printf("�̸� : %s / ���ϸ��� : %s / ��ȭ��ȣ : %s\n", list[h].name, list[h].point, list[h].number);
		}
	}
	if (count == 0) {
		printf(" ã�� �̸��� �����ϴ�.\n");
	}
}

void SearchSupply() { // ��� �˻� �Լ� ���� 
	int count = 0;
	int h;
	int test_exp = 0;
	int test_rest = 0;
	printf("           ����� ���� �� ������� �ӹ� ��ǰ �˻� �޴���\n");
	printf("===================================================================\n");
	for (h = 0; h < s; h++) {
		int test_exp = atoi(list_s[h].exp);
		int test_rest = atoi(list_s[h].rest);
		if ((test_exp - today() < 3) || (test_rest < 3)) {
			printf("��ǰ�� : %-10s / ��� : %-7s / �ǸŰ��� : %-7s / ������� : %-12s\n", list_s[h].name, list_s[h].rest, list_s[h].price, list_s[h].exp);
			count++;
		}
	}
	if (count == 0) {
		printf("��� 3�� �����̰ų�\n��������� 3�� ���Ϸ� ���� ��ǰ�� �����ϴ�.\n");
	}
}

void SearchMember() { // ȸ�� �˻� �Լ� ���� 
	system("cls");
	mainlogo();
	char snumber[20];
	int count = 0;
	int h;
	printf("           ����ȭ��ȣ �˻� �޴���\n");
	printf("==============================================\n");
	printf(" ã�� ��ȭ��ȣ �Է� : ");
	scanf("%s", snumber);
	fflush(stdin);
	for (h = 0; h < x; h++) {
		if (strcmp(list[h].number, snumber) == 0) {
			count++;
			printf("�̸� : %s / ���ϸ��� : %s / ��ȭ��ȣ : %s\n", list[h].name, list[h].point, list[h].number);
		}
	}
	if (count == 0) {
		printf(" ã�� �̸��� �����ϴ�.\n");
	}
}

void PrintStock() { //��ü ��� ��� ��� �Լ� ���� 
	system("cls");
	mainlogo();
	int c = 0;

	printf("                   ����ü ��� ��� �޴���\n");
	printf("=================================================================\n");
	printf("%-10s %-7s %-7s %-12s\n", "��ǰ��", "���", "�ǸŰ���", "�������");
	for (c = 0; c < s; c++) {
		if (list_s[c].name[0] != 0) {
			printf("%-10s %-7s %-7s %-12s\n", list_s[c].name, list_s[c].rest, list_s[c].price, list_s[c].exp);
		}
	}
}

void PrintMember() { // ȸ�� ��� �Լ� ���� 
	system("cls");
	mainlogo();
	int c = 0;

	printf("             ��ȸ�� ��� �޴���\n");
	printf("==============================================\n");
	printf("%-6s %-6s %-11s\n", "�̸�", "���ϸ���", "��ȭ��ȣ");
	for (c = 0; c < x; c++) {
		if (list[c].name[0] != 0) {
			printf("%-6s %-6s %-11s\n", list[c].name, list[c].point, list[c].number);
		}
	}
}

void ExitProg() { //���� �Լ� ���� 
	exit(0);
}

int Stock_LoadFile() {   //�ʱ⿡ ��� ���� �ҷ����� 
	FILE* fp1 = NULL;
	errno_t errCheck = fopen_s(&fp1, "Stock.txt", "rb");

	if (errCheck == 2) {
		printf(" ���� ��� ���� ������ ���� \n");
		return 1;
	}
	else if (errCheck != 0) {
		printf(" ���� ���� ���� \n");
		return 0;
	}
	char Stock_szBuffer[100] = { 0, };
	int S_iCount = 0;   //���ϳ��̾ƴҶ����� ���پ� szBuffer �� ���ͼ� 

	while (fscanf(fp1, "%s", Stock_szBuffer) != EOF) {
		switch (S_iCount % 4) {
		case 0:
			strcpy(list_s[s].name, Stock_szBuffer);
			break;
		case 1:
			strcpy(list_s[s].rest, Stock_szBuffer);
			break;
		case 2:
			strcpy(list_s[s].price, Stock_szBuffer);
			break;
		case 3:
			strcpy(list_s[s].exp, Stock_szBuffer);
			s++;
			break;
		}
		S_iCount++;
	}
	fclose(fp1);

	return 1;
}
int LoadFile() {   //�ʱ⿡ ���� �ҷ����� 
	FILE* fp = NULL;
	errno_t errCheck = fopen_s(&fp, "Member.txt", "rb");

	if (errCheck == 2) {
		printf(" ���� ȸ�� ���� ������ �����ϴ�. \n");
		return 1;
	}
	else if (errCheck != 0) {
		printf("���� ���� �����߽��ϴ�. \n");
		return 0;
	}
	char szBuffer[100] = { 0, };
	int iCount = 0;   //���ϳ��̾ƴҶ����� ���پ� szBuffer �� ���ͼ� 

	while (fscanf(fp, "%s", szBuffer) != EOF) {
		switch (iCount % 3) {
		case 0:
			strcpy(list[x].name, szBuffer);
			break;
		case 1:
			strcpy(list[x].point, szBuffer);
			break;
		case 2:
			strcpy(list[x].number, szBuffer);
			x++;
			break;
		}
		iCount++;
	}
	fclose(fp);

	return 1;
}
//��� �������� 
void Stock_SaveFile() {
	FILE* fp1 = NULL;
	errno_t errCheck = fopen_s(&fp1, "Stock.txt", "wb");
	if (errCheck != 0) {
		printf("���� ���� �����߽��ϴ�. \n");
		return;
	}

	char szBuffer[100] = { 0, };  //s ���� ���鼭 ���Ͽ� ���� 
	for (int i = 0; i < s; i++) {
		fprintf(fp1, "%s\r\n", list_s[i].name);
		fprintf(fp1, "%s\r\n", list_s[i].rest);
		fprintf(fp1, "%s\r\n", list_s[i].price);
		fprintf(fp1, "%s\r\n", list_s[i].exp);
	}
	fclose(fp1);
}

//�������� 
void SaveFile() {
	FILE* fp = NULL;
	errno_t errCheck = fopen_s(&fp, "Member.txt", "wb");
	if (errCheck != 0) {
		printf("���� ���� �����߽��ϴ�. \n");
		return;
	}

	char szBuffer[100] = { 0, };  //x ���� ���鼭 ���Ͽ� ���� 
	for (int i = 0; i < x; i++) {
		fprintf(fp, "%s\r\n", list[i].name);
		fprintf(fp, "%s\r\n", list[i].point);
		fprintf(fp, "%s\r\n", list[i].number);
	}
	fclose(fp);
}
// ���� ��¥ ���������� �ٲ��ִ� �Լ�
int today() {
	char* mm = NULL;
	char* dd = NULL;
	char* yy = NULL;
	char date[9];
	int m, d, y;

	_strdate(date);

	mm = strtok(date, "/");
	if (mm != NULL)
		dd = strtok(NULL, "/");
	if (dd != NULL)
		yy = strtok(NULL, "/");
	y = atoi(yy); m = atoi(mm); d = atoi(dd); //atoi �Լ��� ���ڸ� ���ڷ� �ٲ��ִ� �Լ�.
	return (2000 + y) * 10000 + m * 100 + d;//20160715�� return����
}
// ���� �ΰ� �Լ�
void mainlogo() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F6);
	printf("\t       ������ \n");
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F4);
	printf("\t      ��"); printf("�ڡڡڡ�"); printf("��\n");
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F3);
	printf("\t      ��"); printf("��    ��"); printf("��\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F5);
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F6);
	printf("\t      ��"); printf("     ��"); printf(" ��\n");
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F2);
	printf("\t      ��"); printf("ELE��VEN"); printf("��\n");
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F9);
	printf("\t      ��"); printf("  ��  "); printf("  ��\n");
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F6);
	printf("\t      ��"); printf(" ��  "); printf("   ��\n");
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F1);
	printf("\t       ������ \n\n");
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F4);
}
//ó�� �α���
void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
// ���� �α��� �Լ�
void main_login() {
	mainlogo();
	int i, s, x = 10, y = 10;
	gotoxy(5, y); printf("��");
	// �� ��ȣ�� �Ŀ� ����Ʈ���� �����ؼ� ��� ����  
	gotoxy(5, y + 11); printf("��");
	for (i = 7; i <= 34; i += 2)
	{
		gotoxy(i, y);
		printf("��");
		gotoxy(i, y + 11);
		printf("��");
	}
	gotoxy(x + 25, y); printf("��");
	gotoxy(x + 25, y + 11); printf("��");
	for (i = y + 1; i <= y + 10; i++)
	{
		gotoxy(5, i);
		printf("��");
		gotoxy(5 + 30, i);
		printf("��");
	}
	gotoxy(9, 11); printf("�ڡڡ�Ceven eleven�ڡڡ�");
	gotoxy(12, 14); printf("1. ��  ��   �� ");
	gotoxy(12, 15); printf("2. ȸ �� �� �� ");
	gotoxy(12, 16); printf("3. ��       ��  ");
	gotoxy(9, 20); printf("��ȣ�� �����ϼ��� (   )\b\b\b");
	scanf_s("%d", &s);
	if (s == 1)
		login();
	else
		if (s == 2)
			UserRegister();
		else
			exit(0);
}
//���� �α��� �����б�
void LoadUserData()
{

	int index = 0;
	FILE* p_file = fopen("user.txt", "r");
	if (p_file != NULL) {
		fread(&g_user_count, sizeof(int), 1, p_file);
		for (index = 0; index < g_user_count; index++) {
			fread(g_user_data + index, sizeof(UI), 1, p_file);
		}
		fclose(p_file);
	}
}
//���� �α��� ��������
void SaveUserData() {
	int index = 0;
	FILE* p_file = fopen("user.txt", "wb");
	if (p_file != NULL) {
		fwrite(&g_user_count, sizeof(int), 1, p_file);
		for (index = 0; index < g_user_count; index++) {
			fwrite(g_user_data + index, sizeof(UI), 1, p_file);
		}
		fclose(p_file);
	}
}
//���� ��й�ȣ 
void GetPassword(char parm_password[]) {
	int input = 0, index = 0;
	while (input != 13) {
		input = _getch();
		if (input == 13) parm_password[index] = 0;
		else {
			printf("*");
			parm_password[index++] = input;
		}
	}
	printf("\n");
}
//���� ȸ������ 
void UserRegister() {
	system("cls");
	mainlogo();
	printf("\n��ȸ�� ����� �Ͻ÷��� ���� ������ �Է�\n");

	printf("1. Input ID:");
	scanf("%s", g_user_data[g_user_count].id);
	fflush(stdin);
	printf("\n");
	printf("2. Input Password:");
	scanf("%s", g_user_data[g_user_count].password);
	fflush(stdin);
	printf("\n");
	printf("3. Input Name:");
	scanf("%s", g_user_data[g_user_count].name);
	fflush(stdin);
	printf("\n");
	printf("4. Input Address:");
	scanf("%s", g_user_data[g_user_count].address);
	fflush(stdin);
	printf("\n");
	printf("5. Input Phone Number:");
	scanf("%s", g_user_data[g_user_count].phone);
	fflush(stdin);
	g_user_count++;
	printf("\nȸ���� �ǽŰ� ���ϵ帳�ϴ�.. \n");
}
//�α��� �Լ�
void login() {
	int index = 0, input = 0;
	char id[16], password[16], success_login = 0;
	LoadUserData();
	while (!success_login) {
		system("cls");
		mainlogo();
		printf("\n              �طα��Ρ�\n");
		printf("==============================================\n");
		printf("  Input ID: ");
		scanf("%s", id);
		fflush(stdin);
		printf("\n  Input Password: ");
		GetPassword(password);
		for (index = 0; index < g_user_count; index++) {
			if (!strcmp(g_user_data[index].id, id)) {
				if (!strcmp(g_user_data[index].password, password)) {
					success_login = 1;
					printf("==============================================\n");
					printf("\n���������� �α��� �߽��ϴ�. ^^; \n");
				}
				else printf("��ȣ�� Ʋ�Ƚ��ϴ�. �Ѥ�!\n\n");
				break;
			}
		}
		if (index == g_user_count) {
			printf("\n�Է��Ͻ� ID�� ����� �Ǿ����� �ʽ��ϴ�. ����Ͻðڽ��ϱ�? ( y / n ): ");
			input = _getche();
			if (input == 'y' || input == 'Y') UserRegister();
			else printf("�ٽ� �Է��ϼ���...\n\n");
		}
		SaveUserData();
	}
}