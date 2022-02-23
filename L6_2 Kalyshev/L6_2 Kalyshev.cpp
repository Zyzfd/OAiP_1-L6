// L6_2 Kalyshev.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "L6_2 Kalyshev.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
int numImage = 1;
int sizeImage = 80;
int numLaba = 1;

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
    LoadStringW(hInstance, IDC_L62KALYSHEV, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_L62KALYSHEV));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_L62KALYSHEV));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_L62KALYSHEV);
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

void Image1(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size;
    int y1 = cy - size;
    int x2 = cx + size;
    int y2 = cy - size;
    int x3 = cx;
    int y3 = cy + size;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void RecursiveImage1_1(HDC hdc, int cx, int cy, int size) {
    Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage1_1(hdc, cx - size, cy - size, size / 2);
    RecursiveImage1_1(hdc, cx + size, cy - size, size / 2);
}

void RecursiveImage1_2(HDC hdc, int cx, int cy, int size) {
    Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage1_2(hdc, cx - size, cy - size, size / 2);
    RecursiveImage1_2(hdc, cx, cy + size, size / 2);
}

void RecursiveImage1_3(HDC hdc, int cx, int cy, int size) {
    Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage1_3(hdc, cx - size, cy - size, size / 2);
    RecursiveImage1_3(hdc, cx + size, cy - size, size / 2);
    RecursiveImage1_3(hdc, cx, cy + size, size / 2);
}

void RecursiveImage1_4(HDC hdc, int cx, int cy, int size) {
    Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage1_4(hdc, cx, cy - size, size / 2);
}

void RecursiveImage1_5(HDC hdc, int cx, int cy, int size) {
    Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage1_5(hdc, cx + size, cy, size / 2);
}

void RecursiveImage1_6(HDC hdc, int cx, int cy, int size) {
    Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage1_6(hdc, cx - size, cy, size / 2);
}

void RecursiveImage1_7(HDC hdc, int cx, int cy, int size) {
    Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage1_7(hdc, cx, cy - size, size / 2);
    RecursiveImage1_7(hdc, cx - size, cy, size / 2);
    RecursiveImage1_7(hdc, cx + size, cy, size / 2);
}

void Image2(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size / 2;
    int y1 = cy - size;
    int x2 = cx + size / 2;
    int y2 = cy - size;
    int x3 = cx - size;
    int y3 = cy + size;
    int x4 = cx + size;
    int y4 = cy + size;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}


void RecursiveImage2_1(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    RecursiveImage2_1(hdc, cx - size / 2, cy - size, size / 2);
}

void RecursiveImage2_2(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    RecursiveImage2_2(hdc, cx - size / 2, cy - size, size / 2);
    RecursiveImage2_2(hdc, cx + size / 2, cy - size, size / 2);
}

void RecursiveImage2_3(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    RecursiveImage2_3(hdc, cx - size, cy + size, size / 2);
    RecursiveImage2_3(hdc, cx + size, cy + size, size / 2);
}

void RecursiveImage2_4(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    RecursiveImage2_4(hdc, cx - size / 2, cy - size, size / 2);
    RecursiveImage2_4(hdc, cx + size / 2, cy - size, size / 2);
    RecursiveImage2_4(hdc, cx - size, cy + size, size / 2);
    RecursiveImage2_4(hdc, cx + size, cy + size, size / 2);
}

void RecursiveImage2_5(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    RecursiveImage2_5(hdc, cx - size, cy, size / 2);
}

void RecursiveImage2_6(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    RecursiveImage2_6(hdc, cx + size, cy, size / 2);
}

void RecursiveImage2_7(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    RecursiveImage2_7(hdc, cx + size, cy, size / 2);
    RecursiveImage2_7(hdc, cx - size, cy, size / 2);
}

void Image3(HDC hdc, int cx, int cy, int size) {
    int x1 = cx;
    int y1 = cy - size;
    int x2 = cx + size;
    int y2 = cy;
    int x3 = cx;
    int y3 = cy + size;
    int x4 = cx - size;
    int y4 = cy;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void RecursiveImage3_1(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage3_1(hdc, cx - size, cy, size / 2);
    RecursiveImage3_1(hdc, cx + size, cy, size / 2);
}

void RecursiveImage3_2(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage3_2(hdc, cx - size, cy, size / 2);
    RecursiveImage3_2(hdc, cx + size, cy, size / 2);
    RecursiveImage3_2(hdc, cx, cy + size, size / 2);
}

void RecursiveImage3_3(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage3_3(hdc, cx - size, cy, size / 2);
    RecursiveImage3_3(hdc, cx + size, cy, size / 2);
    RecursiveImage3_3(hdc, cx, cy - size, size / 2);
}

void RecursiveImage3_4(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage3_4(hdc, cx - size, cy, size / 2);
    RecursiveImage3_4(hdc, cx + size, cy, size / 2);
    RecursiveImage3_4(hdc, cx, cy - size, size / 2);
    RecursiveImage3_4(hdc, cx, cy + size, size / 2);
}

void RecursiveImage3_5(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage3_5(hdc, cx - size, cy + size, size / 2);
    RecursiveImage3_5(hdc, cx + size, cy + size, size / 2);
}

void RecursiveImage3_6(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage3_6(hdc, cx + size, cy + size, size / 2);
    RecursiveImage3_6(hdc, cx - size, cy - size, size / 2);
}

void RecursiveImage3_7(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage3_7(hdc, cx - size / 2, cy - size, size / 2);
    RecursiveImage3_7(hdc, cx + size / 2, cy - size, size / 2);
    RecursiveImage3_7(hdc, cx - size, cy + size, size / 2);
    RecursiveImage3_7(hdc, cx + size, cy + size, size / 2);
}

void RecursiveImage3_8(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage3_8(hdc, cx + size / 2, cy - size, size / 2);
    RecursiveImage3_8(hdc, cx + size / 2, cy + size, size / 2);
}

void Image4(HDC hdc, int cx, int cy, int size) {
    int x1 = cx;
    int y1 = cy - size;
    int x2 = cx + size / 4;
    int y2 = cy - size / 4;
    int x3 = cx + size;
    int y3 = cy;
    int x4 = cx + size / 4;
    int y4 = cy + size / 4;
    int x5 = cx;
    int y5 = cy + size;
    int x6 = cx - size / 4;
    int y6 = cy + size / 4;
    int x7 = cx - size;
    int y7 = cy;
    int x8 = cx - size / 4;
    int y8 = cy - size / 4;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x6, y6);
    LineTo(hdc, x7, y7);
    LineTo(hdc, x8, y8);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void RecursiveImage4_1(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    RecursiveImage4_1(hdc, cx + size, cy, size / 2);
    RecursiveImage4_1(hdc, cx - size, cy, size / 2);
}

void RecursiveImage4_2(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    RecursiveImage4_2(hdc, cx, cy + size, size / 2);
    RecursiveImage4_2(hdc, cx, cy - size, size / 2);
}

void RecursiveImage4_3(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    RecursiveImage4_3(hdc, cx, cy + size, size / 2);
    RecursiveImage4_3(hdc, cx, cy - size, size / 2);
    RecursiveImage4_3(hdc, cx - size, cy, size / 2);
}

void RecursiveImage4_4(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    RecursiveImage4_4(hdc, cx - size / 2, cy - size, size / 2);
    RecursiveImage4_4(hdc, cx + size / 2, cy - size, size / 2);
    RecursiveImage4_4(hdc, cx - size, cy + size, size / 2);
    RecursiveImage4_4(hdc, cx + size, cy + size, size / 2);
}

void RecursiveImage4_5(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    RecursiveImage4_5(hdc, cx - size, cy, size / 2);
    RecursiveImage4_5(hdc, cx + size, cy, size / 2);
    RecursiveImage4_5(hdc, cx, cy - size, size / 2);
    RecursiveImage4_5(hdc, cx, cy + size, size / 2);
}

void RecursiveImage4_6(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage4_6(hdc, cx - size, cy, size / 2);
    RecursiveImage4_6(hdc, cx + size, cy, size / 2);
    RecursiveImage4_6(hdc, cx, cy - size, size / 2);
}

void RecursiveImage4_7(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage4_7(hdc, cx - size, cy - size, size / 2);
    RecursiveImage4_7(hdc, cx + size, cy + size, size / 2);
}

void Image5(HDC hdc, int cx, int cy, int size) {
    int x1 = cx + size;
    int y1 = cy;
    int x2 = cx;
    int y2 = cy + size;
    int x3 = cx - size;
    int y3 = cy;
    int x4 = cx - size / 2;
    int y4 = cy - size / 2;
    int x5 = cx + size / 2;
    int y5 = cy - size / 2;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void RecursiveImage5_1(HDC hdc, int cx, int cy, int size) {
    Image5(hdc, cx, cy, size);
    if (size < 60) {
        return;
    }
    RecursiveImage5_1(hdc, cx + size, cy, size / 2);
    RecursiveImage5_1(hdc, cx - size / 2, cy - size / 2, size / 2);
    RecursiveImage5_1(hdc, cx + size / 2, cy - size / 2, size / 2);
    RecursiveImage5_1(hdc, cx - size, cy, size / 2);
    RecursiveImage5_1(hdc, cx, cy + size, size / 2);
}

void RecursiveImage5_2(HDC hdc, int cx, int cy, int size) {
    Image5(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    RecursiveImage5_2(hdc, cx + size, cy, size / 2);
    RecursiveImage5_2(hdc, cx - size / 2, cy - size / 2, size / 2);
    RecursiveImage5_2(hdc, cx + size / 2, cy - size / 2, size / 2);
    RecursiveImage5_2(hdc, cx - size, cy, size / 2);
    RecursiveImage5_2(hdc, cx, cy + size, size / 2);
}

void Image6(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size / 2;
    int y1 = cy;
    int x2 = cx - size;
    int y2 = cy - size;
    int x3 = cx;
    int y3 = cy - size;
    int x4 = cx + size / 2;
    int y4 = cy;
    int x5 = cx;
    int y5 = cy + size;
    int x6 = cx - size;
    int y6 = cy + size;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x6, y6);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void RecursiveImage6_1(HDC hdc, int cx, int cy, int size) {
    Image6(hdc, cx, cy, size);
    if (size < 60) {
        return;
    }
    RecursiveImage6_1(hdc, cx + (size / 4) * 3, cy, size / 2);
    RecursiveImage6_1(hdc, cx - (size / 4) * 3, cy, size / 2);
}

void RecursiveImage6_2(HDC hdc, int cx, int cy, int size) {
    Image6(hdc, cx, cy, size);
    if (size < 10) {
        return;
    }
    RecursiveImage6_2(hdc, cx + (size / 4) * 3, cy, size / 2);
    RecursiveImage6_2(hdc, cx - (size / 4) * 3, cy, size / 2);
}

void Image7(HDC hdc, int cx, int cy, int size) {
    int x1 = cx;
    int y1 = cy;
    int x2 = cx - size;
    int y2 = cy;
    int x3 = cx + size / 2;
    int y3 = cy - size / 2;
    int x4 = cx;
    int y4 = cy + size;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void RecursiveImage7_1(HDC hdc, int cx, int cy, int size) {
    Image7(hdc, cx, cy, size);
    if (size < 60) {
        return;
    }
    RecursiveImage7_1(hdc, cx + size / 2, cy - size / 2, size / 2);
    RecursiveImage7_1(hdc, cx - size / 4, cy + size / 4, size / 2);
}

void RecursiveImage7_2(HDC hdc, int cx, int cy, int size) {
    Image7(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    RecursiveImage7_2(hdc, cx + size / 2, cy - size / 2, size / 2);
    RecursiveImage7_2(hdc, cx - size / 4, cy + size / 4, size / 2);
}

void Image8(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size / 2;
    int y1 = cy;
    int x2 = cx - size;
    int y2 = cy - size;
    int x3 = cx + size;
    int y3 = cy - size;
    int x4 = cx + size / 2;
    int y4 = cy;
    int x5 = cx + size;
    int y5 = cy;
    int x6 = cx + size;
    int y6 = cy + size;
    int x7 = cx - size;
    int y7 = cy + size;
    int x8 = cx - size;
    int y8 = cy;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x6, y6);
    LineTo(hdc, x7, y7);
    LineTo(hdc, x8, y8);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void RecursiveImage8_1(HDC hdc, int cx, int cy, int size) {
    Image8(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    RecursiveImage8_1(hdc, cx, cy - size, size / 2);
    RecursiveImage8_1(hdc, cx, cy + size, size / 2);
}

void Image9(HDC hdc, int cx, int cy, int size) {
    int x1 = cx;
    int y1 = cy;
    int x2 = cx - size;
    int y2 = cy - size;
    int x3 = cx + size / 2;
    int y3 = cy - size;
    int x4 = cx + size / 2;
    int y4 = cy + size;
    int x5 = cx - size;
    int y5 = cy + size;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void RecursiveImage9_1(HDC hdc, int cx, int cy, int size) {
    Image9(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    RecursiveImage9_1(hdc, cx + size, cy, size / 2);
}

void Сrown(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color) {

    POINT p[] = {
        cx,		cy - sizeY,
        cx + sizeX / 2,	cy,
        cx + sizeX,	cy - sizeY,
        cx + sizeX,	cy + sizeY,
        cx - sizeX,	cy + sizeY,
        cx - sizeX,	cy - sizeY,
        cx - sizeX / 2,	cy,
        cx,		cy - sizeY
    };

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Polyline(hdc, p, 8);
    DeleteObject(hPen);
}

void CrownWall_1(HDC hdc) {
    int y = 50;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;
    int sizeX = 10;

    while (x < 900) {
        Сrown(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        x += 100;
        sizeX += 5;

        b += 30;
    }

}


void CrownWall_2(HDC hdc) {
    int y = 100;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;
    int sizeX = 10;

    while (y < 900) {
        Сrown(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 100;
        sizeY += 5;

        r += 30;
    }

}

void CrownWall_3(HDC hdc) {
    int y = 100;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 100;
    int sizeX = 10;

    while (y < 900) {
        Сrown(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 100;
        x += 100;
        sizeX += 5;
        sizeY += 5;

        r += 30;
        g += 30;
    }

}

void CrownWall_4(HDC hdc) {
    int y = 100;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    while (y < 500) {
        int x = 1000;
        int sizeX = 10;
        g = 0;
        while (x < 1900) {
            Сrown(hdc, x, y, sizeX, sizeY, RGB(r, g, b));
            x += 100;
            sizeX += 5;
            g += 30;
        }

        y += 100;
        sizeY += 5;
        r += 80;
    }
}

void MyFigure(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color) {

    POINT p[] = {
        cx - sizeX, cy,
        cx + sizeX / 2, cy - sizeY,
        cx + sizeX, cy,
        cx - sizeX / 2, cy + sizeY,
        cx - sizeX, cy,
    };

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Polyline(hdc, p, 5);
    DeleteObject(hPen);
}

void MyFigureWall_1(HDC hdc) {
    int y = 50;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;
    int sizeX = 10;

    while (x < 900) {
        MyFigure(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        x += 100;
        sizeX += 5;

        b += 30;
    }

}

void MyFigureWall_2(HDC hdc) {
    int y = 100;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;
    int sizeX = 10;

    while (y < 900) {
        MyFigure(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 100;
        sizeY += 5;

        r += 30;
    }

}

void MyFigureWall_3(HDC hdc) {
    int y = 100;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 100;
    int sizeX = 10;

    while (y < 900) {
        MyFigure(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 100;
        x += 100;
        sizeX += 5;
        sizeY += 5;

        r += 30;
        g += 30;
    }

}

void MyFigureWall_4(HDC hdc) {
    int y = 100;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    while (y < 500) {
        int x = 1000;
        int sizeX = 10;
        g = 0;
        while (x < 1900) {
            MyFigure(hdc, x, y, sizeX, sizeY, RGB(r, g, b));
            x += 100;
            sizeX += 5;
            g += 30;
        }

        y += 100;
        sizeY += 5;
        r += 80;
    }
}

void MyFigure1(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color) {

    POINT p[] = {
        cx + sizeX,		cy - sizeY,
        cx + sizeX,	    cy + sizeY,
        cx,	            cy + 2 * sizeY,
        cx - sizeX,	    cy + sizeY,
        cx - sizeX,	    cy - sizeY,
        cx,         	cy - 2 * sizeY,
        cx + sizeX,		cy - sizeY
    };

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Polyline(hdc, p, 7);
    DeleteObject(hPen);
}

void MyFigure1Wall_1(HDC hdc) {
    int y = 50;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;
    int sizeX = 10;

    while (x < 900) {
        MyFigure1(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        x += 100;
        sizeX += 5;

        b += 30;
    }

}

void MyFigure1Wall_2(HDC hdc) {
    int y = 100;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;
    int sizeX = 10;

    while (y < 900) {
        MyFigure1(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 150;
        sizeY += 5;

        r += 30;
    }

}

void MyFigure1Wall_3(HDC hdc) {
    int y = 100;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 100;
    int sizeX = 10;

    while (y < 900) {
        MyFigure1(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 100;
        x += 100;
        sizeX += 5;
        sizeY += 5;

        r += 30;
        g += 30;
    }

}

void MyFigure1Wall_4(HDC hdc) {
    int y = 100;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    while (y < 500) {
        int x = 1000;
        int sizeX = 10;
        g = 0;
        while (x < 1900) {
            MyFigure1(hdc, x, y, sizeX, sizeY, RGB(r, g, b));
            x += 100;
            sizeX += 5;
            g += 30;
        }

        y += 100;
        sizeY += 5;
        r += 80;
    }
}

void MyFigure2(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color) {

    POINT p[] = {
        cx + sizeX,		cy + sizeY,
        cx - sizeX,	    cy + sizeY,
        cx - sizeX,	    cy,
        cx,     	    cy - sizeY,
        cx + sizeX,	    cy,
        cx + sizeX,		cy + sizeY
    };

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Polyline(hdc, p, 6);
    DeleteObject(hPen);
}

void MyFigure2Wall_1(HDC hdc) {
    int y = 50;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;
    int sizeX = 10;

    while (x < 900) {
        MyFigure2(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        x += 100;
        sizeX += 5;

        b += 30;
    }

}

void MyFigure2Wall_2(HDC hdc) {
    int y = 100;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;
    int sizeX = 10;

    while (y < 900) {
        MyFigure2(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 150;
        sizeY += 5;

        r += 30;
    }

}

void MyFigure2Wall_3(HDC hdc) {
    int y = 100;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 100;
    int sizeX = 10;

    while (y < 900) {
        MyFigure2(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 100;
        x += 100;
        sizeX += 5;
        sizeY += 5;

        r += 30;
        g += 30;
    }

}

void MyFigure2Wall_4(HDC hdc) {
    int y = 100;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    while (y < 500) {
        int x = 1000;
        int sizeX = 10;
        g = 0;
        while (x < 1900) {
            MyFigure2(hdc, x, y, sizeX, sizeY, RGB(r, g, b));
            x += 100;
            sizeX += 5;
            g += 30;
        }

        y += 100;
        sizeY += 5;
        r += 80;
    }
}

void MyFigure2Wall_5(HDC hdc) {
    int y = 100;
    int sizeY = 10;

    int i = 1;

    int r = 0;
    int b = 0;
    int g = 0;

    while (i < 7) {
        int x = 700;
        int sizeX = 10;
        int k = 1;
        int n = 100;
        MyFigure2(hdc, x, y, sizeX, sizeY, RGB(r, g, b));
        while (k < i) {
            MyFigure2(hdc, x + n, y, sizeX, sizeY, RGB(r, g, b));
            MyFigure2(hdc, x - n, y, sizeX, sizeY, RGB(r, g, b));
            n += 100;
            k++;
        }
        b += 40;
        y += 100;
        sizeY += 10;
        i++;
    }
}

void StClausAuto(HDC hdc, int x, int y) {
    //верхний треугольник
    MoveToEx(hdc, 20 + x, 0 + y, NULL);
    LineTo(hdc, 30 + x, 20 + y);
    LineTo(hdc, 10 + x, 20 + y);
    LineTo(hdc, 20 + x, 0 + y);

    //средний треугольник
    MoveToEx(hdc, 20 + x, 10 + y, NULL);
    LineTo(hdc, 30 + x, 40 + y);
    LineTo(hdc, 10 + x, 40 + y);
    LineTo(hdc, 20 + x, 10 + y);

    //нижний треугольник
    MoveToEx(hdc, 20 + x, 30 + y, NULL);
    LineTo(hdc, 40 + x, 80 + y);
    LineTo(hdc, 0 + x, 80 + y);
    LineTo(hdc, 20 + x, 30 + y);
}

void StClausTree(HDC hdc, int x, int y) {
    Ellipse(hdc, 20 + x, 0 + y, 40 + x, 20 + y);
    Ellipse(hdc, 10 + x, 20 + y, 50 + x, 60 + y);
    Ellipse(hdc, 0 + x, 60 + y, 60 + x, 120 + y);
    MoveToEx(hdc, 0 + x, 40 + y, NULL);
    LineTo(hdc, 15 + x, 30 + y);
    MoveToEx(hdc, 60 + x, 40 + y, NULL);
    LineTo(hdc, 45 + x, 30 + y);
    MoveToEx(hdc, 40 + x, 120 + y, NULL);
    LineTo(hdc, 70 + x, 0 + y);
    MoveToEx(hdc, 66 + x, 20 + y, NULL);
    LineTo(hdc, 64 + x, 0 + y);
    MoveToEx(hdc, 66 + x, 20 + y, NULL);
    LineTo(hdc, 75 + x, 0 + y);
}

void Logo(HDC hdc, int x, int y) {
    HPEN hPen_line;
    HPEN hPen_white;
    HBRUSH hBrush_black_car;
    HBRUSH hBrush_white;
    hPen_white = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    hPen_line = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    hBrush_black_car = CreateSolidBrush(RGB(0, 0, 0));
    hBrush_white = CreateSolidBrush(RGB(255, 255, 255));

    SelectObject(hdc, hBrush_black_car);
    SelectObject(hdc, hPen_line);
    Ellipse(hdc, x - 100, y - 50, x + 100, y + 50);
    SelectObject(hdc, hBrush_white);
    SelectObject(hdc, hPen_white);
    Ellipse(hdc, x - 75, y - 35, x + 75, y + 25);
    POINT infi1[4];
    infi1[0].x = x;
    infi1[0].y = y - 25;
    infi1[1].x = x + 55;
    infi1[1].y = y + 35;
    infi1[2].x = x - 55;
    infi1[2].y = y + 35;
    SelectObject(hdc, hPen_line);
    SelectObject(hdc, hBrush_black_car);
    Polygon(hdc, infi1, 3);
    POINT infi[4];
    infi[0].x = x;
    infi[0].y = y - 15;
    infi[1].x = x + 35;
    infi[1].y = y + 65;
    infi[2].x = x - 35;
    infi[2].y = y + 65;
    SelectObject(hdc, hPen_white);
    SelectObject(hdc, hBrush_white);
    Polygon(hdc, infi, 3);

    DeleteObject(hPen_line);
    DeleteObject(hPen_white);
    DeleteObject(hBrush_black_car);
    DeleteObject(hBrush_white);
}


void L1_1(HDC hdc) {
    HPEN hPen_stvol;
    HPEN hPen_crona;
    HPEN hPen_crona_dark;
    HPEN hPen_sun;
    HPEN hPen_cloud;
    HPEN hPen_line;
    HPEN hPen_wood;
    HPEN hPen_white;
    HBRUSH hBrush_line;
    HBRUSH hBrush_crona;
    HBRUSH hBrush_crona_dark;
    HBRUSH hBrush_sun;
    HBRUSH hBrush_cloud;
    HBRUSH hBrush_wood;
    HBRUSH hBrush_wood_lite;
    HBRUSH hBrush_red_car;
    HBRUSH hBrush_black_car;
    HBRUSH hBrush_white;
    hPen_line = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    hPen_stvol = CreatePen(PS_SOLID, 20, RGB(119, 38, 19));
    hPen_crona = CreatePen(PS_SOLID, 20, RGB(27, 111, 12));
    hPen_crona_dark = CreatePen(PS_SOLID, 20, RGB(12, 45, 1));
    hPen_sun = CreatePen(PS_SOLID, 5, RGB(214, 228, 0));
    hPen_cloud = CreatePen(PS_SOLID, 5, RGB(145, 173, 255));
    hPen_wood = CreatePen(PS_SOLID, 1, RGB(132, 77, 44));
    hPen_white = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    hBrush_crona = CreateSolidBrush(RGB(27, 111, 12));
    hBrush_crona_dark = CreateSolidBrush(RGB(12, 45, 1));
    hBrush_sun = CreateHatchBrush(HS_CROSS, RGB(214, 228, 0));
    hBrush_cloud = CreateSolidBrush(RGB(145, 173, 255));
    hBrush_wood = CreateSolidBrush(RGB(132, 77, 44));
    hBrush_wood_lite = CreateSolidBrush(RGB(173, 107, 55));
    hBrush_line = CreateSolidBrush(RGB(255, 255, 255));
    hBrush_red_car = CreateSolidBrush(RGB(255, 0, 0));
    hBrush_black_car = CreateSolidBrush(RGB(0, 0, 0));
    hBrush_white = CreateSolidBrush(RGB(255, 255, 255));

    POINT poly[4];
    poly[0].x = 150;
    poly[0].y = 350;
    poly[1].x = 275;
    poly[1].y = 250;
    poly[2].x = 400;
    poly[2].y = 350;
    SelectObject(hdc, hBrush_wood_lite);
    Polygon(hdc, poly, 3);
    MoveToEx(hdc, 150, 350, NULL);
    LineTo(hdc, 275, 250);
    LineTo(hdc, 400, 350);
    // Дом
    RECT rect_house = { 150, 350, 400, 525 };
    FillRect(hdc, &rect_house, hBrush_wood);
    LineTo(hdc, 400, 525);
    LineTo(hdc, 150, 525);
    LineTo(hdc, 150, 350);
    LineTo(hdc, 400, 350);
    // Окно
    RECT rect_window = { 225, 400, 325, 475 };
    FillRect(hdc, &rect_window, hBrush_cloud);
    MoveToEx(hdc, 225, 400, NULL);
    LineTo(hdc, 225, 475);
    LineTo(hdc, 325, 475);
    LineTo(hdc, 325, 400);
    LineTo(hdc, 225, 400);
    // Рама
    MoveToEx(hdc, 275, 400, NULL);
    LineTo(hdc, 275, 475);
    MoveToEx(hdc, 275, 425, NULL);
    LineTo(hdc, 325, 425);

    DeleteObject(hPen_stvol);
    DeleteObject(hPen_crona);
    DeleteObject(hPen_crona_dark);
    DeleteObject(hPen_sun);
    DeleteObject(hPen_cloud);
    DeleteObject(hPen_line);
    DeleteObject(hPen_wood);
    DeleteObject(hPen_white);
    DeleteObject(hBrush_line);
    DeleteObject(hBrush_crona);
    DeleteObject(hBrush_crona_dark);
    DeleteObject(hBrush_sun);
    DeleteObject(hBrush_cloud);
    DeleteObject(hBrush_wood);
    DeleteObject(hBrush_wood_lite);
    DeleteObject(hBrush_red_car);
    DeleteObject(hBrush_black_car);
    DeleteObject(hBrush_white);
}

void L1_2(HDC hdc) {
    HPEN hPen_stvol;
    HPEN hPen_crona;
    HPEN hPen_crona_dark;
    HPEN hPen_sun;
    HPEN hPen_cloud;
    HPEN hPen_line;
    HPEN hPen_wood;
    HPEN hPen_white;
    HBRUSH hBrush_line;
    HBRUSH hBrush_crona;
    HBRUSH hBrush_crona_dark;
    HBRUSH hBrush_sun;
    HBRUSH hBrush_cloud;
    HBRUSH hBrush_wood;
    HBRUSH hBrush_wood_lite;
    HBRUSH hBrush_red_car;
    HBRUSH hBrush_black_car;
    HBRUSH hBrush_white;
    hPen_line = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    hPen_stvol = CreatePen(PS_SOLID, 20, RGB(119, 38, 19));
    hPen_crona = CreatePen(PS_SOLID, 20, RGB(27, 111, 12));
    hPen_crona_dark = CreatePen(PS_SOLID, 20, RGB(12, 45, 1));
    hPen_sun = CreatePen(PS_SOLID, 5, RGB(214, 228, 0));
    hPen_cloud = CreatePen(PS_SOLID, 5, RGB(145, 173, 255));
    hPen_wood = CreatePen(PS_SOLID, 1, RGB(132, 77, 44));
    hPen_white = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    hBrush_crona = CreateSolidBrush(RGB(27, 111, 12));
    hBrush_crona_dark = CreateSolidBrush(RGB(12, 45, 1));
    hBrush_sun = CreateHatchBrush(HS_CROSS, RGB(214, 228, 0));
    hBrush_cloud = CreateSolidBrush(RGB(145, 173, 255));
    hBrush_wood = CreateSolidBrush(RGB(132, 77, 44));
    hBrush_wood_lite = CreateSolidBrush(RGB(173, 107, 55));
    hBrush_line = CreateSolidBrush(RGB(255, 255, 255));
    hBrush_red_car = CreateSolidBrush(RGB(255, 0, 0));
    hBrush_black_car = CreateSolidBrush(RGB(0, 0, 0));
    hBrush_white = CreateSolidBrush(RGB(255, 255, 255));

    SelectObject(hdc, hBrush_wood_lite);
    MoveToEx(hdc, 500, 400, NULL);
    LineTo(hdc, 525, 375);
    LineTo(hdc, 550, 400);
    LineTo(hdc, 500, 400);
    MoveToEx(hdc, 475, 450, NULL);
    LineTo(hdc, 525, 400);
    LineTo(hdc, 575, 450);
    LineTo(hdc, 475, 450);
    MoveToEx(hdc, 450, 525, NULL);
    LineTo(hdc, 525, 450);
    LineTo(hdc, 600, 525);
    LineTo(hdc, 450, 525);

    DeleteObject(hPen_stvol);
    DeleteObject(hPen_crona);
    DeleteObject(hPen_crona_dark);
    DeleteObject(hPen_sun);
    DeleteObject(hPen_cloud);
    DeleteObject(hPen_line);
    DeleteObject(hPen_wood);
    DeleteObject(hPen_white);
    DeleteObject(hBrush_line);
    DeleteObject(hBrush_crona);
    DeleteObject(hBrush_crona_dark);
    DeleteObject(hBrush_sun);
    DeleteObject(hBrush_cloud);
    DeleteObject(hBrush_wood);
    DeleteObject(hBrush_wood_lite);
    DeleteObject(hBrush_red_car);
    DeleteObject(hBrush_black_car);
    DeleteObject(hBrush_white);
}

void L1_3(HDC hdc) {
    HPEN hPen_stvol;
    HPEN hPen_crona;
    HPEN hPen_crona_dark;
    HPEN hPen_sun;
    HPEN hPen_cloud;
    HPEN hPen_line;
    HPEN hPen_wood;
    HPEN hPen_white;
    HBRUSH hBrush_line;
    HBRUSH hBrush_crona;
    HBRUSH hBrush_crona_dark;
    HBRUSH hBrush_sun;
    HBRUSH hBrush_cloud;
    HBRUSH hBrush_wood;
    HBRUSH hBrush_wood_lite;
    HBRUSH hBrush_red_car;
    HBRUSH hBrush_black_car;
    HBRUSH hBrush_white;
    hPen_line = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    hPen_stvol = CreatePen(PS_SOLID, 20, RGB(119, 38, 19));
    hPen_crona = CreatePen(PS_SOLID, 20, RGB(27, 111, 12));
    hPen_crona_dark = CreatePen(PS_SOLID, 20, RGB(12, 45, 1));
    hPen_sun = CreatePen(PS_SOLID, 5, RGB(214, 228, 0));
    hPen_cloud = CreatePen(PS_SOLID, 5, RGB(145, 173, 255));
    hPen_wood = CreatePen(PS_SOLID, 1, RGB(132, 77, 44));
    hPen_white = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    hBrush_crona = CreateSolidBrush(RGB(27, 111, 12));
    hBrush_crona_dark = CreateSolidBrush(RGB(12, 45, 1));
    hBrush_sun = CreateHatchBrush(HS_CROSS, RGB(214, 228, 0));
    hBrush_cloud = CreateSolidBrush(RGB(145, 173, 255));
    hBrush_wood = CreateSolidBrush(RGB(132, 77, 44));
    hBrush_wood_lite = CreateSolidBrush(RGB(173, 107, 55));
    hBrush_line = CreateSolidBrush(RGB(255, 255, 255));
    hBrush_red_car = CreateSolidBrush(RGB(255, 0, 0));
    hBrush_black_car = CreateSolidBrush(RGB(0, 0, 0));
    hBrush_white = CreateSolidBrush(RGB(255, 255, 255));

    // Деревце

    //Ствол
    SelectObject(hdc, hPen_stvol);
    MoveToEx(hdc, 700, 525, NULL);
    LineTo(hdc, 700, 350);
    //Крона
    SelectObject(hdc, hPen_crona);
    SelectObject(hdc, hBrush_crona);
    Ellipse(hdc, 650, 250, 750, 450);
    SelectObject(hdc, hPen_crona_dark);
    SelectObject(hdc, hBrush_crona_dark);
    Ellipse(hdc, 672, 380, 690, 400);
    Ellipse(hdc, 722, 330, 740, 350);
    Ellipse(hdc, 692, 280, 710, 300);

    DeleteObject(hPen_stvol);
    DeleteObject(hPen_crona);
    DeleteObject(hPen_crona_dark);
    DeleteObject(hPen_sun);
    DeleteObject(hPen_cloud);
    DeleteObject(hPen_line);
    DeleteObject(hPen_wood);
    DeleteObject(hPen_white);
    DeleteObject(hBrush_line);
    DeleteObject(hBrush_crona);
    DeleteObject(hBrush_crona_dark);
    DeleteObject(hBrush_sun);
    DeleteObject(hBrush_cloud);
    DeleteObject(hBrush_wood);
    DeleteObject(hBrush_wood_lite);
    DeleteObject(hBrush_red_car);
    DeleteObject(hBrush_black_car);
    DeleteObject(hBrush_white);
}

void L1_4(HDC hdc) {
    HPEN hPen_stvol;
    HPEN hPen_crona;
    HPEN hPen_crona_dark;
    HPEN hPen_sun;
    HPEN hPen_cloud;
    HPEN hPen_line;
    HPEN hPen_wood;
    HPEN hPen_white;
    HBRUSH hBrush_line;
    HBRUSH hBrush_crona;
    HBRUSH hBrush_crona_dark;
    HBRUSH hBrush_sun;
    HBRUSH hBrush_cloud;
    HBRUSH hBrush_wood;
    HBRUSH hBrush_wood_lite;
    HBRUSH hBrush_red_car;
    HBRUSH hBrush_black_car;
    HBRUSH hBrush_white;
    hPen_line = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    hPen_stvol = CreatePen(PS_SOLID, 20, RGB(119, 38, 19));
    hPen_crona = CreatePen(PS_SOLID, 20, RGB(27, 111, 12));
    hPen_crona_dark = CreatePen(PS_SOLID, 20, RGB(12, 45, 1));
    hPen_sun = CreatePen(PS_SOLID, 5, RGB(214, 228, 0));
    hPen_cloud = CreatePen(PS_SOLID, 5, RGB(145, 173, 255));
    hPen_wood = CreatePen(PS_SOLID, 1, RGB(132, 77, 44));
    hPen_white = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    hBrush_crona = CreateSolidBrush(RGB(27, 111, 12));
    hBrush_crona_dark = CreateSolidBrush(RGB(12, 45, 1));
    hBrush_sun = CreateHatchBrush(HS_CROSS, RGB(214, 228, 0));
    hBrush_cloud = CreateSolidBrush(RGB(145, 173, 255));
    hBrush_wood = CreateSolidBrush(RGB(132, 77, 44));
    hBrush_wood_lite = CreateSolidBrush(RGB(173, 107, 55));
    hBrush_line = CreateSolidBrush(RGB(255, 255, 255));
    hBrush_red_car = CreateSolidBrush(RGB(255, 0, 0));
    hBrush_black_car = CreateSolidBrush(RGB(0, 0, 0));
    hBrush_white = CreateSolidBrush(RGB(255, 255, 255));

    // Солнышко
    SelectObject(hdc, hPen_sun);
    SelectObject(hdc, hBrush_sun);
    Ellipse(hdc, 50, 50, 150, 150);

    DeleteObject(hPen_stvol);
    DeleteObject(hPen_crona);
    DeleteObject(hPen_crona_dark);
    DeleteObject(hPen_sun);
    DeleteObject(hPen_cloud);
    DeleteObject(hPen_line);
    DeleteObject(hPen_wood);
    DeleteObject(hPen_white);
    DeleteObject(hBrush_line);
    DeleteObject(hBrush_crona);
    DeleteObject(hBrush_crona_dark);
    DeleteObject(hBrush_sun);
    DeleteObject(hBrush_cloud);
    DeleteObject(hBrush_wood);
    DeleteObject(hBrush_wood_lite);
    DeleteObject(hBrush_red_car);
    DeleteObject(hBrush_black_car);
    DeleteObject(hBrush_white);
}

void L1_5(HDC hdc) {
    HPEN hPen_stvol;
    HPEN hPen_crona;
    HPEN hPen_crona_dark;
    HPEN hPen_sun;
    HPEN hPen_cloud;
    HPEN hPen_line;
    HPEN hPen_wood;
    HPEN hPen_white;
    HBRUSH hBrush_line;
    HBRUSH hBrush_crona;
    HBRUSH hBrush_crona_dark;
    HBRUSH hBrush_sun;
    HBRUSH hBrush_cloud;
    HBRUSH hBrush_wood;
    HBRUSH hBrush_wood_lite;
    HBRUSH hBrush_red_car;
    HBRUSH hBrush_black_car;
    HBRUSH hBrush_white;
    hPen_line = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    hPen_stvol = CreatePen(PS_SOLID, 20, RGB(119, 38, 19));
    hPen_crona = CreatePen(PS_SOLID, 20, RGB(27, 111, 12));
    hPen_crona_dark = CreatePen(PS_SOLID, 20, RGB(12, 45, 1));
    hPen_sun = CreatePen(PS_SOLID, 5, RGB(214, 228, 0));
    hPen_cloud = CreatePen(PS_SOLID, 5, RGB(145, 173, 255));
    hPen_wood = CreatePen(PS_SOLID, 1, RGB(132, 77, 44));
    hPen_white = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    hBrush_crona = CreateSolidBrush(RGB(27, 111, 12));
    hBrush_crona_dark = CreateSolidBrush(RGB(12, 45, 1));
    hBrush_sun = CreateHatchBrush(HS_CROSS, RGB(214, 228, 0));
    hBrush_cloud = CreateSolidBrush(RGB(145, 173, 255));
    hBrush_wood = CreateSolidBrush(RGB(132, 77, 44));
    hBrush_wood_lite = CreateSolidBrush(RGB(173, 107, 55));
    hBrush_line = CreateSolidBrush(RGB(255, 255, 255));
    hBrush_red_car = CreateSolidBrush(RGB(255, 0, 0));
    hBrush_black_car = CreateSolidBrush(RGB(0, 0, 0));
    hBrush_white = CreateSolidBrush(RGB(255, 255, 255));

    // Облако
    SelectObject(hdc, hPen_cloud);
    SelectObject(hdc, hBrush_cloud);
    Ellipse(hdc, 300, 50, 500, 150);
    Ellipse(hdc, 350, 100, 550, 200);
    Ellipse(hdc, 450, 100, 650, 194);
    Ellipse(hdc, 420, 30, 660, 130);

    DeleteObject(hPen_stvol);
    DeleteObject(hPen_crona);
    DeleteObject(hPen_crona_dark);
    DeleteObject(hPen_sun);
    DeleteObject(hPen_cloud);
    DeleteObject(hPen_line);
    DeleteObject(hPen_wood);
    DeleteObject(hPen_white);
    DeleteObject(hBrush_line);
    DeleteObject(hBrush_crona);
    DeleteObject(hBrush_crona_dark);
    DeleteObject(hBrush_sun);
    DeleteObject(hBrush_cloud);
    DeleteObject(hBrush_wood);
    DeleteObject(hBrush_wood_lite);
    DeleteObject(hBrush_red_car);
    DeleteObject(hBrush_black_car);
    DeleteObject(hBrush_white);
}

void L1_6(HDC hdc) {
    HPEN hPen_stvol;
    HPEN hPen_crona;
    HPEN hPen_crona_dark;
    HPEN hPen_sun;
    HPEN hPen_cloud;
    HPEN hPen_line;
    HPEN hPen_wood;
    HPEN hPen_white;
    HBRUSH hBrush_line;
    HBRUSH hBrush_crona;
    HBRUSH hBrush_crona_dark;
    HBRUSH hBrush_sun;
    HBRUSH hBrush_cloud;
    HBRUSH hBrush_wood;
    HBRUSH hBrush_wood_lite;
    HBRUSH hBrush_red_car;
    HBRUSH hBrush_black_car;
    HBRUSH hBrush_white;
    hPen_line = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    hPen_stvol = CreatePen(PS_SOLID, 20, RGB(119, 38, 19));
    hPen_crona = CreatePen(PS_SOLID, 20, RGB(27, 111, 12));
    hPen_crona_dark = CreatePen(PS_SOLID, 20, RGB(12, 45, 1));
    hPen_sun = CreatePen(PS_SOLID, 5, RGB(214, 228, 0));
    hPen_cloud = CreatePen(PS_SOLID, 5, RGB(145, 173, 255));
    hPen_wood = CreatePen(PS_SOLID, 1, RGB(132, 77, 44));
    hPen_white = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    hBrush_crona = CreateSolidBrush(RGB(27, 111, 12));
    hBrush_crona_dark = CreateSolidBrush(RGB(12, 45, 1));
    hBrush_sun = CreateHatchBrush(HS_CROSS, RGB(214, 228, 0));
    hBrush_cloud = CreateSolidBrush(RGB(145, 173, 255));
    hBrush_wood = CreateSolidBrush(RGB(132, 77, 44));
    hBrush_wood_lite = CreateSolidBrush(RGB(173, 107, 55));
    hBrush_line = CreateSolidBrush(RGB(255, 255, 255));
    hBrush_red_car = CreateSolidBrush(RGB(255, 0, 0));
    hBrush_black_car = CreateSolidBrush(RGB(0, 0, 0));
    hBrush_white = CreateSolidBrush(RGB(255, 255, 255));

    // Лучи
    SelectObject(hdc, hPen_sun);
    MoveToEx(hdc, 60, 150, NULL);
    LineTo(hdc, 40, 200);
    MoveToEx(hdc, 100, 160, NULL);
    LineTo(hdc, 100, 220);
    MoveToEx(hdc, 145, 150, NULL);
    LineTo(hdc, 175, 200);
    MoveToEx(hdc, 160, 125, NULL);
    LineTo(hdc, 200, 160);

    DeleteObject(hPen_stvol);
    DeleteObject(hPen_crona);
    DeleteObject(hPen_crona_dark);
    DeleteObject(hPen_sun);
    DeleteObject(hPen_cloud);
    DeleteObject(hPen_line);
    DeleteObject(hPen_wood);
    DeleteObject(hPen_white);
    DeleteObject(hBrush_line);
    DeleteObject(hBrush_crona);
    DeleteObject(hBrush_crona_dark);
    DeleteObject(hBrush_sun);
    DeleteObject(hBrush_cloud);
    DeleteObject(hBrush_wood);
    DeleteObject(hBrush_wood_lite);
    DeleteObject(hBrush_red_car);
    DeleteObject(hBrush_black_car);
    DeleteObject(hBrush_white);
}

void L1_7(HDC hdc) {
    HPEN hPen_stvol;
    HPEN hPen_crona;
    HPEN hPen_crona_dark;
    HPEN hPen_sun;
    HPEN hPen_cloud;
    HPEN hPen_line;
    HPEN hPen_wood;
    HPEN hPen_white;
    HBRUSH hBrush_line;
    HBRUSH hBrush_crona;
    HBRUSH hBrush_crona_dark;
    HBRUSH hBrush_sun;
    HBRUSH hBrush_cloud;
    HBRUSH hBrush_wood;
    HBRUSH hBrush_wood_lite;
    HBRUSH hBrush_red_car;
    HBRUSH hBrush_black_car;
    HBRUSH hBrush_white;
    hPen_line = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    hPen_stvol = CreatePen(PS_SOLID, 20, RGB(119, 38, 19));
    hPen_crona = CreatePen(PS_SOLID, 20, RGB(27, 111, 12));
    hPen_crona_dark = CreatePen(PS_SOLID, 20, RGB(12, 45, 1));
    hPen_sun = CreatePen(PS_SOLID, 5, RGB(214, 228, 0));
    hPen_cloud = CreatePen(PS_SOLID, 5, RGB(145, 173, 255));
    hPen_wood = CreatePen(PS_SOLID, 1, RGB(132, 77, 44));
    hPen_white = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    hBrush_crona = CreateSolidBrush(RGB(27, 111, 12));
    hBrush_crona_dark = CreateSolidBrush(RGB(12, 45, 1));
    hBrush_sun = CreateHatchBrush(HS_CROSS, RGB(214, 228, 0));
    hBrush_cloud = CreateSolidBrush(RGB(145, 173, 255));
    hBrush_wood = CreateSolidBrush(RGB(132, 77, 44));
    hBrush_wood_lite = CreateSolidBrush(RGB(173, 107, 55));
    hBrush_line = CreateSolidBrush(RGB(255, 255, 255));
    hBrush_red_car = CreateSolidBrush(RGB(255, 0, 0));
    hBrush_black_car = CreateSolidBrush(RGB(0, 0, 0));
    hBrush_white = CreateSolidBrush(RGB(255, 255, 255));
    
    // Машина
    //Кузов
    POINT poly1[11];
    poly1[0].x = 100;
    poly1[0].y = 800;
    poly1[1].x = 500;
    poly1[1].y = 800;
    poly1[2].x = 500;
    poly1[2].y = 740;
    poly1[3].x = 490;
    poly1[3].y = 740;
    poly1[4].x = 490;
    poly1[4].y = 650;
    poly1[5].x = 240;
    poly1[5].y = 650;
    poly1[6].x = 220;
    poly1[6].y = 720;
    poly1[7].x = 110;
    poly1[7].y = 720;
    poly1[8].x = 110;
    poly1[8].y = 740;
    poly1[9].x = 100;
    poly1[9].y = 740;
    poly1[10].x = 100;
    poly1[10].y = 800;
    SelectObject(hdc, hPen_line);
    SelectObject(hdc, hBrush_red_car);
    Polygon(hdc, poly1, 11);

    //Стекла
    POINT poly2[5];
    poly2[0].x = 240;
    poly2[0].y = 720;
    poly2[1].x = 255;
    poly2[1].y = 660;
    poly2[2].x = 470;
    poly2[2].y = 660;
    poly2[3].x = 470;
    poly2[3].y = 720;
    poly2[4].x = 240;
    poly2[4].y = 720;
    SelectObject(hdc, hPen_line);
    SelectObject(hdc, hBrush_cloud);
    Polygon(hdc, poly2, 5);

    MoveToEx(hdc, 300, 660, NULL);
    LineTo(hdc, 300, 720);
    MoveToEx(hdc, 400, 660, NULL);
    LineTo(hdc, 400, 720);
    //Колеса
    SelectObject(hdc, hBrush_black_car);
    Ellipse(hdc, 130, 740, 230, 840);
    Ellipse(hdc, 370, 740, 470, 840);

    DeleteObject(hPen_stvol);
    DeleteObject(hPen_crona);
    DeleteObject(hPen_crona_dark);
    DeleteObject(hPen_sun);
    DeleteObject(hPen_cloud);
    DeleteObject(hPen_line);
    DeleteObject(hPen_wood);
    DeleteObject(hPen_white);
    DeleteObject(hBrush_line);
    DeleteObject(hBrush_crona);
    DeleteObject(hBrush_crona_dark);
    DeleteObject(hBrush_sun);
    DeleteObject(hBrush_cloud);
    DeleteObject(hBrush_wood);
    DeleteObject(hBrush_wood_lite);
    DeleteObject(hBrush_red_car);
    DeleteObject(hBrush_black_car);
    DeleteObject(hBrush_white);
}

void L1_8(HDC hdc) {
    HPEN hPen_stvol;
    HPEN hPen_crona;
    HPEN hPen_crona_dark;
    HPEN hPen_sun;
    HPEN hPen_cloud;
    HPEN hPen_line;
    HPEN hPen_wood;
    HPEN hPen_white;
    HBRUSH hBrush_line;
    HBRUSH hBrush_crona;
    HBRUSH hBrush_crona_dark;
    HBRUSH hBrush_sun;
    HBRUSH hBrush_cloud;
    HBRUSH hBrush_wood;
    HBRUSH hBrush_wood_lite;
    HBRUSH hBrush_red_car;
    HBRUSH hBrush_black_car;
    HBRUSH hBrush_white;
    hPen_line = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    hPen_stvol = CreatePen(PS_SOLID, 20, RGB(119, 38, 19));
    hPen_crona = CreatePen(PS_SOLID, 20, RGB(27, 111, 12));
    hPen_crona_dark = CreatePen(PS_SOLID, 20, RGB(12, 45, 1));
    hPen_sun = CreatePen(PS_SOLID, 5, RGB(214, 228, 0));
    hPen_cloud = CreatePen(PS_SOLID, 5, RGB(145, 173, 255));
    hPen_wood = CreatePen(PS_SOLID, 1, RGB(132, 77, 44));
    hPen_white = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    hBrush_crona = CreateSolidBrush(RGB(27, 111, 12));
    hBrush_crona_dark = CreateSolidBrush(RGB(12, 45, 1));
    hBrush_sun = CreateHatchBrush(HS_CROSS, RGB(214, 228, 0));
    hBrush_cloud = CreateSolidBrush(RGB(145, 173, 255));
    hBrush_wood = CreateSolidBrush(RGB(132, 77, 44));
    hBrush_wood_lite = CreateSolidBrush(RGB(173, 107, 55));
    hBrush_line = CreateSolidBrush(RGB(255, 255, 255));
    hBrush_red_car = CreateSolidBrush(RGB(255, 0, 0));
    hBrush_black_car = CreateSolidBrush(RGB(0, 0, 0));
    hBrush_white = CreateSolidBrush(RGB(255, 255, 255));

    // Infiniti
    SelectObject(hdc, hBrush_black_car);
    SelectObject(hdc, hPen_line);
    Ellipse(hdc, 1500, 500, 1700, 600);
    SelectObject(hdc, hBrush_white);
    SelectObject(hdc, hPen_white);
    Ellipse(hdc, 1525, 515, 1675, 575);
    POINT infi1[4];
    infi1[0].x = 1600;
    infi1[0].y = 525;
    infi1[1].x = 1655;
    infi1[1].y = 585;
    infi1[2].x = 1545;
    infi1[2].y = 585;
    SelectObject(hdc, hPen_line);
    SelectObject(hdc, hBrush_black_car);
    Polygon(hdc, infi1, 3);
    POINT infi[4];
    infi[0].x = 1600;
    infi[0].y = 535;
    infi[1].x = 1635;
    infi[1].y = 615;
    infi[2].x = 1565;
    infi[2].y = 615;
    SelectObject(hdc, hPen_white);
    SelectObject(hdc, hBrush_white);
    Polygon(hdc, infi, 3);

    DeleteObject(hPen_stvol);
    DeleteObject(hPen_crona);
    DeleteObject(hPen_crona_dark);
    DeleteObject(hPen_sun);
    DeleteObject(hPen_cloud);
    DeleteObject(hPen_line);
    DeleteObject(hPen_wood);
    DeleteObject(hPen_white);
    DeleteObject(hBrush_line);
    DeleteObject(hBrush_crona);
    DeleteObject(hBrush_crona_dark);
    DeleteObject(hBrush_sun);
    DeleteObject(hBrush_cloud);
    DeleteObject(hBrush_wood);
    DeleteObject(hBrush_wood_lite);
    DeleteObject(hBrush_red_car);
    DeleteObject(hBrush_black_car);
    DeleteObject(hBrush_white);
}

void L2_1(HDC hdc) {
    int x1_1 = 800, y1_1 = 100;
    int x2_1 = 950, y2_1 = 0;
    int i_1 = 0;
    do {
        MoveToEx(hdc, x1_1, y1_1, NULL);
        LineTo(hdc, x2_1, y2_1);
        x1_1 = x1_1 + 6;
        y2_1 = y2_1 + 6;
        i_1++;
    } while (i_1 < 15);
}

void L2_2(HDC hdc) {
    int x1_2 = 1000, y1_2 = 100;
    int x2_2 = 1200, y2_2 = 0;
    int i_2 = 0;
    do {
        MoveToEx(hdc, x1_2, y1_2, NULL);
        LineTo(hdc, x2_2, y2_2);
        x1_2 = x1_2 + 7;
        x2_2 = x2_2 - 7;
        i_2++;
    } while (i_2 < 15);
}

void L2_3(HDC hdc) {
    int x1_3 = 1300, y1_3 = 100;
    int x2_3 = 1300, y2_3 = 0;
    int i_3 = 0;
    do {
        MoveToEx(hdc, x1_3, y1_3, NULL);
        LineTo(hdc, x2_3, y2_3);
        y1_3 = y1_3 - 5;
        x2_3 = x2_3 + 5;
        i_3++;
    } while (i_3 < 15);
}

void L2_4(HDC hdc) {
    int x1_4 = 800, y1_4 = 400;
    int x2_4 = 800, y2_4 = 300;
    int i_4 = 0;
    do {
        MoveToEx(hdc, x1_4, y1_4, NULL);
        LineTo(hdc, x2_4, y2_4);
        x1_4 = x1_4 + 6;
        x2_4 = x2_4 + 6;
        y1_4 = y1_4 + 2;
        y2_4 = y2_4 - 2;
        i_4++;
    } while (i_4 < 15);
}

void L2_5(HDC hdc) {
    int x1_5 = 1000, y1_5 = 400;
    int x2_5 = 1000, y2_5 = 300;
    int i_5 = 0;
    do {
        MoveToEx(hdc, x1_5, y1_5, NULL);
        LineTo(hdc, x2_5, y2_5);
        x1_5 = x1_5 + 6;
        x2_5 = x2_5 + 6;
        y1_5 = y1_5 - 8;
        y2_5 = y2_5 + 8;
        i_5++;
    } while (i_5 < 15);
}

void L2_6(HDC hdc) {
    int x1_6 = 1300, y1_6 = 300;
    int x2_6 = 1350, y2_6 = 400;
    int i_6 = 0;
    do {
        MoveToEx(hdc, x1_6, y1_6, NULL);
        LineTo(hdc, x2_6, y2_6);
        x1_6 = x1_6 + 4;
        y1_6 = y1_6 + 4;
        y2_6 = y2_6 - 8;
        i_6++;
    } while (i_6 < 19);
}

void L2_7(HDC hdc) {
    int x1_7 = 800, y1_7 = 600;
    int x2_7 = 800, y2_7 = 800;
    int i_7 = 0;
    do {
        MoveToEx(hdc, x1_7, y1_7, NULL);
        LineTo(hdc, x2_7, y2_7);
        x1_7 = x1_7 - 8;
        y1_7 = y1_7 + 8;
        x2_7 = x2_7 + 8;
        y2_7 = y2_7 - 8;
        i_7++;
    } while (i_7 < 15);
}

void L2_8(HDC hdc) {
    int x1_8 = 1000, y1_8 = 600;
    int x2_8 = 1000, y2_8 = 800;
    int i_8 = 0;
    do {
        MoveToEx(hdc, x1_8, y1_8, NULL);
        LineTo(hdc, x2_8, y2_8);
        y1_8 = y1_8 + 14;
        x2_8 = x2_8 + 14;
        i_8++;
    } while (i_8 < 15);
}

void L2_9(HDC hdc) {
    int x1_9 = 1300, y1_9 = 600;
    int x2_9 = 1300, y2_9 = 800;
    int i_9 = 0;
    do {
        MoveToEx(hdc, x1_9, y1_9, NULL);
        LineTo(hdc, x2_9, y2_9);
        y2_9 = y2_9 - 8;
        x1_9 = x1_9 - 8;
        y1_9 = y1_9 + 8;
        i_9++;
    } while (i_9 < 15);
}

void L2_10(HDC hdc) {
    int x1_10 = 1500, y1_10 = 100;
    int x2_10 = 1700, y2_10 = 100;
    int i_10 = 0;
    do {
        MoveToEx(hdc, x1_10, y1_10, NULL);
        LineTo(hdc, x2_10, y2_10);
        y1_10 = y1_10 - 4;
        y2_10 = y2_10 + 4;
        i_10++;
    } while (i_10 < 15);
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
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:
            numImage--;
            if (numImage < 1) numImage = 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT:
            numImage++;
            if (numImage > 37) numImage = 37;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_DOWN:
            sizeImage -= 10;
            if (sizeImage < 10) sizeImage = 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP:
            sizeImage += 10;
            if (sizeImage > 200) sizeImage = 200;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_F1:
            numLaba--;
            if (numLaba < 1) numLaba = 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_F2:
            numLaba++;
            if (numLaba > 5) numLaba = 5;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            int x = 0; int y = 0;
            switch (numLaba) {
            case 1:
                switch (numImage) {
                case 1:
                    L1_1(hdc);
                    break;
                case 2:
                    L1_2(hdc);
                    break;
                case 3:
                    L1_3(hdc);
                    break;
                case 4:
                    L1_4(hdc);
                    break;
                case 5:
                    L1_5(hdc);
                    break;
                case 6:
                    L1_6(hdc);
                    break;
                case 7:
                    L1_7(hdc);
                    break;
                case 8:
                    L1_8(hdc);
                    break;
                }
                break;
            case 2:
                switch (numImage) {
                case 1:
                    L2_1(hdc);
                    break;
                case 2:
                    L2_2(hdc);
                    break;
                case 3:
                    L2_3(hdc);
                    break;
                case 4:
                    L2_4(hdc);
                    break;
                case 5:
                    L2_5(hdc);
                    break;
                case 6:
                    L2_6(hdc);
                    break;
                case 7:
                    L2_7(hdc);
                    break;
                case 8:
                    L2_8(hdc);
                    break;
                case 9:
                    L2_9(hdc);
                    break;
                case 10:
                    L2_10(hdc);
                    break;
                }
                break;
            case 3:
                switch (numImage) {
                case 1:
                    StClausAuto(hdc, 0, 0);
                    StClausAuto(hdc, 300, 0);
                    StClausAuto(hdc, 150, 150);
                    StClausAuto(hdc, 0, 300);
                    StClausAuto(hdc, 300, 300);
                    break;
                case 2:
                    x = 300;
                    do {
                        StClausAuto(hdc, x, 0);
                        x += 50;
                    } while (x < 701);
                    break;
                case 3:
                    y = 300;
                    do {
                        StClausAuto(hdc, 0, y);
                        y += 90;
                    } while (y < 700);
                    break;
                case 4:
                    x = 300;
                    y = 300;
                    do {
                        StClausAuto(hdc, x, y);
                        x += 50;
                        y += 90;
                    } while (y < 700);
                    break;
                case 5:
                    x = 800;
                    do {
                        y = 0;
                        do {
                            StClausAuto(hdc, x, y);
                            y += 90;
                        } while (y < 300);
                        x += 50;
                    } while (x < 1200);
                    break;
                case 6:
                    Ellipse(hdc, 20, 0, 40, 20);
                    Ellipse(hdc, 10, 20, 50, 60);
                    Ellipse(hdc, 0, 60, 60, 120);
                    MoveToEx(hdc, 0, 40, NULL);
                    LineTo(hdc, 15, 30);
                    MoveToEx(hdc, 60, 40, NULL);
                    LineTo(hdc, 45, 30);
                    MoveToEx(hdc, 40, 120, NULL);
                    LineTo(hdc, 70, 0);
                    MoveToEx(hdc, 66, 20, NULL);
                    LineTo(hdc, 64, 0);
                    MoveToEx(hdc, 66, 20, NULL);
                    LineTo(hdc, 75, 0);
                    break;
                case 7:
                    StClausTree(hdc, 600, 300);
                    break;
                case 8:
                    StClausTree(hdc, 0, 0);
                    StClausTree(hdc, 300, 0);
                    StClausTree(hdc, 150, 150);
                    StClausTree(hdc, 0, 300);
                    StClausTree(hdc, 300, 300);

                    x = 300;
                    do {
                        StClausTree(hdc, x, 0);
                        x += 80;
                    } while (x < 701);

                    y = 300;
                    do {
                        StClausTree(hdc, 0, y);
                        y += 130;
                    } while (y < 700);

                    x = 300;
                    y = 300;
                    do {
                        StClausTree(hdc, x, y);
                        x += 80;
                        y += 130;
                    } while (y < 700);

                    x = 800;
                    do {
                        y = 0;
                        do {
                            StClausTree(hdc, x, y);
                            y += 130;
                        } while (y < 300);
                        x += 80;
                    } while (x < 1200);
                    break;
                case 9:
                    Logo(hdc, 100, 50);
                    Logo(hdc, 400, 50);
                    Logo(hdc, 250, 200);
                    Logo(hdc, 100, 350);
                    Logo(hdc, 400, 350);
                    break;
                case 10:
                    x = 650;
                    do {
                        Logo(hdc, x, 50);
                        x += 210;
                    } while (x < 1400);
                    break;
                case 11:
                    y = 470;
                    do {
                        Logo(hdc, 100, y);
                        y += 110;
                    } while (y < 700);
                    break;
                case 12:
                    x = 650;
                    y = 470;
                    do {
                        Logo(hdc, x, y);
                        x += 150;
                        y += 110;
                    } while (y < 700);
                    break;
                case 13:
                    x = 1500;
                    do {
                        y = 50;
                        do {
                            Logo(hdc, x, y);
                            y += 110;
                        } while (y < 700);
                        x += 210;
                    } while (x < 2000);
                    break;
                }
                break;
            case 4:
                switch (numImage) {
                case 1:
                    RecursiveImage1_1(hdc, 400, 400, sizeImage);
                    break;
                case 2:
                    RecursiveImage1_2(hdc, 400, 400, sizeImage);
                    break;
                case 3:
                    RecursiveImage1_3(hdc, 400, 400, sizeImage);
                    break;
                case 4:
                    RecursiveImage1_4(hdc, 400, 400, sizeImage);
                    break;
                case 5:
                    RecursiveImage1_5(hdc, 400, 400, sizeImage);
                    break;
                case 6:
                    RecursiveImage1_6(hdc, 400, 400, sizeImage);
                    break;
                case 7:
                    RecursiveImage1_7(hdc, 400, 400, sizeImage);
                    break;
                case 8:
                    RecursiveImage2_1(hdc, 400, 400, sizeImage);
                    break;
                case 9:
                    RecursiveImage2_2(hdc, 400, 400, sizeImage);
                    break;
                case 10:
                    RecursiveImage2_3(hdc, 400, 400, sizeImage);
                    break;
                case 11:
                    RecursiveImage2_4(hdc, 400, 400, sizeImage);
                    break;
                case 12:
                    RecursiveImage2_5(hdc, 400, 400, sizeImage);
                    break;
                case 13:
                    RecursiveImage2_6(hdc, 400, 400, sizeImage);
                    break;
                case 14:
                    RecursiveImage2_7(hdc, 400, 400, sizeImage);
                    break;
                case 15:
                    RecursiveImage3_1(hdc, 400, 400, sizeImage);
                    break;
                case 16:
                    RecursiveImage3_2(hdc, 400, 400, sizeImage);
                    break;
                case 17:
                    RecursiveImage3_3(hdc, 400, 400, sizeImage);
                    break;
                case 18:
                    RecursiveImage3_4(hdc, 400, 400, sizeImage);
                    break;
                case 19:
                    RecursiveImage3_5(hdc, 400, 400, sizeImage);
                    break;
                case 20:
                    RecursiveImage3_6(hdc, 400, 400, sizeImage);
                    break;
                case 21:
                    RecursiveImage3_7(hdc, 400, 400, sizeImage);
                    break;
                case 22:
                    RecursiveImage3_8(hdc, 400, 400, sizeImage);
                    break;
                case 23:
                    RecursiveImage4_1(hdc, 400, 400, sizeImage);
                    break;
                case 24:
                    RecursiveImage4_2(hdc, 400, 400, sizeImage);
                    break;
                case 25:
                    RecursiveImage4_3(hdc, 400, 400, sizeImage);
                    break;
                case 26:
                    RecursiveImage4_4(hdc, 400, 400, sizeImage);
                    break;
                case 27:
                    RecursiveImage4_5(hdc, 400, 400, sizeImage);
                    break;
                case 28:
                    RecursiveImage4_6(hdc, 400, 400, sizeImage);
                    break;
                case 29:
                    RecursiveImage4_7(hdc, 400, 400, sizeImage);
                    break;
                case 30:
                    RecursiveImage5_1(hdc, 400, 400, sizeImage);
                    break;
                case 31:
                    RecursiveImage5_2(hdc, 400, 400, sizeImage);
                    break;
                case 32:
                    RecursiveImage6_1(hdc, 400, 400, sizeImage);
                    break;
                case 33:
                    RecursiveImage6_2(hdc, 400, 400, sizeImage);
                    break;
                case 34:
                    RecursiveImage7_1(hdc, 400, 400, sizeImage);
                    break;
                case 35:
                    RecursiveImage7_2(hdc, 400, 400, sizeImage);
                    break;
                case 36:
                    Image8(hdc, 70, 70, 50);
                    RecursiveImage8_1(hdc, 400, 400, sizeImage);
                    break;
                case 37:
                    Image9(hdc, 70, 70, 50);
                    RecursiveImage9_1(hdc, 300, 300, sizeImage);
                    break;
                }
                break;
            case 5:
                switch (numImage) {
                case 1:
                    CrownWall_1(hdc);
                    break;
                case 2:
                    CrownWall_2(hdc);
                    break;
                case 3:
                    CrownWall_3(hdc);
                    break;
                case 4:
                    CrownWall_4(hdc);
                    break;
                case 5:
                    MyFigureWall_1(hdc);
                    break;
                case 6:
                    MyFigureWall_2(hdc);
                    break;
                case 7:
                    MyFigureWall_3(hdc);
                    break;
                case 8:
                    MyFigureWall_4(hdc);
                    break;
                case 9:
                    MyFigure1Wall_1(hdc);
                    break;
                case 10:
                    MyFigure1Wall_2(hdc);
                    break;
                case 11:
                    MyFigure1Wall_3(hdc);
                    break;
                case 12:
                    MyFigure1Wall_4(hdc);
                    break;
                case 13:
                    MyFigure2Wall_1(hdc);
                    break;
                case 14:
                    MyFigure2Wall_2(hdc);
                    break;
                case 15:
                    MyFigure2Wall_3(hdc);
                    break;
                case 16:
                    MyFigure2Wall_4(hdc);
                    break;
                case 17:
                    MyFigure2Wall_5(hdc);
                    break;
                }
                break;
            }
            break;
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
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
