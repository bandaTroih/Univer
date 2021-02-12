// Univer.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Univer.h"
#include "DBmanager.h"


//#include <sqlite3.h>

#define MAX_LOADSTRING 100
#define IDC_BUTTON0 5000



HWND hButton0;
HWND hStatic0;

HWND hButton1;
HWND hButton2;
HWND hButton3;
HWND hButton4;

HWND hCombo1, hList1, hList2;
HWND hEdit1, hEdit2, hEdit3, hEdit4, hEdit5;


std::vector<Faculty> faculties;
std::vector<Group> groups;


// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна


// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    MainDlg(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_UNIVER, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_UNIVER));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_STUDY));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;//MAKEINTRESOURCEW(IDC_UNIVER);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_STUDY));

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

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_SYSMENU | WS_MINIMIZEBOX,
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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        {
            SetWindowText(hWnd, L"Университет");
            MoveWindow(hWnd, 480, 200, 400, 300, true);
            hStatic0 = CreateWindowEx(0, L"STATIC", L"Система управления персональными данными студентов", WS_CHILD | WS_VISIBLE | SS_CENTER, 40, 60, 300, 50, hWnd, NULL, hInst, NULL);
            hButton0 = CreateWindowEx(0, L"BUTTON", L"Открыть приложение", WS_CHILD | WS_VISIBLE , 65, 120, 250, 30, hWnd, (HMENU)IDC_BUTTON0, hInst, NULL);
        }
       
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDC_BUTTON0:
                {
                    DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, MainDlg);
                }
                break;
            case IDM_ABOUT:
                {
                    DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                }
                break;
            case IDM_EXIT:
                {
                    DestroyWindow(hWnd);
                }
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

//
int callback1(void* err, int argc, char** argv, char** colName)
{
    int id = 0;
    for (size_t i = 0; i < argc; i++)
    {
        if (i % 2 == 0)
            id = atoi(argv[i]);
        else 
        {
            Faculty faculty(id, argv[i]);
            faculties.push_back(faculty);

            size_t size1 = strlen(argv[i]) + 1;
            TCHAR* buff = new TCHAR[size1];
            size_t size2;

            mbstowcs_s(&size2, buff, size1, argv[i], _TRUNCATE);
            ::SendMessage(hCombo1, CB_ADDSTRING, 0, LPARAM(buff));
            delete[] buff;
        }
    }
    ::SendMessage(hCombo1, CB_SETCURSEL, 0, 0);

    return 0;
}

int callback2(void* err, int argc, char** argv, char** colName)
{
    int id = 0;
    int fid = 0;

    for (size_t i = 0; i < argc; i++)
    {
        if (i % 3 == 0)
        {
            id = atoi(argv[i]);
        }
        else if (i % 3 == 1)
        {
            fid = atoi(argv[i]);
        }
        else {
            Group group(id, fid, argv[i]);
            groups.push_back(group);

            size_t size1 = strlen(argv[i]) + 1;
            TCHAR* buff = new TCHAR[size1];
            size_t size2;

            mbstowcs_s(&size2, buff, size1, argv[i], _TRUNCATE);
            ::SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(buff));
            delete[] buff;
        }
    }

    return 0;
}

//
INT_PTR CALLBACK MainDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    TCHAR buff[100];

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        {
            hCombo1 = GetDlgItem(hDlg, IDC_COMBO1);
            hList1 = GetDlgItem(hDlg, IDC_LIST1);
            hList2 = GetDlgItem(hDlg, IDC_LIST2);

            hEdit1 = GetDlgItem(hDlg, IDC_EDIT1);
            hEdit2 = GetDlgItem(hDlg, IDC_EDIT2);
            hEdit3 = GetDlgItem(hDlg, IDC_EDIT3);
            hEdit4 = GetDlgItem(hDlg, IDC_EDIT4);
            hEdit5 = GetDlgItem(hDlg, IDC_EDIT5);

            hButton1 = GetDlgItem(hDlg, IDC_BUTTON1);
            hButton2 = GetDlgItem(hDlg, IDC_BUTTON2);
            hButton3 = GetDlgItem(hDlg, IDC_BUTTON3);
            hButton4 = GetDlgItem(hDlg, IDC_BUTTON4);

            // !
            /*SendMessage(hCombo1, CB_ADDSTRING, 0, LPARAM(L"Пункт списка - 1"));
            SendMessage(hCombo1, CB_ADDSTRING, 0, LPARAM(L"Пункт списка - 2"));
            SendMessage(hCombo1, CB_ADDSTRING, 0, LPARAM(L"Пункт списка - 3"));

            SendMessage(hCombo1, CB_SETCURSEL, 2, 0);*/
            faculties = DBmanager::Get()->get_faculties();
            for(Faculty f : faculties)
                SendMessage(hCombo1, CB_ADDSTRING, 0, LPARAM(f.LgetName()));

            //sqlite3_open("univer.db", &db);
            //sqlite3_exec(db, "select * from faculties", callback1, NULL, NULL);
            //(db);
            

        }
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDC_BUTTON1)
        {
            /*
                MessageBox(hDlg, L"Создание базы данных SQLite", L"Сообщение", MB_OK);
                ::sqlite3_open("univer.db", &db);
                ::sqlite3_close(db);
            */
            MessageBox(hDlg, L"Базы данных успешно создана", L"Сообщение", MB_OK);
        }
        else if (LOWORD(wParam) == IDC_COMBO1 && HIWORD(wParam) == CBN_SELCHANGE)
        {
            int selIndex = SendMessage(hCombo1, CB_GETCURSEL, 0, 0);
            int fid = faculties[selIndex].getId();

            groups.clear();
            SendMessage(hList1, LB_RESETCONTENT, 0, 0);
            groups = DBmanager::Get()->get_groups(fid);
            for (Group g : groups)
                SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(g.LgetName()));
        }
        else if (LOWORD(wParam) == IDC_LIST1 && HIWORD(wParam) == CBN_SELCHANGE)
        {
            //int selIndex = SendMessage(hList1, LB_GETCURSEL, 0, 0);
            //int gid = groups[selIndex].getId();

            //groups.clear();
            //SendMessage(hList1, LB_RESETCONTENT, 0, 0);
            //groups = DBmanager::Get()->get_groups(gid);0
            //for (Group g : groups)
                //SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(g.LgetName()));
        }

        /*if (LOWORD(wParam) == IDC_COMBO1 || LOWORD(wParam) == CBN_SELCHANGE)
        {
           
        }*/
        return (INT_PTR)TRUE;
    case WM_CLOSE:
        EndDialog(hDlg, LOWORD(wParam));
        return (INT_PTR)TRUE;
    }

    return (INT_PTR)FALSE;
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
