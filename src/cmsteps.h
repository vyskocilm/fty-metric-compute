/*  =========================================================================
    cmsteps - Helper class for list of steps

    Copyright (C) 2016 - 2017 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
    =========================================================================
*/

#ifndef CMSTEPS_H_INCLUDED
#define CMSTEPS_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CMSTEPS_T_DEFINED
typedef struct _cmsteps_t cmsteps_t;
#define CMSTEPS_T_DEFINED
#endif

//  @interface
//  Create a new cmsteps
FTY_METRIC_COMPUTE_EXPORT cmsteps_t *
    cmsteps_new (void);

//  Destroy the cmsteps
FTY_METRIC_COMPUTE_EXPORT void
    cmsteps_destroy (cmsteps_t **self_p);

//  Convert the time with prefix to number in seconds
//      "42" -> 42
//      "42s" -> 42
//      "42m" -> 2520
FTY_METRIC_COMPUTE_EXPORT int64_t
    cmsteps_toint (const char *step);

//  Return greatest common divisor of steps - 0 means no steps are in a list
FTY_METRIC_COMPUTE_EXPORT uint32_t
    cmsteps_gcd (cmsteps_t *self);

//  Put new step to the list, return -1 if fail (possibly wrong step)
FTY_METRIC_COMPUTE_EXPORT int
    cmsteps_put (cmsteps_t *self, const char* step);

//  Get new step to the list. Return -1 in case of error, however positive
//  result can be cast to uint32_t
FTY_METRIC_COMPUTE_EXPORT int64_t
    cmsteps_get (cmsteps_t *self, const char* step);

//  Return iterator to first item
FTY_METRIC_COMPUTE_EXPORT uint32_t *
    cmsteps_first (cmsteps_t *self);

//  Return iterator to next item or NULL
FTY_METRIC_COMPUTE_EXPORT uint32_t *
    cmsteps_next (cmsteps_t *self);

//  Return cursor
FTY_METRIC_COMPUTE_EXPORT const void *
    cmsteps_cursor (cmsteps_t *self);

//  Self test of this class
FTY_METRIC_COMPUTE_EXPORT void
    cmsteps_test (bool verbose);

//  @end

#ifdef __cplusplus
}
#endif

#endif
