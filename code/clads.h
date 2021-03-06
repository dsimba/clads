/**
 * Copyright (C) 2011-2014 Joao Paulo de Souza Medeiros
 *
 * Author(s): Joao Paulo de Souza Medeiros <ignotus21@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef CLADS_H
#define CLADS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define CLADS_REAL_STR  "%Lf"
#define CLADS_UINT_STR  "%llu"
#define CLADS_POW       powl
#define CLADS_SQRT      sqrtl
#define CLADS_EXP       expl
#define CLADS_LOG       logl
#define CLADS_SIN       sinl
#define CLADS_COS       cosl
#define CLADS_ATAN2     atan2l
#define CLADS_FABS      fabsl

#define CLADS_VERBOSE   1
#define CLADS_DEBUG     1

#define CLADS_SWAP(a,b)         {(a) += (b); (b) = (a) - (b); (a) -= (b);}
#define CLADS_SCALE(v,a,b)      (2 * (((v) - (b)) / ((a) - (b))) - 1)
#define CLADS_CAST(i,type)      ((type) (i))
#define CLADS_ALLOC(s,type)     (type *) malloc(sizeof(type) * s); \
                                clads_alloc_count++;
#define CLADS_FREE(i)           free((clads_addr_type) i); \
                                clads_alloc_count--;


typedef void clads_void_type;
typedef void * clads_addr_type;
typedef unsigned char clads_byte_type;
typedef unsigned char clads_u8_type;
typedef unsigned short int clads_u16_type;
typedef long double clads_real_type;
typedef long long int clads_int_type;
typedef unsigned long long int clads_uint_type;
typedef clads_uint_type clads_id_type;
typedef clads_uint_type clads_size_type;
typedef size_t clads_size_t_type;
typedef char * clads_string_type;
typedef FILE * clads_file_type;

typedef enum {clads_false = 0,
              clads_true = 1} clads_bool_type;

typedef enum {clads_off = 0,
              clads_on = 1} clads_key_type;

typedef enum {clads_less = -1,
              clads_equal = 0,
              clads_more = 1,
              clads_unknown = 2} clads_order_type;
/**
 * Global variables
 */
clads_size_type clads_alloc_count;


/**
 *
 */
clads_void_type
clads_initialize(clads_void_type);

/**
 *
 */
clads_void_type
clads_finalize(clads_void_type);

/**
 *
 */
clads_size_type
clads_loop_index(clads_size_type i,
                 clads_size_type n);

/**
 *
 */
clads_void_type
clads_shuffle(clads_int_type *vector,
              clads_size_type length);

/**
 *
 */
clads_real_type
clads_nrand(clads_void_type);

/**
 *
 */
clads_real_type
clads_rand(const clads_real_type min,
           const clads_real_type max);

/**
 *
 */
clads_int_type
clads_randint(const clads_int_type min,
              const clads_int_type max);

/**
 *
 */
clads_uint_type
clads_factorial(const clads_uint_type v);

/**
 *
 */
clads_uint_type
clads_binomial(const clads_uint_type n,
               const clads_uint_type k);

/**
 *
 */
clads_uint_type
clads_nextpow2(clads_uint_type n);

#endif
