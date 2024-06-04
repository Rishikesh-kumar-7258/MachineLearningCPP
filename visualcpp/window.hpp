/**
 * @file window.hpp
 * @brief Window class
 * @ingroup VisualCpp
 * @date 2021-08-06
 * @author Rishikesh Kumar
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <tchar.h>
#include <windows.h>

namespace visualcpp
{

    LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg)
        {
        case WM_CLOSE:
            DestroyWindow(hWnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        }

        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    class Window
    {
    private:
        HINSTANCE hInstance;
        HWND hWnd;

    public:
        Window(int width = 640, int height = 480, std::string name = "Sample Window") : hInstance(GetModuleHandle(nullptr))
        {
            auto *CLASS_NAME = _T("Sample Window Class");

            WNDCLASS wc = {};
            wc.lpszClassName = CLASS_NAME;
            wc.hInstance = hInstance;
            wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
            wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
            wc.lpfnWndProc = WindowProc;

            RegisterClass(&wc);

            DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

            RECT rect;
            rect.left = 250;
            rect.top = 250;
            rect.right = rect.left + width;
            rect.bottom = rect.top + height;

            AdjustWindowRect(&rect, style, FALSE);

            hWnd = CreateWindowEx(
                0,
                CLASS_NAME,
                _T(name.c_str()),
                style,
                rect.left,
                rect.top,
                rect.right - rect.left,
                rect.bottom - rect.top,
                nullptr,
                nullptr,
                hInstance,
                nullptr);

            ShowWindow(hWnd, SW_SHOWDEFAULT);
        }
        ~Window()
        {
            auto *CLASS_NAME = _T("Sample Window Class");
            UnregisterClass(CLASS_NAME, hInstance);
        }
        Window(const Window &) = delete;
        Window &operator=(const Window &) = delete;

        bool processMessages()
        {
            MSG msg = {};

            while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
            {
                if (msg.message == WM_QUIT)
                    return false;

                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }

            return true;
        }
    };
} // visual cpp

#endif // WINDOW_HPP