/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 *    Copyright 2014-2017 (c) Fraunhofer IOSB (Author: Julius Pfrommer)
 *    Copyright 2014, 2017 (c) Florian Palm
 *    Copyright 2015 (c) LEvertz
 *    Copyright 2015-2016 (c) Sten Grüner
 *    Copyright 2015 (c) Chris Iatrou
 *    Copyright 2015-2016 (c) Oleksiy Vasylyev
 *    Copyright 2017 (c) Stefan Profanter, fortiss GmbH
 */

#ifndef UA_UTIL_H_
#define UA_UTIL_H_

#include "ua_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* BSD Queue Macros */
#include "../deps/queue.h"

/* Macro-Expand for MSVC workarounds */
#define UA_MACRO_EXPAND(x) x

/* Thread-Local Storage
 * --------------------
 * Thread-local storage is not required by the main library functionality. It is
 * only used for some testing strategies. ``UA_THREAD_LOCAL`` is empty if the
 * feature is not available. */

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
# define UA_THREAD_LOCAL _Thread_local /* C11 */
#elif defined(__cplusplus) && __cplusplus > 199711L
# define UA_THREAD_LOCAL thread_local /* C++11 */
#elif defined(__GNUC__)
# define UA_THREAD_LOCAL __thread /* GNU extension */
#elif defined(_MSC_VER)
# define UA_THREAD_LOCAL __declspec(thread) /* MSVC extension */
#else
# define UA_THREAD_LOCAL
#endif

/* Integer Shortnames
 * ------------------
 * These are not exposed on the public API, since many user-applications make
 * the same definitions in their headers. */

typedef UA_Byte u8;
typedef UA_SByte i8;
typedef UA_UInt16 u16;
typedef UA_Int16 i16;
typedef UA_UInt32 u32;
typedef UA_Int32 i32;
typedef UA_UInt64 u64;
typedef UA_Int64 i64;
typedef UA_StatusCode status;

/* Utility Functions
 * ----------------- */

/* Convert given byte string to a positive number. Returns the number of valid
 * digits. Stops if a non-digit char is found and returns the number of digits
 * up to that point. */
size_t UA_readNumber(u8 *buf, size_t buflen, u32 *number);

#define MIN(A,B) (A > B ? B : A)
#define MAX(A,B) (A > B ? A : B)

#ifdef UA_DEBUG_DUMP_PKGS
void UA_EXPORT UA_dump_hex_pkg(UA_Byte* buffer, size_t bufferLen);
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* UA_UTIL_H_ */
