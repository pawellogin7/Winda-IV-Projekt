// draw.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "draw.h"
#include <iostream>
#include <Windows.h>

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
INT value1 = FLOOR_0;
INT FLOOR = FLOOR_0;
INT direction = 0;
BOOL move1 = false;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

HWND hwndButton;

void ElevatorMove(HDC hdc)
{
	if (move1 == false)
	{
		switch (FLOOR)
		{
		case FLOOR_0:
			direction = 1;
			FLOOR = FLOOR_1;
			move1 = true;
			break;
		case FLOOR_1:
			if (direction == 1)
				FLOOR = FLOOR_2;
			else
				FLOOR = FLOOR_0;
			move1 = true;
			break;
		case FLOOR_2:
			if (direction == 1)
				FLOOR = FLOOR_3;
			else
				FLOOR = FLOOR_1;
			move1 = true;
			break;
		case FLOOR_3:
			direction = 0;
			FLOOR = FLOOR_2;
			move1 = true;
			break;
		}
	}
	else
	{
		if (value1 > FLOOR)
			value1--;
		else if (value1 < FLOOR)
			value1++;
		else
			move1 = false;
	}



}

void MyOnPaint(HDC hdc)
{
	value++;
	Graphics graphics(hdc);
	Pen pen_blue(Color(255, 0, 0, 255));
	Pen pen_black(Color(255, 0, 0, 0));
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
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	//0
	case ID_BUTTON1F0:
		MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
		break;
	case ID_BUTTON2F0:
		MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
		break;
	case ID_BUTTON3F0:
		MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
		break;
		//1
	case ID_BUTTON0F1:
		MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
		break;
	case ID_BUTTON2F1:
		MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
		break;
	case ID_BUTTON3F1:
		MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
		break;
		//
	case ID_BUTTON0F2:
		MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
		break;
	case ID_BUTTON1F2:
		MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
		break;
	case ID_BUTTON3F2:
		MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
		break;
		//3
	case ID_BUTTON0F3:
		MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
		break;
	case ID_BUTTON1F3:
		MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
		break;
	case ID_BUTTON2F3:
		MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
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
