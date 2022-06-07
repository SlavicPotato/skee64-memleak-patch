.data
extern skee_operator_delete : qword

.code

NIOVTaskDeferredMask_Dispose proc

test rcx, rcx
je exit
mov qword ptr[rsp+8h], rbx
mov qword ptr[rsp+10h], rsi
push rdi
sub rsp, 20h
mov rdi, rcx
mov rbx, qword ptr[rcx+28h] ; std::shared_ptr<ItemAttributeData>
mov esi, 0FFFFFFFFh
test rbx, rbx
je try_release_niptr

; try release std::shared_ptr<ItemAttributeData>
mov eax, esi
lock xadd dword ptr [rbx+8h], eax
cmp eax, 1h
jne try_release_niptr
mov rax, qword ptr[rbx]
mov rcx, rbx
call qword ptr[rax]
mov eax, esi
lock xadd dword ptr [rbx+0Ch], eax
cmp eax, 1h
jne try_release_niptr
mov rax, qword ptr[rbx]
mov rcx, rbx
call qword ptr[rax + 8h]
nop

; try release NiPointer<NiAVObject>
try_release_niptr:

mov rcx, qword ptr [rdi+18h] ; NiPointer<NiAVObject>
test rcx, rcx
je delete
lock xadd dword ptr [rcx+8h], esi
cmp esi, 1h
jne zero_niptr
; refcount zero

mov rax, qword ptr[rcx]
call qword ptr[rax + 8h]
zero_niptr:
mov qword ptr [rdi + 18h], 0

delete:

mov edx, 30h ; size
mov rcx, rdi ; ptr
call qword ptr[skee_operator_delete]

mov rbx, qword ptr [rsp + 30h]
mov rsi, qword ptr [rsp + 38h]
add rsp, 20h
pop rdi

exit:

ret

NIOVTaskDeferredMask_Dispose endp

end