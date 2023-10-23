#include "LifeGame.h"
#include "Parse.hpp"

using namespace std;

LifeGame::LifeGame(const unsigned int heightSize, const unsigned int widthSize)
{
	this->heightSize = heightSize;
	this->widthSize = widthSize;

	aliveCells.resize(heightSize * widthSize);
}

bool LifeGame::IsAlive(int y, int x)
{
	int lifeCount = 0;

	// �����܂߂�����9�}�X��cell�̐�����Ԃ��m�F����
	for (int i = y - 1; i <= y + 1; i++)
	{
		// 0 <= i < heightSize
		if ((unsigned int)i >= heightSize) continue;

		for (int j = x - 1; j <= x + 1; j++)
		{
			// 0 <= j < widthSize
			if ((unsigned int)j >= widthSize) continue;

			//int index = y * widthSize + x;

			if (!aliveCells.at(PositionToIndex(i, j, widthSize))) continue;
			lifeCount++;
		}
	}

	if (aliveCells.at(PositionToIndex(y, x, widthSize)))
	{
		// ���S(����)�𔲂�������8�}�X�̐���cell��
		int aroundLifeCount = lifeCount - 1;
		// ���͂̐����Ă���cell���Q���R�Ȃ�ΐ���
		return aroundLifeCount == 2 || aroundLifeCount == 3;
	}
	else
	{
		// ����������ł��Ď��͂̐����Ă���cell����3�Ȃ�Βa��
		return lifeCount == 3;
	}
}

vector<bool> LifeGame::NextGeneration()
{
	vector<bool> newGene(heightSize * widthSize);
	for (int y = 0; y < heightSize; y++)
	{
		for (int x = 0; x < widthSize; x++)
		{
			newGene.at(PositionToIndex(y, x, widthSize)) = IsAlive(y, x);
		}
	}
	return newGene;
}

void LifeGame::RenderState()
{
	for (int y = 0; y < heightSize; y++)
	{
		for (int x = 0; x < widthSize; x++)
		{
			cout << (aliveCells.at(PositionToIndex(y, x, widthSize)) ? "��" : "��");
		}
		cout << "\n";
	}
}