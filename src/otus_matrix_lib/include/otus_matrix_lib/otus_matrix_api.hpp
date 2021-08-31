#pragma once
// Generic helper definitions for shared library support
#if defined _WIN32 || defined __CYGWIN__
#define OTUS_MATRIX_LIB_HELPER_DLL_IMPORT __declspec(dllimport)
#define OTUS_MATRIX_LIB_HELPER_DLL_EXPORT __declspec(dllexport)
#define OTUS_MATRIX_LIB_HELPER_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define OTUS_MATRIX_LIB_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
#define OTUS_MATRIX_LIB_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
#define OTUS_MATRIX_LIB_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define OTUS_MATRIX_LIB_HELPER_DLL_IMPORT
#define OTUS_MATRIX_LIB_HELPER_DLL_EXPORT
#define OTUS_MATRIX_LIB_HELPER_DLL_LOCAL
#endif
#endif

// Now we use the generic helper definitions above to define OTUS_MATRIX_LIB_API and OTUS_MATRIX_LIB_LOCAL.
// OTUS_MATRIX_LIB_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
// OTUS_MATRIX_LIB_LOCAL is used for non-api symbols.

#ifdef OTUS_MATRIX_LIB_DLL // defined if otus_matrix_lib is compiled as a DLL
#ifdef OTUS_MATRIX_LIB_DLL_EXPORTS // defined if we are building the otus_matrix_lib DLL (instead of using it)
#define OTUS_MATRIX_LIB_API OOTUS_MATRIX_LIB_HELPER_DLL_EXPORT
#else
#define OTUS_MATRIX_LIB_API OTUS_MATRIX_LIB_HELPER_DLL_IMPORT
#endif // OTUS_MATRIX_LIB_DLL_EXPORTS
#define OTUS_MATRIX_LIB_LOCAL OTUS_MATRIX_LIB_HELPER_DLL_LOCAL
#else // OTUS_MATRIX_LIB_DLL is not defined: this means OTUS_MATRIX_LIB is a static lib.
#define OTUS_MATRIX_LIB_API
#define OTUS_MATRIX_LIB_LOCAL
#endif // OTUS_MATRIX_LIB_DLL

