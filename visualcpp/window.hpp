/**
 * @file window.hpp
 * @brief Window class
 * @ingroup VisualCpp
 * @date 2021-08-06
 * @author Rishikesh Kumar
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <windows.h>

class Window
{
private:
  HINSTANCE hInstance;
  HWND hWnd;

public:
  Window() : hInstance(nullptr)
  {
    const wchar_t *CLASS_NAME = L"Sample Window Class";

    WNDCLASS wc = {};
    wc.lpszClassName = CLASS_NAME;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.lpfnWndProc = nullptr;

    RegisterClass(&wc);
  }
  ~Window() {}
  Window(const Window &) = delete;
  Window &operator=(const Window &) = delete;

  bool processMessages()
  {
    return false;
  }
};

#endif // WINDOW_HPP