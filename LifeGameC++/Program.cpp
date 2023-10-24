#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "Parse.hpp"
#include "LifeGame.h"

using namespace std;

vector<int8_t> InitSetting(int& height, int& width);

int main()
{
	int height;
	int width;
	int generationCount = 0;
	auto initInstance = InitSetting(height, width);
	vector<int8_t>& initRef = initInstance;

	mt19937 mt{ std::random_device{}() };
	uniform_int_distribution<int> dist(0, 1);

	for (int i = 0; i < initRef.size(); i++)
	{
		// ランダムに0,1を代入する
		initRef.at(i) = dist(mt);
		cout << initRef.at(i);
	}

	LifeGame* lifeGame = new LifeGame(height, width);
	IntToBool(initRef, height, width, lifeGame->aliveCells);

	// 自動で世代を進める
	while (true)
	{
		// コンソールのクリア
		system("cls");
		cout << generationCount << "世代目" << endl;
		lifeGame->RenderState();
		// 待機
		Sleep(1000);
		lifeGame->aliveCells = lifeGame->NextGeneration();
		generationCount++;
	}

	delete lifeGame;
}

/// <summary>
/// 初期設定
/// </summary>
/// <param name="height">縦</param>
/// <param name="width">横</param>
/// <returns>(height*width)</returns>
vector<int8_t> InitSetting(int& height, int& width)
{
	while (true)
	{
		cout << "横の長さは？：";
		cin >> width;
		if (width != 0) break;
		cout << "数字を入力してね！" << endl;
	}

	while (true)
	{
		cout << "縦の長さは？：";
		cin >> height;
		if (height != 0) break;
		cout << "数字を入力してね！" << endl;
	}

	vector<int8_t> arr(height * width);
	return	arr;
}