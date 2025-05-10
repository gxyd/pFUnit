#include "parameters/T/copy_deque_T_to_internal_T.inc"
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

! define derived generic template parameters from internal parameters.
#include "parameters/T/define_derived_macros.inc"
   
   ! Structure constructors
   interface __deque
      module procedure __MANGLE(new_deque_range)
   end interface __deque

   type :: __MANGLE(wrapper)
      __T_declare_component__ :: item
   end type __MANGLE(Wrapper)

   type :: __MANGLE(bucket)
      type(__MANGLE(wrapper)) :: bucket_items
   end type __MANGLE(bucket)

   type :: __MANGLE(bucket_ptr)
      type(__MANGLE(bucket)), pointer :: ptr => null()
   end type __MANGLE(bucket_ptr)

   type :: __deque
      private
      !type(__MANGLE(bucket_ptr)), allocatable :: buckets(:)
      integer(kind=GFTL_SIZE_KIND) :: size_ = 0
      integer(kind=GFTL_SIZE_KIND) :: front_ = -1
      integer(kind=GFTL_SIZE_KIND) :: back_ = 0
   contains
   end type __deque

#if defined(__T_EQ__) || defined(__T_LT__)
   interface operator(==)
   end interface operator(==)
   interface operator(/=)
   end interface operator(/=)

#endif


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
#include "parameters/T/undef_derived_macros.inc"

! undef internal template parameters
#undef __guard
#include "parameters/T/undef_internal.inc"

