#pragma once

#include <vector>
#include <algorithm>

struct Vector2 {
	int x,
		y;
};

class GameMap
{
	//ѕол€ класса
private:
	int** map;
	Vector2 size;
	int length;//необходима€ длина выйгрышной последовательности

	  //ћетоды класса
public:
	GameMap();//конструктор
	GameMap(Vector2, int);//конструктор
	GameMap(int, int, int);//конструктор
	~GameMap();//деструктор

	bool SetPosition(Vector2, int);//задать позицию
	bool IsEmpty(Vector2);//проверка на свободную €чейку
	bool IsEmpty(int, int);//проверка на свободную €чейку
	void SetMap(Vector2, int);
	void SetMap(int, int, int);
	int GetValue(Vector2);
	int GetValue(int, int);
	int GetLength() { return length; };
	Vector2 GetSize() { return size; };
	int CheckList(std::vector<int> a);
	int CheckingWin();
	bool CanMove();
	Vector2 GetCenter();
};

