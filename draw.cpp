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

void ElevatorMove(HDC hdc);

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

INT value;
INT next_floor = 0;
INT value1 = FLOOR_0;
INT floor_cord = FLOOR_0;
string direction = "down";
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
			next_floor = 4;
			direction = "up";
			for (vector<int>::iterator it = vectorE.begin(); it != vectorE.end(); it++)
			{
				int personFloor = *it;
				if (personFloor == 0)
					vectorE.erase(it);
				else if (personFloor < next_floor)
					next_floor = personFloor;

			}

			for (vector<int>::iterator it = vector0.begin(); it != vector0.end() && vectorE.size() < 8; it++)
			{
				int personFloor = *it;
				if ((direction == "up") && (personFloor < next_floor) && (personFloor > 0))
					next_floor = personFloor;
				vectorE.push_back(personFloor);
				vector0.erase(it);
			}
			E_move = true;
			break;


		case FLOOR_1:
			if (direction == "up")
				next_floor = 3;
			else
				next_floor = 0;

			for (vector<int>::iterator it = vectorE.begin(); it != vectorE.end(); it++)
			{
				int personFloor = *it;
				if (personFloor == 1)
					vectorE.erase(it);
				else if ((direction == "up") && (personFloor < next_floor) && (personFloor > 1))
					next_floor = personFloor;
				else if ((direction == "down") && (personFloor > next_floor) && (personFloor < 1))
					next_floor = personFloor;
			}

			for (vector<int>::iterator it = vector1.begin(); it != vector1.end() && vectorE.size() < 8; it++)
			{
				int personFloor = *it;
				if ((direction == "up") && (personFloor < next_floor) && (personFloor > 1))
					next_floor = personFloor;
				else if ((direction == "down") && (personFloor > next_floor) && (personFloor < 1))
					next_floor = personFloor;
				vectorE.push_back(personFloor);
				vector1.erase(it);
			}
			E_move = true;
			break;


		case FLOOR_2:
			if (direction == "up")
				next_floor = 3;
			else
				next_floor = 0;

			for (vector<int>::iterator it = vectorE.begin(); it != vectorE.end(); it++)
			{
				int personFloor = *it;
				if (personFloor == 2)
					vectorE.erase(it);
				else if ((direction == "up") && (personFloor < next_floor) && (personFloor > 2))
					next_floor = personFloor;
				else if ((direction == "down") && (personFloor > next_floor) && (personFloor < 2))
					next_floor = personFloor;
			}

			for (vector<int>::iterator it = vector2.begin(); it != vector2.end() && vectorE.size() < 8; it++)
			{
				int personFloor = *it;
				if ((direction == "up") && (personFloor < next_floor) && (personFloor > 2))
					next_floor = personFloor;
				else if ((direction == "down") && (personFloor > next_floor) && (personFloor < 2))
					next_floor = personFloor;
				vectorE.push_back(personFloor);
				vector2.erase(it);
			}
			E_move = true;
			break;


		case FLOOR_3:
			next_floor = 0;
			direction = "down";
			for (vector<int>::iterator it = vectorE.begin(); it != vectorE.end(); it++)
			{
				int personFloor = *it;
				if (personFloor == 3)
					vectorE.erase(it);
				else if ((direction == "down") && (personFloor > next_floor) && (personFloor < 3))
					next_floor = personFloor;
			}

			for (vector<int>::iterator it = vector3.begin(); it != vector3.end() && vectorE.size() < 8; it++)
			{
				int personFloor = *it;
				if ((direction == "down") && (personFloor > next_floor) && (personFloor < 3))
					next_floor = personFloor;
				vectorE.push_back(personFloor);
				vector3.erase(it);
			}
			E_move = true;
			break;
		}
	}

void Draw_passengers_3 (int size)
{
	for(int i=0;i<size;i++)
		graphics.DrawLine(&pen_black, 225 - i*25, 670, 240 - i*25, 670);
		graphics.DrawLine(&pen_black, 225 - i*25, 670, 225 - i*25, 650);
		graphics.DrawLine(&pen_black, 240 - i*25, 670, 240 - i*25, 650);
	for(int i=size;i<11;i++)
		graphics.DrawLine(&pen_white, 226 - i*25, 670, 241 - i*25, 670);
		graphics.DrawLine(&pen_white, 226 - i*25, 670, 226 - i*25, 650);
		graphics.DrawLine(&pen_white, 241 - i*25, 670, 241 - i*25, 650);
}

void Draw_passengers_2 (int size)
{
	for(int i=0;i<size;i++)
		graphics.DrawLine(&pen_black, 225 - i*25, 520, 240 - i*25, 520);
		graphics.DrawLine(&pen_black, 225 - i*25, 520, 225 - i*25, 500);
		graphics.DrawLine(&pen_black, 240 - i*25, 520, 240 - i*25, 500);
	for(int i=size;i<11;i++)
		graphics.DrawLine(&pen_white, 226 - i*25, 520, 241 - i*25, 520);
		graphics.DrawLine(&pen_white, 226 - i*25, 520, 226 - i*25, 500);
		graphics.DrawLine(&pen_white, 241 - i*25, 520, 241 - i*25, 500);	
}
void Draw_passengers_1 (int size)
{
	for(int i=0;i<size;i++)
		graphics.DrawLine(&pen_black, 225 - i*25, 370, 240 - i*25, 370);
		graphics.DrawLine(&pen_black, 225 - i*25, 370, 225 - i*25, 350);
		graphics.DrawLine(&pen_black, 240 - i*25, 370, 240 - i*25, 350);
	for(int i=size;i<11;i++)
		graphics.DrawLine(&pen_white, 226 - i*25, 370, 241 - i*25, 370);
		graphics.DrawLine(&pen_white, 226 - i*25, 370, 226 - i*25, 350);
		graphics.DrawLine(&pen_white, 241 - i*25, 370, 241 - i*25, 350);	
}
void Draw_passengers_0 (int size)
{
	for(int i=0;i<size;i++)
		graphics.DrawLine(&pen_black, 225 - i*15, 220, 240 - i*15, 220);
		graphics.DrawLine(&pen_black, 225 - i*15, 220, 225 - i*15, 200);
		graphics.DrawLine(&pen_black, 240 - i*15, 220, 240 - i*15, 200);
	for(int i=size;i<11;i++)
		graphics.DrawLine(&pen_white, 226 - i*15, 220, 241 - i*15, 220);
		graphics.DrawLine(&pen_white, 226 - i*15, 220, 226 - i*15, 200);
		graphics.DrawLine(&pen_white, 241 - i*15, 220, 241 - i*15, 200);	
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


void MyOnPaint(HDC hdc)
{
	value++;
	Graphics graphics(hdc);
	Pen pen_blue(Color(255, 0, 0, 255));
	Pen pen_black(Color(255, 0, 0, 0));
	Pen pen_white(Color(255, 255, 255, 255));
	//graphics.DrawLine(&pen,0,0,200,100);

	ElevatorMove(hdc);



	graphics.DrawRectangle(&pen_blue,100+value,100,10, 20);
	graphics.DrawRectangle(&pen_blue, 250, value1 - 150, 120, 150);
	graphics.DrawLine(&pen_black, 0, 650, 250, 650);
	graphics.DrawLine(&pen_black, 0, 500, 250, 500);
	graphics.DrawLine(&pen_black, 0, 350, 250, 350);
	graphics.DrawLine(&pen_black, 0, 200, 250, 200);
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
	if (!InitInstance (hInstance, nCmdShow))
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

	return (int) msg.wParam;
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

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
		wmId    = LOWORD(wParam);
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
