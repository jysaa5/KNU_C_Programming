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

#include <stdio.h> //헤더파일 stdio.h포함 
#include <string.h>//헤더파일 string.h포함
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <time.h>
#include <conio.h>
#include "TeamProject.h"


//- 파일명은 Member.txt , Stock.txt
//- fprintf()와 fscanf() 함수를 이용하여 Member.txt , Stock.txt로 부터 읽고, 쓰기 기능 
//- 즉, 프로그램 시작할 때, 파일로부터 DB를 읽어오고, 프로그램 종료시 파일에 DB를 저장. 

void finish() {   //메뉴로 돌아가기 위한 함수 정의
	char key;
	printf("=============================================\n");
	printf(" 이전 화면으로 돌아가시려면 아무 키나 입력하시오  \n");
	scanf(" %c", &key);
	fflush(stdin);
	system("cls");
}

void PrintMenu() {  //메뉴 함수 정의 
	system("cls");
	mainlogo();
	printf("                Cven eleven                  \n");
	printf("=============================================\n");
	printf(" 1. 회원 관리\n");
	printf(" 2. 마일리지 관리\n");
	printf(" 3. 재고 관리\n");
	printf(" 4. 종료(Exit)\n");
	printf("=============================================\n");
	printf(" 어떤 업무를 보시겠습니까?\n");
}

void MPrintMenu() { // 회원 가입 메뉴 함수 정의 
	system("cls");
	mainlogo();
	printf("              회원관리 프로그램              \n");
	printf("=============================================\n");
	printf(" 1. 회원가입(Insert)\n");
	printf(" 2. 회원찾기(Search)\n");
	printf(" 3. 회원삭제(Delete)\n");
	printf(" 4. 회원출력(Print)\n");
	printf(" 5. 저장(Save)\n");
	printf(" 6. 종료(Exit)\n");
	printf(" 7. 처음으로\n");
	printf("=============================================\n");
	printf("  ※원하시는 업무의 번호를 입력 :   ");
}

void PPrintMenu() { // 마일리지 관리 메뉴 함수 정의
	system("cls");
	mainlogo();
	printf("              마일리지 관리 프로그램              \n");
	printf("=============================================\n");
	printf(" 1. 마일리지 추가\n");
	printf(" 2. 마일리지 삭감\n");
	printf(" 3. 마일리지 조회\n");
	printf(" 4. 저장(Save)\n");
	printf(" 5. 종료(Exit)\n");
	printf(" 6. 처음으로\n");
	printf("=============================================\n");
	printf("  ※원하시는 업무의 번호를 입력 :   ");
}

void SPrintMenu() { // 마일리지 관리 메뉴 함수 정의
	mainlogo();
	printf("           ※재고 관리 업무선택※ \n");
	printf("==============================================\n");
	printf("  1. 재고 등록\n");
	printf("  2. 재고 추가\n");
	printf("  3. 재고 감소\n");
	printf("  4. 주문해야할 물품\n");
	printf("  5. 전체 재고 목록\n");
	printf("  6. 저장\n");
	printf("  7. 종료 \n");
	printf("  8. 처음으로 \n");
	printf("==============================================\n");
	printf("  ※원하시는 업무의 번호를 입력 :   ");
}

void InsertSupply() { // 재고등록
	system("cls");
	mainlogo();
	printf("             ※재고 등록 메뉴※\n");
	printf("==============================================\n");
	printf(" 제품명 : ");
	scanf("%s", list_s[s].name);
	fflush(stdin);
	printf(" 추가량 : ");
	scanf("%s", list_s[s].rest);
	fflush(stdin);
	printf(" 판매 가격(원) : ");
	scanf("%s", list_s[s].price);
	fflush(stdin);
	printf(" 유통기한(yyyymmdd) : ");
	scanf("%s", list_s[s].exp);
	fflush(stdin);
	printf("♣정상적으로 저장♣\n");
	s++;
}

void InsertMember() { //회원 등록 함수 정의 
	system("cls");
	mainlogo();
	printf("             ※회원 등록 메뉴※\n");
	printf("==============================================\n");
	printf(" 이름 입력 : ");
	scanf("%s", list[x].name);
	fflush(stdin);
	printf(" 마일리지 입력 : ");
	scanf("%s", list[x].point);
	fflush(stdin);
	printf(" 전화번호 입력 : ");
	scanf("%s", list[x].number);
	fflush(stdin);
	printf("♣정상적으로 저장♣\n");
	x++;
}

void DeleteMember() { //회원 삭제 함수 정의 
	system("cls");
	mainlogo();
	char del[TEL_LEN];

	int count = 0;
	int n, i;

	printf("             ※회원 삭제 메뉴※\n");
	printf("==============================================\n");
	printf("전화번호 입력 : ");
	scanf("%s", del);
	fflush(stdin);

	for (n = 0; n < x; n++) {
		if (strcmp(list[n].number, del) == 0) { //strcmp 비교하는 함수 
			count++;
			printf(" 정상적으로 삭제되었습니다\n");
			for (i = n; i < x; i++)
				list[i] = list[i + 1];
			x--;
		}
	}
	if (count == 0) {
		printf(" 찾는 이름이 없습니다.\n");
	}
}

void AddSupply() { // 재고량 추가 함수 정의 
	system("cls");
	mainlogo();
	char sname[20];
	char s_num[20];
	int count = 0;
	int h;
	int addnum = 0, befnum = 0, complenum = 0;
	printf("            ※재고 추가 메뉴※\n");
	printf("==============================================\n\n");
	printf("추가할 제품명을 입력 : ");
	scanf("%s", sname);
	fflush(stdin);
	printf("추가할 공급량을 입력 : ");
	scanf("%s", s_num);
	fflush(stdin);
	for (h = 0; h < s; h++) {
		if (strcmp(list_s[h].name, sname) == 0) {
			count++;
			addnum = atoi(s_num);
			befnum = atoi(list_s[h].rest);
			complenum = addnum + befnum;
			snprintf(list_s[h].rest, Stock_MAX, "%d", complenum);
			printf(" 재고가 추가되었습니다.: ");
			printf("제품명 : %s / 재고량 : %s / 판매가격 : %s / 유통기한 : %s\n", list_s[h].name, list_s[h].rest, list_s[h].price, list_s[h].exp);
		}
	}
	if (count == 0) {
		printf(" 찾는 제품이 없습니다.\n등록해주십쇼~!\n");
	}
}

void AddPoint() { // 마일리지 추가 함수 정의 
	system("cls");
	mainlogo();
	char snumber[20];
	char spoint[20];
	int count = 0;
	int h;
	int addpoint = 0, befpoint = 0, complepoint = 0;
	printf("           ※마일리지 추가 메뉴※\n");
	printf("==============================================\n");
	printf("회원님의 전화번호 입력 : ");
	scanf("%s", snumber);
	fflush(stdin);
	printf("추가할 마일리지 입력 : ");
	scanf("%s", spoint);
	fflush(stdin);
	for (h = 0; h < x; h++) {
		if (strcmp(list[h].number, snumber) == 0) {
			count++;
			addpoint = atoi(spoint);
			befpoint = atoi(list[h].point);
			complepoint = addpoint + befpoint;
			snprintf(list[h].point, 30, "%d", complepoint);
			printf(" 마일리지가 추가되었습니다.: ");
			printf("이름 : %s / 마일리지 : %s / 전화번호 : %s\n", list[h].name, list[h].point, list[h].number);
		}
	}
	if (count == 0) {
		printf(" 찾는 이름이 없습니다.\n");
	}
}

void SubSupply() { // 재고량 감소 함수 정의 
	system("cls");
	mainlogo();
	char sname[20];
	int s_num = 0;
	int count = 0;
	int h;
	int befnum = 0, complenum = 0;
	printf("            ※재고 삭감 메뉴※\n");
	printf("==============================================\n\n");
	printf("삭감할 제품명 입력 : ");
	scanf("%s", sname);
	fflush(stdin);
	printf("삭감할 재고량 입력 : ");
	scanf("%d", &s_num);
	fflush(stdin);
	for (h = 0; h < s; h++) {
		if (strcmp(list_s[h].name, sname) == 0) {
			count++;
			befnum = atoi(list_s[h].rest);
			if (befnum <= 0) {
				printf(" 저장된 재고가 없습니다.\n 재고 등록부터 하세요.\n");
			}
			else {
				complenum = befnum - s_num;
				snprintf(list_s[h].rest, Stock_MAX, "%d", complenum);
				printf(" 재고가 삭감되었습니다.: ");
				printf("제품명 : %s / 재고량 : %s / 판매가격 : %s / 유통기한 : %s\n", list_s[h].name, list_s[h].rest, list_s[h].price, list_s[h].exp);
			}
		}
	}
	if (count == 0) {
		printf(" 찾는 제품이 없습니다.\n등록해주십쇼~!\n");
	}
}

void SubPoint() { // 마일리지 삭감 함수 정의 
	system("cls");
	mainlogo();
	char snumber[20];
	char spoint[20];
	int count = 0;
	int h;
	int addpoint = 0, befpoint = 0, complepoint = 0;
	printf("           ※마일리지 삭감 메뉴※\n");
	printf("==============================================\n");
	printf(" 회원님의 전화번호 입력 : ");
	scanf("%s", snumber);
	fflush(stdin);
	printf(" 삭감할 마일리지 입력 : ");
	scanf("%s", spoint);
	fflush(stdin);
	for (h = 0; h < x; h++) {
		if (strcmp(list[h].number, snumber) == 0) {
			count++;
			addpoint = atoi(spoint);
			befpoint = atoi(list[h].point);
			complepoint = befpoint - addpoint;
			snprintf(list[h].point, 30, "%d", complepoint);
			printf(" 마일리지가 삭감되었습니다.: ");
			printf("이름 : %s / 마일리지 : %s / 전화번호 : %s\n", list[h].name, list[h].point, list[h].number);
		}
	}
	if (count == 0) {
		printf(" 찾는 이름이 없습니다.\n");
	}
}

void SearchPoint() { // 마일리지 조회 함수 정의 
	system("cls");
	mainlogo();
	char snumber[20];
	int count = 0;
	int h;
	printf("           ※마일리지 조회 메뉴※\n");
	printf("==============================================\n");
	printf(" 찾는 전화번호 입력 : ");
	scanf("%s", snumber);
	fflush(stdin);
	for (h = 0; h < x; h++) {
		if (strcmp(list[h].number, snumber) == 0) {
			count++;
			printf("이름 : %s / 마일리지 : %s / 전화번호 : %s\n", list[h].name, list[h].point, list[h].number);
		}
	}
	if (count == 0) {
		printf(" 찾는 이름이 없습니다.\n");
	}
}

void SearchSupply() { // 재고 검색 함수 정의 
	int count = 0;
	int h;
	int test_exp = 0;
	int test_rest = 0;
	printf("           ※재고 부족 및 유통기한 임박 물품 검색 메뉴※\n");
	printf("===================================================================\n");
	for (h = 0; h < s; h++) {
		int test_exp = atoi(list_s[h].exp);
		int test_rest = atoi(list_s[h].rest);
		if ((test_exp - today() < 3) || (test_rest < 3)) {
			printf("제품명 : %-10s / 재고량 : %-7s / 판매가격 : %-7s / 유통기한 : %-12s\n", list_s[h].name, list_s[h].rest, list_s[h].price, list_s[h].exp);
			count++;
		}
	}
	if (count == 0) {
		printf("재고가 3개 이하이거나\n유통기한이 3일 이하로 남은 제품이 없습니다.\n");
	}
}

void SearchMember() { // 회원 검색 함수 정의 
	system("cls");
	mainlogo();
	char snumber[20];
	int count = 0;
	int h;
	printf("           ※전화번호 검색 메뉴※\n");
	printf("==============================================\n");
	printf(" 찾는 전화번호 입력 : ");
	scanf("%s", snumber);
	fflush(stdin);
	for (h = 0; h < x; h++) {
		if (strcmp(list[h].number, snumber) == 0) {
			count++;
			printf("이름 : %s / 마일리지 : %s / 전화번호 : %s\n", list[h].name, list[h].point, list[h].number);
		}
	}
	if (count == 0) {
		printf(" 찾는 이름이 없습니다.\n");
	}
}

void PrintStock() { //전체 재고 목록 출력 함수 정의 
	system("cls");
	mainlogo();
	int c = 0;

	printf("                   ※전체 재고 목록 메뉴※\n");
	printf("=================================================================\n");
	printf("%-10s %-7s %-7s %-12s\n", "제품명", "재고량", "판매가격", "유통기한");
	for (c = 0; c < s; c++) {
		if (list_s[c].name[0] != 0) {
			printf("%-10s %-7s %-7s %-12s\n", list_s[c].name, list_s[c].rest, list_s[c].price, list_s[c].exp);
		}
	}
}

void PrintMember() { // 회원 출력 함수 정의 
	system("cls");
	mainlogo();
	int c = 0;

	printf("             ※회원 출력 메뉴※\n");
	printf("==============================================\n");
	printf("%-6s %-6s %-11s\n", "이름", "마일리지", "전화번호");
	for (c = 0; c < x; c++) {
		if (list[c].name[0] != 0) {
			printf("%-6s %-6s %-11s\n", list[c].name, list[c].point, list[c].number);
		}
	}
}

void ExitProg() { //종료 함수 정의 
	exit(0);
}

int Stock_LoadFile() {   //초기에 재고 파일 불러오기 
	FILE* fp1 = NULL;
	errno_t errCheck = fopen_s(&fp1, "Stock.txt", "rb");

	if (errCheck == 2) {
		printf(" 기존 재고 저장 데이터 없음 \n");
		return 1;
	}
	else if (errCheck != 0) {
		printf(" 파일 오픈 실패 \n");
		return 0;
	}
	char Stock_szBuffer[100] = { 0, };
	int S_iCount = 0;   //파일끝이아닐때까지 한줄씩 szBuffer 에 얻어와서 

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
int LoadFile() {   //초기에 파일 불러오기 
	FILE* fp = NULL;
	errno_t errCheck = fopen_s(&fp, "Member.txt", "rb");

	if (errCheck == 2) {
		printf(" 기존 회원 저장 데이터 없습니다. \n");
		return 1;
	}
	else if (errCheck != 0) {
		printf("파일 오픈 실패했습니다. \n");
		return 0;
	}
	char szBuffer[100] = { 0, };
	int iCount = 0;   //파일끝이아닐때까지 한줄씩 szBuffer 에 얻어와서 

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
//재고 파일저장 
void Stock_SaveFile() {
	FILE* fp1 = NULL;
	errno_t errCheck = fopen_s(&fp1, "Stock.txt", "wb");
	if (errCheck != 0) {
		printf("파일 오픈 실패했습니다. \n");
		return;
	}

	char szBuffer[100] = { 0, };  //s 까지 돌면서 파일에 쓰기 
	for (int i = 0; i < s; i++) {
		fprintf(fp1, "%s\r\n", list_s[i].name);
		fprintf(fp1, "%s\r\n", list_s[i].rest);
		fprintf(fp1, "%s\r\n", list_s[i].price);
		fprintf(fp1, "%s\r\n", list_s[i].exp);
	}
	fclose(fp1);
}

//파일저장 
void SaveFile() {
	FILE* fp = NULL;
	errno_t errCheck = fopen_s(&fp, "Member.txt", "wb");
	if (errCheck != 0) {
		printf("파일 오픈 실패했습니다. \n");
		return;
	}

	char szBuffer[100] = { 0, };  //x 까지 돌면서 파일에 쓰기 
	for (int i = 0; i < x; i++) {
		fprintf(fp, "%s\r\n", list[i].name);
		fprintf(fp, "%s\r\n", list[i].point);
		fprintf(fp, "%s\r\n", list[i].number);
	}
	fclose(fp);
}
// 오늘 날짜 정수형으로 바꿔주는 함수
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
	y = atoi(yy); m = atoi(mm); d = atoi(dd); //atoi 함수는 문자를 숫자로 바꿔주는 함수.
	return (2000 + y) * 10000 + m * 100 + d;//20160715를 return해줌
}
// 메인 로고 함수
void mainlogo() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F6);
	printf("\t       〓〓〓〓〓 \n");
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F4);
	printf("\t      Ⅱ"); printf("★★★★"); printf("Ⅱ\n");
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F3);
	printf("\t      Ⅱ"); printf("★    ★"); printf("Ⅱ\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F5);
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F6);
	printf("\t      Ⅱ"); printf("     ★"); printf(" Ⅱ\n");
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F2);
	printf("\t      Ⅱ"); printf("ELE★VEN"); printf("Ⅱ\n");
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F9);
	printf("\t      Ⅱ"); printf("  ★  "); printf("  Ⅱ\n");
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F6);
	printf("\t      Ⅱ"); printf(" ★  "); printf("   Ⅱ\n");
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F1);
	printf("\t       〓〓〓〓〓 \n\n");
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F4);
}
//처음 로그인
void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
// 메인 로그인 함수
void main_login() {
	mainlogo();
	int i, s, x = 10, y = 10;
	gotoxy(5, y); printf("┏");
	// ┏ 기호는 파워 포인트에서 복사해서 사용 가능  
	gotoxy(5, y + 11); printf("┗");
	for (i = 7; i <= 34; i += 2)
	{
		gotoxy(i, y);
		printf("━");
		gotoxy(i, y + 11);
		printf("━");
	}
	gotoxy(x + 25, y); printf("┓");
	gotoxy(x + 25, y + 11); printf("┛");
	for (i = y + 1; i <= y + 10; i++)
	{
		gotoxy(5, i);
		printf("┃");
		gotoxy(5 + 30, i);
		printf("┃");
	}
	gotoxy(9, 11); printf("★★★Ceven eleven★★★");
	gotoxy(12, 14); printf("1. 로  그   인 ");
	gotoxy(12, 15); printf("2. 회 원 가 입 ");
	gotoxy(12, 16); printf("3. 종       료  ");
	gotoxy(9, 20); printf("번호를 선택하세요 (   )\b\b\b");
	scanf_s("%d", &s);
	if (s == 1)
		login();
	else
		if (s == 2)
			UserRegister();
		else
			exit(0);
}
//점장 로그인 파일읽기
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
//점장 로그인 파일저장
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
//점장 비밀번호 
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
//점장 회원가입 
void UserRegister() {
	system("cls");
	mainlogo();
	printf("\n※회원 등록을 하시려면 다음 정보를 입력\n");

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
	printf("\n회원이 되신걸 축하드립니다.. \n");
}
//로그인 함수
void login() {
	int index = 0, input = 0;
	char id[16], password[16], success_login = 0;
	LoadUserData();
	while (!success_login) {
		system("cls");
		mainlogo();
		printf("\n              ※로그인※\n");
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
					printf("\n성공적으로 로그인 했습니다. ^^; \n");
				}
				else printf("암호가 틀렸습니다. ㅡㅡ!\n\n");
				break;
			}
		}
		if (index == g_user_count) {
			printf("\n입력하신 ID는 등록이 되어있지 않습니다. 등록하시겠습니까? ( y / n ): ");
			input = _getche();
			if (input == 'y' || input == 'Y') UserRegister();
			else printf("다시 입력하세요...\n\n");
		}
		SaveUserData();
	}
}