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


int main(void) {
	system("mode con:cols=120 lines=30");
	system("title CVEN ELEVEN MANAGEMENT PROGRAM(편의점 관리 프로그램(회원/마일리지/재고))");
	//초기에 전역 배열 초기화
	for (int i = 0; i < MAX; i++) {
		memset(list[i].name, 0, NAME_LEN);
		memset(list[i].point, 0, POINT_LEN);
		memset(list[i].number, 0, TEL_LEN);
	}
	for (int j = 0; j < MAX; j++) {
		memset(list_s[j].name, 0, Stock_MAX);
		memset(list_s[j].rest, 0, Stock_MAX);
		memset(list_s[j].price, 0, Stock_MAX);
		memset(list_s[j].exp, 0, Stock_MAX);
	}


	//파일에서 데이터 불러와서 배열에 저장 
	if (!LoadFile()) return 0;
	if (!Stock_LoadFile()) return 0;

	// 유통기한이 임박 했거나 재고가 3개 이하로 남아있을 때 경고 창 뜨게 했습니다.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00FC);
	printf("■              ■    ■■      ■■■■■  ■      ■  ■■■  ■      ■     ■■■     ■■   ■■  \n");
	Sleep(100);
	printf("■      ■      ■   ■  ■     ■      ■  ■■    ■    ■    ■■    ■   ■      ■   ■■   ■■  \n");
	Sleep(100);
	printf(" ■    ■■    ■   ■    ■    ■■■■■  ■  ■  ■    ■    ■  ■  ■  ■            ■■   ■■  \n");
	Sleep(100);
	printf("  ■  ■  ■  ■   ■■■■■   ■    ■    ■   ■ ■    ■    ■   ■ ■  ■   ■■■   ■■   ■■  \n");
	Sleep(100);
	printf("   ■■    ■■   ■        ■  ■      ■  ■    ■■    ■    ■    ■■  ■     ■                  \n");
	Sleep(100);
	printf("    ■      ■    ■        ■  ■      ■  ■      ■  ■■■  ■      ■   ■■■■     ■■   ■■  \n");
	SearchSupply();
	Sleep(1500);
	system("cls");
	main_login();
	printf("\n\n잠시만 기다리면 다음 화면으로 넘어갑니다.!");
	Sleep(1500);
	int menu = 0, menu1 = 0, menu2 = 0, menu3 = 0;
start:

	do {
		PrintMenu();

		scanf("%d", &menu);
		fflush(stdin);

		switch (menu) {
		case 1: // 회원관리 항목
			while (menu1 != 6) {
				system("cls");
				MPrintMenu();
				scanf("%d", &menu1);
				fflush(stdin);

				switch (menu1) {
				case 1://회원 가입
					InsertMember();
					finish();
					break;
				case 2://회원 조회
					SearchMember();
					finish();
					break;
				case 3://회원 삭제
					DeleteMember();
					finish();
					break;
				case 4://회원 출력
					PrintMember();
					finish();
					break;
				case 5://저장
					SaveFile();
					break;
				case 6://종료
					printf("※프로그램을 종료합니다.※ \n");
					ExitProg();
					break;
				case 7://처음으로
					goto start;
					break;
				default: //case문의 경우의 수 이외의 값이 발생할때 실행 
					printf("다시입력하세요[1-7]\n"); break;
				}
			}
			break;
		case 2: // 마일리지 관리 항목
			while (menu2 != 5) {
				system("cls");
				PPrintMenu();
				scanf("%d", &menu2);
				fflush(stdin);

				switch (menu2) {
				case 1: //마일리지 추가
					AddPoint();
					finish();
					break;
				case 2: //마일리지 삭감
					SubPoint();
					finish();
					break;
				case 3: //마일리지 조회
					SearchPoint();
					finish();
					break;
				case 4://저장
					SaveFile();
					break;
				case 5://종료
					printf("※프로그램을 종료합니다.※ \n");
					ExitProg();
					break;
				case 6://처음으로
					goto start;
					break;
				default: //case문의 경우의 수 이외의 값이 발생할때 실행 
					printf("다시입력하세요[1-6]\n");
				}
			}
			break;
		case 3:// 재고 관리
			while (menu3 != 7) {
				system("cls");
				SPrintMenu();
				scanf("%d", &menu3);
				fflush(stdin);

				switch (menu3) {
				case 1:
					InsertSupply();     //재고 등록
					finish();
					break;
				case 2:
					AddSupply();     //재고 추가
					finish();
					break;
				case 3:
					SubSupply();      //재고 감소
					finish();
					break;
				case 4:
					system("cls");
					mainlogo();
					SearchSupply();     //3일 이내의 유통기한과 3개 이하의 재고량을
					finish();         //검색해서 주문해야할 물품만.               
					break;
				case 5:
					PrintStock();     //재고 목록을 검색하기 위한 함수 호출
					finish();
					break;
				case 6:
					Stock_SaveFile(); //저장
					break;
				case 7:
					printf("※프로그램을 종료합니다.※ \n");
					ExitProg();
					break;
				case 8:
					goto start;
					break;
				default:
					printf("다시입력하세요[1-8]\n");
				}
			}
			break;
		case 4:
			printf("※프로그램을 종료합니다.※ \n");
			ExitProg();
			break; //종료 함수 사용
		default: //case문의 경우의 수 이외의 값이 발생할때 실행 
			printf("다시입력하세요[1-4]\n");
		}
	} while (menu != 4);
	return 0;
}