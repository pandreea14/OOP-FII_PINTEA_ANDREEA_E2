#include "Canvas.h";
#include <stdlib.h>
#include <iostream>

Canvas::Canvas(int w, int h):width(w), height(h)
{
	for (int i = 0; i < height; i++)
	{
		matrix[i] = (char*)(malloc(width * sizeof(char)));
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if ((i - x)*(i-x) + (j - y)*(j-y) >= ray * (ray - 1) && (i - x)*(i-x) + (j - y) *(j-y <= ray * (ray + 1)))
			{
				matrix[i][j] = ch;
			}
			else
			{
				matrix[i][j] = ' ';
			}
		}
	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
			{
				matrix[i][j] = ch;
			}
			else
			{
				matrix[i][j] = ' ';
			}
		}
	}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{

}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{

}
void Canvas::SetPoint(int x, int y, char ch)
{

}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int D = 2 * dy - dx;
	int y = y1;

	for (int x = x1; x <= x2; x++)
	{
		matrix[x][y] = ch;
		if (D > 0)
		{
			y = y + 1;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
	}
}
void Canvas::Print()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%s", matrix[i][j]);
		}
	}
}
void Canvas::Clear()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}