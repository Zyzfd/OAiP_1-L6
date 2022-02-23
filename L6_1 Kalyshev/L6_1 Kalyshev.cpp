// L6_1 Kalyshev.cpp : Определяет точку входа для приложения.
//

#include "framework.h"

#include "L6_1 Kalyshev.h"
#include <stdio.h>


#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Параметры цели (мишени) - Target
int targetCx = 300;
int targetCy = 200;
int targetSize = 100;

// Параметры прицела - Scope
int scopeX = 100;
int scopeY = 100;

// Счетчики выстрелов
int hit = 0; // попал
int missed = 0; // промазал

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_L61KALYSHEV, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_L61KALYSHEV));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_L61KALYSHEV));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_L61KALYSHEV);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//

void moveDown() {
    scopeY += 10;
}

void moveToLeft() {
    scopeX -= 10;
}

void moveUp() {
    scopeY -= 10;
}

void moveToRight() {
    scopeX += 10;
}

int insideTarget(int x, int y) {
    if (x < targetCx - targetSize)
        return 0;
    if (x > targetCx + targetSize)
        return 0;
    if (y < targetCy - targetSize)
        return 0;
    if (y > targetCy + targetSize)
        return 0;
    return 1;
}


void RecursiveRectagle(HDC hdc, int cx, int cy, int size) {
    Rectangle(hdc, cx - size, cy - size, cx + size, cy + size);

    if (size < 5) {
        return;
    }

    RecursiveRectagle(hdc, cx - size * 0.45, cy - size * 0.45, size / 2.5);
    RecursiveRectagle(hdc, cx + size * 0.45, cy - size * 0.45, size / 2.5);
    RecursiveRectagle(hdc, cx - size * 0.45, cy + size * 0.45, size / 2.5);
    RecursiveRectagle(hdc, cx + size * 0.45, cy + size * 0.45, size / 2.5);
}


void DrawTarget(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
    SelectObject(hdc, hPen);

    RecursiveRectagle(hdc, targetCx, targetCy, targetSize);

    DeleteObject(hPen);
}

void DrawSight(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(128, 0, 0));
    SelectObject(hdc, hPen);

    Ellipse(hdc, scopeX - 40, scopeY - 40, scopeX + 40, scopeY + 40);
    Ellipse(hdc, scopeX - 30, scopeY - 30, scopeX + 30, scopeY + 30);
    Ellipse(hdc, scopeX - 20, scopeY - 20, scopeX + 20, scopeY + 20);

    MoveToEx(hdc, scopeX - 50, scopeY, NULL);
    LineTo(hdc, scopeX + 50, scopeY);

    MoveToEx(hdc, scopeX, scopeY - 50, NULL);
    LineTo(hdc, scopeX, scopeY + 50);
    DeleteObject(hPen);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
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
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            HFONT hFont = CreateFont(20,
                0, 0, 0, 0, 0, 0, 0,
                DEFAULT_CHARSET,
                0, 0, 0, 0,
                L"Courier New"
            );
            SelectObject(hdc, hFont);
            SetTextColor(hdc, RGB(0, 0, 128));

            TCHAR  string1[] = _T("Попал:");
            TextOut(hdc, 10, 10, string1, _tcslen(string1));

            TCHAR  string2[] = _T("Промазал:");
            TextOut(hdc, 400, 10, string2, _tcslen(string2));

            char sHit[5]; // локальная переменная sHit
            TCHAR  tsHit[5];
            sprintf_s(sHit, "%d", hit); // использование глобальной переменной hit
            OemToChar(sHit, tsHit);
            TextOut(hdc, 100, 10, tsHit, _tcslen(tsHit));

            char sMissed[5];
            TCHAR  tsMissed[5];
            sprintf_s(sMissed, "%d", missed);
            OemToChar(sMissed, tsMissed);
            TextOut(hdc, 520, 10, tsMissed, _tcslen(tsMissed));

            DrawTarget(hdc); // цель
            DrawSight(hdc); // прицел

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_DOWN:
            moveDown();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_LEFT:
            moveToLeft();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP:
            moveUp();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT:
            moveToRight();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RETURN:
            if (insideTarget(scopeX, scopeY)) {
                hit++;
            }
            else {
                missed++;
            }

            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
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
