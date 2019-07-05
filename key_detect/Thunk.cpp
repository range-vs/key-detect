#include "Thunk.h"

ThunkCreator::ThunkCreator(const ThunkCreator& tc)
{
	callbackMethod = reinterpret_cast<Thunk*>(VirtualAlloc(NULL, sizeof(Thunk), MEM_COMMIT, PAGE_EXECUTE_READWRITE));
	callbackMethod->stub1 = tc.callbackMethod->stub1;
	callbackMethod->nThisPtr = tc.callbackMethod->nThisPtr;
	callbackMethod->stub2 = tc.callbackMethod->stub2;
	callbackMethod->nJumpProc = tc.callbackMethod->nJumpProc;
	callbackMethod->stub3 = tc.callbackMethod->stub3;
}

ThunkCreator& ThunkCreator::operator=(const ThunkCreator& tc)
{
	if (this != &tc)
	{
		callbackMethod = reinterpret_cast<Thunk*>(VirtualAlloc(NULL, sizeof(Thunk), MEM_COMMIT, PAGE_EXECUTE_READWRITE));
		callbackMethod->stub1 = tc.callbackMethod->stub1;
		callbackMethod->nThisPtr = tc.callbackMethod->nThisPtr;
		callbackMethod->stub2 = tc.callbackMethod->stub2;
		callbackMethod->nJumpProc = tc.callbackMethod->nJumpProc;
		callbackMethod->stub3 = tc.callbackMethod->stub3;
	}
	return *this;
}

Thunk* ThunkCreator::getCallbackMethod()
{
	return callbackMethod;
}

ThunkCreator::~ThunkCreator()
{
	VirtualFree(callbackMethod, sizeof(Thunk), MEM_DECOMMIT);
}