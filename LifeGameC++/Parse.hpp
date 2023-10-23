#include <string>
#include <stdexcept>

/// <summary>
/// string�������int�ɕϊ�
/// </summary>
/// <param name="y">�c�̍��W</param>
/// <param name="x">���̍��W</param>
static bool TryStringToInt(const std::string& value, int& result)
{
	try
	{
		//stoi�֐�:https://cpprefjp.github.io/reference/string/stoi.html
		result = std::stoi(value);
		return true;
	}
	catch (std::invalid_argument& _)
	{
		return false;
	}
}

/// <summary>
/// ���W���ꎟ�z��̃C���f�b�N�X�ɕϊ�
/// </summary>
/// <param name="y">�c</param>
/// <param name="x">��</param>
/// <param name="WidthSize">�z��̉���</param>
static int PositionToIndex(int y, int x, const int WidthSize)
{
	return y * WidthSize + x;
}

/// <summary>
/// int�^�z�񂩂�bool�^�z��ɕϊ�
/// </summary>
/// <param name="ints">int�^�z��</param>
/// <param name="Height">�c</param>
/// <param name="Width">��</param>
/// <param name="result"></param>
static void IntToBool(const vector<int> ints, const int Height, const int Width, vector<bool>& result)
{
	vector<bool> bools(Height * Width);

	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			// 0,1�ȊO�������Ă�����I��
			if (!(ints.at(PositionToIndex(y, x, Width)) == 0
				|| ints.at(PositionToIndex(y, x, Width)) == 1)) return;

			bools.at(PositionToIndex(y, x, Width)) = ints.at(PositionToIndex(y, x, Width)) == 1;
		}
	}

	result = bools;
}