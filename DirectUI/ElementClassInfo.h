namespace DirectUI
{
	class ElementClassInfo : public IClassInfo
	{
	public:
		static HRESULT Register(const PropertyInfo** info, unsigned int propertyCount);

		virtual void AddRef(void);
		virtual int Release(void);
		virtual HRESULT CreateInstance(Element*, ULONG*, Element**);
		virtual const PropertyInfo* EnumPropertyInfo(UINT);
		virtual const PropertyInfo* GetByClassIndex(UINT);
		virtual unsigned int GetPICount(void) const { return m_propertyCount; };
		virtual unsigned int GetGlobalIndex(void) const { return 0; };
		virtual IClassInfo* GetBaseClass(void);
		virtual const wchar_t* GetName() const { return L"Element"; };
		virtual bool IsValidProperty(PropertyInfo const* property) { return this == property->m_value->m_classInfo; };
		virtual bool IsSubclassOf(IClassInfo* classInfo) const { return this == classInfo; };
		virtual void Destroy(void);
		virtual HINSTANCE GetModule(void) const { return DUI_GLOBAL_CLASS; };
		virtual bool IsGlobal(void) const { return TRUE; };
		virtual void AddChild(void);
		virtual void RemoveChild(void);
		virtual int GetChildren(void) const { return m_childrenCount;  };
		virtual void AssertPIZeroRef(void) const {};

	private:
		static HRESULT Create(const PropertyInfo** info, unsigned int propertyCount, IClassInfo** result);

		const PropertyInfo** m_propertyInfo;
		unsigned int m_propertyCount;
		DWORD m_refCount;
		DWORD m_childrenCount;
	};
}