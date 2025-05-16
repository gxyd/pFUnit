# Compiler-specific flags for LFortran

# Enable preprocessing (equivalent to -cpp in GFortran)
set(cpp "--cpp")

# Position-independent code (required by pFUnit)
set(pic "")

# Debugging info (equivalent to GFortran's -fbacktrace or -g)
set(debug "")
set(nowarnings "--no-warnings")
set(nostylewarnings "--no-style-warnings")

# No optimization for debug builds (LFortran ignores -O for now, but set explicitly)
set(opt "")

# Common flags supported by LFortran
set(common_flags "${nowarnings} ${nostylewarnings}")
# set(common_flags "${cpp} ${pic} ${opt}")

# Debug and release flags
set(CMAKE_Fortran_FLAGS_DEBUG "${common_flags} ${debug}")
set(CMAKE_Fortran_FLAGS_RELEASE "${common_flags}")

# Define a preprocessor symbol to identify LFortran (optional)
add_compile_definitions(_LFORTRAN)

