// draw.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "draw.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

#define MAX_LOADSTRING 100
#define TMR_1 1

#define FLOOR_0 650
#define FLOOR_1 500
#define FLOOR_2 350
#define FLOOR_3 200
#define UP 1
#define DOWN -1

void ElevatorMove(HDC hdc);

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

INT value;
INT next_floor = 0;
INT value1 = FLOOR_0;
INT floor_cord = FLOOR_0;
INT direction = DOWN;
BOOL E_move = false;

vector<int>vector0;
vector<int>vector1;
vector<int>vector2;
vector<int>vector3;
vector<int>vectorE;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

HWND hwndButton;

void ElevatorMove(HDC hdc)
{

	if (E_move == true)
	{
		if ((value1 < FLOOR_0) && (value1 > FLOOR_1))
		{
			if ((direction == UP) && !vector1.empty())
			{
				next_floor = 1;
				floor_cord = FLOOR_1;
				int x = 0;
			}
		}
		else if ((value1 < FLOOR_1) && (value1 > FLOOR_2))
		{
			if ((direction == UP) && !vector2.empty())
			{
				next_floor = 2;
				floor_cord = FLOOR_2;
			}
			else if ((direction == DOWN) && !vector1.empty())
			{
				next_floor = 1;
				floor_cord = FLOOR_1;
			}
		}
		else if ((value1 < FLOOR_2) && (value1 > FLOOR_3))
		{
			if ((direction == DOWN) && !vector2.empty())
			{
				next_floor = 2;
				floor_cord = FLOOR_2;
			}
		}

		if (value1 > floor_cord)
			value1--;
		else if (value1 < floor_cord)
			value1++;
		else
			E_move = false;
	}
	else
	{
		switch (floor_cord)
		{

		case FLOOR_0:
		{
			next_floor = 4;
			direction = UP;
			for (int i = 0; i < vectorE.size(); i++)
			{
				int personFloor = vectorE[i];
				if (personFloor == 0)
				{
					vectorE.erase(vectorE.begin() + i);
					i--;
				}
				else if (personFloor < next_floor)
					next_floor = personFloor;
			}

			for (int i = 0; i < vector0.size() && vectorE.size() < 8; i++)
			{
				int personFloor = vector0[i];
				if ((personFloor < next_floor) && (personFloor > 0))
					next_floor = personFloor;
				vectorE.push_back(personFloor);
				vector0.erase(vector0.begin() + i);
				i--;
			}

			if (!vectorE.empty())
			{
				E_move = true;
			}
			else if (vectorE.empty() && !vector1.empty())
			{
				next_floor = 1;
				E_move = true;
			}
			else if (vectorE.empty() && !vector2.empty())
			{
				next_floor = 2;
				E_move = true;
			}
			else if (vectorE.empty() && !vector3.empty())
			{
				next_floor = 3;
				E_move = true;
			}
			break;
		}


		case FLOOR_1:
		{
			int max_floor = 3;
			int min_floor = 0;
			bool good_direction = false;

			for (int i = 0; i < vectorE.size(); i++)
			{
				int personFloor = vectorE[i];
				if (personFloor == 1)
				{
					vectorE.erase(vectorE.begin() + i);
					i--;
				}
				else if ((personFloor <= max_floor) && (personFloor > 1))
				{
					max_floor = personFloor;
					if (direction == UP)
						good_direction = true;
				}
				else if ((personFloor >= min_floor) && (personFloor < 1))
				{
					min_floor = personFloor;
					if (direction == DOWN)
						good_direction = true;
				}
			}


			for (int i = 0; i < vector1.size() && vectorE.size() < 8; i++)
			{
				int personFloor = vector1[i];
				if ((personFloor <= max_floor) && (personFloor > 1))
				{
					max_floor = personFloor;
					if (direction == UP)
						good_direction = true;
				}
				else if ((personFloor >= min_floor) && (personFloor < 1))
				{
					min_floor = personFloor;
					if (direction == DOWN)
						good_direction = true;
				}
				vectorE.push_back(personFloor);
				vector1.erase(vector1.begin() + i);
				i--;
			}


			if (!vectorE.empty() && (good_direction == true))
			{
				if (direction == UP)
					next_floor = max_floor;
				else if (direction == DOWN)
					next_floor = min_floor;
				E_move = true;
			}
			else if (!vectorE.empty() && (good_direction == false))
			{
				if (direction == UP)
				{
					direction = DOWN;
					next_floor = min_floor;
				}
				else if (direction == DOWN)
				{
					direction == UP;
					next_floor = max_floor;
				}
				E_move = true;
			}
			else if (vectorE.empty() && !vector0.empty())
			{
				direction == DOWN;
				next_floor = 0;
				E_move = true;
			}
			else if (vectorE.empty() && !vector2.empty())
			{
				direction == UP;
				next_floor = 2;
				E_move = true;
			}
			else if (vectorE.empty() && !vector3.empty())
			{
				direction == UP;
				next_floor = 3;
				E_move = true;
			}


			break;
		}


		case FLOOR_2:
		{
			int max_floor = 3;
			int min_floor = 0;
			bool good_direction = false;

			for (int i = 0; i < vectorE.size(); i++)
			{
				int personFloor = vectorE[i];
				if (personFloor == 2)
				{
					vectorE.erase(vectorE.begin() + i);
					i--;
				}
				else if ((personFloor <= max_floor) && (personFloor > 2))
				{
					max_floor = personFloor;
					if (direction == UP)
						good_direction = true;
				}
				else if ((personFloor >= min_floor) && (personFloor < 2))
				{
					min_floor = personFloor;
					if (direction == DOWN)
						good_direction = true;
				}
			}

			for (int i = 0; i < vector2.size() && vectorE.size() < 8; i++)
			{
				int personFloor = vector2[i];
				if ((personFloor <= max_floor) && (personFloor > 2))
				{
					max_floor = personFloor;
					if (direction == UP)
					{
						good_direction = true;
					}
				}
				else if ((personFloor >= min_floor) && (personFloor < 2))
				{
					min_floor = personFloor;
					if (direction == DOWN)
						good_direction = true;
				}
				vectorE.push_back(personFloor);
				vector2.erase(vector2.begin() + i);
				i--;
			}


			if (!vectorE.empty() && (good_direction == true))
			{
				if (direction == UP)
					next_floor = max_floor;
				else if (direction == DOWN)
					next_floor = min_floor;
				E_move = true;
			}
			else if (!vectorE.empty() && (good_direction == false))
			{
				if (direction == UP)
				{
					direction = DOWN;
					next_floor = min_floor;
				}
				else if (direction == DOWN)
				{
					direction == UP;
					next_floor = max_floor;
				}
				E_move = true;
			}
			else if (vectorE.empty() && !vector0.empty())
			{
				direction == DOWN;
				next_floor = 0;
				E_move = true;
			}
			else if (vectorE.empty() && !vector1.empty())
			{
				direction == DOWN;
				next_floor = 1;
				E_move = true;
			}
			else if (vectorE.empty() && !vector3.empty())
			{
				direction == UP;
				next_floor = 3;
				E_move = true;
			}
			break;
		}


		case FLOOR_3:
		{
			next_floor = 0;
			direction = DOWN;
			for (int i = 0; i < vectorE.size(); i++)
			{
				int personFloor = vectorE[i];
				if (personFloor == 3)
				{
					vectorE.erase(vectorE.begin() + i);
					i--;
				}
				else if ((direction == DOWN) && (personFloor > next_floor) && (personFloor < 3))
					next_floor = personFloor;
			}

			for (int i = 0; i < vector3.size() && vectorE.size() < 8; i++)
			{
				int personFloor = vector3[i];
				if ((direction == DOWN) && (personFloor > next_floor) && (personFloor < 3))
					next_floor = personFloor;
				vectorE.push_back(personFloor);
				vector3.erase(vector3.begin() + i);
				i--;
			}

			if (!vectorE.empty())
			{
				E_move = true;
			}
			else if (vectorE.empty() && !vector0.empty())
			{
				direction == DOWN;
				next_floor = 0;
				E_move = true;
			}
			else if (vectorE.empty() && !vector1.empty())
			{
				direction == DOWN;
				next_floor = 1;
				E_move = true;
			}
			else if (vectorE.empty() && !vector3.empty())
			{
				direction == DOWN;
				next_floor = 2;
				E_move = true;
			}

			break;
		}
		}


		switch (next_floor)
		{
		case 0:
			floor_cord = FLOOR_0;
			break;
		case 1:
			floor_cord = FLOOR_1;
			break;
		case 2:
			floor_cord = FLOOR_2;
			break;
		case 3:
			floor_cord = FLOOR_3;
			break;
		}
	}

}

void Draw_passengers_3(HDC hdc)
{
	int size = vector3.size();
	Graphics graphics(hdc);
	Pen pen_white(Color(255, 255, 255, 255));
	Pen pen_black(Color(255, 0, 0, 0));

	for (int i = 0; i < size; i++)
	{
		graphics.DrawLine(&pen_black, 225 - i * 25, 670, 240 - i * 25, 670);
		graphics.DrawLine(&pen_black, 225 - i * 25, 670, 225 - i * 25, 650);
		graphics.DrawLine(&pen_black, 240 - i * 25, 670, 240 - i * 25, 650);
	}
	for (int i = size; i < 11; i++)
	{
		graphics.DrawLine(&pen_white, 225 - i * 25, 670, 240 - i * 25, 670);
		graphics.DrawLine(&pen_white, 225 - i * 25, 670, 225 - i * 25, 651);
		graphics.DrawLine(&pen_white, 240 - i * 25, 670, 240 - i * 25, 651);
	}
}

void Draw_passengers_2(HDC hdc)
{
	int size = vector2.size();
	Graphics graphics(hdc);
	Pen pen_white(Color(255, 255, 255, 255));
	Pen pen_black(Color(255, 0, 0, 0));

	for (int i = 0; i < size; i++)
	{
		graphics.DrawLine(&pen_black, 225 - i * 25, 520, 240 - i * 25, 520);
		graphics.DrawLine(&pen_black, 225 - i * 25, 520, 225 - i * 25, 500);
		graphics.DrawLine(&pen_black, 240 - i * 25, 520, 240 - i * 25, 500);
	}
	for (int i = size; i < 11; i++)
	{
		graphics.DrawLine(&pen_white, 225 - i * 25, 520, 240 - i * 25, 520);
		graphics.DrawLine(&pen_white, 225 - i * 25, 520, 225 - i * 25, 501);
		graphics.DrawLine(&pen_white, 240 - i * 25, 520, 240 - i * 25, 501);
	}
}
void Draw_passengers_1(HDC hdc)
{
	int size = vector1.size();
	Graphics graphics(hdc);
	Pen pen_white(Color(255, 255, 255, 255));
	Pen pen_black(Color(255, 0, 0, 0));

	for (int i = 0; i < size; i++)
	{
		graphics.DrawLine(&pen_black, 225 - i * 25, 370, 240 - i * 25, 370);
		graphics.DrawLine(&pen_black, 225 - i * 25, 370, 225 - i * 25, 350);
		graphics.DrawLine(&pen_black, 240 - i * 25, 370, 240 - i * 25, 350);
	}
	for (int i = size; i < 11; i++)
	{
		graphics.DrawLine(&pen_white, 225 - i * 25, 370, 240 - i * 25, 370);
		graphics.DrawLine(&pen_white, 225 - i * 25, 370, 225 - i * 25, 351);
		graphics.DrawLine(&pen_white, 240 - i * 25, 370, 240 - i * 25, 351);
	}
}
void Draw_passengers_0(HDC hdc)
{
	int size = vector0.size();
	Graphics graphics(hdc);
	Pen pen_white(Color(255, 255, 255, 255));
	Pen pen_black(Color(255, 0, 0, 0));

	for (int i = 0; i < size; i++)
	{
		graphics.DrawLine(&pen_black, 225 - i * 15, 220, 240 - i * 15, 220);
		graphics.DrawLine(&pen_black, 225 - i * 15, 220, 225 - i * 15, 200);
		graphics.DrawLine(&pen_black, 240 - i * 15, 220, 240 - i * 15, 200);
	}
	for (int i = size; i < 11; i++)
	{
		graphics.DrawLine(&pen_white, 225 - i * 15, 220, 240 - i * 15, 220);
		graphics.DrawLine(&pen_white, 225 - i * 15, 220, 225 - i * 15, 201);
		graphics.DrawLine(&pen_white, 240 - i * 15, 220, 240 - i * 15, 201);
	}
}

void MyOnPaint(HDC hdc)
{
	value++;
	Graphics graphics(hdc);
	Pen pen_blue(Color(255, 0, 0, 255));
	Pen pen_black(Color(255, 0, 0, 0));
	Font font(&FontFamily(L"Arial"), 12);
	LinearGradientBrush brush(Rect(0, 0, 100, 100), Color::Red, Color::Black, LinearGradientModeHorizontal);
	//graphics.DrawLine(&pen,0,0,200,100);

	ElevatorMove(hdc);



	//graphics.DrawRectangle(&pen_blue, 100 + value, 100, 10, 20);
	graphics.DrawRectangle(&pen_blue, 250, value1 - 150, 120, 150);
	graphics.DrawLine(&pen_black, 0, 650, 250, 650);
	graphics.DrawLine(&pen_black, 0, 500, 250, 500);
	graphics.DrawLine(&pen_black, 0, 350, 250, 350);
	graphics.DrawLine(&pen_black, 0, 200, 250, 200);
	
	Draw_passengers_0(hdc);
	Draw_passengers_1(hdc);
	Draw_passengers_2(hdc);
	Draw_passengers_3(hdc);
	
	int waga = 0;
	for (int i = 0; i < vectorE.size(); i++)
	{
		if (vectorE[i] != 0)
			waga += 70;
	}

	std::wstring value_wstr = std::to_wstring(waga);
	const wchar_t* value_str = value_wstr.c_str();                             
	graphics.DrawString(value_str, -1, &font, PointF(910, 300), &brush);

	if (waga >= 560)
	{
	TextOut(hdc, 910, 300, L"PRZECIAZENIE", 12);
	}
}


int OnCreate(HWND window)
{
	SetTimer(window, TMR_1, 25, 0);
	return 0;
}



int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	value = 10;

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	GdiplusShutdown(gdiplusToken);

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	//0
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("1"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		40, 565,
		40, 40,
		hWnd,
		(HMENU)ID_BUTTON1F0,
		hInstance,
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("2"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		100, 565,
		40, 40,
		hWnd,
		(HMENU)ID_BUTTON2F0,
		hInstance,
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("3"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		160, 565,
		40, 40,
		hWnd,
		(HMENU)ID_BUTTON3F0,
		hInstance,
		NULL);

	//1
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("0"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		40, 415,
		40, 40,
		hWnd,
		(HMENU)ID_BUTTON0F1,
		hInstance,
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("2"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		100, 415,
		40, 40,
		hWnd,
		(HMENU)ID_BUTTON2F1,
		hInstance,
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("3"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		160, 415,
		40, 40,
		hWnd,
		(HMENU)ID_BUTTON3F1,
		hInstance,
		NULL);

	//2
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("0"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		40, 265,
		40, 40,
		hWnd,
		(HMENU)ID_BUTTON0F2,
		hInstance,
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("1"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		100, 265,
		40, 40,
		hWnd,
		(HMENU)ID_BUTTON1F2,
		hInstance,
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("3"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		160, 265,
		40, 40,
		hWnd,
		(HMENU)ID_BUTTON3F2,
		hInstance,
		NULL);

	//3
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("0"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		40, 115,
		40, 40,
		hWnd,
		(HMENU)ID_BUTTON0F3,
		hInstance,
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("1"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		100, 115,
		40, 40,
		hWnd,
		(HMENU)ID_BUTTON1F3,
		hInstance,
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("2"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		160, 115,
		40, 40,
		hWnd,
		(HMENU)ID_BUTTON2F3,
		hInstance,
		NULL);
	
	hwndButton = CreateWindow(TEXT("EDIT"),                      
		TEXT("Aktualna waga:"),                  
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  
		800, 300,                                  
		110, 25,                              
		hWnd,                                 
		(HMENU)slowa,                   
		hInstance,                           
		NULL);                               


	OnCreate(hWnd);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	//OnCreate(hWnd,wParam,lParam);
	//OnTimer(hWnd,wParam,lParam);

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
			//0
		case ID_BUTTON1F0:
			if (vector0.size() < 10)
				vector0.push_back(1);
			break;
		case ID_BUTTON2F0:
			if (vector0.size() < 10)
				vector0.push_back(2);
			break;
		case ID_BUTTON3F0:
			if (vector0.size() < 10)
				vector0.push_back(3);
			break;
			//1
		case ID_BUTTON0F1:
			if (vector1.size() < 10)
				vector1.push_back(0);
			break;
		case ID_BUTTON2F1:
			if (vector1.size() < 10)
				vector1.push_back(2);
			break;
		case ID_BUTTON3F1:
			if (vector1.size() < 10)
				vector1.push_back(3);
			break;
			//2
		case ID_BUTTON0F2:
			if (vector2.size() < 10)
				vector2.push_back(0);
			break;
		case ID_BUTTON1F2:
			if (vector2.size() < 10)
				vector2.push_back(1);
			break;
		case ID_BUTTON3F2:
			if (vector2.size() < 10)
				vector2.push_back(3);
			break;
			//3
		case ID_BUTTON0F3:
			if (vector3.size() < 10)
				vector3.push_back(0);
			break;
		case ID_BUTTON1F3:
			if (vector3.size() < 10)
				vector3.push_back(1);
			break;
		case ID_BUTTON2F3:
			if (vector3.size() < 10)
				vector3.push_back(2);
			break;

		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			// TODO: Add any drawing code here...
			MyOnPaint(hdc);
			EndPaint(hWnd, &ps);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case TMR_1:
			//force window to repaint
			InvalidateRect(hWnd, NULL, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			MyOnPaint(hdc);
			EndPaint(hWnd, &ps);
			break;
		}

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
