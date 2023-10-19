#include <string>
#include <stdexcept>

/// <summary>
/// string•¶š—ñ‚ğint‚É•ÏŠ·.
/// </summary>
/// <param name="y">c‚ÌÀ•W</param>
/// <param name="x">‰¡‚ÌÀ•W</param>
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