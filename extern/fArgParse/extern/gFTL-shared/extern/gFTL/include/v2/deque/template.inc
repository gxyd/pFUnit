#define __IDENTITY(x) x
#define __MANGLE(proc) __IDENTITY(__guard)__IDENTITY(proc)

   implicit none
   integer, parameter :: GFTL_SIZE_KIND = selected_int_kind(18)

#define __deque Deque
#define __deque_iterator DequeIterator
#define __deque_riterator DequeRIterator


   private
   public :: __deque
   public :: __deque_iterator

   ! Iterator functions
   public :: operator(+)
   public :: operator(-)
   public :: operator(==)
   public :: operator(/=)

   public :: operator(<)
   public :: operator(>)
   public :: operator(<=)
   public :: operator(>=)

#define __guard deque_

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
      integer(kind=gftl_size_kind) :: current_index = -1 ! intentionally invalid value

   contains

   end type __deque_iterator__


   interface operator(==)
      module procedure __MANGLE(iter_equal)
   end interface operator(==)

   interface operator(/=)
      module procedure __MANGLE(iter_not_equal)
   end interface operator(/=)

type __deque_riterator__
private
type(__deque), pointer :: deque
   integer(kind=gftl_size_kind) :: current_index = -1 ! intentionally invalid value
end type __deque_riterator__


interface operator(==)
module procedure __MANGLE(riter_equal)
end interface operator(==)

interface operator(/=)
module procedure __MANGLE(riter_not_equal)
end interface operator(/=)

   contains

! code from deque/procedures.inc
#define __deque_iterator__ DequeIterator
#define __deque_riterator__ DequeRIterator

   function __MANGLE(new_deque_range)(first, last) result(v)
      type (__deque) :: v
      type (__deque_iterator__), intent(in) :: first
      type (__deque_iterator__), intent(in) :: last

      type (__deque_iterator__) :: iter

      print *, iter /= last
      return
   end function __MANGLE(new_deque_range)

   logical function __MANGLE(iter_equal)(a, b) result(eq)
      type(__deque_iterator__), intent(in) :: a
      type(__deque_iterator__), intent(in) :: b
      eq = (a%current_index == b%current_index)
   end function __MANGLE(iter_equal)

   logical function __MANGLE(iter_not_equal)(a, b) result(ne)
      type(__deque_iterator__), intent(in) :: a
      type(__deque_iterator__), intent(in) :: b
      ne = .not. (a == b)
   end function __MANGLE(iter_not_equal)

   logical function __MANGLE(riter_equal)(a, b) result(eq)
      type(__deque_riterator__), intent(in) :: a
      type(__deque_riterator__), intent(in) :: b
      eq = (a%current_index == b%current_index)
   end function __MANGLE(riter_equal)

   logical function __MANGLE(riter_not_equal)(a, b) result(ne)
      type(__deque_riterator__), intent(in) :: a
      type(__deque_riterator__), intent(in) :: b
      ne = .not. (a == b)
   end function __MANGLE(riter_not_equal)

! undef internal template parameters
#undef __guard
