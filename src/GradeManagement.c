#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stuIds[50][10];
float grades[50];
int cnt = 0;

int findByStudentId(char id[10]) {
	for (int i = 0; i < cnt; i++) {
		if (strcmp(stuIds[i], id) == 0) {
			return i;
		}
	}
	return -1;
}

void show(int index) {
	printf("\n| Index | Student ID | Grade |");
	if (index <= -1) {
		for (int i = 0; i < cnt; i++) {
			printf("\n| %d | %s | %f |", i + 1, stuIds[i], grades[i]);
		}
	} else {
		printf("\n| %d | %s | %f |", index + 1, stuIds[index], grades[index]);
	}
}

void sortById(int mode) {
	char tempId[10];
	float tempGrade;

	if(mode == 0) {
		for (int i = 0; i < cnt; i++) {
			for (int y = 0; y < cnt; y++) {
				if(strcmp(stuIds[i], stuIds[y]) < 0) {
					strcpy(tempId, stuIds[i]);
					strcpy(stuIds[i], stuIds[y]);
					strcpy(stuIds[y], tempId);

					tempGrade = grades[i];
					grades[i] = grades[y];
					grades[y] = tempGrade;
				}
			}
		}
	} else {
		for (int i = 0; i < cnt; i++) {
			for (int y = 0; y < cnt; y++) {
				if(strcmp(stuIds[i], stuIds[y]) > 0) {
					strcpy(tempId, stuIds[i]);
					strcpy(stuIds[i], stuIds[y]);
					strcpy(stuIds[y], tempId);

					tempGrade = grades[i];
					grades[i] = grades[y];
					grades[y] = tempGrade;
				}
			}
		}
	}
}

void sortByGrade(int mode) {
	char tempId[10];
	float tempGrade;

	if(mode == 0) {
		for (int i = 0; i < cnt; i++) {
			for (int y = 0; y < cnt; y++) {
				if(grades[i] > grades[y]) {
					strcpy(tempId, stuIds[i]);
					strcpy(stuIds[i], stuIds[y]);
					strcpy(stuIds[y], tempId);

					tempGrade = grades[i];
					grades[i] = grades[y];
					grades[y] = tempGrade;
				}
			}
		}
	} else {
		for (int i = 0; i < cnt; i++) {
			for (int y = 0; y < cnt; y++) {
				if(grades[i] < grades[y]) {
					strcpy(tempId, stuIds[i]);
					strcpy(stuIds[i], stuIds[y]);
					strcpy(stuIds[y], tempId);

					tempGrade = grades[i];
					grades[i] = grades[y];
					grades[y] = tempGrade;
				}
			}
		}
	}
}

int main(void) {

	int opt = 0;
	int index = -1;

	do {
		printf("\n1. GRADE BOARD");
		printf("\n2. SORTING GRADE BOARD");
		printf("\n3. SEARCH");
		printf("\n4. ADD NEW GRADEs");
		printf("\n5. EDIT GRADEs");
		printf("\n6. REMOVE GRADEs");
		printf("\n7. EXIT PROGRAM");

		printf("\nENTER A MENU INDEX:");
		fflush (stdout);
		scanf("%d", &opt);
		fflush (stdin);

		switch (opt) {
		    case 1:
		    	printf("\nGRADE BOARD!");
		    	show(index);
		    	printf("\nPress any key to back to the Menu!");
		    		fflush(stdout);
		    		getchar();
		    		fflush(stdin);
		      break;
		    case 2:
		    	int sortOpt;
				do {
					printf("\n1. SORT BY STUDENT ID - ASC");
					printf("\n2. SORT BY STUDENT ID - DESC");
					printf("\n3. SORT BY GRADE - HIGHEST TO HIGHEST");
					printf("\n4. SORT BY GRADE - LOWEST TO LOWEST");
					printf("\n5. BACK TO MENU");
					printf("\nENTER SORTING OPTION:");
					fflush (stdout);
					scanf("%d", &sortOpt);
					fflush (stdin);
					switch (sortOpt) {
						case 1:
							printf("\nSORT BY STUDENT ID - ASC");
							sortById(0);
							show(-1);
							printf("\nPress any key to back to the Menu!");
								fflush(stdout);
								getchar();
								fflush(stdin);
						  break;
						case 2:
							printf("\nSORT BY STUDENT ID - DESC");
							sortById(1);
							show(-1);
							printf("\nPress any key to back to the Menu!");
								fflush(stdout);
								getchar();
								fflush(stdin);
						  break;
						case 3:
							printf("\nSORT BY GRADE - HIGHEST TO LOWEST");
							sortByGrade(0);
							show(-1);
							printf("\nPress any key to back to the Menu!");
								fflush(stdout);
								getchar();
								fflush(stdin);
						  break;
						case 4:
							printf("\nSORT BY GRADE - LOWEST TO HIGHEST");
							sortByGrade(1);
							show(-1);
							printf("\nPress any key to back to the Menu!");
								fflush(stdout);
								getchar();
								fflush(stdin);
						  break;
						case 5:
							printf("\nBack to Main Menu...");
						  break;
						default:
							printf("PLEASE INPUT A CORRECT INDEX OPTION!");
							break;
					}
				} while (sortOpt != 5);
		      break;
		    case 3:
		    	int searchOpt;
				do {
					printf("\n1. SEARCH BY STUDENT ID");
					printf("\n2. FIND HIGHEST GRADE");
					printf("\n3. FIND LOWEST GRADE");
					printf("\n4. BACK TO MENU");
					printf("\nENTER SEARCHING OPTION:");
					fflush(stdout);
					scanf("%d", &searchOpt);
					fflush(stdin);
					switch (searchOpt) {
						case 1:

								int index;
								char id[10];
								char cont;
								printf("\nSEARCH BY STUDENT ID");
								do {
									printf("\nEnter Student ID:");
									fflush(stdout);
									scanf("%s", &id);
									fflush(stdin);

									index = findByStudentId(id);
									if (index > -1) {
										show(index);
									} else {
										printf("Student ID '%s' does not exist, please try again!", id);
									}
										printf("\nDo you want to continue? (Y/N)");
										fflush(stdout);
										scanf("%c", &cont);
										fflush(stdin);
								} while (cont == 'Y' || cont == 'y');
						  break;
						case 2:
							printf("\nFIND HIGHEST GRADE");
							sortByGrade(0);
							show(0);
							printf("\nPress any key to back to the Menu!");
								fflush(stdout);
								getchar();
								fflush(stdin);
						  break;
						case 3:
							printf("\nFIND LOWEST GRADE");
							sortByGrade(1);
							show(0);
							printf("\nPress any key to back to the Menu!");
								fflush(stdout);
								getchar();
								fflush(stdin);
						case 4:
							printf("\nBack to Main Menu...");
						  break;
						default:
							printf("PLEASE INPUT A CORRECT INDEX OPTION!");
							break;
					}
				} while(searchOpt != 4);
			  break;
		    case 4:
				char id[10];
				char cont = 'N';
				printf("\nADD NEW GRADE");
				do {
					printf("\nEnter New Student ID:");
					fflush(stdout);
					scanf("%s", &id);
					fflush(stdin);

					if (findByStudentId(id) <= -1) {
						strcpy(stuIds[cnt], id);

						printf("Enter Grade of Student %s: ", stuIds[cnt]);
						fflush(stdout);
						scanf("%f", &grades[cnt]);
						fflush(stdin);

						cnt++;
						printf("\nAdded successfully!");
					} else {
						printf("Student ID '%s' is already existed, please try again!", id);
					}
					printf("\nDo you want to continue? (Y/N)");
								fflush(stdout);
								scanf("%c", &cont);
								fflush(stdin);
				} while(cont == 'Y' || cont == 'y');
				break;
		    case 5:
				int index;
				char id[10];
				char cont;
				printf("\nEDIT A GRADE");
				do {
					printf("\nEnter Student ID:");
					fflush(stdout);
					scanf("%s", &id);
					fflush(stdin);

					index = findByStudentId(id);

					if (index > -1) {
						show(index);

						printf("\nEnter New Grade for Student '%s': ", id);
						fflush(stdout);
						scanf("%f", &grades[index]);
						fflush(stdin);

						printf("Edited successfully!");
					} else {
						printf("Student ID '%s' does not exist, please try again!", id);
					}
					printf("\nDo you want to continue? (Y/N)");
								fflush(stdout);
								scanf("%c", &cont);
								fflush(stdin);
				} while (cont == 'Y' || cont == 'y');
			  break;
		    case 6:
				int index;
				char id[10];
				char cont;
				char confirm;
				printf("\nREMOVE A GRADE");
				do {
					printf("\nEnter Student ID:");
					fflush(stdout);
					scanf("%s", &id);
					fflush(stdin);

					index = findByStudentId(id);
					if (index > -1) {
						show(index);
						printf("\nDo you want to remove Grade of Student '%s'? (Y/N)", id);
						fflush(stdout);
						scanf("%s", &confirm);
						fflush(stdin);

						if (confirm == 'Y' || confirm == 'y') {
							strcpy(stuIds[index], stuIds[cnt - 1]);
							strcpy(stuIds[cnt - 1], "");

							grades[index] = grades[cnt - 1];
							grades[cnt - 1] = 0;
							cnt--;
							printf("Student '%s' has been removed successfully!", id);
						} else {
							printf("Removing has been cancelled!");
						}
					} else {
						printf("Student ID '%s' does not exist, please try again!", id);
					}
					printf("\nDo you want to continue? (Y/N)");
								fflush(stdout);
								scanf("%c", &cont);
								fflush(stdin);
				} while (cont == 'Y' || cont == 'y');
			  break;
		    case 7:
				printf("\nEXISTED");
				return 0;
			  break;
		    default:
		    	printf("PLEASE INPUT A CORRECT MENU INDEX!");
		    	break;
		}
	} while (opt != 7);

	return 0;
}
