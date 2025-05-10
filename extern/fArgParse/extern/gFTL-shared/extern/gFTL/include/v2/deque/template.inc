
#include "shared/define_common_macros.inc"

#define __deque Deque
#define __deque_iterator DequeIterator
#define __deque_riterator DequeRIterator
#define __deque_guard deque_


   private
   public :: __deque
   public :: __deque_iterator

   ! Iterator functions
   public :: operator(+)
   public :: operator(-)


   ! Iterator and possibly container functions:
   ! The following are always defined for the iterator.
   ! May not also be defined for the container itself depending
   ! on properties of parameter T.

   public :: operator(==)
   public :: operator(/=)

   public :: operator(<)
   public :: operator(>)
   public :: operator(<=)
   public :: operator(>=)


#define __guard __deque_guard

#ifdef __deque_iterator
#    define __deque_iterator__ __deque_iterator
#else
#    define __deque_iterator__ DequeIterator
#endif

#ifdef __deque_riterator
#    define __deque_riterator__ __deque_riterator
#else
#    define __deque_riterator__ DequeRIterator
#endif

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


#ifdef __deque_iterator__
#    undef __deque_iterator__
#endif

#ifdef __deque_riterator__
#    undef __deque_riterator__
#endif

! undef derived template parameters

! undef internal template parameters
#undef __guard
!#include "parameters/T/undef_internal.inc"



   contains

#include "deque/procedures.inc"
