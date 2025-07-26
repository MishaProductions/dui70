#pragma once

namespace DirectUI
{

	class UILIB_API NativeHWNDHost
	{
	public:
		NativeHWNDHost(const NativeHWNDHost&);
		NativeHWNDHost();
		virtual ~NativeHWNDHost();

		static LRESULT WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);
		NativeHWNDHost& operator=(const NativeHWNDHost&);
		static UINT WINAPI AsyncDestroyMsg();

		static HRESULT WINAPI Create(const wchar_t* lpClassName, const wchar_t* lpWindowName, HWND hWndParent, HICON hIcon, int x, int y, int nWidth, int nHeight, int dwExStyle, int dwStyle, HINSTANCE, UINT, NativeHWNDHost**out);
		static HRESULT WINAPI Create(const wchar_t* lpWindowName, HWND hWndParent, HICON hIcon, int x, int y, int nWidth, int nHeight, int dwExStyle, int dwStyle, unsigned int, NativeHWNDHost**out);

		void Destroy();
		void DestroyWindow();

		class Element* GetElement();
		HWND GetHWND();

		void HideWindow();
		void Host(class Element*);

		HRESULT Initialize(const wchar_t* lpClassName, const wchar_t* lpWindowName, HWND hWndParent, HICON hIcon, int x, int y, int nWidth, int nHeight, int dwExStyle, int dwStyle, HINSTANCE, UINT);
		HRESULT Initialize(const wchar_t*, HWND, HICON, int, int, int, int, int, int, UINT);

		virtual HRESULT OnMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT*);

		int RestoreFocus();
		void SaveFocus();
		void SetDefaultFocusID(const wchar_t*);
		void ShowWindow(int);

	private:
		HWND m_hWnd;
		Element* m_rootElement;
		UINT m_windowOptions;
		HWND m_hWndFocus;
	};
}