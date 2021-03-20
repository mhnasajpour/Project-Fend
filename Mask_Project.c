#include<stdlib.h>
#include<stdio.h>
#include <conio.h>
#include<windows.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<time.h>

#pragma warning(disable:4996);
//****************************************************  structurs  ****************************************************
struct ordinary_user {
	char name[20];
	char name_kh[30];
	char username[20];
	char email[35];
	char blood_group[4];
	char code_melli[11];
	char age[4];
	char height[4];
	char weight[4];
	char password[25];
	int code;
	time_t catch_code[5];
	time_t history_of_health_status[11];
	time_t history_of_place_that_be_gone[50];
	char name_and_status_of_place[2][50][20];
	int code_in_place[50];
	int counter_history_of_health_status;
	int counter_history_of_place_that_be_gone;
	int code_10[11];
	char code_melli_met[100][11];
	int counter_met;
	time_t history_met[100];
	char notification[15][100];
	int counter_note;
	time_t notif[15];
	time_t last_message;
	int counter_message;
	char message[20][100];
};

struct employer {
	char name[20];
	char name_kh[30];
	char code_melli[11];
	char username[20];
	char email[35];
	char name_sherkat[30];
	char city_sherkat[20];
	char mantaghe_sherkat[20];
	char password[25];
	char code_sherkat[6];
	time_t time_vorood_bimar;
};

struct manager {
	char username[20];
	char password[25];
	time_t read_message[1000];
};

struct place {
	char name[20];
	char code;
};

struct hospital {
	char name[20];
	char state[20];
	char city[20];
	char mantagheh[20];
	char address[100];
};

struct death {
	char name[20];
	char name_kh[30];
	char code_melli[11];
	time_t time;
};

//*****************************************************  functions  *************************************************
void logo();
void log_in();
void sign_up_ordinary_user();
void sign_up_employer();
void forget_password();
void _ordinary_user(int);
void _employer(int);
void _manager();
void Register_the_Latest_health_status(int);
void edit_profile_employer(int);
void start();
void start1();
void log_out();
void exit();
void View_the_status_of_place(int);
char* Disinfect_your_place(int);
void ramz_star(char*);
void edit_profile_ordinary_user(int);
void manager_view_statistics();
void view_all_users();
void sort_o(struct ordinary_user*, int);
void sort_e(struct employer*, int);
void History_of_health_status(int);
int authentication(char*, char*);
void add_hospitals();
void View_all_Registered_hospitals();
void Change_status_of_users();
void View_dead_users();
void View_the_near_hospitals(int);
void To_add_place_that_be_gone(int);
void History_of_place_that_be_gone(int);
void Statistics_of_covid19();
void View_patients(int);
void checking_code();
void check_code_sherkat();
void To_register_visit_another(int);
void check_step_to_step4(int);
void check_step_to_step3(int);
void History_of_visit_another(int);
void notification(int);
void note(int);
void message(int);
void Message_to_admin(int);

//************************************************************  global variable  *********************************************************
struct ordinary_user ordinary_user[1000];
struct employer employer[600];
struct death death[200];
struct hospital hospital[100];
struct manager manager;

int counter_ordinary_user = -1;
int counter_employer = -1;
int counter_hospital = -1;
int counter_death = -1;

//===========================================================  Start main  =================================================
int main() {
	system("cls");
	system("color e4");
	logo();

	if (fopen("fordinary.bin", "rb") == NULL) {
		FILE* a = fopen("fordinary.bin", "wb");
		fwrite(&counter_ordinary_user, sizeof(int), 1, a);
		fclose(a);
	}

	if (fopen("femployer.bin", "rb") == NULL) {
		FILE* a = fopen("femployer.bin", "wb");
		fwrite(&counter_employer, sizeof(int), 1, a);
		fclose(a);
	}

	if (fopen("fmanager.bin", "rb") == NULL) {
		strcpy(manager.username, "manage");
		strcpy(manager.password, "4591814");
		FILE* a = fopen("fmanager.bin", "wb");
		fwrite(&manager, sizeof(struct manager), 1, a);
		fclose(a);
	}

	if (fopen("fdeath.bin", "rb") == NULL) {
		FILE* a = fopen("fdeath.bin", "wb");
		fwrite(&counter_death, sizeof(int), 1, a);
		fclose(a);
	}

	if (fopen("fhospital.bin", "rb") == NULL) {
		FILE* a = fopen("fhospital.bin", "wb");
		fwrite(&counter_hospital, sizeof(int), 1, a);
		fclose(a);
	}

	FILE* a = fopen("fordinary.bin", "rb");
	fread(&counter_ordinary_user, sizeof(int), 1, a);
	fread(&ordinary_user, sizeof(struct ordinary_user), counter_ordinary_user + 1, a);
	fclose(a);

	a = fopen("femployer.bin", "rb");
	fread(&counter_employer, sizeof(int), 1, a);
	fread(&employer, sizeof(struct employer), counter_employer + 1, a);
	fclose(a);

	a = fopen("fmanager.bin", "rb");
	fread(&manager, sizeof(struct manager), 1, a);
	fclose(a);

	a = fopen("fhospital.bin", "rb");
	fread(&counter_hospital, sizeof(int), 1, a);
	fread(&hospital, sizeof(struct hospital), counter_hospital + 1, a);
	fclose(a);

	a = fopen("fdeath.bin", "rb");
	fread(&counter_death, sizeof(int), 1, a);
	fread(&death, sizeof(struct hospital), counter_death + 1, a);
	fclose(a);

	checking_code();
	check_code_sherkat();
	start1();
}
//______________________________________________finish main________________________________________________
//_________________________________________________________________________________________________________
void logo() {
	printf("\n\n\n");
	puts("		_________________________   __________ ");
	puts("		___  ____/___  ____/___  | / /___  __ \\");
	puts("		__  /_    __  __/   __   |/ / __  / / /");
	puts("		_  __/    _  /___   _  /|  /  _  /_/ / ");
	puts("		/_/       /_____/   /_/ |_/   /_____/  ");
	puts("\n		   Created by MOHAMMAD NASAJPOUR");

	printf("\n\n	   	   LOADING ");
	for (int i = 0; i <= 16; i++) {
		printf("%c", 219);
		Sleep(350);
	}
	Sleep(2000);
	system("cls");
	printf("\n\n\n");
	puts("		_________________________   __________ ");
	puts("		___  ____/___  ____/___  | / /___  __ \\");
	puts("		__  /_    __  __/   __   |/ / __  / / /");
	puts("		_  __/    _  /___   _  /|  /  _  /_/ / ");
	puts("		/_/       /_____/   /_/ |_/   /_____/  ");
	puts("\n		   Created by MOHAMMAD NASAJPOUR");
	printf("\n\n	   	   PRESS ENTER ...\n\n		   Eny where you can use (~) to go back\n   		   ");
	while (getchar() != 10);
	return;
}
//_________________________________________________________________________________________________________
void start1() {
	start();
}
//_________________________________________________________________________________________________________
void start() {
	while (1) {
		system("color e8");
		system("cls");
		char counter[20];
		printf("\n   1 %c Log in\n   2 %c Sign up\n   3 %c Forget the password\n   4 %c Exit\n\n   input: ", 16, 16, 16, 16);
		gets_s(counter);
		if (strcmpi(counter, "1") == 0 || strcmpi(counter, "log in") == 0)
			log_in();
		/*******************************************************************************/
		if (strcmpi(counter, "2") == 0 || strcmpi(counter, "sign up") == 0) {
			while (1) {
				system("cls");
				printf("\n   1 %c Ordinary user\n   2 %c Employer\n\n   input: ", 528, 528);
				gets_s(counter);
				if (strcmp(counter, "~") == 0)
					start();
				if (strcmpi(counter, "1") == 0 || strcmpi(counter, "ordinary user") == 0)
					sign_up_ordinary_user();
				if (strcmpi(counter, "2") == 0 || strcmpi(counter, "employer") == 0)
					sign_up_employer();
			}
		}

		/******************************************************************************/
		if (strcmpi(counter, "3") == 0 || strcmpi(counter, "forget the password") == 0)
			forget_password();
		/******************************************************************************/
		if (strcmpi(counter, "4") == 0 || strcmpi(counter, "Exit") == 0) {
			exit();
		}
	}
}
//_________________________________________________________________________________________________________
void sign_up_ordinary_user() {
	while (1) {
		system("cls");
		system("color f4");
		puts("\n	Hello dear...\n	Please fill in the blanks...\n");
		//------------------------------------
		printf("	First name* : ");
		do {
			fgets(ordinary_user[counter_ordinary_user + 1].name, 20, stdin);
		} while (strcmp(ordinary_user[counter_ordinary_user + 1].name, "\n") == 0);
		ordinary_user[counter_ordinary_user + 1].name[strlen(ordinary_user[counter_ordinary_user + 1].name) - 1] = '\0';
		if (strcmp(ordinary_user[counter_ordinary_user + 1].name, "~") == 0)return;
		//------------------------------------
		printf("	Family name*  : ");
		do {
			fgets(ordinary_user[counter_ordinary_user + 1].name_kh, 30, stdin);
		} while (strcmp(ordinary_user[counter_ordinary_user + 1].name_kh, "\n") == 0);
		ordinary_user[counter_ordinary_user + 1].name_kh[strlen(ordinary_user[counter_ordinary_user + 1].name_kh) - 1] = '\0';
		if (strcmp(ordinary_user[counter_ordinary_user + 1].name_kh, "~") == 0) continue;
		//------------------------------------
		int z = 0;
		do {
			printf("	National Code* : ");
			scanf("%s", ordinary_user[counter_ordinary_user + 1].code_melli);
			if (strcmp(ordinary_user[counter_ordinary_user + 1].code_melli, "~") == 0) sign_up_ordinary_user();
			if (strlen(ordinary_user[counter_ordinary_user + 1].code_melli) != 10) {
				printf("\tThis national code is wrong. Please input your national code correctly\n\n");
				continue;
			}
			int i = 0;
			for (; i < 10; i++) {
				if (ordinary_user[counter_ordinary_user + 1].code_melli[i] < 48 || ordinary_user[counter_ordinary_user + 1].code_melli[i] >57) {
					printf("\tThis national code is wrong. Please input your national code correctly\n\n");
					break;
				}
			}
			if (i != 10) {
				continue;
			}
			if (authentication((char*)"code melli", ordinary_user[counter_ordinary_user + 1].code_melli) == 0) {
				printf("\tThis national code is exist in system.\n\n");
			}
			z = 1;
		} while (authentication((char*)"code melli", ordinary_user[counter_ordinary_user + 1].code_melli) == 0 || z == 0);
		//------------------------------------
		do {
			printf("	Email* : ");
			scanf("%s", ordinary_user[counter_ordinary_user + 1].email);
			if (strcmp(ordinary_user[counter_ordinary_user + 1].email, "~") == 0) sign_up_ordinary_user();
			if ((strstr(ordinary_user[counter_ordinary_user + 1].email, ".com") == NULL) || (strstr(ordinary_user[counter_ordinary_user + 1].email, "@") == NULL)) {
				printf("\tThis Email is wrong. Please input your Email correctly\n\n");
			}
		} while ((strstr(ordinary_user[counter_ordinary_user + 1].email, ".com") == NULL) || (strstr(ordinary_user[counter_ordinary_user + 1].email, "@") == NULL));
		//-----------------------------------
		printf("	Blood group >>optional : ");
		getchar();
		scanf("%[^\n]s", ordinary_user[counter_ordinary_user + 1].blood_group);
		if (strcmp(ordinary_user[counter_ordinary_user + 1].blood_group, "~") == 0) continue;
		//----------------------------------
		printf("	Age >>optional : ");
		getchar();
		scanf("%[^\n]s", ordinary_user[counter_ordinary_user + 1].age);
		if (strcmp(ordinary_user[counter_ordinary_user + 1].age, "~") == 0) continue;
		//-----------------------------------
		printf("	Height >>optional : ");
		getchar();
		scanf("%[^\n]s", ordinary_user[counter_ordinary_user + 1].height);
		if (strcmp(ordinary_user[counter_ordinary_user + 1].height, "~") == 0) continue;

		//-----------------------------------
		printf("	Weight >>optional : ");
		getchar();
		scanf("%[^\n]s", ordinary_user[counter_ordinary_user + 1].weight);
		if (strcmp(ordinary_user[counter_ordinary_user + 1].weight, "~") == 0) continue;
		//----------------------------------
		do {
			system("cls");
			printf("\n	Username* : ");
			scanf("%s", ordinary_user[counter_ordinary_user + 1].username);
			if (strcmp(ordinary_user[counter_ordinary_user + 1].username, "~") == 0) sign_up_ordinary_user();
			if (authentication((char*)"username", ordinary_user[counter_ordinary_user + 1].username) == 0) {
				printf("\n\n\tThis username is exist and you should change it !!!");
				Sleep(3000);
			}
		} while (authentication((char*)"username", ordinary_user[counter_ordinary_user + 1].username) == 0);
		//----------------------------------
		char tekrar[25];
		do {
			printf("	Password* : ");
			ramz_star(ordinary_user[counter_ordinary_user + 1].password);
			if (strcmp(ordinary_user[counter_ordinary_user + 1].password, "~") == 0) sign_up_ordinary_user();
			printf("	Repeat Password* : ");
			ramz_star(tekrar);
			if (strcmp(tekrar, "~") == 0) sign_up_ordinary_user();
			if (strcmpi(tekrar, ordinary_user[counter_ordinary_user + 1].password)) {
				system("cls");
				printf("\n	Username* : %s\n", ordinary_user[counter_ordinary_user + 1].username);
				printf("	Your password and reapeat password is not same!!!\n	TRY AGAIN...\n\n");
			}
		} while (strcmpi(tekrar, ordinary_user[counter_ordinary_user + 1].password));
		printf("\n\n	Loading  ");
		for (int i = 1; i <= 3; i++) {
			Sleep(1000);
			printf("%c ", 3);
		}
		ordinary_user[counter_ordinary_user + 1].counter_history_of_health_status = 0;
		ordinary_user[counter_ordinary_user + 1].catch_code[1] = time(NULL);
		ordinary_user[counter_ordinary_user + 1].code = 1;
		counter_ordinary_user++;
		note(counter_ordinary_user);
		strcpy(ordinary_user[counter_ordinary_user].notification[ordinary_user[counter_ordinary_user].counter_note], "Welcome to FEND app. We hope to keep you safe. Join us and take care of yourself");
		ordinary_user[counter_ordinary_user].notif[ordinary_user[counter_ordinary_user].counter_note] = time(NULL);
		_ordinary_user(counter_ordinary_user);
	}
}
//__________________________________________________________________________________________________________________________
void sign_up_employer() {
	while (1) {
		system("cls");
		system("color f4");
		puts("\n	Hello dear...\n	Please fill in the blanks...\n");
		//---------------------------------------------
		printf("	Manager first name* : ");
		do {
			fgets(employer[counter_employer + 1].name, 20, stdin);
		} while (strcmp(employer[counter_employer + 1].name, "\n") == 0);
		employer[counter_employer + 1].name[strlen(employer[counter_employer + 1].name) - 1] = '\0';
		if (strcmp(employer[counter_employer + 1].name, "~") == 0) return;
		//---------------------------------------------
		printf("	Manager family name*  : ");
		do {
			fgets(employer[counter_employer + 1].name_kh, 30, stdin);
		} while (strcmp(employer[counter_employer + 1].name_kh, "\n") == 0);
		employer[counter_employer + 1].name_kh[strlen(employer[counter_employer + 1].name_kh) - 1] = '\0';
		if (strcmp(employer[counter_employer + 1].name_kh, "~") == 0) continue;
		//---------------------------------------------
		int z = 0;
		do {
			printf("	Manager national Code* : ");
			scanf("%s", employer[counter_employer + 1].code_melli);
			if (strcmp(employer[counter_employer + 1].code_melli, "~") == 0) sign_up_employer();
			if (strlen(employer[counter_employer + 1].code_melli) != 10) {
				printf("\tThis national code is wrong. Please input your national code correctly\n\n");
				continue;
			}
			int i = 0;
			for (; i < 10; i++) {
				if (employer[counter_employer + 1].code_melli[i] < 48 || employer[counter_employer + 1].code_melli[i] >57) {
					printf("\tThis national code is wrong. Please input your national code correctly\n\n");
					break;
				}
			}
			if (i != 10) {
				continue;
			}
			z = 1;
		} while (z == 0);
		//---------------------------------------------
		do {
			printf("	Email* : ");
			scanf("%s", employer[counter_employer + 1].email);
			if (strcmp(employer[counter_employer + 1].email, "~") == 0) sign_up_employer;
			if ((strstr(employer[counter_employer + 1].email, ".com") == NULL) || (strstr(employer[counter_employer + 1].email, "@") == NULL)) {
				printf("\tThis Email is wrong. Please input your Email correctly\n\n");
			}
		} while ((strstr(employer[counter_employer + 1].email, ".com") == NULL) || (strstr(employer[counter_employer + 1].email, "@") == NULL));
		//---------------------------------------------
		printf("	Name of place(company)(store)* : ");
		do {
			fgets(employer[counter_employer + 1].name_sherkat, 30, stdin);
		} while (strcmp(employer[counter_employer + 1].name_sherkat, "\n") == 0);
		employer[counter_employer + 1].name_sherkat[strlen(employer[counter_employer + 1].name_sherkat) - 1] = '\0';
		if (strcmp(employer[counter_employer + 1].name_sherkat, "~") == 0) continue;
		//---------------------------------------------
		printf("	City of place(company)(store)* : ");
		do {
			fgets(employer[counter_employer + 1].city_sherkat, 20, stdin);
		} while (strcmp(employer[counter_employer + 1].city_sherkat, "\n") == 0);
		employer[counter_employer + 1].city_sherkat[strlen(employer[counter_employer + 1].city_sherkat) - 1] = '\0';
		if (strcmp(employer[counter_employer + 1].city_sherkat, "~") == 0) continue;
		//---------------------------------------------
		printf("	Region of place(company)(store)* : ");
		do {
			fgets(employer[counter_employer + 1].mantaghe_sherkat, 20, stdin);
		} while (strcmp(employer[counter_employer + 1].mantaghe_sherkat, "\n") == 0);
		employer[counter_employer + 1].mantaghe_sherkat[strlen(employer[counter_employer + 1].mantaghe_sherkat) - 1] = '\0';
		if (strcmp(employer[counter_employer + 1].mantaghe_sherkat, "~") == 0) continue;
		//----------------------------------------------
		do {
			system("cls");
			printf("\n	Username* : ");
			scanf("%s", employer[counter_employer + 1].username);
			if (strcmp(employer[counter_employer + 1].username, "~") == 0) continue;
			if (authentication((char*)"username", employer[counter_employer + 1].username) == 0) {
				printf("\n\n\tThis username is exist and you should change it !!!");
				Sleep(3000);
			}
		} while (authentication((char*)"username", employer[counter_employer + 1].username) == 0);
		//----------------------------------------------
		char tekrar1[25];
		do {
			printf("	Password* : ");
			ramz_star(employer[counter_employer + 1].password);
			if (strcmp(employer[counter_employer + 1].password, "~") == 0) sign_up_employer();
			printf("	Repeat Password* : ");
			ramz_star(tekrar1);
			if (strcmp(tekrar1, "~") == 0) sign_up_employer();
			if (strcmp(tekrar1, employer[counter_employer + 1].password)) {
				system("cls");
				printf(" \n	Username* : ");
				printf("%s\n", employer[counter_employer + 1].username);
				printf("	Your password and reapeat password is not same!!!\n	TRY AGAIN...\n\n");
			}
		} while (strcmp(tekrar1, employer[counter_employer + 1].password));
		printf("\n\n	Loading  ");
		for (int i = 1; i <= 3; i++) {
			Sleep(1000);
			printf("%c ", 3);
		}
		strcpy(employer[counter_employer + 1].code_sherkat, "White");
		counter_employer++;
		_employer(counter_employer);
	}
}
//__________________________________________________________________________________________________________________________________
void log_in() {
	system("color f4");
	while (1) {
		char username[20], password[25];
		system("cls");
		printf("\n\n		Wellcom to your app...\n ");
		printf("\n\n		Username :  ");
		scanf("%s", username);
		if (strcmp(username, "~") == 0)return;
		printf("\n\n		Password :  ");
		ramz_star(password);
		if (strcmp(password, "~") == 0)continue;

		for (int i = 0; i <= counter_ordinary_user; i++) {
			if (strcmp(username, ordinary_user[i].username) == 0 && strcmp(password, ordinary_user[i].password) == 0) {
				printf("\n\n		Loading  ");
				for (int i = 1; i <= 3; i++) {
					Sleep(1000);
					printf("%c ", 3);
				}
				_ordinary_user(i);
			}
		}

		for (int i = 0; i <= counter_employer; i++) {
			if (strcmp(username, employer[i].username) == 0 && strcmp(password, employer[i].password) == 0) {
				printf("\n\n		Loading  ");
				for (int i = 1; i <= 3; i++) {
					Sleep(1000);
					printf("%c ", 3);
				}
				_employer(i);
			}
		}

		if (strcmp(username, manager.username) == 0 && strcmp(password, manager.password) == 0) {
			printf("\n\n		Loading  ");
			for (int i = 1; i <= 3; i++) {
				Sleep(1000);
				printf("%c ", 3);
			}
			_manager();
		}

		printf("\n\n		The informations is not correct!!!\n		Try again...");
		Sleep(3000);
	}
}
//__________________________________________________________________________________________________________________________________
void forget_password() {
	char tekrar[25], username[20];
	char c[11];
	char e[35];
	while (1) {
		system("cls");
		system("color f4");
		printf("\n\n		You forgot your password!!!...\n		Don't worry...");
		printf("\n\n		Username : ");
		scanf("%s", username);
		if (strcmp(username, "~") == 0)
			return;

		bool r1 = false, r2 = false, r3 = false;
		int i = -1;

		for (; i <= counter_ordinary_user || i <= counter_employer;) {
			i++;
			if (i <= counter_ordinary_user && (strcmp(username, ordinary_user[i].username) == 0)) {
				r1 = true;
				break;
			}
			else if (i <= counter_employer && strcmp(username, employer[i].username) == 0) {
				r2 = true;
				break;
			}
			else if (i <= 0 && strcmp(username, manager.username) == 0) {
				r3 = true;
				break;
			}
		}

		if (r1 == r2 == r3 == false) {
			printf("\n\n		This username is not exist!");
			Sleep(3000);
		}

		if (r1 == true) {
			printf("\n\n		National Code : ");
			scanf("%s", c);
			if (strcmp(c, "~") == 0)continue;

			printf("\n\n		Email : ");
			scanf("%s", e);
			if (strcmp(e, "~") == 0)continue;

			if (strcmp(ordinary_user[i].email, e) == 0 && strcmp(ordinary_user[i].code_melli, c) == 0) {
				while (1) {
					system("cls");
					printf("\n\n\t\tEnter new password : ");
					ramz_star(ordinary_user[i].password);
					if (strcmp(ordinary_user[i].password, "~") == 0)forget_password();

					printf("\n\t\tRepeat Password : ");
					ramz_star(tekrar);
					if (strcmp(tekrar, "~") == 0)forget_password();

					if (strcmp(tekrar, ordinary_user[i].password) == 0) _ordinary_user(i);
					else {
						system("cls");
						printf("\n\n\tYour password and reapeat password is not same!!!\n	TRY AGAIN...\n\n");
						Sleep(3000);
					}
				}
			}
			else {
				printf("\n\n\t\tThese informations are not exist!");
				Sleep(3000);
			}
		}
		//------------------------------------------------------------------------
		if (r2 == true) {
			printf("\n\n		National Code : ");
			scanf("%s", c);
			if (strcmp(c, "~") == 0)continue;

			printf("\n\n		Email : ");
			scanf("%s", e);
			if (strcmp(e, "~") == 0)continue;

			if (strcmp(employer[i].email, e) == 0 && strcmp(employer[i].code_melli, c) == 0) {
				while (1) {
					system("cls");
					printf("\n\n		Enter new password : ");
					scanf("%s", employer[i].password);
					if (strcmp(employer[i].password, "~") == 0)forget_password();

					printf("\n		Repeat Password : ");
					ramz_star(tekrar);
					if (strcmp(tekrar, "~") == 0)forget_password();

					if (strcmp(tekrar, employer[i].password) == 0) _employer(i);
					else {
						system("cls");
						printf("\n\n	Your password and reapeat password is not same!!!\n	TRY AGAIN...\n\n");
						Sleep(3000);
					}
				}
			}
			else {
				printf("\n\n		These informations are not exist!");
				Sleep(3000);
			}
		}
	}
}
//_________________________________________________________________________________________________________________________________
void _ordinary_user(int i) {
	while (1) {
		system("cls");
		system("color f1");
		printf("\n	Hello %s %c \n	Your health code is [%d]\n\n\n", ordinary_user[i].name, 3, ordinary_user[i].code);
		printf("	 1 %c Edit profile\n	 2 %c Register the Latest health status\n	 3 %c History of health status\n	 4 %c To register visit another\n	 5 %c History of visit another\n	 6 %c To add place that be gone\n	 7 %c History of place that be gone\n	 8 %c Statistics of covid19\n	 9 %c View the near hospitals\n	10 %c Log out\n	11 %c Exit\n\n	12 %c Notification\n	13 %c Message to admin\n\n	Input: ", 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16);
		char counter[40];
		gets_s(counter);
		if (strcmpi(counter, "1") == 0 || strcmpi(counter, "Edit profile") == 0) edit_profile_ordinary_user(i);
		else if (strcmpi(counter, "2") == 0 || strcmpi(counter, "Register the Latest health status") == 0)Register_the_Latest_health_status(i);
		else if (strcmpi(counter, "3") == 0 || strcmpi(counter, "History of health status") == 0) History_of_health_status(i);
		else if (strcmpi(counter, "4") == 0 || strcmpi(counter, "To register visit another") == 0)To_register_visit_another(i);
		else if (strcmpi(counter, "5") == 0 || strcmpi(counter, "History of visit another") == 0)History_of_visit_another(i);
		else if (strcmpi(counter, "6") == 0 || strcmpi(counter, "To add place that be gone") == 0)To_add_place_that_be_gone(i);
		else if (strcmpi(counter, "7") == 0 || strcmpi(counter, "History of place that be gone") == 0)History_of_place_that_be_gone(i);
		else if (strcmpi(counter, "8") == 0 || strcmpi(counter, "Statistics of covid19") == 0)Statistics_of_covid19();
		else if (strcmpi(counter, "9") == 0 || strcmpi(counter, "View the near hospitals") == 0)View_the_near_hospitals(i);
		else if (strcmpi(counter, "10") == 0 || strcmpi(counter, "Log out") == 0) log_out();
		else if (strcmpi(counter, "11") == 0 || strcmpi(counter, "Exit") == 0) exit();
		else if (strcmpi(counter, "12") == 0 || strcmpi(counter, "Notification") == 0) notification(i);
		else if (strcmpi(counter, "13") == 0 || strcmpi(counter, "Message to admin") == 0) Message_to_admin(i);
	}
}
//____________________________________________________________________________________________________________________________
void _manager() {
	char counter[32];
	while (1) {
		system("cls");
		system("color f1");
		printf("\n\n	Hello admin %c\n	We are ready to help you\n\n", 3);
		printf("	1 %c Add hospital\n	2 %c View statistic\n	3 %c Change status of users\n	4 %c View all users\n	5 %c View dead users\n	6 %c View all Registered hospitals\n	7 %c Log out\n	8 %c Exit\n\n	Input: ", 16, 16, 16, 16, 16, 16, 16, 16, 16);
		gets_s(counter);
		if (strcmpi(counter, "1") == 0 || strcmpi(counter, "Add hospital") == 0) add_hospitals();
		else if (strcmpi(counter, "2") == 0 || strcmpi(counter, "View statistic") == 0) manager_view_statistics();
		else if (strcmpi(counter, "3") == 0 || strcmpi(counter, "Change status of users") == 0)Change_status_of_users();
		else if (strcmpi(counter, "4") == 0 || strcmpi(counter, "View all users") == 0) view_all_users();
		else if (strcmpi(counter, "5") == 0 || strcmpi(counter, "View dead users") == 0)View_dead_users();
		else if (strcmpi(counter, "6") == 0 || strcmpi(counter, "View all Registered hospitals") == 0)View_all_Registered_hospitals();
		else if (strcmpi(counter, "7") == 0 || strcmpi(counter, "Log out") == 0) log_out();
		else if (strcmpi(counter, "8") == 0 || strcmpi(counter, "Exit") == 0) exit();
	}
}
//____________________________________________________________________________________________________________________________
void _employer(int i) {
	while (1) {
		system("cls");
		system("color f1");
		char counter[30];
		printf("\n\n	Hello %s %c\n	We will happy to help you\n", employer[i].name, 3);
		printf("\n\n	1 %c Edit profile\n	2 %c View the status of place\n	3 %c Disinfect your place\n	4 %c View patients\n	5 %c Log out \n	6 %c Exit\n\n	Input: ", 16, 16, 16, 16, 16, 16);
		gets_s(counter);
		if (strcmpi(counter, "1") == 0 || strcmpi(counter, "Edit profile") == 0)edit_profile_employer(i);
		else if (strcmpi(counter, "2") == 0 || strcmpi(counter, "View the status of place") == 0)View_the_status_of_place(i);
		else if (strcmpi(counter, "3") == 0 || strcmpi(counter, "Disinfect your place") == 0) strcpy(employer[i].code_sherkat, Disinfect_your_place(i));
		else if (strcmpi(counter, "4") == 0 || strcmpi(counter, "View patients") == 0)View_patients(i);
		else if (strcmpi(counter, "5") == 0 || strcmpi(counter, "Log out") == 0) log_out();
		else if (strcmpi(counter, "6") == 0 || strcmpi(counter, "Exit") == 0) exit();
	}
}
//____________________________________________________________________________________________________________________________
void log_out() {
	while (1) {
		char counter[25];
		system("cls");
		system("color d7");
		printf("\n\n		Are you sure to log out ???");
		printf("\n\n		1: Yes\n		2: Cancel and back to menu\n\n		Input: ");
		gets_s(counter);
		if (strcmpi(counter, "1") == 0 || strcmpi(counter, "yes") == 0) {
			printf("\n\n		Loading  ");
			for (int i = 1; i <= 3; i++) {
				Sleep(1000);
				printf("%c ", 3);
			}
			start();
		}
		if (strcmpi(counter, "2") == 0 || strcmpi(counter, "Cancel and back to menu") == 0)return;
	}
}
//____________________________________________________________________________________________________________________________
void exit() {
	while (1) {
		char counter[25];
		system("cls");
		system("color d7");
		printf("\n\n		Are you sure to exit ???");
		printf("\n\n\t\t1: Yes\n\t\t2: Cancel and back to menu\n\n\t\tInput: ");
		gets_s(counter);
		if (strcmpi(counter, "1") == 0 || strcmpi(counter, "yes") == 0) {
			system("cls");
			printf("\n\n\t\tWe hope to be safe %c\n\n\t\tSee you later %c\n\n\t\tBye %c%c\n\n", 1, 1, 3, 3);

			FILE* a = fopen("fordinary.bin", "wb");
			fwrite(&counter_ordinary_user, sizeof(int), 1, a);
			fwrite(&ordinary_user, sizeof(struct ordinary_user), counter_ordinary_user + 1, a);
			fclose(a);

			a = fopen("fmanager.bin", "wb");
			fwrite(&manager, sizeof(struct manager), 1, a);
			fclose(a);

			a = fopen("femployer.bin", "wb");
			fwrite(&counter_employer, sizeof(int), 1, a);
			fwrite(&employer, sizeof(struct employer), counter_employer + 1, a);
			fclose(a);

			a = fopen("fhospital.bin", "wb");
			fwrite(&counter_hospital, sizeof(int), 1, a);
			fwrite(&hospital, sizeof(struct hospital), counter_hospital + 1, a);
			fclose(a);

			a = fopen("fdeath.bin", "wb");
			fwrite(&counter_death, sizeof(int), 1, a);
			fwrite(&death, sizeof(struct death), counter_death + 1, a);
			fclose(a);

			exit(0);
		}
		if (strcmpi(counter, "2") == 0 || strcmpi(counter, "Cancel and back to menu") == 0)return;
	}
}
//_______________________________________________________________________________________________________________________
void Register_the_Latest_health_status(int i) {
	if (ordinary_user[i].counter_history_of_health_status < 10) {
		ordinary_user[i].counter_history_of_health_status++;
	}
	else {
		for (int j = 1; j < 10; j++) {
			ordinary_user[i].code_10[j] = ordinary_user[i].code_10[j + 1];
			ordinary_user[i].history_of_health_status[j] = ordinary_user[i].history_of_health_status[j + 1];
		}
	}
	while (1) {
		char x[4];
		int sum = 0;
		system("cls");
		system("color e4");
		printf("\n	Hello %s %c\n	please fill in the blanks with [YES=1] or [NO=2]\n\n", ordinary_user[i].name, 3);
		printf("\n	sorfeh khoshk ba tedad ziad %c ", 26);
		scanf("%s", x);
		if (strcmpi(x, "yes") == 0 || strcmpi("1", x) == 0) sum += 30;
		if (strcmp(x, "~") == 0) return;
		printf("\n	tab balaye 37 daraje %c ", 26);
		scanf("%s", x);
		if (strcmp(x, "~") == 0)continue;
		if (strcmpi(x, "yes") == 0 || strcmpi("1", x) == 0) sum += 20;
		printf("\n	tangi nafas %c ", 26);
		scanf("%s", x);
		if (strcmp(x, "~") == 0)continue;
		if (strcmp(x, "yes") == 0 || strcmp("1", x) == 0) sum += 20;
		printf("\n	dard va kooftegi %c ", 26);
		scanf("%s", x);
		if (strcmp(x, "~") == 0)continue;
		if (strcmp(x, "yes") == 0 || strcmp("1", x) == 0) sum += 15;
		printf("\n	geloo dard %c ", 26);
		scanf("%s", x);
		if (strcmp(x, "~") == 0)continue;
		if (strcmp(x, "yes") == 0 || strcmp("1", x) == 0) sum += 15;
		int a = ordinary_user[i].code;
		if (sum >= 75) {
			ordinary_user[i].code = 4;
			ordinary_user[i].catch_code[4] = time(NULL);
			ordinary_user[i].history_of_health_status[ordinary_user[i].counter_history_of_health_status] = time(NULL);
			ordinary_user[i].code_10[ordinary_user[i].counter_history_of_health_status] = 4;
			check_step_to_step4(i);

			time_t b = time(NULL);
			for (int g = ordinary_user[i].counter_history_of_place_that_be_gone - 1; g >= 0 && b - ordinary_user[i].history_of_place_that_be_gone[g] < 604800; g--) {
				for (int t = 0; t <= counter_employer; t++) {
					if (strcmpi(employer[t].name_sherkat, ordinary_user[i].name_and_status_of_place[0][g]) == 0) {
						strcpy(employer[t].code_sherkat, "Red");
						employer[t].time_vorood_bimar = time(NULL);
					}
				}
			}
		}
		else if (sum >= 50) {
			ordinary_user[i].code = 3;
			ordinary_user[i].catch_code[3] = time(NULL);
			ordinary_user[i].history_of_health_status[ordinary_user[i].counter_history_of_health_status] = time(NULL);
			ordinary_user[i].code_10[ordinary_user[i].counter_history_of_health_status] = 3;
			check_step_to_step3(i);
		}
		else if (sum >= 15) {
			ordinary_user[i].code = 2;
			ordinary_user[i].catch_code[2] = time(NULL);
			ordinary_user[i].history_of_health_status[ordinary_user[i].counter_history_of_health_status] = time(NULL);
			ordinary_user[i].code_10[ordinary_user[i].counter_history_of_health_status] = 2;
		}
		else {
			ordinary_user[i].code = 1;
			ordinary_user[i].catch_code[1] = time(NULL);
			ordinary_user[i].history_of_health_status[ordinary_user[i].counter_history_of_health_status] = time(NULL);
			ordinary_user[i].code_10[ordinary_user[i].counter_history_of_health_status] = 1;
		}
		if (a > ordinary_user[i].code) {
			ordinary_user[i].code = a;
			ordinary_user[i].code_10[ordinary_user[i].counter_history_of_health_status] = a;
			printf("\n\n	Because your health code is more than the result's answer so your health code will not update");
			note(i);
			strcpy(ordinary_user[i].notification[ordinary_user[i].counter_note], "your health code couldn't upgrade");
			ordinary_user[i].notif[ordinary_user[i].counter_note] = time(NULL);
		}
		else {
			printf("\n\n	Your health code is %d", ordinary_user[i].code);
			if (ordinary_user[i].code == 1) {
				note(i);
				strcpy(ordinary_user[i].notification[ordinary_user[i].counter_note], "your health code didn't change");
				ordinary_user[i].notif[ordinary_user[i].counter_note] = time(NULL);
			}
			else if (ordinary_user[i].code == 2) {
				note(i);
				strcpy(ordinary_user[i].notification[ordinary_user[i].counter_note], "your health code has been increased to 2");
				ordinary_user[i].notif[ordinary_user[i].counter_note] = time(NULL);
			}
			else if (ordinary_user[i].code == 3) {
				note(i);
				strcpy(ordinary_user[i].notification[ordinary_user[i].counter_note], "your health code has been increased to 3");
				ordinary_user[i].notif[ordinary_user[i].counter_note] = time(NULL);
			}
			else if (ordinary_user[i].code == 4) {
				note(i);
				strcpy(ordinary_user[i].notification[ordinary_user[i].counter_note], "your health code has been increased to 4");
				ordinary_user[i].notif[ordinary_user[i].counter_note] = time(NULL);
			}
		}
		printf("\n\n	press enter to back menu\n	");
		getchar();
		getchar();
		return;
	}
}
//_________________________________________________________________________________________________________________________
void View_the_status_of_place(int i) {
	system("cls");
	if (strcmpi(employer[i].code_sherkat, "Red") == 0) {
		system("color c0");
		printf("\n\n		Your place (%s) is RED\n\n		You may disinfection your place and then inform...", employer[i].name_sherkat);
		printf("\n\n		press enter to back menu\n		");
		getchar();
		_employer(i);
	}
	if (strcmpi(employer[i].code_sherkat, "White") == 0) {
		system("color f4");
		printf("\n\n		Your place (%s) is WHITE\n\n		Thanks for keeping clean your place %C", employer[i].name_sherkat, 3);
		printf("\n\n		press enter to back menu\n		");
		getchar();
		_employer(i);
	}
}
//_____________________________________________________________________________________________________________________________
char* Disinfect_your_place(int i) {
	system("cls");
	if (strcmpi(employer[i].code_sherkat, "White") == 0) {
		system("color f4");
		printf("\n\n		Your place (%s) is clean and you not required to disinfect %c\n		", employer[i].name_sherkat, 1);
		printf("\n\n		press enter to back menu\n		");
		getchar();
		return employer[i].code_sherkat;
	}
	if (strcmpi(employer[i].code_sherkat, "Red") == 0) {
		while (1) {
			system("color c7");
			printf("\n\n		Your place is dirty and you should disinfect it\n\n		If you disinfected your place press [yes=1] else press [No=2]\n\n		input: ");
			char a[4];
			scanf("%s", a);
			if (strcmpi(a, "yes") == 0 || strcmp(a, "1") == 0) {
				strcpy(employer[i].code_sherkat, "White");
				printf("\n\n		The color of your place was be white");
				system("color f4");

				note(i);
				strcpy(ordinary_user[i].notification[ordinary_user[i].counter_note], "Thanks sake disinfecting your place :)");
				ordinary_user[i].notif[ordinary_user[i].counter_note] = time(NULL);

				printf("\n\n		press enter to back menu\n		");
				getchar();
				getchar();
				return employer[i].code_sherkat;
			}
			if (strcmpi(a, "no") == 0 || strcmp(a, "2") == 0) {
				printf("\n\n		please disinfection your place immediately");
				printf("\n\n		press enter to back menu\n		");
				getchar();
				getchar();
				return employer[i].code_sherkat;
			}
		}
	}
}
//_____________________________________________________________________________________________________________________________
void ramz_star(char password[25]) {
	int count = 0;
	while (1) {
		password[count] = _getch();
		if (password[count] == '\b')
		{
			printf("\b \b");
			count--;
		}
		else if (password[count] != '\r')
		{
			printf("%c", 12);
			count++;
		}
		else if (password[count] == '\r') break;
		if (count < 0) {
			count++;
			printf(" ");
		}
	}
	password[count] = '\0';
	puts("");
}
//_____________________________________________________________________________________________________________________________
void edit_profile_ordinary_user(int i) {
	struct ordinary_user user1;
	user1 = ordinary_user[i];
	char a[15];
	system("color a0");
	while (1) {
		system("cls");
		printf("\n\n\tHello %s %c\n\tYou wanna to edit profile", user1.name, 3);
		printf("\n\n\n\t 1 %c First name    %c %s\n\t 2 %c Family name   %c %s", 219, 16, user1.name, 219, 16, user1.name_kh);
		printf("\n\t 3 %c National Code %c %s\n\t 4 %c Email         %c %s\n\t 5 %c Blood group   %c %s", 219, 16, user1.code_melli, 219, 16, user1.email, 219, 16, user1.blood_group);
		printf("\n\t 6 %c Age           %c %s\n\t 7 %c Height        %c %s\n\t 8 %c Weight        %c %s", 219, 16, user1.age, 219, 16, user1.height, 219, 16, user1.weight);
		printf("\n\n\t 9 %c Username      %c %s\n\t10 %c Password      %c ", 219, 16, user1.username, 219, 16);
		for (int i = 0; i < strlen(user1.password); i++) {
			printf("*");
		}
		printf("\n\n\t11 %c Exit", 219);

		printf("\n\n\tInput: ");
		fgets(a, 15, stdin);
		a[strlen(a) - 1] = '\0';
		if (strcmpi("First name", a) == 0 || strcmpi("1", a) == 0) {
			printf("\n\n	First name* : ");
			do {
				fgets(user1.name, 20, stdin);
			} while (strcmp(user1.name, "\n") == 0);
			user1.name[strlen(user1.name) - 1] = '\0';
		}
		else if (strcmpi("family name", a) == 0 || strcmpi("2", a) == 0) {
			printf("\n\n	Family name*  : ");
			do {
				fgets(user1.name_kh, 30, stdin);
			} while (strcmp(user1.name_kh, "\n") == 0);
			user1.name_kh[strlen(user1.name_kh) - 1] = '\0';
		}
		else if (strcmpi("National Code", a) == 0 || strcmpi("3", a) == 0) {
			int z = 0;
			do {
				printf("\n\n	National Code* : ");
				scanf("%s", user1.code_melli);
				if (strlen(user1.code_melli) != 10) {
					printf("\tThis national code is wrong. Please input your national code correctly\n\n");
					continue;
				}
				int i = 0;
				for (; i < 10; i++) {
					if (user1.code_melli[i] < 48 || user1.code_melli[i] > 57) {
						printf("\tThis national code is wrong. Please input your national code correctly\n\n");
						break;
					}
				}
				if (i != 10) {
					continue;
				}
				if (authentication((char*)"code melli", user1.code_melli) == 0) {
					printf("\tThis national code is exist in system.\n\n");
				}
				z = 1;
			} while (authentication((char*)"code melli", user1.code_melli) == 0 || z == 0);
		}
		else if (strcmpi("Email", a) == 0 || strcmpi("4", a) == 0) {
			do {
				printf("\n\n	Email* : ");
				scanf("%s", user1.email);
				if ((strstr(user1.email, ".com") == NULL) || (strstr(user1.email, "@") == NULL)) {
					printf("\tThis Email is wrong. Please input your Email correctly\n\n");
				}
			} while ((strstr(user1.email, ".com") == NULL) || (strstr(user1.email, "@") == NULL));
		}
		else if (strcmpi("Blood group", a) == 0 || strcmpi("5", a) == 0) {
			printf("\n\n	Blood group >>optional : ");
			scanf("%[^\n]s", user1.blood_group);
		}
		else if (strcmpi("Age", a) == 0 || strcmpi("6", a) == 0) {
			printf("\n\n	Age >>optional : ");
			scanf("%[^\n]s", user1.age);
		}
		else if (strcmpi("Height", a) == 0 || strcmpi("7", a) == 0) {
			printf("\n\n	Height >>optional : ");
			scanf("%[^\n]s", user1.height);
		}
		else if (strcmpi("Weight", a) == 0 || strcmpi("8", a) == 0) {
			printf("\n\n	Weight >>optional : ");
			scanf("%[^\n]s", user1.weight);
		}
		else if (strcmpi("Username", a) == 0 || strcmpi("9", a) == 0) {
			do {
				printf("\n\n	Username* : ");
				scanf("%s", user1.username);
				if (authentication((char*)"username", user1.username) == 0) {
					printf("\n\n\tThis username is exist and you should change it !!!");
					Sleep(3000);
				}
			} while (authentication((char*)"username", user1.username) == 0);
		}
		else if (strcmpi("Password", a) == 0 || strcmpi("10", a) == 0) {
			char tekrar[25];
			do {
				printf("\n\n	Password* : ");
				ramz_star(user1.password);
				printf("\n	Repeat Password* : ");
				ramz_star(tekrar);
				if (strcmpi(tekrar, user1.password)) {
					printf("\n	Your password and reapeat password is not same!!!\n	TRY AGAIN...\n\n");
				}
			} while (strcmpi(tekrar, user1.password));
		}
		else if (strcmpi("Exit", a) == 0 || strcmpi("11", a) == 0)break;
	}
	char d[4];
	printf("\n\n\tAre you sure to update your information?\n\t[YES = 1]    [NO = 2]\n\n\tInput: ");
	while (1) {
		scanf("%s", d);
		if (strcmpi("yes", d) == 0 || strcmpi("1", d) == 0) {

			ordinary_user[i] = user1;

			note(i);
			strcpy(ordinary_user[i].notification[ordinary_user[i].counter_note], "You updated your informations");
			ordinary_user[i].notif[ordinary_user[i].counter_note] = time(NULL);

			break;
		}
		else if (strcmpi("no", d) == 0 || strcmpi("2", d) == 0) {
			break;
		}
	}
}
//________________________________________________________________________________________________________________
void edit_profile_employer(int i) {
	struct employer user1;
	user1 = employer[i];
	char a[15];
	system("color a0");
	while (1) {
		system("cls");
		printf("\n\n\tHello %s %c\n\tYou wanna to edit profile", user1.name, 3);
		printf("\n\n\n\t 1 %c Manager first name              %c %s\n\t 2 %c Manager family name             %c %s", 219, 16, user1.name, 219, 16, user1.name_kh);
		printf("\n\t 3 %c Manager national Code           %c %s\n\t 4 %c Email                           %c %s\n\t 5 %c Name of place(company)(store)   %c %s", 219, 16, user1.code_melli, 219, 16, user1.email, 219, 16, user1.name_sherkat);
		printf("\n\t 6 %c City of place(company)(store)   %c %s\n\t 7 %c Region of place(company)(store) %c %s\n\n\t 8 %c Username                        %c %s", 219, 16, user1.city_sherkat, 219, 16, user1.mantaghe_sherkat, 219, 16, user1.username);
		printf("\n\t 9 %c Password                        %c ", 219, 16);
		for (int i = 0; i < strlen(user1.password); i++) {
			printf("*");
		}
		printf("\n\n\t10 %c Exit", 219);

		printf("\n\n\tInput: ");
		fgets(a, 15, stdin);
		a[strlen(a) - 1] = '\0';
		if (strcmpi("Manager first name", a) == 0 || strcmpi("1", a) == 0) {
			printf("\n\n	Manager first name* : ");
			do {
				fgets(user1.name, 20, stdin);
			} while (strcmp(user1.name, "\n") == 0);
			user1.name[strlen(user1.name) - 1] = '\0';
		}
		else if (strcmpi("Manager family name", a) == 0 || strcmpi("2", a) == 0) {
			printf("\n\n	Manager family name*  : ");
			do {
				fgets(user1.name_kh, 30, stdin);
			} while (strcmp(user1.name_kh, "\n") == 0);
			user1.name_kh[strlen(user1.name_kh) - 1] = '\0';
		}
		else if (strcmpi("Manager national Code", a) == 0 || strcmpi("3", a) == 0) {
			int z = 0;
			do {
				printf("\n\n	Manager national Code* : ");
				scanf("%s", user1.code_melli);
				if (strlen(user1.code_melli) != 10) {
					printf("\tThis national code is wrong. Please input your national code correctly\n\n");
					continue;
				}
				int i = 0;
				for (; i < 10; i++) {
					if (user1.code_melli[i] < 48 || user1.code_melli[i] > 57) {
						printf("\tThis national code is wrong. Please input your national code correctly\n\n");
						break;
					}
				}
				if (i != 10) {
					continue;
				}
				if (authentication((char*)"code melli", user1.code_melli) == 0) {
					printf("\tThis national code is exist in system.\n\n");
				}
				z = 1;
			} while (authentication((char*)"code melli", user1.code_melli) == 0 || z == 0);
		}
		else if (strcmpi("Email", a) == 0 || strcmpi("4", a) == 0) {
			do {
				printf("\n\n	Email* : ");
				scanf("%s", user1.email);
				if ((strstr(user1.email, ".com") == NULL) || (strstr(user1.email, "@") == NULL)) {
					printf("\tThis Email is wrong. Please input your Email correctly\n\n");
				}
			} while ((strstr(user1.email, ".com") == NULL) || (strstr(user1.email, "@") == NULL));
		}
		else if (strcmpi("Name of place(company)(store)", a) == 0 || strcmpi("5", a) == 0) {
			printf("\n\n	Name of place(company)(store)*  : ");
			do {
				fgets(user1.name_sherkat, 30, stdin);
			} while (strcmp(user1.name_sherkat, "\n") == 0);
			user1.name_kh[strlen(user1.name_sherkat) - 1] = '\0';
		}
		else if (strcmpi("City of place(company)(store)", a) == 0 || strcmpi("6", a) == 0) {
			printf("\n\n	City of place(company)(store)*  : ");
			do {
				fgets(user1.city_sherkat, 30, stdin);
			} while (strcmp(user1.city_sherkat, "\n") == 0);
			user1.name_kh[strlen(user1.city_sherkat) - 1] = '\0';
		}
		else if (strcmpi("Region of place(company)(store)", a) == 0 || strcmpi("7", a) == 0) {
			printf("\n\n	Region of place(company)(store)*  : ");
			do {
				fgets(user1.mantaghe_sherkat, 30, stdin);
			} while (strcmp(user1.mantaghe_sherkat, "\n") == 0);
			user1.name_kh[strlen(user1.mantaghe_sherkat) - 1] = '\0';
		}
		else if (strcmpi("Username", a) == 0 || strcmpi("8", a) == 0) {
			do {
				printf("\n\n	Username* : ");
				scanf("%s", user1.username);
				if (authentication((char*)"username", user1.username) == 0) {
					printf("\n\n\tThis username is exist and you should change it !!!");
					Sleep(3000);
				}
			} while (authentication((char*)"username", user1.username) == 0);
		}
		else if (strcmpi("Password", a) == 0 || strcmpi("9", a) == 0) {
			char tekrar[25];
			do {
				printf("\n\n	Password* : ");
				ramz_star(user1.password);
				printf("\n	Repeat Password* : ");
				ramz_star(tekrar);
				if (strcmpi(tekrar, user1.password)) {
					printf("\n	Your password and reapeat password is not same!!!\n	TRY AGAIN...\n\n");
				}
			} while (strcmpi(tekrar, user1.password));
		}
		else if (strcmpi("Exit", a) == 0 || strcmpi("10", a) == 0)break;
	}
	char d[4];
	printf("\n\n\tAre you sure to update your information?\n\t[YES=1]    [NO=2]\n\n\tInput: ");
	while (1) {
		scanf("%s", d);
		if (strcmpi("yes", d) == 0 || strcmpi("1", d) == 0) {
			employer[i] = user1;
			break;
		}
		else if (strcmpi("no", d) == 0 || strcmpi("2", d) == 0) {
			break;
		}
	}
}
//____________________________________________________________________________________________________________________________
void manager_view_statistics() {
	system("color c0");
	system("cls");
	int counter = 0;
	for (int i = 0; i <= counter_ordinary_user; i++) {
		if (ordinary_user[i].code == 4) {
			counter++;
		}
	}
	int x = -1;
	struct ordinary_user* user = (struct ordinary_user*)malloc(counter * sizeof(struct ordinary_user));
	for (int i = 0; i <= counter_ordinary_user; i++) {
		if (ordinary_user[i].code == 4) {
			x++;
			user[x] = ordinary_user[i];
		}
	}
	counter--;
	sort_o(user, counter);

	printf("\n\n");
	for (int i = 0; i <= counter; i++) {
		struct tm* a = localtime(&user[i].catch_code[4]);
		char w[50];
		strcpy(w, user[i].name_kh);
		strcat(w, " ");
		strcat(w, user[i].name);
		printf("\t%3d   %-40s   %s   %s", i + 1, w, user[i].code_melli, asctime(a));
	}

	printf("\n\n	press enter to back menu\n	");
	getchar();
	return;
}
//____________________________________________________________________________________________________________
void view_all_users() {
	while (1) {
		system("cls");
		system("color c0");
		char input[16];
		printf("\n\n\tHi admin %c", 3);
		printf("\n\n\t1 %c Ordinary user [num: %d]\n\t2 %c Employer [num: %d]\n\n\tInput: ", 219, counter_ordinary_user + 1, 219, counter_employer + 1);
		do {
			fgets(input, 16, stdin);
		} while (input[0] == '\n');
		system("cls");
		system("color c0");
		printf("\n\n");
		input[strlen(input)- 1] = '\0';
		if (strcmpi(input, "~") == 0) return;
		else if (strcmpi(input, "Ordinary user") == 0 || strcmp(input, "1") == 0) {
			while (1) {
				sort_o(ordinary_user, counter_ordinary_user);
				for (int i = 0; i <= counter_ordinary_user; i++) {
					printf("\t%3d    %-25s   %-15s   %-10s   %d     ", i + 1, ordinary_user[i].name_kh, ordinary_user[i].name, ordinary_user[i].code_melli, ordinary_user[i].code);
					if (ordinary_user[i].last_message > manager.read_message[i]) {
						printf("new message\n");
					}
				}
				printf("\n\n\tIf you want to read messages from persons input his or her id else input 0 and go back\n\tInput: ");
				int n;
				scanf("%d", &n);
				if (n == 0) {
					return;
				}
				else if (n == 1) {
					system("cls");
					printf("\n\n\tName: %s\n\tFamily name: %s\n\tHealth code: %d\n\n", ordinary_user[n - 1].name, ordinary_user[n - 1].name_kh, ordinary_user[n - 1].code);
					for (int r = ordinary_user[n - 1].counter_message; r > 0; r--) {
						printf("\t%s\n", ordinary_user[n - 1].message[r]);
					}
					manager.read_message[n - 1] = time(NULL);

					printf("\n\n\tIf you want to send message to him input 1 else input 0\n\tInput: ");
					scanf("%d", &n);
					if (n == 0) {
						return;
					}
					else if (n == 1) {
						printf("\n\n\tWhat is your message? At the end of your message use /\n\n\t");
						message(n - 1);
						char str[80];
						char str1[100];
						strcpy(str1, "\t\t\t");
						getchar();
						scanf("%[^/]s", str);
						strcat(str1, str);
						printf("\n\n\tYour message sent successfully");
						message(n - 1);
						strcpy(ordinary_user[n - 1].message[ordinary_user[n - 1].counter_message], str1);

						note(n - 1);
						strcpy(ordinary_user[n - 1].notification[ordinary_user[n - 1].counter_note], "you have a new message from admin. Read it");
						ordinary_user[n - 1].notif[ordinary_user[n - 1].counter_note] = time(NULL);
						return;
					}
				}
			}
		}

		else if (strcmpi(input, "Employer") == 0 || strcmp(input, "2") == 0) {
			sort_e(employer, counter_employer);
			for (int i = 0; i <= counter_employer; i++) {
				printf("\t%-20s   %-20s   %-15s   %-10s   %s\n", employer[i].name_sherkat, employer[i].name_kh, employer[i].name, employer[i].code_melli, employer[i].code_sherkat);
			}
			printf("\n\n	press enter to back menu\n	");
			getchar();
			return;
		}
	}
}
//_________________________________________________________________________________________________________________
void sort_o(struct ordinary_user* user, int counter) {
	struct ordinary_user a;
	for (int i = 0; i <= counter; i++) {
		for (int j = i + 1; j <= counter; j++) {
			if (strcmpi(user[i].name_kh, user[j].name_kh) > 0) {
				a = user[i];
				user[i] = user[j];
				user[j] = a;
			}
			else if ((strcmpi(user[i].name_kh, user[j].name_kh) == 0) && (strcmpi(user[i].name, user[j].name) > 0)) {
				a = user[i];
				user[i] = user[j];
				user[j] = a;
			}
			else if ((strcmpi(user[i].name_kh, user[j].name_kh) == 0) && (strcmpi(user[i].name, user[j].name) == 0) && (strcmp(user[i].code_melli, user[j].code_melli) > 0)) {
				a = user[i];
				user[i] = user[j];
				user[j] = a;
			}
		}
	}
}
//___________________________________________________________________________________________________________________
void sort_e(struct employer* user, int counter) {
	struct employer a;
	for (int i = 0; i <= counter; i++) {
		for (int j = i + 1; j <= counter; j++) {
			if (strcmpi(user[i].name_kh, user[j].name_kh) > 0) {
				a = user[i];
				user[i] = user[j];
				user[j] = a;
			}
			else if ((strcmpi(user[i].name_kh, user[j].name_kh) == 0) && (strcmpi(user[i].name, user[j].name) > 0)) {
				a = user[i];
				user[i] = user[j];
				user[j] = a;
			}
			else if ((strcmpi(user[i].name_kh, user[j].name_kh) == 0) && (strcmpi(user[i].name, user[j].name) == 0) && (strcmp(user[i].code_melli, user[j].code_melli) > 0)) {
				a = user[i];
				user[i] = user[j];
				user[j] = a;
			}
		}
	}
}
//______________________________________________________________________________________________________________________
void History_of_health_status(int i) {
	system("cls");
	system("color c0");
	printf("\n\n\tYour last 10 answers are:\n\n\n");
	for (int j = ordinary_user[i].counter_history_of_health_status; j > 0; j--) {
		struct tm* a = localtime(&(ordinary_user[i].history_of_health_status[j]));
		printf("\t%d  %c  %s\n", ordinary_user[i].code_10[j], 219, asctime(a));
	}
	printf("\n\n	press enter to back menu\n	");
	getchar();
	return;
}
//______________________________________________________________________________________________________________________
int authentication(char* n, char* user) {
	if (strcmp(n, "username") == 0) {
		for (int i = 0; i <= counter_ordinary_user; i++) {
			if (strcmpi(user, ordinary_user[i].username) == 0) {
				return 0;
			}
		}
		for (int i = 0; i <= counter_employer; i++) {
			if (strcmpi(user, employer[i].username) == 0) {
				return 0;
			}
		}
		if (strcmpi(user, manager.username) == 0) {
			return 0;
		}
		return 1;
	}

	if (strcmp(n, "code melli") == 0) {
		for (int i = 0; i <= counter_ordinary_user; i++) {
			if (strcmpi(user, ordinary_user[i].code_melli) == 0) {
				return 0;
			}
		}
		return 1;
	}
}
//__________________________________________________________________________________________________________________________
void add_hospitals() {
	while (1) {
		system("cls");
		system("color d7");
		printf("\n\n\tHello admin %c You can add hospitals in this menu\n\n\n", 3);

		printf("\tState %c ", 16);
		fgets(hospital[counter_hospital + 1].state, 20, stdin);
		hospital[counter_hospital + 1].state[strlen(hospital[counter_hospital + 1].state) - 1] = '\0';
		if (strcmp("~", hospital[counter_hospital + 1].state) == 0) {
			_manager();
		}

		printf("\n\n\tCity %c ", 16);
		fgets(hospital[counter_hospital + 1].city, 20, stdin);
		hospital[counter_hospital + 1].city[strlen(hospital[counter_hospital + 1].city) - 1] = '\0';
		if (strcmp("~", hospital[counter_hospital + 1].city) == 0) {
			_manager();
		}

		printf("\n\n\tRegion %c ", 16);
		fgets(hospital[counter_hospital + 1].mantagheh, 20, stdin);
		hospital[counter_hospital + 1].mantagheh[strlen(hospital[counter_hospital + 1].mantagheh) - 1] = '\0';
		if (strcmp("~", hospital[counter_hospital + 1].mantagheh) == 0) {
			continue;
		}

		printf("\n\n\tName of hospital %c ", 16);
		fgets(hospital[counter_hospital + 1].name, 20, stdin);
		hospital[counter_hospital + 1].name[strlen(hospital[counter_hospital + 1].name) - 1] = '\0';
		if (strcmp("~", hospital[counter_hospital + 1].name) == 0) {
			continue;
		}

		printf("\n\n\tAddress %c ", 16);
		fgets(hospital[counter_hospital + 1].address, 20, stdin);
		hospital[counter_hospital + 1].address[strlen(hospital[counter_hospital + 1].address) - 1] = '\0';
		if (strcmp("~", hospital[counter_hospital + 1].address) == 0) {
			_manager();
		}

		counter_hospital++;
		printf("\n\n\tThe hospital (%s) added successfully", hospital[counter_hospital].name);
		Sleep(3000);
		break;
	}
}
//___________________________________________________________________________________________________________________
void View_all_Registered_hospitals() {
	system("cls");
	system("color d7");
	printf("\n\n\tHello admin %c You can View hospitals profile in this menu\n\n\n", 3);
	for (int i = 0; i <= counter_hospital; i++) {
		for (int j = i + 1; j <= counter_hospital; j++) {
			if (strcmpi(hospital[i].state, hospital[j].state) > 0) {
				struct hospital temp;
				temp = hospital[i];
				hospital[i] = hospital[j];
				hospital[j] = temp;
			}
			if ((strcmpi(hospital[i].state, hospital[j].state) == 0) && (strcmpi(hospital[i].city, hospital[j].city) > 0)) {
				struct hospital temp;
				temp = hospital[i];
				hospital[i] = hospital[j];
				hospital[j] = temp;
			}
			if ((strcmpi(hospital[i].state, hospital[j].state) == 0) && (strcmpi(hospital[i].city, hospital[j].city) == 0) && (strcmpi(hospital[i].mantagheh, hospital[j].mantagheh) > 0)) {
				struct hospital temp;
				temp = hospital[i];
				hospital[i] = hospital[j];
				hospital[j] = temp;
			}
			if ((strcmpi(hospital[i].state, hospital[j].state) == 0) && (strcmpi(hospital[i].city, hospital[j].city) == 0) && (strcmpi(hospital[i].mantagheh, hospital[j].mantagheh) == 0) && (strcmpi(hospital[i].mantagheh, hospital[j].mantagheh) > 0)) {
				struct hospital temp;
				temp = hospital[i];
				hospital[i] = hospital[j];
				hospital[j] = temp;
			}
		}
	}
	bool z = true;
	for (int i = 0; i <= counter_hospital; i++) {
		if (z) {
			printf("\n\t%-3s   %-20s %-20s %-20s %s\n", "Num", "Hospital name", "Hospital state", "Hospital city", "Hospital region");
			z = false;
		}
		printf("\n\t%-3d   %-20s %-20s %-20s %s", i + 1, hospital[i].name, hospital[i].state, hospital[i].city, hospital[i].mantagheh);
	}

	printf("\n\n	press enter to back menu\n	");
	getchar();
	return;
}
//________________________________________________________________________________________________________________________________________
void Change_status_of_users() {
	char n[11];
	while (1) {
		system("cls");
		system("color e1");
		printf("\n\n\tHello admin %c You can report death or recovery of anyone", 3);
		printf("\n\tIf you want to back to menu use (~)");
		printf("\n\n\tNational code: ");
		scanf("%s", n);
		if (n[0] == '~') {
			break;
		}
		int i = 0;
		for (; i <= counter_ordinary_user; i++) {
			if (strcmp(n, ordinary_user[i].code_melli) == 0) {
				break;
			}
		}
		if (i > counter_ordinary_user) {
			printf("\n\n\tThis national code (%s) is not exist", n);
			Sleep(3000);
			continue;
		}
		else {
			char num;
			printf("\n\n\tName: %s\n\tFamily name: %s\n\tNational code: %s\n\tHealth code: %d", ordinary_user[i].name, ordinary_user[i].name_kh, ordinary_user[i].code_melli, ordinary_user[i].code);


			if (ordinary_user[i].code == 4) {
				printf("\n\n\t1 %c He or she got better", 16);
				printf("\n\t2 %c He or she Died\n\n\tInput: ", 16);
				getchar();
				scanf("%c", &num);
				if (num == '~') {
					continue;
				}
				else if (num == '1') {
					int r;
					printf("\n\n\tIs he or she got better?\t1: yes\t2: No\n\tInput: ");
					scanf("%d", &r);
					if (r == 1) {
						note(i);
						strcpy(ordinary_user[i].notification[ordinary_user[i].counter_note], "Admin updated your health code to 2");
						ordinary_user[i].notif[ordinary_user[i].counter_note] = time(NULL);

						printf("\n\tThe information successfully registered...");
						Sleep(3000);
						if (ordinary_user[i].counter_history_of_health_status < 10) {
							ordinary_user[i].counter_history_of_health_status++;
						}
						else {
							for (int j = 1; j < 10; j++) {
								ordinary_user[i].code_10[j] = ordinary_user[i].code_10[j + 1];
								ordinary_user[i].history_of_health_status[j] = ordinary_user[i].history_of_health_status[j + 1];
							}
						}
						ordinary_user[i].code = 2;
						ordinary_user[i].catch_code[2] = time(NULL);
						ordinary_user[i].history_of_health_status[ordinary_user[i].counter_history_of_health_status] = time(NULL);
						ordinary_user[i].code_10[ordinary_user[i].counter_history_of_health_status] = 2;
						continue;
					}
					else if (r == 2) {
						continue;
					}
				}
				else if (num == '2') {
					int r;
					printf("\n\n\tIs he or she died?\t1: yes\t2: No\n\tInput: ");
					scanf("%d", &r);
					if (r == 1) {
						printf("\n\tThe information successfully registered...");

						strcpy(death[counter_death + 1].name, ordinary_user[i].name);
						strcpy(death[counter_death + 1].name_kh, ordinary_user[i].name_kh);
						strcpy(death[counter_death + 1].code_melli, ordinary_user[i].code_melli);
						death[counter_death + 1].time = time(NULL);
						counter_death++;

						for (; i <= counter_ordinary_user; i++) {
							ordinary_user[i] = ordinary_user[i + 1];
						}
						counter_ordinary_user--;


						Sleep(2800);
						continue;
					}

					else if (r == 2) {
						continue;
					}
				}
			}
			else {
				int r;
				printf("\n\n\tIs he or she died?\t1: yes\t2: No\n\tInput: ");
				scanf("%d", &r);
				if (r == 1) {
					printf("\n\tThe information successfully registered...");

					strcpy(death[counter_death + 1].name, ordinary_user[i].name);
					strcpy(death[counter_death + 1].name_kh, ordinary_user[i].name_kh);
					strcpy(death[counter_death + 1].code_melli, ordinary_user[i].code_melli);
					death[counter_death + 1].time = time(NULL);
					counter_death++;

					for (; i <= counter_ordinary_user; i++) {
						ordinary_user[i] = ordinary_user[i + 1];
					}
					counter_ordinary_user--;

					Sleep(2800);

					continue;
				}

				else if (r == 2) {
					continue;
				}
			}
		}
	}
}
//______________________________________________________________________________________________________________
void View_dead_users() {
	system("cls");
	system("color c0");
	FILE* a = fopen("fdeath.txt", "r");
	printf("\n\n\tThis list sorted based on history of death\n\n");

	bool z = true;
	for (int i = counter_death; i >= 0; i--) {
		if (z) {
			printf("\t%-15s %-20s %s\n\n", "Name", "Family name", "National code");
			z = false;
		}
		printf("\t%-15s %-20s %s\n", death[i].name, death[i].name_kh, death[i].code_melli);
	}

	printf("\n\n	press enter to back menu\n	");
	getchar();
	return;
}
//_____________________________________________________________________________________________________________________
void View_the_near_hospitals(int i) {
	while (1) {
		system("cls");
		system("color d7");
		printf("\n\n\tHello %s%c. you can search the closest hospitals to yourself in this side %c", ordinary_user[i].name, 3, 1);
		struct hospital temp;
		printf("\n\n\tState: ");
		scanf("%[^\n]s", temp.state);
		getchar();
		if (temp.state[0] == '~') {
			return;
		}

		printf("\n\tCity: ");
		scanf("%[^\n]s", temp.city);
		getchar();
		if (temp.city[0] == '~') {
			continue;
		}

		printf("\n\tRegion: ");
		scanf("%[^\n]s", temp.mantagheh);
		getchar();
		if (temp.mantagheh[0] == '~') {
			continue;
		}

		puts("\n");
		int z = 0;
		for (int i = 0; i <= counter_hospital; i++) {
			if ((strcmpi(temp.mantagheh, hospital[i].mantagheh) == 0) && (strcmpi(temp.state, hospital[i].state) == 0) && (strcmpi(temp.city, hospital[i].city) == 0)) {
				if (z == 0) {
					printf("\t%-20s %s\n\n", "Hospital name", "Hospital address");
				}
				printf("\t%-20s %s\n", hospital[i].name, hospital[i].address);
				z++;
			}
		}
		if (z == 0) {
			for (int i = 0; i <= counter_hospital; i++) {
				if ((strcmpi(temp.state, hospital[i].state) == 0) && strcmpi(temp.city, hospital[i].city) == 0) {
					if (z == 0) {
						printf("\t%-10s %-20s %s\n\n", "Region", "Hospital name", "Hospital address");
					}
					printf("\t%-10s %-20s %s\n", hospital[i].mantagheh, hospital[i].name, hospital[i].address);
					z++;
				}
			}
		}
		if (z == 0) {
			for (int i = 0; i <= counter_hospital; i++) {
				if (strcmpi(temp.state, hospital[i].state) == 0) {
					if (z == 0) {
						printf("\t%-10s %-10s %-15s %s\n\n", "City", "Region", "Hospital name", "Hospital address");
					}
					printf("\t%-10s %-10s %-15s %s\n", hospital[i].city, hospital[i].mantagheh, hospital[i].name, hospital[i].address);
					z++;
				}
			}
		}
		if (z == 0) {
			printf("\tUnfortunately no hospital were found around you");
		}

		printf("\n\n	press enter to back menu\n	");
		getchar();
		return;
	}
}
//________________________________________________________________________________________________________________________
void To_add_place_that_be_gone(int x) {
	while (1) {
		system("cls");
		system("color e8");
		printf("\n\n\tHello %s%c You can search name of places and decide that...", ordinary_user[x].name, 3);
		printf("\n\n\tName of place: ");
		char a[20];
		scanf("%[^\n]s", a);
		getchar();
		if (a[0] == '~') {
			return;
		}
		int i = 0;
		for (; i <= counter_employer; i++) {
			if (strcmpi(a, employer[i].name_sherkat) == 0) {
				printf("\n\n\tThe name of place: %s", employer[i].name_sherkat);
				printf("\n\tThe city of place: %s", employer[i].city_sherkat);
				printf("\n\tThe region of place: %s", employer[i].mantaghe_sherkat);
				if (strcmpi(employer[i].code_sherkat, "White") == 0) {
					printf("\n\n\tThe healthy code of this place is *WHITE* :)");
					printf("\n\n\tYou can go there with following health protocols");
					printf("\n\tIf you wanna to go there input 1 or if cancel it input 2\n\tInput: ");
					int n;
					scanf("%d", &n);

					if (n == 1) {
						strcpy(ordinary_user[x].name_and_status_of_place[0][ordinary_user[x].counter_history_of_place_that_be_gone], employer[i].name_sherkat);
						strcpy(ordinary_user[x].name_and_status_of_place[1][ordinary_user[x].counter_history_of_place_that_be_gone], "White");
						ordinary_user[x].code_in_place[ordinary_user[x].counter_history_of_place_that_be_gone] = ordinary_user[x].code;
						ordinary_user[x].history_of_place_that_be_gone[ordinary_user[x].counter_history_of_place_that_be_gone] = time(NULL);
						ordinary_user[x].counter_history_of_place_that_be_gone++;
						if (ordinary_user[x].code == 4) {
							strcpy(employer[i].code_sherkat, "Red");
							employer[i].time_vorood_bimar = time(NULL);
						}
					}

					printf("\n\n	press enter to back menu\n	");
					getchar();
					getchar();
					return;
				}
				else {
					int n;
					printf("\n\n\tThe healthy code of this place is *RED* :(");
					printf("\n\n\tUnfortunately this place is very dangrous and we recommend to you that don't go there");
					printf("\n\tBut if you wanna to go there input 1 or if cancel it input 2\n\tInput: ");
					scanf("%d", &n);
					if (n == 1) {
						strcpy(ordinary_user[x].name_and_status_of_place[0][ordinary_user[x].counter_history_of_place_that_be_gone], employer[i].name_sherkat);
						strcpy(ordinary_user[x].name_and_status_of_place[1][ordinary_user[x].counter_history_of_place_that_be_gone], "Red");
						ordinary_user[x].code_in_place[ordinary_user[x].counter_history_of_place_that_be_gone] = ordinary_user[x].code;
						ordinary_user[x].history_of_place_that_be_gone[ordinary_user[x].counter_history_of_place_that_be_gone] = time(NULL);
						ordinary_user[x].counter_history_of_place_that_be_gone++;
						if (ordinary_user[x].code == 4) {
							employer[i].time_vorood_bimar = time(NULL);
						}

						if (ordinary_user[x].code == 1) {
							if (ordinary_user[x].counter_history_of_health_status < 10) {
								ordinary_user[x].counter_history_of_health_status++;
							}
							else {
								for (int j = 1; j < 10; j++) {
									ordinary_user[x].code_10[j] = ordinary_user[x].code_10[j + 1];
									ordinary_user[x].history_of_health_status[j] = ordinary_user[i].history_of_health_status[j + 1];
								}
							}
							ordinary_user[x].code = 2;

							char p[100];
							strcpy(p, "your health code increases to 2 because you went to a red place(");
							strcat(p, employer[i].name_sherkat);
							strcat(p, ")");
							note(x);
							strcpy(ordinary_user[x].notification[ordinary_user[x].counter_note], p);
							ordinary_user[x].notif[ordinary_user[x].counter_note] = time(NULL);

							ordinary_user[x].catch_code[2] = time(NULL);
							ordinary_user[x].history_of_health_status[ordinary_user[x].counter_history_of_health_status] = time(NULL);
							ordinary_user[x].code_10[ordinary_user[x].counter_history_of_health_status] = 2;
						}
						printf("\n\n\tGo but very very be carefull :|");
						printf("\n\n	press enter to back menu\n	");
						getchar();
						getchar();
						return;
					}
					else {
						printf("\n\n\tThank you very much to give up :)");
						printf("\n\n	press enter to back menu\n	");
						getchar();
						getchar();
						return;
					}
				}
			}
		}
		if (i > counter_employer) {
			printf("\n\n\tThis name is not exist. Try again...");
			Sleep(3000);
			continue;
		}
	}
}
//______________________________________________________________________________________________________________
void History_of_place_that_be_gone(int i) {
	system("cls");
	system("color c0");
	printf("\n\n\tHello %s%c You can see last 10 place that go there in this side\n\n", ordinary_user[i].name, 3);
	for (int s = 0; (s < 10) && (s < ordinary_user[i].counter_history_of_place_that_be_gone); s++) {
		struct tm* a = localtime(&(ordinary_user[i].history_of_place_that_be_gone[ordinary_user[i].counter_history_of_place_that_be_gone - s - 1]));
		printf("\t%-5s  %d  %-20s  %s\n", ordinary_user[i].name_and_status_of_place[1][ordinary_user[i].counter_history_of_place_that_be_gone - s - 1], ordinary_user[i].code_in_place[ordinary_user[i].counter_history_of_place_that_be_gone - s - 1], ordinary_user[i].name_and_status_of_place[0][ordinary_user[i].counter_history_of_place_that_be_gone - s - 1], asctime(a));
	}

	printf("\n\n	press enter to back menu\n	");
	getchar();
	return;
}
//_______________________________________________________________________________________________________________
void Statistics_of_covid19() {
	system("cls");
	system("color a0");

	int a[10] = { 0 };
	time_t b = time(NULL);

	for (int i = 0; i <= counter_ordinary_user; i++) {
		if (ordinary_user[i].code == 3) {
			a[0]++;
		}
		if ((ordinary_user[i].code == 3) && ((b - ordinary_user[i].catch_code[3]) < 86400)) {
			a[1]++;
		}
		if ((ordinary_user[i].code == 3) && ((b - ordinary_user[i].catch_code[3]) < 604800)) {
			a[2]++;
		}
		if (ordinary_user[i].code == 4) {
			a[3]++;
		}
		if ((ordinary_user[i].code == 4) && ((b - ordinary_user[i].catch_code[4]) < 86400)) {
			a[4]++;
		}
		if ((ordinary_user[i].code == 4) && ((b - ordinary_user[i].catch_code[4]) < 604800)) {
			a[5]++;
		}
		if (ordinary_user[i].catch_code[4] != 0) {
			a[9]++;
		}
	}
	a[6] = counter_death + 1;
	for (int i = 0; i <= counter_death; i++) {
		if ((b - death[i].time) < 86400) {
			a[7]++;
		}
		if ((b - death[i].time) < 604800) {
			a[8]++;
		}
	}

	printf("\n\n\tThe number of dangrous person(3) is | %d | until now", a[0]);
	printf("\n\tThe number of dangrous person(3) is | %d | in 24 hours ago", a[1]);
	printf("\n\tThe number of dangrous person(3) is | %d | in a week ago", a[2]);

	printf("\n\n\tThe number of patients(4) is | %d | until now", a[3]);
	printf("\n\tThe number of patients(4) is | %d | in 24 hours ago", a[4]);
	printf("\n\tThe number of patients(4) is | %d | in a week ago", a[5]);

	printf("\n\n\tThe number of dead person is | %d | until now", a[6]);
	printf("\n\tThe number of dead person is | %d | in 24 hours ago", a[7]);
	printf("\n\tThe number of dead person is | %d | in a week ago", a[8]);

	printf("\n\n\tTotal number of patients in total is | %d |", a[9]);

	printf("\n\n	press enter to back menu\n	");
	getchar();
	return;
}
//______________________________________________________________________________________________________________________
void View_patients(int z) {
	system("cls");
	system("color a0");

	int a[6] = { 0 };
	time_t b = time(NULL);

	for (int i = 0; i <= counter_ordinary_user; i++) {
		for (int j = 0; j < ordinary_user[i].counter_history_of_place_that_be_gone; j++) {

			if (strcmpi(employer[z].name_sherkat, ordinary_user[i].name_and_status_of_place[0][j]) == 0) {
				if (ordinary_user[i].code_in_place[j] == 4) {
					if (b - ordinary_user[i].history_of_place_that_be_gone[j] < 604800) {
						a[5]++;
					}
					a[4]++;
				}

				else if (ordinary_user[i].code_in_place[j] == 3) {
					if (b - ordinary_user[i].history_of_place_that_be_gone[j] < 604800) {
						a[3]++;
					}
					a[2]++;
				}

				else if (ordinary_user[i].code_in_place[j] == 2) {
					if (b - ordinary_user[i].history_of_place_that_be_gone[j] < 604800) {
						a[1]++;
					}
					a[0]++;
				}
			}
		}
	}

	printf("\n\n\tThe number of patients(4) is | %d | until now", a[4]);
	printf("\n\tThe number of patients(4) is | %d | in a week ago", a[5]);

	printf("\n\n\tThe number of dangrous person(3) is | %d | until now", a[2]);
	printf("\n\tThe number of dangrous person(3) is | %d | in a week ago", a[3]);

	printf("\n\n\tThe number of suspicious person(2) is | %d | until now", a[0]);
	printf("\n\tThe number of suspicious person(2) is | %d | in a week ago", a[1]);

	printf("\n\n	press enter to back menu\n	");
	getchar();
	return;
}
//_____________________________________________________________________________________________________________________
void checking_code() {
	time_t now = time(NULL);
	for (int i = 0; i <= counter_ordinary_user; i++) {
		if (ordinary_user[i].code == 2) {
			if (now - ordinary_user[i].catch_code[2] > 604800) {
				ordinary_user[i].catch_code[1] = time(NULL);
				ordinary_user[i].code = 1;

				note(i);
				strcpy(ordinary_user[i].notification[ordinary_user[i].counter_note], "Your health code decrease to 1 after a week");
				ordinary_user[i].notif[ordinary_user[i].counter_note] = time(NULL);

			}
		}
		else if (ordinary_user[i].code == 3) {
			if (now - ordinary_user[i].catch_code[3] > 604800) {
				ordinary_user[i].catch_code[2] = time(NULL);
				ordinary_user[i].code = 2;

				note(i);
				strcpy(ordinary_user[i].notification[ordinary_user[i].counter_note], "Your health code decrease to 1 after a week");
				ordinary_user[i].notif[ordinary_user[i].counter_note] = time(NULL);
			}
		}
	}
}
//______________________________________________________________________________________________________________________
void check_code_sherkat() {
	time_t now = time(NULL);
	for (int i = 0; i <= counter_employer; i++) {
		if (strcmpi(employer[i].code_sherkat, "Red") == 0) {
			if (now - employer[i].time_vorood_bimar > 1209600) {
				strcpy(employer[i].code_sherkat, "white");
			}
		}
	}
}
//_____________________________________________________________________________________________________________________
void To_register_visit_another(int x) {
	char a[11];
	while (1) {
		system("cls");
		system("color f4");
		printf("\n\n\tHello %s %c\n\tYou can input national code in this side and influence on person's health code and yourself health code", ordinary_user[x].name, 3);
		printf("\n\n\tNational code of the person who visited: ");
		scanf("%s", a);
		if (a[0] == '~') {
			return;
		}
		if (strcmpi(a, ordinary_user[x].code_melli) == 0) {
			printf("\n\n\tYou can not visit yourself");
			Sleep(3000);
			continue;
		}
		int i = 0;
		for (; i <= counter_ordinary_user; i++) {
			if (strcmp(a, ordinary_user[i].code_melli) == 0) {
				strcpy(ordinary_user[i].code_melli_met[ordinary_user[i].counter_met], ordinary_user[x].code_melli);
				strcpy(ordinary_user[x].code_melli_met[ordinary_user[x].counter_met], a);
				ordinary_user[i].history_met[ordinary_user[i].counter_met] = time(NULL);
				ordinary_user[x].history_met[ordinary_user[x].counter_met] = time(NULL);
				ordinary_user[i].counter_met++;
				ordinary_user[x].counter_met++;

				if (ordinary_user[i].code == 4) {
					check_step_to_step4(i);
				}
				if (ordinary_user[i].code == 3) {
					check_step_to_step3(i);
				}
				if (ordinary_user[x].code == 4) {
					check_step_to_step4(x);
				}
				if (ordinary_user[x].code == 3) {
					check_step_to_step3(x);
				}

				printf("\n\n\tThis meet has saved successfully");
				printf("\n\n\tpress enter to back menu\n	");
				getchar();
				getchar();
				return;
			}
		}
		if (i > counter_ordinary_user) {
			printf("\n\n\tThis national code is not exist");
			printf("\n\tTry again...");
			Sleep(3000);
		}
	}
}
//_________________________________________________________________________________________________________________
void check_step_to_step4(int x) {
	time_t now = time(NULL);
	for (int i = ordinary_user[x].counter_met - 1; i >= 0 && now - ordinary_user[x].history_met[i] < 604800; i--) {
		for (int j = 0; j <= counter_ordinary_user; j++) {
			if (strcmp(ordinary_user[x].code_melli_met[i], ordinary_user[j].code_melli) == 0) {

				if (ordinary_user[j].code == 4) {
					break;
				}
				else {
					if (ordinary_user[j].counter_history_of_health_status < 10) {
						ordinary_user[j].counter_history_of_health_status++;
					}
					else {
						for (int v = 1; v < 10; v++) {
							ordinary_user[j].code_10[v] = ordinary_user[j].code_10[v + 1];
							ordinary_user[j].history_of_health_status[v] = ordinary_user[j].history_of_health_status[v + 1];
						}
					}
					ordinary_user[j].code = 3;
					ordinary_user[j].catch_code[3] = time(NULL);
					ordinary_user[j].history_of_health_status[ordinary_user[j].counter_history_of_health_status] = time(NULL);
					ordinary_user[j].code_10[ordinary_user[j].counter_history_of_health_status] = 3;

					char s[100];
					strcpy(s, ordinary_user[x].name);
					strcat(s, " ");
					strcat(s, ordinary_user[x].name_kh);
					strcat(s, " has visited you so your health code updated to 3");

					note(j);
					strcpy(ordinary_user[j].notification[ordinary_user[j].counter_note], s);
					ordinary_user[j].notif[ordinary_user[j].counter_note] = time(NULL);
				}

				for (int p = ordinary_user[j].counter_met - 1; p >= 0 && now - ordinary_user[j].history_met[p] < 604800; p--) {
					for (int j1 = 0; j1 <= counter_ordinary_user; j1++) {
						if (strcmp(ordinary_user[j1].code_melli_met[p], ordinary_user[j1].code_melli) == 0) {

							if (ordinary_user[j1].code == 4 || ordinary_user[j1].code == 3) {
								break;
							}
							else {
								if (ordinary_user[j1].counter_history_of_health_status < 10) {
									ordinary_user[j1].counter_history_of_health_status++;
								}
								else {
									for (int v1 = 1; v1 < 10; v1++) {
										ordinary_user[j1].code_10[v1] = ordinary_user[j1].code_10[v1 + 1];
										ordinary_user[j1].history_of_health_status[v1] = ordinary_user[j1].history_of_health_status[v1 + 1];
									}
								}
								ordinary_user[j1].code = 2;
								ordinary_user[j1].catch_code[2] = time(NULL);
								ordinary_user[j1].history_of_health_status[ordinary_user[j1].counter_history_of_health_status] = time(NULL);
								ordinary_user[j1].code_10[ordinary_user[j1].counter_history_of_health_status] = 2;

								char s[100];
								strcpy(s, ordinary_user[j].name);
								strcat(s, " ");
								strcat(s, ordinary_user[j].name_kh);
								strcat(s, " has visited you so your health code updated to 2");

								note(j1);
								strcpy(ordinary_user[j1].notification[ordinary_user[j1].counter_note], s);
								ordinary_user[j1].notif[ordinary_user[j1].counter_note] = time(NULL);
							}
						}
					}
				}
			}
		}
	}
}
//_________________________________________________________________________________________________________________
void check_step_to_step3(int j) {
	time_t now = time(NULL);
	for (int p = ordinary_user[j].counter_met - 1; p >= 0 && now - ordinary_user[j].history_met[p] < 604800; p--) {
		for (int j1 = 0; j1 <= counter_ordinary_user; j1++) {
			if (strcmp(ordinary_user[j].code_melli_met[p], ordinary_user[j1].code_melli) == 0) {

				if (ordinary_user[j1].code == 4 || ordinary_user[j1].code == 3) {
					break;
				}
				else {
					if (ordinary_user[j1].counter_history_of_health_status < 10) {
						ordinary_user[j1].counter_history_of_health_status++;
					}
					else {
						for (int v1 = 1; v1 < 10; v1++) {
							ordinary_user[j1].code_10[v1] = ordinary_user[j1].code_10[v1 + 1];
							ordinary_user[j1].history_of_health_status[v1] = ordinary_user[j1].history_of_health_status[v1 + 1];
						}
					}
					ordinary_user[j1].code = 2;
					ordinary_user[j1].catch_code[2] = time(NULL);
					ordinary_user[j1].history_of_health_status[ordinary_user[j1].counter_history_of_health_status] = time(NULL);
					ordinary_user[j1].code_10[ordinary_user[j1].counter_history_of_health_status] = 2;

					char s[100];
					strcpy(s, ordinary_user[j].name);
					strcat(s, " ");
					strcat(s, ordinary_user[j].name_kh);
					strcat(s, " has visited you so your health code updated to 2");

					note(j1);
					strcpy(ordinary_user[j1].notification[ordinary_user[j1].counter_note], s);
					ordinary_user[j1].notif[ordinary_user[j1].counter_note] = time(NULL);
				}
			}
		}
	}
}
//________________________________________________________________________________________________________________
void History_of_visit_another(int z) {
	system("cls");
	system("color c0");
	printf("\n\n\tCode  %-10s %-15s  %-13s  %s\n", "Name", "Family name", "National code", "Time");
	for (int i = 0; i < 10 && i < ordinary_user[z].counter_met; i++) {
		int j = 0;
		for (; j <= counter_ordinary_user; j++) {
			if (strcmp(ordinary_user[z].code_melli_met[ordinary_user[z].counter_met - 1 - i], ordinary_user[j].code_melli) == 0) {
				struct tm* a = localtime(&ordinary_user[z].history_met[ordinary_user[z].counter_met - 1 - i]);
				printf("\n\t%4d  %-10s %-15s  %-13s  %s", ordinary_user[j].code, ordinary_user[j].name, ordinary_user[j].name_kh, ordinary_user[j].code_melli, asctime(a));
				break;
			}
		}
		if (j > counter_ordinary_user) {
			for (int w = 0; w <= counter_death; w++) {
				if (strcmp(ordinary_user[z].code_melli_met[ordinary_user[z].counter_met - 1 - i], death[w].code_melli) == 0) {
					struct tm* a = localtime(&ordinary_user[z].history_met[ordinary_user[z].counter_met - 1 - i]);
					printf("\n\tDead  %-10s %-15s  %-13s  %s", death[w].name, death[w].name_kh, death[w].code_melli, asctime(a));
				}
			}
		}
	}
	printf("\n\n	press enter to back menu\n	");
	getchar();
	return;
}
//______________________________________________________________________________________________________________________
void notification(int i) {
	system("cls");
	system("color e4");
	printf("\n\n\tHello %s %c There are your last 15 notifications\n\n", ordinary_user[i].name, 3);
	for (int z = ordinary_user[i].counter_note; z > 0; z--) {
		struct tm* a = localtime(&ordinary_user[i].notif[z]);
		char w[50];
		strcpy(w, asctime(a));
		w[strlen(w) - 1] = '\0';
		printf("\t%s %c %s\n", w, 219, ordinary_user[i].notification[z]);
	}

	printf("\n\n	press enter to back menu\n	");
	getchar();
	return;
}
//______________________________________________________________________________________________________________________
void note(int i) {
	if (ordinary_user[i].counter_note < 15) {
		ordinary_user[i].counter_note++;
	}
	else {
		for (int j = 1; j < 15; j++) {
			strcpy(ordinary_user[i].notification[j], ordinary_user[i].notification[j + 1]);
		}
	}
}
//____________________________________________________________________________________________________________________
void message(int i) {
	if (ordinary_user[i].counter_message < 20) {
		ordinary_user[i].counter_message++;
	}
	else {
		for (int j = 1; j < 20; j++) {
			strcpy(ordinary_user[i].message[j], ordinary_user[i].message[j + 1]);
		}
	}
}
//__________________________________________________________________________________________________________________
void Message_to_admin(int i) {
	system("color a0");
	system("cls");
	printf("\n");
	printf("\t  _____   ____   ______ ___________     ____   ____   _______  ____   ____   _____  \n");
	printf("\t /     \\_/ __ \\ /  ___//  ___/\\__  \\   / ___\\_/ __ \\  \\_  __ \\/  _ \\ /  _ \\ /     \\ \n");
	printf("\t|  Y Y  \\  ___/ \\___ \\ \\___ \\  / __ \\_/ /_/  >  ___/   |  | \\(  <_> |  <_> )  Y Y  \\\n");
	printf("\t|__|_|  /\\___  >____  >____  >(____  /\\___  / \\___  >  |__|   \\____/ \\____/|__|_|  /\n");
	printf("\t      \\/     \\/     \\/     \\/      \//_____/      \\/                             \\/ \n");
	printf("\n\n");
	for (int z = ordinary_user[i].counter_message; z > 0; z--) {
		printf("\t%s\n", ordinary_user[i].message[z]);
	}

	printf("\n\n\tIf you want to send message input 1 else input 0 to go back\n\tInput: ");
	int n;
	scanf("%d", &n);
	while (1) {
		if (n == 0) {
			return;
		}
		else if (n == 1) {
			printf("\n\n\tWhat is your message? At the end of your message use /\n\n\t");
			ordinary_user[i].last_message = time(NULL);
			message(i);
			getchar();
			scanf("%[^/]s", ordinary_user[i].message[ordinary_user[i].counter_message]);
			break;
		}
	}
}