#pragma once
#include <SFML\Graphics.hpp>


int i, j;
const int HEIGHT_MAP = 25;//������ ����� ������
const int WIDTH_MAP = 40;//������ ����� ������ 


sf::String TileMap[HEIGHT_MAP] = {
	"0000000000000000000000000000000000000000",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0000000000000000000000000000000000000000",
};

void randomMapGenerate() {//�������� ����������� �����

	int randomElementX = 0;//��������� ������� �� �����������
	int randomElementY = 0;//���� ��-� �� ���������
	srand(time(0));//������	

//--------------------------------------------
	for (i = 1; i < (HEIGHT_MAP-1); i += 3)
	{
		//������������ ������ ������ ���� ����������� ��������� | ��� �� 2, ������ ��� ��-������� ����� �� ���������� :�
		for (j = 1; j < (WIDTH_MAP - 1); j += 2)
		{
			TileMap[i][j] = ('%d', j);
			TileMap[i][j + 1] = ('%d', j);
			TileMap[i][j + 2] = ('%d', j);


			TileMap[i+1][j] = ('%d', j);
			TileMap[i+1][j + 1] = ('%d', j);
			TileMap[i+1][j + 2] = ('%d', j);
		}

		for (j = 3; j < (WIDTH_MAP - 2); j += 3)// ???????????
		{
			//������ �������

			int random = 1 + rand() % 2;//�������� ������, ��������� ������� ��� ���
			if (random == 1 && i==1)//���� 1, �� ���������
			{
				TileMap[i][j] = '0';
				TileMap[i+1][j] = '0';
			}
			if (i != 1 && random==1)
			{
				if ((TileMap[i - 1][j] == '0' && TileMap[i - 2][j] == '0') || (TileMap[i - 1][j - 1] != '0' && TileMap[i - 1][j - 2] != '0' && TileMap[i - 1][j + 1] != '0' && TileMap[i - 1][j + 2]))
				{
					TileMap[i][j] = '0';
					TileMap[i + 1][j] = '0';
				}
			}
		}

		if (i != 22)
		{
			//����������� ��������
			for (j = 4; j < (WIDTH_MAP - 1); j++)
			{
				if (TileMap[i][j + 1] != TileMap[i][j] && TileMap[i][j] != '0' && TileMap[i][j + 1] != '0')
				{
					TileMap[i][j + 1] = TileMap[i][j];//���������� ������ � ���� ���������
					TileMap[i + 1][j + 1] = TileMap[i + 1][j];
				}
			}


			//�������� ������ ������
			//�������� �� ��������� �������
			for (j = 1; j < (WIDTH_MAP - 1); j++)
			{
				int random = 1 + rand() % 2;//�������� ������, ��������� ������� ��� ���
				if ((random == 1 && TileMap[i][j + 2] == TileMap[i][j]) || (random == 1 && TileMap[i][j] == '0') || (random == 1 && TileMap[i][j] != TileMap[i][j + 2] && TileMap[i][j + 1] == '0' && TileMap[i + 2][j - 1] != '0' && TileMap[i + 2][j - 2] != '0'))//���� 1, �� ���������
				{
					TileMap[i + 2][j] = '0';
				}
				else
				{
					TileMap[i + 2][j] = ' ';
				}
			}

			//�������� �� ����� ������ 
			for (j = 1; j < (WIDTH_MAP); j++)
			{
				if (TileMap[i + 2][j] != '0' && TileMap[i + 2][j - 1] == '0' && TileMap[i + 2][j + 1] == '0' && TileMap[i + 1][j - 1] != '0')//���� ������� �����������, �� ���������� ������� ������ ������������� �������� ������� �� �������
				{
					TileMap[i + 2][j - 1] = TileMap[i + 2][j];
				}
			}

			//����������� ������, ��� ��� ������ �������, � �� �������� 
			for (j = 1; j < (WIDTH_MAP - 1); j++)
			{
				TileMap[i + 3][j] = TileMap[i][j];//����������� ���� ������ ������, ��� ������ �������
				TileMap[i + 4][j] = TileMap[i + 1][j];
				TileMap[i + 5][j] = TileMap[i + 2][j];//����������� ���� ������ ������, ��� ������ �������
			}

			for (j = 1; j < (WIDTH_MAP); j++)//�������� ������
			{
				if (TileMap[i + 3][j] == '0')
				{
					TileMap[i + 3][j] = TileMap[i + 3][j - 1];//�������� ������ ������: ���� ������ ������=0, �� ������������ �� � ����������
					TileMap[i + 4][j] = TileMap[i + 3][j - 1];
				}

				if (TileMap[i + 5][j] == '0')
				{
					TileMap[i + 5][j] = ' ';
				}
			}
		}
	}

		for (i = 0; i < HEIGHT_MAP; i++)
		{
			for (j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] != '0')
				{
					TileMap[i][j] =' ';
				}
			}
		}

		//�������� ������ � ������ �������
		for (i = 0; i < HEIGHT_MAP; i++)
		{
			TileMap[i][39] = '0';
		}
		for (j = 0; j < WIDTH_MAP; j++)
		{
			TileMap[24][j] = '0';
		}

		do {
		randomElementX = 1 + rand() % (WIDTH_MAP - 1);//��������� �� ���� �� 1 �� ������ �����-1, ����� �� �������� ����� ������� �����
		randomElementY = 1 + rand() % (HEIGHT_MAP - 1);//�� ������ ��� ��

		if (TileMap[randomElementY][randomElementX] == ' ') {//���� ��������� ������ ������, 
			TileMap[randomElementY][randomElementX] = 'h'; //�� ������ ���� ������.
		}
	} while (TileMap[randomElementY][randomElementX] == ' ');
	int count=0;//����������� �����
	while (count < 10) {
		do {
			randomElementX = 1 + rand() % (WIDTH_MAP - 1);//��������� �� ���� �� 1 �� ������ �����-1, ����� �� �������� ����� ������� �����
			randomElementY = 1 + rand() % (HEIGHT_MAP - 1);//�� ������ ��� ��

			if (TileMap[randomElementY][randomElementX] == ' ') {//���� ��������� ������ ������, 
				TileMap[randomElementY][randomElementX] = 'f';
				count++;
			}
		} while ((TileMap[randomElementY][randomElementX] == ' '));
	}
	count = 0;//����������� �����
	while (count < 10) {
		do {
			randomElementX = 1 + rand() % (WIDTH_MAP - 1);//��������� �� ���� �� 1 �� ������ �����-1, ����� �� �������� ����� ������� �����
			randomElementY = 1 + rand() % (HEIGHT_MAP - 1);//�� ������ ��� ��

			if (TileMap[randomElementY][randomElementX] == ' ') {//���� ��������� ������ ������, 
				TileMap[randomElementY][randomElementX] = 's';
				count++;
			}
		} while ((TileMap[randomElementY][randomElementX] == ' '));
	}

}