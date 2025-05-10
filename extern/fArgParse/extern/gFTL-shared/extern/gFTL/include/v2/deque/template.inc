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
      module procedure deque_new_deque_range
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
      module procedure deque_iter_equal
   end interface operator(==)

   interface operator(/=)
      module procedure deque_iter_not_equal
   end interface operator(/=)

type __deque_riterator__
private
type(__deque), pointer :: deque
   integer(kind=gftl_size_kind) :: current_index = -1 ! intentionally invalid value
end type __deque_riterator__


interface operator(==)
module procedure deque_riter_equal
end interface operator(==)

interface operator(/=)
module procedure deque_riter_not_equal
end interface operator(/=)

   contains

   function deque_new_deque_range(first, last) result(v)
      type (__deque) :: v
      type (__deque_iterator__), intent(in) :: first
      type (__deque_iterator__), intent(in) :: last

      type (__deque_iterator__) :: iter

      print *, iter /= last
      return
   end function deque_new_deque_range

   logical function deque_iter_equal(a, b) result(eq)
      type(__deque_iterator__), intent(in) :: a
      type(__deque_iterator__), intent(in) :: b
      eq = (a%current_index == b%current_index)
   end function deque_iter_equal

   logical function deque_iter_not_equal(a, b) result(ne)
      type(__deque_iterator__), intent(in) :: a
      type(__deque_iterator__), intent(in) :: b
      ne = .not. (a == b)
   end function deque_iter_not_equal

   logical function deque_riter_equal(a, b) result(eq)
      type(__deque_riterator__), intent(in) :: a
      type(__deque_riterator__), intent(in) :: b
      eq = (a%current_index == b%current_index)
   end function deque_riter_equal

   logical function deque_riter_not_equal(a, b) result(ne)
      type(__deque_riterator__), intent(in) :: a
      type(__deque_riterator__), intent(in) :: b
      ne = .not. (a == b)
   end function deque_riter_not_equal

! undef internal template parameters
#undef __guard
