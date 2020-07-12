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


int main(void) {
	system("mode con:cols=120 lines=30");
	system("title CVEN ELEVEN MANAGEMENT PROGRAM(������ ���� ���α׷�(ȸ��/���ϸ���/���))");
	//�ʱ⿡ ���� �迭 �ʱ�ȭ
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


	//���Ͽ��� ������ �ҷ��ͼ� �迭�� ���� 
	if (!LoadFile()) return 0;
	if (!Stock_LoadFile()) return 0;

	// ��������� �ӹ� �߰ų� ��� 3�� ���Ϸ� �������� �� ��� â �߰� �߽��ϴ�.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00FC);
	printf("��              ��    ���      ������  ��      ��  ����  ��      ��     ����     ���   ���  \n");
	Sleep(100);
	printf("��      ��      ��   ��  ��     ��      ��  ���    ��    ��    ���    ��   ��      ��   ���   ���  \n");
	Sleep(100);
	printf(" ��    ���    ��   ��    ��    ������  ��  ��  ��    ��    ��  ��  ��  ��            ���   ���  \n");
	Sleep(100);
	printf("  ��  ��  ��  ��   ������   ��    ��    ��   �� ��    ��    ��   �� ��  ��   ����   ���   ���  \n");
	Sleep(100);
	printf("   ���    ���   ��        ��  ��      ��  ��    ���    ��    ��    ���  ��     ��                  \n");
	Sleep(100);
	printf("    ��      ��    ��        ��  ��      ��  ��      ��  ����  ��      ��   �����     ���   ���  \n");
	SearchSupply();
	Sleep(1500);
	system("cls");
	main_login();
	printf("\n\n��ø� ��ٸ��� ���� ȭ������ �Ѿ�ϴ�.!");
	Sleep(1500);
	int menu = 0, menu1 = 0, menu2 = 0, menu3 = 0;
start:

	do {
		PrintMenu();

		scanf("%d", &menu);
		fflush(stdin);

		switch (menu) {
		case 1: // ȸ������ �׸�
			while (menu1 != 6) {
				system("cls");
				MPrintMenu();
				scanf("%d", &menu1);
				fflush(stdin);

				switch (menu1) {
				case 1://ȸ�� ����
					InsertMember();
					finish();
					break;
				case 2://ȸ�� ��ȸ
					SearchMember();
					finish();
					break;
				case 3://ȸ�� ����
					DeleteMember();
					finish();
					break;
				case 4://ȸ�� ���
					PrintMember();
					finish();
					break;
				case 5://����
					SaveFile();
					break;
				case 6://����
					printf("�����α׷��� �����մϴ�.�� \n");
					ExitProg();
					break;
				case 7://ó������
					goto start;
					break;
				default: //case���� ����� �� �̿��� ���� �߻��Ҷ� ���� 
					printf("�ٽ��Է��ϼ���[1-7]\n"); break;
				}
			}
			break;
		case 2: // ���ϸ��� ���� �׸�
			while (menu2 != 5) {
				system("cls");
				PPrintMenu();
				scanf("%d", &menu2);
				fflush(stdin);

				switch (menu2) {
				case 1: //���ϸ��� �߰�
					AddPoint();
					finish();
					break;
				case 2: //���ϸ��� �谨
					SubPoint();
					finish();
					break;
				case 3: //���ϸ��� ��ȸ
					SearchPoint();
					finish();
					break;
				case 4://����
					SaveFile();
					break;
				case 5://����
					printf("�����α׷��� �����մϴ�.�� \n");
					ExitProg();
					break;
				case 6://ó������
					goto start;
					break;
				default: //case���� ����� �� �̿��� ���� �߻��Ҷ� ���� 
					printf("�ٽ��Է��ϼ���[1-6]\n");
				}
			}
			break;
		case 3:// ��� ����
			while (menu3 != 7) {
				system("cls");
				SPrintMenu();
				scanf("%d", &menu3);
				fflush(stdin);

				switch (menu3) {
				case 1:
					InsertSupply();     //��� ���
					finish();
					break;
				case 2:
					AddSupply();     //��� �߰�
					finish();
					break;
				case 3:
					SubSupply();      //��� ����
					finish();
					break;
				case 4:
					system("cls");
					mainlogo();
					SearchSupply();     //3�� �̳��� ������Ѱ� 3�� ������ �����
					finish();         //�˻��ؼ� �ֹ��ؾ��� ��ǰ��.               
					break;
				case 5:
					PrintStock();     //��� ����� �˻��ϱ� ���� �Լ� ȣ��
					finish();
					break;
				case 6:
					Stock_SaveFile(); //����
					break;
				case 7:
					printf("�����α׷��� �����մϴ�.�� \n");
					ExitProg();
					break;
				case 8:
					goto start;
					break;
				default:
					printf("�ٽ��Է��ϼ���[1-8]\n");
				}
			}
			break;
		case 4:
			printf("�����α׷��� �����մϴ�.�� \n");
			ExitProg();
			break; //���� �Լ� ���
		default: //case���� ����� �� �̿��� ���� �߻��Ҷ� ���� 
			printf("�ٽ��Է��ϼ���[1-4]\n");
		}
	} while (menu != 4);
	return 0;
}