#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "Parse.hpp"
#include "LifeGame.h"

using namespace std;

vector<int8_t> SizeSetting(int& height, int& width);

int main()
{
	int height;
	int width;
	int generationCount = 0;
	vector<int8_t> initArray = SizeSetting(height, width);

	mt19937 mt{ std::random_device{}() };
	uniform_int_distribution<int> dist(0, 1);

	for (int i = 0; i < initArray.size(); i++)
	{
		// ランダムに0,1を代入する
		initArray.at(i) = dist(mt);
		cout << initArray.at(i);
	}

	LifeGame* lifeGame = new LifeGame(height, width);
	IntToBool(initArray, height, width, lifeGame->aliveCells);

	// 自動で世代を進める
	while (true)
	{
		// コンソールのクリア
		system("cls");
		cout << generationCount << "世代目" << endl;
		lifeGame->Render();
		if (lifeGame->IsAllDead())break;
		// 待機
		Sleep(1000);
		lifeGame->NextGeneration();
		generationCount++;
	}

	cout << "全滅したので終了";
	cin.get();
	delete lifeGame;
}

/// <summary>
/// サイズ設定
/// </summary>
/// <param name="height">縦</param>
/// <param name="width">横</param>
/// <returns>(height*width)</returns>
vector<int8_t> SizeSetting(int& height, int& width)
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