#include <string>
#include <stdexcept>

/// <summary>
/// string�������int�ɕϊ�.
/// </summary>
/// <param name="y">�c�̍��W</param>
/// <param name="x">���̍��W</param>
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