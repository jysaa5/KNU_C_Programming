
#ifndef __STDIO_H
#define __STDIO_H

//����ü
struct person {
	char name[20]; // ȸ�� �̸�
	char number[20]; // ȸ�� ��ȭ��ȣ
	char point[30]; // ȸ�� ���ϸ���
};
struct person list[100]; // ȸ�� �� ���ϸ��� ���� ����ü

struct stock {
	char name[100];   //��ǰ��
	char rest[100];   //���
	char price[100];   //�ǸŰ���
	char exp[100];   //�������
};
struct stock list_s[100]; // ��� ���� ����ü

typedef struct UserInformation {
	char id[16];   // ���� ���̵�
	char password[16];   // ���� �н�����
	char address[40];   // ���� �ּ�
	char name[16];   // ���� �̸�
	char phone[24];   // ���� ��ȭ��ȣ
} UI;
UI g_user_data[100]; //���� �α��� ����ü


// �Լ� ����

static int g_user_count; // �α� ���� ����

				  // �α� ���� �Լ�
void main_login();//���� �α���
void LoadUserData();//���� ���� �б� �Լ�
void SaveUserData();//���� ���� ���� �Լ� 
void GetPassword(char parm_password[]); // ���� �α��� ��й�ȣ *��ȯ �Լ�
void UserRegister();// ���� ȸ������ �Լ� 
void login();// ���� �α��� �Լ�

static int x = 0;  // ���ϸ��� �� ȸ�� ���� �Լ� ���� ó�� �� �Է� ����..
static int s = 0;   // ��� ���� �Լ� ���� ó�� �� �Է� ����..

			 // ���ϸ��� �� ȸ�� ���� �Լ���..
void AddPoint();   // ���ϸ��� �߰� �Լ�
void SubPoint();   //���ϸ��� �谨 �Լ�
void SearchPoint();      // ���ϸ��� ��ȸ �Լ�
void InsertMember();   // ȸ�� ���� �Լ�
void DeleteMember();   // ȸ�� ���� �Լ�
void SearchMember();   // ȸ�� �˻� �Լ�
void PrintMember();      // ȸ�� ��ȸ �Լ�
void ExitProg();   //���� �Լ� ���� 
void MPrintMenu();   //ȸ�� ���� �޴� �Լ� 
void PPrintMenu();   //���ϸ��� ���� �޴� �Լ�
void SaveFile();   // ������ ���� �Լ�
int LoadFile();      // ������ �ε� �Լ�

					 // ��� ���� �Լ���..
void InsertSupply();    //��� ��� �߰� �Լ�
void SPrintMenu();   //��� ���� �޴� �Լ�
void AddSupply();   // ��� �߰��Լ�
void SubSupply();   // ��� �����Լ�
int today();   // ���� ��¥ ���������� ��ȯ���ִ� �Լ�
void SearchSupply();   // ������� 3���̳� // ��� 3������ ��ǰ ǥ�� �Լ�
void PrintStock();   // ��ü ��� ��Ȳ �޴� �Լ�
void Stock_SaveFile();   // ��� ���� �Լ�
int Stock_LoadFile();   // ��� ���� �ε� �Լ�

void mainlogo();   //���� �ΰ� �Լ�
void PrintMenu();    //�޴� �Լ� ���� 

void finish();   // �� �Լ� ���� ��ư

#endif