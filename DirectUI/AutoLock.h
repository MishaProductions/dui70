#pragma once

namespace DirectUI
{
	class UILIB_API AutoLock
	{
	public:
		AutoLock(LPCRITICAL_SECTION criticalSection);
		AutoLock& operator=(const AutoLock& );
		~AutoLock();
	private:
		CRITICAL_SECTION* m_critcalSection;
	};
}