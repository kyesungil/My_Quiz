#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SLEN 20
#define MAX 100

typedef struct client_ {
	int age;
	char name[SLEN];
}client;


int add_client(client**, int);
void print_client(client**);
int delete_client(client**, int);
void buffer_clean();


int main()
{
	client* ClientArr[MAX] = { NULL };
	int client_List = 0;
	char name[SLEN] = "";
	char key;

	printf("Client input data key: 'y'\nSearch client data key: 's'\nDelete name key: 'd'\n");

	while (1)
	{
		scanf("%c", &key);

		buffer_clean(); //scanf() buffer '\n' 제거

		switch (key)
		{
		case 'y':
			client_List = add_client(ClientArr, client_List); break;
		case 's':
			print_client(ClientArr, client_List); break;
		case 'd':
			client_List = delete_client(ClientArr, client_List); break;
		default:
			printf("Please input key again\n"); break;
		}

		if (key == 'n')
			break;
	}

	return 0;
}

int add_client(client** clientarr, int client_list)
{
	// ClientArr에 공간이 있는지 확인
	if (client_list < MAX)
	{
		// 동적할당 성공여부
		client* ctr;
		ctr = (client*)malloc(sizeof(client)); // heap에 동적할당

		if (ctr == NULL)
		{
			printf("동적할당 실패");
			exit(1);
		}

		// 동적할당 받은 포인터 ClientArr에 복사(배열에 비어있는 곳부터 저장, 상위번째 데이터를 삭제할수도 있기 때문에)

		for (int i = 0; i <= client_list; i++)
		{
			if (clientarr[i] == NULL)
			{
				clientarr[i] = ctr;
				printf("input client data (client age, client name)\n>>");
				scanf("%d %[^\n]*c", &(clientarr[i]->age), clientarr[i]->name);
				client_list++; // client수 증가
				break;
			}
		}
	}

	buffer_clean();//scanf() buffer '\n' 제거

	return client_list;
}

void print_client(client** clientarr)
{
	printf("-------------------------------------------------\n");
	for (int i = 0; i < MAX; i++)
	{
		if(clientarr[i] != NULL)
			printf("[%d] age:%d\tname:%s\n", i, clientarr[i]->age, clientarr[i]->name);
	}
	printf("-------------------------------------------------\n");
}

int delete_client(client** clientarr, int clientlist)
{
	char name[SLEN];
	//이름 입력
	printf("delete client name input\n>>");
	scanf("%[^\n]*c", name);

	//이름 확인후 삭제
	for (int i = 0; i < clientlist; i++)
	{
		if (clientarr[i] == NULL) // clientlist[i] null 포인터 참조에러 방지
			continue;

		if (strcmp(clientarr[i]->name, name) == 0)
		{
			free(clientarr[i]);
			clientarr[i] = NULL;
			printf("client data delete\n");
			clientlist--;
			break;
		}
	}

	buffer_clean(); //scanf() buffer '\n' 제거

	return clientlist;
}

void buffer_clean()
{
	while (getchar() != '\n')
		continue;
}