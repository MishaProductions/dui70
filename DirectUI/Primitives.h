#pragma once

namespace DirectUI
{
	
	struct Fill
	{

	};

	struct Cursor
	{

	};

	struct Graphic
	{

	};


	struct EnumMap
	{
		const wchar_t** name;
		int value;
	};

	struct PropCapability {
		ValueType type : 6;
		UINT other : 26;
		UINT unk;
	};

	struct PropertyInfo
	{
		const wchar_t* name;
		int unk1;
		int unk2;

		PropCapability* cap;
		
		struct { const wchar_t* str_value; int int_value; } *enum_value_map;

		Value *(*get_default_value)();
		Value* m_value;
	};

	struct DepRecs
	{

	};

	struct Cond
	{
		int unk1;
		int unk2;
		int unk3;
		int unk4;
	};

	struct Decl
	{
		PropertyInfo base;
	};

	struct UILIB_API NavReference
	{
	public:
		NavReference() = delete;
		NavReference(const NavReference&) = delete;
		~NavReference() = delete;

		void Init(Element *, RECT *);
		NavReference& operator=(NavReference const &);
	};
}