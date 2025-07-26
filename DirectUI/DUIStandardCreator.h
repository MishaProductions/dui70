#pragma once
// DirectUI class creation helper

namespace DirectUI {
	template<typename Name>
	class StandardCreator {
	public:
		inline static HRESULT CreateInstance(Element* rootElement, unsigned long* unknown, Element** result)
		{
			return Name::Create(rootElement, unknown, result);
		}
	};

	template<typename Name>
	class EmptyCreator {
	public:
		inline static HRESULT CreateInstance(Element* rootElement, unsigned long* unknown, Element** result)
		{
			return E_NOTIMPL;
		}

	};
	template<typename NewClass, typename BaseClass, typename Creator>
	class ClassInfo : public ClassInfoBase
	{
	public:

		HRESULT CreateInstance(Element* rootElement, unsigned long* unknown, Element** result) override
		{
			return Creator::CreateInstance(rootElement, unknown, result);
		}

		IClassInfo* GetBaseClass() override
		{
			return BaseClass::GetClassInfoPtr();
		}
		HRESULT DoRegister() { return ClassInfoBase::Register(); }

		void Destroy() override
		{
			delete this;
			NewClass::SetClassInfoPtr(NULL);
		}

		static HRESULT Create(HINSTANCE instance, const wchar_t* name, unsigned int propertyCount, bool isGlobal, const DirectUI::PropertyInfo** prop, ClassInfo** result)
		{
			ClassInfo* theClass = new ClassInfo();

			HRESULT hr = theClass->Initialize(instance, name, isGlobal, prop, propertyCount);
			if (SUCCEEDED(hr))
			{
				*result = theClass;
			}
			return hr;
		}
		static HRESULT Register(HINSTANCE instance, const wchar_t* name, const DirectUI::PropertyInfo** properties, unsigned int propertiesCount, bool isGlobal)
		{
			HRESULT hr = S_OK;
			
			// register base class
			if (BaseClass::GetClassInfoPtr() == NULL)
			{
				hr = BaseClass::Register();
			}
			else
			{
				BaseClass::GetClassInfoPtr()->AddRef();
			}

			if (SUCCEEDED(hr))
			{
				CritSecLock lock(Element::GetFactoryLock());

				IClassInfo* baseClassInfo = BaseClass::GetClassInfoPtr();
				IClassInfo* newClassInfo = NewClass::GetClassInfoPtr();

				// ensure that the class does not exist
				if (DirectUI::ClassInfoBase::ClassExist(&baseClassInfo, properties, propertiesCount, newClassInfo, instance, name, isGlobal))
				{
					NewClass::SetClassInfoPtr(baseClassInfo);
				}
				else
				{
					ClassInfo* classInfo = NULL;
					if (SUCCEEDED(hr = Create(instance, name, propertiesCount, isGlobal, properties, &classInfo)))
					{
						if (SUCCEEDED(hr = classInfo->DoRegister()))
						{
							NewClass::SetClassInfoPtr((IClassInfo*)classInfo);
						}
						else
						{
							classInfo->Destroy();
						}
					}
				}
			}
			return hr;
		}
	};
}