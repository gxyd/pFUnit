

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

#include "parameters/T/define_derived_macros.inc"
   
   interface __deque
#ifndef  __gftl_disable_index_kind_overload
#endif

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
      type(__MANGLE(bucket_ptr)), allocatable :: buckets(:)
      integer(kind=GFTL_SIZE_KIND) :: size_ = 0
      integer(kind=GFTL_SIZE_KIND) :: front_ = -1
      integer(kind=GFTL_SIZE_KIND) :: back_ = 0
   contains


      procedure :: at_default => __MANGLE(at_default)
      procedure :: of_default => __MANGLE(of_default)
      generic :: at => at_default
      generic :: at => of_default

#ifndef  __gftl_disable_index_kind_overload
      procedure :: at_size_kind => __MANGLE(at_size_kind)
      generic :: at => at_size_kind
#endif


#ifndef  __gftl_disable_index_kind_overload
#endif



#ifndef  __gftl_disable_index_kind_overload
#endif







#ifdef __T_EQ__
#endif

   end type __deque




#if defined(__T_EQ__) || defined(__T_LT__)

#endif

      

#include "deque/iterator_specification.inc"
#include "deque/reverse_iterator_specification.inc"

#ifdef __deque_iterator__
#    undef __deque_iterator__
#endif

#ifdef __deque_riterator__
#    undef __deque_riterator__
#endif

#include "parameters/T/undef_derived_macros.inc"

#undef __guard
#include "parameters/T/undef_internal.inc"

