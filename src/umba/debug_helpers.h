#pragma once


#include "umba.h"
#include "assert.h"

#if defined(UMBA_WIN32_USED)
    #include "windows.h"
#endif


namespace umba
{


#if defined(UMBA_WIN32_USED)

    inline
    bool isDebuggerPresent()
    {
        return IsDebuggerPresent() ? true : false;
    }


#elif defined(UMBA_MCU_USED) && ( defined(STM32F1_SERIES) || defined(STM32F3_SERIES) || defined(STM32F4_SERIES) )

    inline
    bool isDebuggerPresent()
    {
        // http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.faqs/ka14536.html
        // http://www.onarm.com/forum/62218/
        // https://community.st.com/s/question/0D50X00009XkbSDSAZ/detect-debugger-connected-to-stm32l0-
        // https://www.google.com/search?q=stm32+detect+debugging&rlz=1C1GCEU_ruRU819RU819&oq=stm32+how+to+detect+debug&aqs=chrome.1.69i57j0l2.11847j0j7&sourceid=chrome&ie=UTF-8

        #if defined(CoreDebug)
        return CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk ? true : false;
        #else
        return false;
        #endif
    }

#else

    inline
    bool isDebuggerPresent()
    {
        return false; // Can't detect debugger
    }

#endif


} // namespace umba


#define UMBA_DEBUG_SESSION_ASSERT( expr )    if (isDebuggerPresent()) UMBA_ASSERT( expr )

#define UMBA_DEBUG_SESSION_ASSERT_FAIL()    if (isDebuggerPresent()) UMBA_ASSERT_FAIL( )




