
#ifndef __gftl_common

#    define __IDENTITY(x) x
#    define __MANGLE(proc) __IDENTITY(__guard)proc

#define __UNLIMITED_POLYMORPHIC__ 7
#define __UNLIMITED_POLYMORPHIC 56
#endif

#define __deque Deque
#define __deque_guard deque_

#define __guard __deque_guard
type :: __deque
contains
   procedure :: at_default => __MANGLE(at_default)
   procedure :: of_default => __MANGLE(of_default)
   generic :: at => at_default
   generic :: at => of_default

   procedure :: at_size_kind => __MANGLE(at_size_kind)
   generic :: at => at_size_kind
end type __deque

#undef __guard
   contains

#define __T T
#define __guard __deque_guard

#define __T_type_id__  __T >> 3
#define __T_kind__  1 << (__T & 07)

#define __T_DECLARE__(type,kindlen) __IDENTITY(type)__IDENTITY(kindlen)
#define __T_NAME__(type,kindlen) __IDENTITY(type)//__IDENTITY(kindlen)
!#    elif __T_type_id__ == __UNLIMITED_POLYMORPHIC__

#undef __T_DECLARE__
#undef __T_NAME__
#define __T_DECLARE__(type,kindlen) __IDENTITY(class(*))
#define __T_NAME__(type,kindlen) __IDENTITY("class(*)")
#define __T_polymorphic__
#define __T_type__ *
#define __T_name__ "*"
#if !defined(__T_default__)
#    define __T_default_scalar__ NO_TYPE__
#endif


#ifdef __T_KINDLEN
#    define __T_KINDLEN__(context)  __T_KINDLEN(context)
#else
#    ifndef __T_KINDLEN__
#        define __T_KINDLEN__(context)
#    endif
#endif

#ifdef __T_kindlen_dummy
#    define __T_kindlen_dummy__ __T_kindlen_dummy
#else
#    define __T_kindlen_dummy__ __T_KINDLEN__(*)
#endif

#ifdef __T_kindlen_component
#    define __T_kindlen_component__ __T_kindlen_component
#else
#    define __T_kindlen_component__ __T_KINDLEN__(:)
#endif

#ifdef __T_kindlen_string
#    define __T_kindlen_string__ __T_kindlen_string
#else
#    ifndef __T_kindlen_string__
#        define __T_kindlen_string__ ""
#    endif
#endif

#define __T_dimension_result__
#define __T_dimension_component__
#define __T_dimension_dummy__
#define __T_dimension_string__ ""
#ifdef __T_default_scalar__
#    define __T_default__ __T_default_scalar__
#endif

#if defined(__T_deferred) && !defined(__T_deferred__)
#   define __T_deferred__
#endif

#if defined(__T_deferred__) || defined(__T_polymorphic__) || (__T_rank > 0)
#else
#    define __T_listable__
#endif

#if defined(__T_deferred__) || defined(__T_polymorphic__) || (defined(__T_rank) && !defined(__T_shape))
#    define __T_allocatable__
#    define __T_allocatable_attr__ , allocatable
#    define __T_allocatable_string__ ", allocatable"
#else
#    define __T_allocatable_attr__
#    define __T_allocatable_string__ ""
#endif

! Intel fpp has issues with comma in a macro argument, so we do something a bit brute force here
#define __T_declare_result__ __T_DECLARE__(__T_type__,__T_kindlen_component__)__T_dimension_result__
#undef tmp

#ifdef __T_EQ
#    define __T_EQ__(lhs,rhs) __T_EQ(lhs,rhs)
#elif defined(__T_EQ_SCALAR__)
#    if __T_rank == 0
#        define __T_EQ__(lhs,rhs) __T_EQ_SCALAR__(lhs,rhs)
#    elif defined(__T_shape)
#        define __T_EQ__(lhs,rhs) all(__T_EQ_SCALAR__([lhs],[rhs]))
#    else
! Must be careful about lack of short-circuit rules in Fortran.   Can only compare
! arrays of same shape, so we use reshape to compare the first N elements (always safe) as well as comparing shapes.
#        define __T_EQ__(lhs,rhs) all(shape(lhs)==shape(rhs)).and.all(reshape(lhs,[min(size(lhs),size(rhs))])==reshape(lhs,[min(size(lhs),size(rhs))]))
#    endif
#endif

!#ifdef __T_LT
!#    define __T_LT__(lhs,rhs) __T_LT(lhs,rhs)
!#elif defined(__T_LT_SCALAR__)
!#    if __T_rank == 0
!#        define __T_LT__(lhs,rhs) __T_LT_SCALAR__(lhs,rhs)
!#    endif
!#endif


#ifdef __T_FREE
#    define __T_FREE__(x)  __T_FREE(x)
#else
#    ifdef __T_allocatable__
#        define __T_FREE__(x)  deallocate(x)
#    else
#        define __T_FREE__(x)
#    endif
#endif

#ifdef __T_MOVE
#    define  __T_MOVE__(lhs,rhs)  __T_MOVE(lhs,rhs)
#else
#    ifdef __T_allocatable__
#        define  __T_MOVE__(lhs,rhs)  call move_alloc(from=rhs,to=lhs)
#    else
#        define  __T_MOVE__(lhs,rhs)  lhs=rhs
#    endif
#endif


#ifdef __T_COPY
#    define  __T_COPY__(lhs,rhs)  __T_COPY(lhs,rhs)
#else
#    if defined(__T_polymorphic__)
#        define __T_COPY__(lhs,rhs) allocate(lhs, source=rhs)
#    else
#        define __T_COPY__(lhs,rhs) lhs=rhs
#    endif
#endif

   function __MANGLE(at_size_kind)(this, i, rc) result(res)
      class(__deque), target, intent(in) :: this
      integer(8), intent(in) :: i
      integer, intent(out) :: rc
      __T_declare_result__, pointer :: res
   end function __MANGLE(at_size_kind)

   function __MANGLE(at_default)(this, i, rc) result(res)
      class(__deque), target, intent(in) :: this
      integer, intent(in) :: i
      __T_declare_result__, pointer :: res
      integer, intent(out) :: rc

      res => this%at(int(i,8),rc)

      return
   end function __MANGLE(at_default)

   function __MANGLE(of_default)(this, i) result(res)
      class(__deque), target, intent(in) :: this
      integer, intent(in) :: i
      __T_declare_result__, pointer :: res
   end function __MANGLE(of_default)

#undef __guard
