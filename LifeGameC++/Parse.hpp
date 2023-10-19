#include <string>
#include <stdexcept>

/// <summary>
/// string文字列をintに変換.
/// </summary>
/// <param name="y">縦の座標</param>
/// <param name="x">横の座標</param>
static bool TryStringToInt(const std::string& value, int& result)
{
	try
	{
		result = std::stoi(value);
		return true;
	}
	catch (std::invalid_argument& _)
	{
		return false;
	}
}

static int PositionToIndex(int y, int x, const int WidthSize)
{
	return y * WidthSize + x;
}