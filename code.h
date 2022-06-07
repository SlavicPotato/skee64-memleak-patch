#pragma once

class NIOVTaskDeferredMask;

extern "C" {
	std::uintptr_t skee_operator_delete{ 0 };
	void NIOVTaskDeferredMask_Dispose(NIOVTaskDeferredMask* a_this);
}