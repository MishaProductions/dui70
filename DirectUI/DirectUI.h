#pragma once

#include <windows.h>
#include <oleacc.h>
#include <objbase.h>
#include <initguid.h>
#include <oleacc.h>
#include <commctrl.h>
#include <uiautomationcore.h>
#include <uiautomationcoreapi.h>
#include <dbghelp.h>
#include <xmllite.h>

#if	defined(DIRECTUI_EXPORTS)
#define UILIB_API __declspec(dllexport)
#else
#define UILIB_API __declspec(dllimport)
#endif
#define DUI_VERSION_WIN10_2022 14
#define DUI_VERSION_WIN7 8

#include "types.h"
#include "misc.h"
#include "Interfaces.h"

#include "AutoLock.h"
#include "AutoThread.h"
#include "AutoVariant.h"
#include "Value.h"

#include "Primitives.h"
#include "parser.h"
#include "Element.h"
#include "Browser.h"
#include "Bind.h"
#include "AnimationStrip.h"
#include "Button.h"
#include "base.h"
#include "AccessibleButton.h"
#include "AutoButton.h"
#include "PushButton.h"
#include "event.h"
#include "layout.h"
#include "BorderLayout.h"
#include "host.h"
#include "accessibility.h"
#include "provider.h"
#include "Movie.h"
#include "ElementWithHWND.h"
#include "HWNDElement.h"
#include "DialogElement.h"
#include "NativeHWNDHost.h"
#include "HWNDHost.h"
#include "CBase.h"
#include "CAVI.h"
#include "CPushButton.h"
#include "CBaseCheckRadioButton.h"
#include "CBaseScrollBar.h"
#include "CHScrollBar.h"
#include "CCheckBox.h"
#include "CCommandLink.h"
#include "CListBox.h"
#include "CListView.h"
#include "CProgressBar.h"
#include "CRadioButton.h"
#include "CCSysLink.h"
#include "CTrackBar.h"
#include "CTreeView.h"
#include "CVScrollBar.h"
#include "CallstackTracker.h"
#include "CheckBoxGlyph.h"
#include "Expandable.h"
#include "Clipper.h"
#include "Combobox.h"
#include "DuiNavigate.h"
#include "Edit.h"
#include "Element.h"
#include "EventManager.h"
#include "ExpandCollapse.h"
#include "Expando.h"
#include "ExpandoButtonGlyph.h"
#include "FontCache.h"
#include "FontCheckOut.h"
#include "GridItem.h"
#include "Grid.h"
#include "HWNDElement.h"
#include "InvokeHelper.h"
#include "LinkedList.h"
#include "Macro.h"
#include "NavScoring.h"
#include "Navigator.h"
#include "TextGraphic.h"
#include "PText.h"
#include "Page.h"
#include "Progress.h"
#include "RadioButtonGlyph.h"
#include "RangeValue.h"
#include "RefPointElement.h"
#include "RepeatButton.h"
#include "Repeater.h"
#include "ScrollBar.h"
#include "ScrollItem.h"
#include "Scroll.h"
#include "ScrollViewer.h"
#include "SelectionItem.h"
#include "Selection.h"
#include "Selector.h"
#include "SelectorNoDefault.h"
#include "SelectorSelectionItem.h"
#include "SelectorSelection.h"
#include "StyledScrollViewer.h"
#include "TableItem.h"
#include "Table.h"
#include "TaskPage.h"
#include "Thumb.h"
#include "Toggle.h"
#include "UnknownElement.h"
#include "Viewer.h"
#include "XBaby.h"
#include "XElement.h"
#include "XProvider.h"
#include "BrowserSelection.h"

#include "RichText.h"
#include "TouchButton.h"
#include "TouchCheckBox.h"

#include "DUIStandardCreator.h"

#include "CClassFactory.h"

using namespace DirectUI;

// tells DirectUI that this ClassInfoBase is present accross all threads
#define DUI_GLOBAL_CLASS (HINSTANCE)-1

EXTERN_C
UILIB_API HRESULT WINAPI InitProcessPriv(UINT32 duiVersion, HINSTANCE hModule, BOOLEAN WillRegisterControls, bool bEnableUIAutomationProvider);
EXTERN_C
UILIB_API HRESULT WINAPI UnInitProcessPriv(unsigned short*unk1);
EXTERN_C
UILIB_API HRESULT WINAPI InitThread(int iDontKnow);
EXTERN_C
UILIB_API void WINAPI UnInitThread();
EXTERN_C
UILIB_API int WINAPI CreateDUIWrapper(DirectUI::Element*,class XProvider**);
EXTERN_C
UILIB_API int WINAPI CreateDUIWrapperEx(DirectUI::Element*, class IXProviderCP*, class XProvider**);
EXTERN_C
UILIB_API int WINAPI CreateDUIWrapperFromResource(HINSTANCE,const wchar_t*, const wchar_t*, const wchar_t*, class XResourceProvider**);
EXTERN_C
UILIB_API int WINAPI GetScreenDPI();
EXTERN_C
UILIB_API HRESULT WINAPI RegisterAllControls();
EXTERN_C
UILIB_API HRESULT WINAPI RegisterBaseControls();
EXTERN_C
UILIB_API HRESULT WINAPI RegisterBrowserControls();
EXTERN_C
UILIB_API HRESULT WINAPI RegisterCommonControls();
EXTERN_C
UILIB_API HRESULT WINAPI RegisterExtendedControls();
EXTERN_C
UILIB_API HRESULT WINAPI RegisterMacroControls();
EXTERN_C
UILIB_API HRESULT WINAPI RegisterMiscControls();
EXTERN_C
UILIB_API HRESULT WINAPI RegisterStandardControls();
EXTERN_C
UILIB_API HRESULT WINAPI RegisterXControls();
EXTERN_C
UILIB_API BOOLEAN WINAPI StartMessagePump();
EXTERN_C
UILIB_API VOID WINAPI StopMessagePump();

extern UILIB_API unsigned long g_dwElSlot;
extern DirectUI::CClassFactory* GlobalCClassFactory;

EXTERN_C ATOM WINAPI StrToID(const wchar_t* resId);
EXTERN_C HRESULT WINAPI InternalInitProcessPriv(UINT32 duiVersion, HINSTANCE hModule, BOOLEAN WillRegisterControls, bool bEnableUIAutomationProvider);
EXTERN_C int WINAPI UnicodeToMultiByte(const wchar_t* lpWideCharStr, int cchWideChar, int unk);
EXTERN_C int WINAPI MultiByteToUnicode(LPCSTR lpMultiByteStr, int cbMultiByte, int unk);

EXTERN_C BOOL WINAPI IsAnimationsEnabled();
EXTERN_C int WINAPI IsPalette(HWND hWnd);
EXTERN_C BOOL WINAPI IsUIAutomationProviderEnabled();
EXTERN_C int WINAPI DUIDrawShadowText(HDC hdcDest, const wchar_t* lpchText, int cchText, LPRECT hdcSrc, UINT format, COLORREF dwTextColor);
EXTERN_C int WINAPI BlurBitmap(void*, void*, void*, void*, void*);
EXTERN_C HBRUSH WINAPI BrushFromEnumI(_In_ int Index);
EXTERN_C DWORD WINAPI ColorFromEnumI(_In_ int Index);
EXTERN_C LPVOID WINAPI DisableAnimations();
EXTERN_C int WINAPI DrawShadowTextEx(HDC hdc, const WCHAR* lpchText, int cchText, LPRECT hdcSrc, UINT format, COLORREF dwTextColor, COLORREF dwBkColor, int a9, int a10, COLORREF a11, int a12);
EXTERN_C void* WINAPI ElementFromGadget(void*);
EXTERN_C LPVOID WINAPI EnableAnimations();
EXTERN_C void WINAPI FlushThemeHandles(unsigned int);
EXTERN_C void WINAPI ForceDebugBreak();
EXTERN_C DWORD WINAPI GetElementDataEntry(int a1);
EXTERN_C Macro* WINAPI GetElementMacro(int a1);
EXTERN_C LPVOID WINAPI GetFontCache();
EXTERN_C HRESULT WINAPI GetThemeHandle(LPCWSTR, void**);
EXTERN_C HRESULT WINAPI HrSysAllocString(OLECHAR* psz, BSTR* ppStr);
EXTERN_C HRESULT WINAPI HStrDup(LPCWSTR lpString, LPCWSTR* ppStr);
EXTERN_C BOOL WINAPI InitPreprocessor();
EXTERN_C HRESULT WINAPI SetDefAction(Element* a1, _In_  DWORD dwRole);
EXTERN_C BOOL WINAPI UiaHideOnGetObject(_In_ HWND hWnd, int a2, int a3);
EXTERN_C HANDLE WINAPI UiaOnDestroySink(_In_ HWND hWnd);
EXTERN_C HRESULT WINAPI UiaOnGetObject(void** a1, int a2, InvokeHelper* a3, int a4, int a5);
EXTERN_C BOOL WINAPI UiaOnToolTip(Element*, DWORD);
EXTERN_C void WINAPI NotifyAccessibilityEvent(DWORD event, Element*);
EXTERN_C void* WINAPI PreprocessBuffer(LPCWSTR Src, SIZE_T cSrc, BOOLEAN a3);
EXTERN_C HGDIOBJ WINAPI ProcessAlphaBitmapI(HBITMAP hgdiobj);
EXTERN_C void WINAPI PurgeThemeHandles();

namespace DirectUI
{
	void MapRect(Element* elem, RECT* rect1, RECT* rect);
}