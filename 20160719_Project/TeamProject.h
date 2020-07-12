
#ifndef __STDIO_H
#define __STDIO_H

//구조체
struct person {
	char name[20]; // 회원 이름
	char number[20]; // 회원 전화번호
	char point[30]; // 회원 마일리지
};
struct person list[100]; // 회원 및 마일리지 관리 구조체

struct stock {
	char name[100];   //제품명
	char rest[100];   //재고량
	char price[100];   //판매가격
	char exp[100];   //유통기한
};
struct stock list_s[100]; // 재고 관리 구조체

typedef struct UserInformation {
	char id[16];   // 점장 아이디
	char password[16];   // 점장 패스워드
	char address[40];   // 점장 주소
	char name[16];   // 점장 이름
	char phone[24];   // 점장 전화번호
} UI;
UI g_user_data[100]; //점장 로그인 구조체


// 함수 선언

static int g_user_count; // 로그 관련 변수

				  // 로그 관리 함수
void main_login();//메인 로그인
void LoadUserData();//점장 파일 읽기 함수
void SaveUserData();//점장 파일 저장 함수 
void GetPassword(char parm_password[]); // 점장 로그인 비밀번호 *변환 함수
void UserRegister();// 점장 회원가입 함수 
void login();// 점장 로그인 함수

static int x = 0;  // 마일리지 및 회원 관리 함수 파일 처리 및 입력 관련..
static int s = 0;   // 재고 관리 함수 파일 처리 및 입력 관련..

			 // 마일리지 및 회원 관리 함수들..
void AddPoint();   // 마일리지 추가 함수
void SubPoint();   //마일리지 삭감 함수
void SearchPoint();      // 마일리지 조회 함수
void InsertMember();   // 회원 가입 함수
void DeleteMember();   // 회원 삭제 함수
void SearchMember();   // 회원 검색 함수
void PrintMember();      // 회원 조회 함수
void ExitProg();   //종료 함수 원형 
void MPrintMenu();   //회원 관리 메뉴 함수 
void PPrintMenu();   //마일리지 관리 메뉴 함수
void SaveFile();   // 데이터 저장 함수
int LoadFile();      // 데이터 로딩 함수

					 // 재고 관리 함수들..
void InsertSupply();    //재고 목록 추가 함수
void SPrintMenu();   //재고 관리 메뉴 함수
void AddSupply();   // 재고 추가함수
void SubSupply();   // 재고 감소함수
int today();   // 오늘 날짜 정수형으로 변환해주는 함수
void SearchSupply();   // 유통기한 3일이내 // 재고 3개이하 제품 표시 함수
void PrintStock();   // 전체 재고 현황 메뉴 함수
void Stock_SaveFile();   // 재고 저장 함수
int Stock_LoadFile();   // 재고 저장 로딩 함수

void mainlogo();   //메인 로고 함수
void PrintMenu();    //메뉴 함수 원형 

void finish();   // 각 함수 종료 버튼

#endif