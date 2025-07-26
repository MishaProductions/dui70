#pragma once

namespace DirectUI
{
    class UILIB_API CClassFactory
    {
    public:
	  DirectUI::IClassInfo* WINAPI Get(_In_ const wchar_t *Name, HINSTANCE hInstance);
    HRESULT WINAPI GetNextClassId(VOID);
    HRESULT WINAPI Initialize(VOID);
    HRESULT WINAPI ModuleRelease(_In_ HINSTANCE hInstance);
    HRESULT WINAPI Register(_Out_ DirectUI::IClassInfo* ClassInfo);
    HRESULT WINAPI Create(_Out_ CClassFactory** Factory);
    IClassInfo* WINAPI GetExact(_In_ bool IsGlobal, _In_ const wchar_t* Name, _In_ HINSTANCE hInstance);
    private:
    //TODO:
    };
}
