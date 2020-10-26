#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

HANDLE hConsole;


void Color(int colorIndex) {
	SetConsoleTextAttribute(hConsole, colorIndex-1);
}

void Clear() {
	system("cls");
}

void Wait(float seconds) {
	Sleep(seconds*1000);
}

void Text(string dialogue) {
	cout << dialogue;
}

void Type(string dialogue, float cps) {
	for (unsigned int i = 0; i < dialogue.size(); i++) {
		cout << dialogue[i];
		Sleep(1000 / cps);
	}
}

void ShowCursor(bool show)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = show; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void SplashScreen() {
	Type("Made with Genjin Engine\n", 18);
	Sleep(1000);
	Type("Please consider donating at ko-fi.com/lukematakitoga", 25);
	Sleep(5000);
	Clear();
	Sleep(1000);
}

bool LTTInit() {

	try
	{
		ShowCursor(false);
		CONSOLE_SCREEN_BUFFER_INFOEX info;
		info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfoEx(hConsole, &info);

		info.ColorTable[0] = RGB(0, 0, 0); // Black
		info.ColorTable[1] = RGB(255, 255, 255); // White
		info.ColorTable[2] = RGB(82, 255, 178); // Cucumber
		info.ColorTable[3] = RGB(135, 206, 235);
		info.ColorTable[4] = RGB(135, 206, 235);
		info.ColorTable[5] = RGB(135, 206, 235);
		info.ColorTable[6] = RGB(135, 206, 235);
		info.ColorTable[7] = RGB(135, 206, 235);
		info.ColorTable[8] = RGB(135, 206, 235);
		info.ColorTable[9] = RGB(135, 206, 235);
		info.ColorTable[10] = RGB(135, 206, 235);
		info.ColorTable[11] = RGB(135, 206, 235);
		info.ColorTable[12] = RGB(135, 206, 235);
		info.ColorTable[13] = RGB(135, 206, 235);
		info.ColorTable[14] = RGB(135, 206, 235);
		info.ColorTable[15] = RGB(25, 25, 25);

		SetConsoleScreenBufferInfoEx(hConsole, &info);

		Color(2);
		SplashScreen(); // You may not modify/remove this function BY LAW
		ShowCursor(true);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << e << '\n';
		return false;
	}
	
	
	return true;
}
