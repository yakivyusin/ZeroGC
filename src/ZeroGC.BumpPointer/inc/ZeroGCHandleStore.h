#pragma once
#include "debugmacros.h"
#include "gcenv.base.h"
#include "gcinterface.h"

class ZeroGCHandleStore : public IGCHandleStore
{
public:
    // Inherited via IGCHandleStore
    virtual void Uproot() override;
    virtual bool ContainsHandle(OBJECTHANDLE handle) override;
    virtual OBJECTHANDLE CreateHandleOfType(Object * object, HandleType type) override;
    virtual OBJECTHANDLE CreateHandleOfType(Object * object, HandleType type, int heapToAffinitizeTo) override;
    virtual OBJECTHANDLE CreateHandleWithExtraInfo(Object * object, HandleType type, void * pExtraInfo) override;
    virtual OBJECTHANDLE CreateDependentHandle(Object * primary, Object * secondary) override;
};