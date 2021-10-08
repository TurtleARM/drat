#ifndef APFS_SIBLING_H
#define APFS_SIBLING_H

/**
 * Structures and related items as defined in
 * §12 Siblings
 */

#include <stdint.h>
#include <apfs/j.h>         // j_key_t

/** `j_sibling_key_t` **/

typedef struct {
    j_key_t     hdr;
    uint64_t    sibling_id;
} __attribute__((packed))   j_sibling_key_t;

/** `j_sibling_val_t` **/

typedef struct {
    uint64_t    parent_id;
    uint16_t    name_len;
    uint8_t     name[0];
} __attribute__((packed))   j_sibling_val_t;

/** `j_sibling_map_key_t` **/

typedef struct {
    j_key_t     hdr;
} __attribute__((packed))   j_sibling_map_key_t;

/** `j_sibling_map_val_t` **/

typedef struct {
    uint64_t    file_id;
} __attribute__((packed))   j_sibling_map_val_t;

#endif // APFS_SIBLING_H
