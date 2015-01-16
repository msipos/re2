# mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug ..
#   or
# mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release ..

project(RE2)
cmake_minimum_required(VERSION 2.8)

# Useful prerequisites:

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  set(WINDOWS TRUE)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(LINUX TRUE)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(MACOSX TRUE)
endif()

if (CMAKE_BUILD_TYPE MATCHES DEBUG)
  set(DEBUG_BUILD TRUE)
else()
  set(RELEASE_BUILD TRUE)
endif()

#######################################################################

# Not interested in multiple threads.
add_definitions(-DNO_THREADS)
include_directories(.)

set(sources re2/set.cc
            re2/onepass.cc
            re2/parse.cc
            re2/mimics_pcre.cc
            re2/unicode_casefold.cc
            re2/prog.cc
            re2/regexp.cc
            re2/dfa.cc
            re2/compile.cc
            re2/tostring.cc
            re2/nfa.cc
            re2/bitstate.cc
            re2/unicode_groups.cc
            re2/filtered_re2.cc
            re2/prefilter.cc
            re2/prefilter_tree.cc
            re2/simplify.cc
            re2/perl_groups.cc
            re2/re2.cc
            util/arena.cc
            util/hash.cc
            util/test.cc
            util/rune.cc
            util/strutil.cc
            util/random.cc
            util/stringpiece.cc
            util/thread.cc
            util/valgrind.cc
            util/pcre.cc
            util/stringprintf.cc
            )

add_library(re2 STATIC ${sources})

add_executable(myre2test test.cc)

target_link_libraries(myre2test re2)
