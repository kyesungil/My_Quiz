#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>

#define LEN 20
#define ALP 26
#define NUM 10

int main()
{
	/* 
		단어를 입력해서 가장많이 나온 문자와 빈도수 찾기
		대문자로 출력
	*/

	char str[LEN];
	int cntr[ALP] = { 0, };
	int MAX = 0, MAX_index = 0;

	while (1)
	{
		printf("단어를 입력하세요. 종료키 end \n>>");
		scanf("%s", str);

		if (str[0] == 'e' && str[1] == 'n' && str[2] == 'd')
			break;

		// 대문자 만들기 toupper
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] < 97) // 'a' = 97
				str[i] += 32; // ASCII 대문자 소문자 차이 32

			cntr[str[i] - 97]++; // index 1, 2, 3.... 맞추기
		}

		// 가장 많이 나온 단어 빈도수 저장
		for (int i = 0; i < ALP; i++)
		{
			if (cntr[i] > MAX)
			{
				MAX = cntr[i];
				MAX_index = i;
			}
			else if (cntr[i] == MAX)
				MAX_index = -2; // '?' ASCII 63
		}

		printf("MAX단어 : %c\n", MAX_index + 65);
	}
	printf("종료\n\n");


	/* 
		2. 숫자를 입력해서 가장많이 나온 문자와 빈도수 찾기
		   숫자출력
	*/
	
	int number[NUM] = { 0, };
	int input[NUM];
	int k;
	int max = 0, max_index = 0;

	printf("숫자 10개 입력하세요\n>>");

	for (int i = 0; i < NUM; i++)
	{
		scanf("%1d", &input[i]);
		number[input[i]]++; // number에 입력된 수가 index역할을 한다.
	}

	// 빈도수 비교
	for (int i = 0; i < NUM; i++)
	{
		if (number[i] > max)
		{
			max = number[i];
			max_index = i;
		}
	}
	printf("%d = %d회\n", max_index, max);

	return 0;
}