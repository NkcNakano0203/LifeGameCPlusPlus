#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>

class LifeGame
{
public:
	LifeGame(const unsigned int heightSize, const unsigned int widthSize);

	/// <summary>
	/// ������P�i�߂�
	/// </summary>
	/// <param name="cells">�������cell�̏��</param>
	/// <returns>�S�ł�����False</returns>
	bool TryNextGeneration(std::vector<bool>& cells);

	/// <summary>
	/// cell�̏�Ԃ�`�悷��
	/// ����:�� ���S:��
	/// </summary>
	void RenderState();

	std::vector<bool> aliveCells;
private:
	/// <summary>
	/// cell�̐����𔻒肷��
	/// </summary>
	/// <param name="y">�c�̍��W</param>
	/// <param name="x">���̍��W</param>
	/// <returns>�����Ă���Ȃ�True</returns>
	bool IsAlive(int y, int x);

	unsigned int heightSize;
	unsigned int widthSize;
};