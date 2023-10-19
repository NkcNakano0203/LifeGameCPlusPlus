#include "LifeGame.h"

using namespace std;

LifeGame::LifeGame(const int heightSize, const int widthSize)
{
	this->heightSize = heightSize;
	this->widthSize = widthSize;

	aliveCells.resize(heightSize * widthSize);
}

/// <summary>
/// cell�̐����𔻒肷��
/// </summary>
/// <param name="y">�c�̍��W</param>
/// <param name="x">���̍��W</param>
/// <returns>�����Ă���Ȃ�True</returns>
bool LifeGame::IsAlive(int y, int x)
{
	int lifeCount = 0;

	// �����܂߂�����9�}�X��cell�̐�����Ԃ��m�F����
	for (int i = y - 1; i < y + 1; i++)
	{
		// 0 <= i < heightSize
		if ((unsigned int)i > heightSize) continue;
		for (int j = x - 1; j < x + 1; j++)
		{
			// 0 <= j < widthSize
			if ((unsigned int)j > widthSize) continue;

			if (!aliveCells.at(i * j)) continue;
			lifeCount++;
		}
	}

	if (aliveCells.at(y * x))
	{
		// ����8�}�X�̐���cell��
		int aroundLifeCount = lifeCount - 1;
		// ���͂̐����Ă���cell�� 2<=x<=3 �Ȃ�ΐ���
		return aroundLifeCount >= 2 && aroundLifeCount <= 3;
	}
	else
	{
		// ����������ł��Ď��͂̐����Ă���cell����3�Ȃ�Βa��
		return lifeCount == 3;
	}
}

/// <summary>
/// ������P�i�߂�
/// </summary>
/// <returns>�������cell�̏��</returns>
vector<bool> LifeGame::NextGeneration()
{
	vector<bool> newGene(heightSize * widthSize);
	for (int y = 0; y < heightSize; y++)
	{
		for (int x = 0; x < widthSize; x++)
		{
			newGene.at(y * x) = IsAlive(y, x);
		}
	}
	return newGene;
}

/// <summary>
/// cell�̏�Ԃ�`�悷��
/// ����:�� ���S:��
/// </summary>
void LifeGame::RenderState()
{
	for (int y = 0; y < heightSize; y++)
	{
		for (int x = 0; x < widthSize; x++)
		{
			if (aliveCells.at(y * x))
			{
				cout << "��";
			}
			else
			{
				cout << "��";
			}
		}
		cout << "\n";
	}
}