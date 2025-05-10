#define __guard __deque_guard

#define __deque_iterator__ DequeIterator
#define __deque_riterator__ DequeRIterator

   ! Structure constructors
   interface __deque
      module procedure __MANGLE(new_deque_range)
   end interface __deque

   type :: __deque
      private
   contains
   end type __deque

   interface operator(==)
   end interface operator(==)
   interface operator(/=)
   end interface operator(/=)

type __deque_iterator__
private

type(__deque), pointer :: deque
integer(kind=__gftl_size_kind) :: current_index = -1 ! intentionally invalid value

contains

end type __deque_iterator__


! Non type-bound functions

! Relational operators
interface operator(==)
module procedure __MANGLE(iter_equal)
end interface operator(==)

interface operator(/=)
module procedure __MANGLE(iter_not_equal)
end interface operator(/=)

type __deque_riterator__
private

type(__deque), pointer :: deque
integer(kind=__gftl_size_kind) :: current_index = -1 ! intentionally invalid value

contains

end type __deque_riterator__

! Relational operators
interface operator(==)
module procedure __MANGLE(riter_equal)
end interface operator(==)

interface operator(/=)
module procedure __MANGLE(riter_not_equal)
end interface operator(/=)


! undef internal template parameters
#undef __guard
