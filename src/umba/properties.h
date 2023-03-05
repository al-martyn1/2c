#pragma once


#define UMBA_CONTAINING_RECORD(address, type, field) ((type *)( \
                                                  1+(char*)(address) - \
                                                  (uintptr_t)(&((type *)1)->field)))


    #define UMBA_DECLARE_PROPERTY_RW(OWNERNAME, TYPE, NAME)                   \
    struct propclass_##NAME {                                                \
        typedef TYPE property_type;                                          \
        DWORD dummy;                                                         \
        /*propclass_##NAME() : dummy() {}*/                                  \
        inline operator property_type() {                                    \
            return CLI_CONTAINING_RECORD(this, OWNERNAME, NAME)-> getProp_##NAME ();    \
        }                                                                    \
        inline void operator=(const property_type &src) {                    \
            CLI_CONTAINING_RECORD(this, OWNERNAME, NAME)-> setProp_##NAME (src); \
        }                                                                    \
        /*private:*/                                                             \
        /*explicit propclass_##NAME(const propclass_##NAME &src) {} */            \
        /*inline void operator=(const propclass_##NAME &src) {}     */           \
                                                                             \
    } NAME
    
    #define UMBA_DECLARE_PROPERTY_R(OWNERNAME, TYPE, NAME)                    \
    struct propclass_##NAME {                                                \
        typedef TYPE property_type;                                          \
        DWORD dummy;                                                         \
        inline operator property_type() {                                    \
            return CLI_CONTAINING_RECORD(this, OWNERNAME, NAME)-> getProp_##NAME ();    \
        }                                                                    \
    } NAME
    
    #define UMBA_DECLARE_PROPERTY_W(OWNERNAME, TYPE, NAME)                    \
    struct propclass_##NAME {                                                \
        typedef TYPE property_type;                                          \
        DWORD dummy;                                                         \
        inline void operator=(const property_type &src) {                    \
            CLI_CONTAINING_RECORD(this, OWNERNAME, NAME)-> set_Prop##NAME (src); \
        }                                                                    \
        private:                                                             \
        inline void operator=(const propclass_##NAME &src) {}                \
    } NAME



