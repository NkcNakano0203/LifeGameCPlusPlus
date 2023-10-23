#include <string>
#include <stdexcept>

/// <summary>
/// string文字列をintに変換
/// </summary>
/// <param name="y">縦の座標</param>
/// <param name="x">横の座標</param>
static bool TryStringToInt(const std::string& value, int& result)
{
	try
	{
		//stoi関数:https://cpprefjp.github.io/reference/string/stoi.html
		result = std::stoi(value);
		return true;
	}
	catch (std::invalid_argument& _)
	{
		return false;
	}
}

/// <summary>
/// 座標を一次配列のインデックスに変換
/// </summary>
/// <param name="y">縦</param>
/// <param name="x">横</param>
/// <param name="WidthSize">配列の横幅</param>
static int PositionToIndex(int y, int x, const int WidthSize)
{
	return y * WidthSize + x;
}

/// <summary>
/// int型配列からbool型配列に変換
/// </summary>
/// <param name="ints">int型配列</param>
/// <param name="Height">縦</param>
/// <param name="Width">横</param>
/// <param name="result"></param>
static void IntToBool(const vector<int> ints, const int Height, const int Width, vector<bool>& result)
{
	vector<bool> bools(Height * Width);

	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			// 0,1以外が入っていたら終了
			if (!(ints.at(PositionToIndex(y, x, Width)) == 0
				|| ints.at(PositionToIndex(y, x, Width)) == 1)) return;

			bools.at(PositionToIndex(y, x, Width)) = ints.at(PositionToIndex(y, x, Width)) == 1;
		}
	}

	result = bools;
}