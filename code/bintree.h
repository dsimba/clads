/**
 * Copyright (C) 2011 Joao Paulo de Souza Medeiros
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

#ifndef CLADS_BINTREE_H
#define CLADS_BINTREE_H

#include "clads.h"


/**
 *
 */
typedef struct bintree_node
{
    clads_id_type id;
    struct bintree_node *parent;
    struct bintree_node *left;
    struct bintree_node *right;
    void *info; // used by external libraries and applications
    clads_key_type status;
} clads_bintree_node_type;

/**
 * Tree structure
 */
typedef struct bintree
{
    clads_bintree_node_type *root;
    clads_size_type n_node;
    clads_size_type height;

    /**
     * This function tell if two nodes have the same information
     * (i.e. are equal).
     */
    clads_bool_type (*f_node_eq)(clads_bintree_node_type *,
                                 clads_bintree_node_type *);
} clads_bintree_type;


/**
 * Initialize a given tree
 */
inline void
clads_bintree_initialize(clads_bintree_type *t);

/**
 * Finalize a given tree
 */
inline void
clads_bintree_finalize(clads_bintree_type *t);

/**
 * Creates a copy of a tree.
 */
int
clads_bintree_copy(const clads_bintree_type *ta,
                   clads_bintree_type *tb);

/**
 * Initialize a given tree node
 */
inline void
clads_bintree_node_initialize(clads_bintree_node_type *n);

/**
 * Finalize a given tree node
 */
inline void
clads_bintree_node_finalize(clads_bintree_node_type *n);

/**
 *
 */
clads_bintree_node_type *
clads_bintree_add_node(clads_bintree_type *t,
                       clads_bintree_node_type *n);

/**
 *
 */
clads_bintree_node_type *
clads_bintree_search_node_from(clads_bintree_type *t,
                               clads_bintree_node_type *r,
                               clads_bintree_node_type *n);

/**
 *
 */
clads_bintree_node_type *
clads_bintree_search_node(clads_bintree_type *t,
                          clads_bintree_node_type *n);


#endif