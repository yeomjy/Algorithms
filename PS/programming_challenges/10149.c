#include <stdio.h>

int get_score(int *arr, int category);
int naive_search(int arr[13][5], int stage, int *score, int *bonus);

int main(void)
{

	int arr[13][5];
	int score[13] = {-1};
	int bonus = 0;
	int i;
	char buf[100];
	int a = 0;
	/*
	Check: 모든 숫자의 합으로 정렬 후 그리디?
	*/

	while (1)
	{
		a++;
		for (i = 0; i < 13; i++)
		{
			if (fgets(buf, 99, stdin) == NULL)
				goto EXIT;

			sscanf(buf, "%d %d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3], &arr[i][4]);
			score[i] = -1;
		}
		bonus = 0;

		int total = naive_search(arr, 1, score, &bonus);
		for (i = 0; i < 13; i++)
		{
			printf("%d ", score[i]);
		}
		printf("%d %d\n", bonus, total + bonus);
	}
EXIT:
	return 0;
}

int naive_search(int arr[13][5], int stage, int *score, int *bonus)
{
	int i;
	if (stage > 13)
	{
		int s = 0;
		for (i = 0; i < 13; i++)
			s += score[i];

		int b = 0;
		for (i = 0; i < 6; i++)
		{
			b += score[i];
		}
		if (b >= 63)
			*bonus = 35;

		else
			*bonus = 0;

		return s;
	}
	int max_val = -1;
	int max_strategy = -1;
	int bonus_available = 0;

	for (i = 0; i < 13; i++)
	{
		if (score[i] != -1)
			continue;

		score[i] = get_score(arr[i], i);
		printf("Input: %d %d %d %d %d, score: %d\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4], score[i]);

		if (max_val < score[i])
		{
			max_val = score[i];
			max_strategy = i;
		}
		score[i] = -1;
	}

	score[max_strategy] = max_val;

	/*
	for (i = 0; i < 13; i++)
	{
		if (score[i] != -1)
			continue;

		score[i] = get_score(arr[i], i);
		int temp = *bonus;

		int new_case = naive_search(arr, stage + 1, score, bonus);

		if (max_val < new_case + *bonus)
		{
			max_val = new_case;
			bonus_available = *bonus;
		}
		score[i] = -1;
		*bonus = temp;
	}
	*bonus = bonus_available;
	*/

	return naive_search(arr, stage + 1, score, bonus);
}

int get_score(int *arr, int category)
{
	int s = 0;
	int i, j;
	category += 1;

	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

	if (category < 7)
	{
		for (i = 0; i < 5; i++)
			if (arr[i] == category)
				s += (category);

		return s;
	}

	else if (category == 7)
	{
		for (i = 0; i < 5; i++)
			s += arr[i];

		return s;
	}
	else if (7 < category && category <= 10)
	{
		int count = category - 5;
		int a[5] = {0};
		int s = 0;

		for (i = 0; i < 5; i++)
		{

			a[arr[i] - 1]++;
			s += arr[i];
		}

		for (i = 0; i < 5; i++)
		{
			if (a[i] >= count)
			{
				if (count < 5)
					return s;

				else
					return 50;
			}
		}
	}
	else if (category == 11)
	{
		int forall = 1;
		int forall2 = 1;
		for (i = 0; i < 4; i++)
		{
			if (arr[i] != i + 1)
			{
				forall = 0;
			}
			if (arr[i + 1] != i + 1)
			{
				forall2 = 0;
			}
		}
		if (forall || forall2)
			return 25;

		for (i = 0; i < 4; i++)
		{
			if (arr[i] != i + 2)
			{
				forall = 0;
			}
			if (arr[i + 1] != i + 2)
			{
				forall2 = 0;
			}
		}
		if (forall || forall2)
			return 25;

		for (i = 0; i < 4; i++)
		{
			if (arr[i] != i + 3)
			{
				forall = 0;
			}
			if (arr[i + 1] != i + 3)
			{
				forall2 = 0;
			}
		}

		if (forall || forall2)
			return 25;
		else
			return 0;
	}
	else if (category == 12)
	{
		int forall = 1;
		for (i = 0; i < 5; i++)
		{
			if (arr[i] != i + 1)
			{
				forall = 0;
			}
		}
		if (forall)
			return 35;
		for (i = 0; i < 5; i++)
		{
			if (arr[i] != i + 2)
			{
				forall = 0;
			}
		}
		if (forall)
			return 35;
		else
			return 0;
	}
	else
	{
		int a[5] = {0};

		for (i = 0; i < 5; i++)
			a[arr[i] - 1]++;

		int exist3 = 0;
		int exist2 = 0;

		for (i = 0; i < 5; i++)
		{
			if (a[i] == 2)
				exist2 = 1;
			if (a[i] == 3)
				exist3 = 1;
		}
		if (exist3 && exist2)
			return 40;
		else
			return 0;
	}
	return 0;
}