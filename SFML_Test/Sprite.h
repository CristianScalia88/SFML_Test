#pragma once

struct Sprite
{
public:
	string name;
	Rect rect;
	Pivot pivot;
};

struct Rect {
public:
	int x;
	int y;
	int width;
	int height;
};

struct Pivot {
public:
	int x;
	int y;
};