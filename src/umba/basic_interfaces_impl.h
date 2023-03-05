/*! \file
\brief Реализация некоторых базовых интерфейсов
*/

#pragma once

#include "basic_interfaces.h"

#include <utility>


namespace umba
{


//-----------------------------------------------------------------------------
struct PingRequestGeneratorImplBase : implements IPingRequestGenerator
{

    //! Задает период пингов
    virtual
    umba::time_service::TimeTick setPingPeriod( umba::time_service::TimeTick t ) override
    {
        std::swap( m_pingPeriod, t );
        return t;
    }

    //! Возвращает период пингов
    virtual
    umba::time_service::TimeTick getPingPeriod( ) override
    {
        return m_pingPeriod;
    }


protected:

    umba::time_service::TimeTick  m_pingPeriod = 0;
};

//-----------------------------------------------------------------------------




//-----------------------------------------------------------------------------
struct SimplePollCapableImplBase : public IPollCapable
{
    UMBA_BEGIN_INTERFACE_MAP( )
         UMBA_IMPLEMENT_INTERFACE( IPollCapable )
    UMBA_END_INTERFACE_MAP()

}; // struct SimpleIdleCapableImplBase

template< typename THandler >
struct SimplePollCapable : public SimplePollCapableImplBase
{
    SimplePollCapable( const THandler &h ) : m_handler(h) {}

    virtual
    void poll() override
    {
        m_handler();
    }

    virtual
    bool isReadyForPoll() override
    {
         //#if defined(UMBA_RTKOS_OS)
         //return UMBA_RTKOS_OS->isStarted();
         //#else
         return true;
         //#endif
    }

protected:

    THandler m_handler;

}; // struct SimpleIPollCapable

template< typename THandler >
inline
SimplePollCapable<THandler> makeSimplePollCapable( const THandler &handler )
{
    return SimplePollCapable<THandler>(handler);
}

//-----------------------------------------------------------------------------





//-----------------------------------------------------------------------------
struct SimpleIdleCapableImplBase : public IIdleCapable
{
    UMBA_BEGIN_INTERFACE_MAP( )
         UMBA_IMPLEMENT_INTERFACE( IIdleCapable )
    UMBA_END_INTERFACE_MAP()

}; // struct SimpleIdleCapableImplBase

template< typename THandler >
struct SimpleIdleCapable : public SimpleIdleCapableImplBase
{
    SimpleIdleCapable( const THandler &h ) : m_handler(h) {}

    virtual
    bool onIdle() override
    {
        return m_handler();
    }

protected:

    THandler m_handler;

}; // struct SimpleIdleCapable

template< typename THandler >
inline
SimpleIdleCapable<THandler> makeSimpleIdleCapable( const THandler &handler )
{
    return SimpleIdleCapable<THandler>(handler);
}

//-----------------------------------------------------------------------------





//-----------------------------------------------------------------------------
struct SimpleTimerHandlerImplBase : public ITimerHandler
{
    UMBA_BEGIN_INTERFACE_MAP( )
         UMBA_IMPLEMENT_INTERFACE( ITimerHandler )
    UMBA_END_INTERFACE_MAP()

}; // struct SimpleTimerHandlerImplBase

template< typename THandler >
struct SimpleTimerHandler : public SimpleTimerHandlerImplBase
{
    SimpleTimerHandler( const THandler &h ) : m_handler(h) {}

    virtual
    void onTimer( unsigned eventId ) override
    {
        m_handler( this, eventId );
    }

protected:

    THandler m_handler;

}; // struct SimpleTimerHandlerImplBase

template< typename THandler >
inline
SimpleTimerHandler<THandler> makeSimpleTimerHandler( const THandler &handler )
{
    return SimpleTimerHandler<THandler>(handler);
}



/*
interface ITimerHandler : inherits umba::IUnknown
{

    UMBA_DECLARE_INTERFACE_ID(0xF10B5BD3);

    virtual
    void onTimer( unsigned timerId ) = 0;

}; // interface ITimerHandler
*/



} // namespace umba

