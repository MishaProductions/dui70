#pragma once
namespace DirectUI
{
    class StyleSheetImpl : public StyleSheet
    {
    public:
		virtual void Destroy();
		virtual HRESULT AddRule(const wchar_t**, IClassInfo*, Cond**, Decl**);
		virtual void MakeImmutable();
		virtual Value* GetSheetValue(Element*, PropertyInfo const*, DepRecs*, DeferCycle*, long*);
		virtual void GetSheetDependencies(Element*, PropertyInfo const*, DepRecs*, DeferCycle*, long*);
		virtual void GetSheetScope(Element*, DepRecs*, DeferCycle*, long*);
		virtual const wchar_t* GetSheetResid();
		virtual HRESULT SetSheetResid(const wchar_t* NewName);

        HRESULT Initialize();

	private:
		const wchar_t* m_resid;
		BOOL m_immutable;
    };
}