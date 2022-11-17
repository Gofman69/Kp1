#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <locale.h>



void main()

{
	char* names[5] = { "Н.В.Стэтхем","Д.Ю.Лисов","Р.Д.Младший","Д.Р.Кемпербетч","П.П.Ватсон" };

	int hours[5][4] =
	{ {1,3,2,0},
	{1,2,1,0} ,
	{2,3,2,0},
	{2,4,2,0},
	{2,4,3,0} };

	int minutes[5][4] =
	{ {11,32,27,0},
	{12,22,12,0} ,
	{24,32,24,0},
	{25,44,24,0},
	{28,42,31,0} };

	float seconds[5][4] =
	{ {48.3,32.2,28.9,0},
	{39.2,23.1,11.1,0} ,
	{32.21,33,2,0},
	{20.2,42.2,50,0},
	{22,43.4,33.2,0} };

	int points[5][1] =
	{ {11},
	{14},
	{10},
	{7},
	{3} };

	int place[5][1] =
	{ {2},
	{1},
	{3},
	{4},
	{5} };


	int selection;

	setlocale(LC_ALL, "Rus");
	printf("Создание таблицы.\n\n");
	
	printf("1) Вывести таблицу.\n2) Изменить таблицу.\n3) Вывести введённые константы.\n\n");
	printf("Выберите и введите номер функции: ");
	scanf("%d", &selection);

	switch (selection) {
	case 1:
		printf("\n");
		printf("========================================================================================================\n");
		printf("|%6s|%17s|%12s|%12s|%12s|%12s|%12s|%12s|\n", "Жребий", "ФИО", "1-Заезд", "2-Заезд", "3-Заезд", "Кол-во очков", "Общее время", "Место");
		printf("========================================================================================================\n");
		for (int i = 0; i < 5; i++) {
			printf("|%6d|", i + 1);
			for (int a = 0; a < 1; a++) {
				printf("|%16s|", names[i]);
			}
			for (int b = 0; b < 1; b++) {
				printf("|%3d:%2d:%4.1f|", hours[i][b], minutes[i][b], seconds[i][b]);
			}
			for (int b = 1; b < 2; b++) {
				printf("|%3d:%2d:%4.1f|", hours[i][b], minutes[i][b], seconds[i][b]);
			}
			for (int b = 2; b < 3; b++) {
				printf("|%3d:%2d:%4.1f|", hours[i][b], minutes[i][b], seconds[i][b]);
			}
			for (int b = 0; b < 1; b++) {
				printf("|%11d|", points[i][b]);
			}
			for (int b = 3; b < 4; b++) {
				int seconds_int;

				hours[i][b] = hours[i][0] + hours[i][1] + hours[i][2];
				minutes[i][b] = minutes[i][0] + minutes[i][1] + minutes[i][2];
				seconds[i][b] = seconds[i][0] + seconds[i][1] + seconds[i][2];

				seconds_int = seconds[i][b];
				if (seconds_int > 60) {
					seconds_int -= 60;
					seconds[i][b] -= 60;
					minutes[i][b] += 1;
				}
				if (minutes[i][b] > 60) {
					minutes[i][b] -= 60;
					hours[i][b] += 1;
				}
				printf("|%3d:%2d:%4.1f|", hours[i][b], minutes[i][b], seconds[i][b]);
			}
			for (int b = 0; b < 1; b++) {
				printf("|%11d|", place[i][b]);

			} printf("\n");
		}
		printf("========================================================================================================\n");
		break;
	}
	getchar();
	return 0;
}