#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>

class LifeGame
{
public:
	LifeGame(const unsigned int heightSize, const unsigned int widthSize);
	/// <summary>
	/// ¢‘ã‚ğ‚P‚Âi‚ß‚é
	/// </summary>
	/// <returns>Ÿ¢‘ã‚Ìcell‚Ìó‘Ô</returns>
	std::vector<bool> NextGeneration();
	/// <summary>
	/// cell‚Ìó‘Ô‚ğ•`‰æ‚·‚é
	/// ¶‘¶:¡ €–S: 
	/// </summary>
	void RenderState();

	std::vector<bool> aliveCells;
private:
	/// <summary>
	/// cell‚Ì¶€‚ğ”»’è‚·‚é
	/// </summary>
	/// <param name="y">c‚ÌÀ•W</param>
	/// <param name="x">‰¡‚ÌÀ•W</param>
	/// <returns>¶‚«‚Ä‚¢‚é‚È‚çTrue</returns>
	bool IsAlive(int y, int x);

	unsigned int heightSize;
	unsigned int widthSize;
};