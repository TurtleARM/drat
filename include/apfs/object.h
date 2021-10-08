#ifndef APFS_OBJECT_H
#define APFS_OBJECT_H

/**
 * Structures and related items as defined in
 * §3 Objects
 */

#include <stdint.h>

/** Supporting Data Types --- forward declared for `obj_phys_t` **/

typedef uint64_t    oid_t;
typedef uint64_t    xid_t;

/** `obj_phys_t` **/

#define MAX_CKSUM_SIZE  8

typedef struct {
    uint8_t     o_cksum[MAX_CKSUM_SIZE];
    oid_t       o_oid;
    xid_t       o_xid;
    uint32_t    o_type;
    uint32_t    o_subtype;
} obj_phys_t;

/** Object Identifier Constants **/

#define OID_NX_SUPERBLOCK   1

#define OID_INVALID         0ULL
#define OID_RESERVED_COUNT  1024

/** Object Type Masks **/

#define OBJECT_TYPE_MASK                0x0000ffff
#define OBJECT_TYPE_FLAGS_MASK          0xffff0000

#define OBJ_STORAGETYPE_MASK            0xc0000000
#define OBJECT_TYPE_FLAGS_DEFINED_MASK  0xf8000000

/** Object Types **/

#define OBJECT_TYPE_NX_SUPERBLOCK       0x00000001

#define OBJECT_TYPE_BTREE               0x00000002
#define OBJECT_TYPE_BTREE_NODE          0x00000003

#define OBJECT_TYPE_SPACEMAN            0x00000005
#define OBJECT_TYPE_SPACEMAN_CAB        0x00000006
#define OBJECT_TYPE_SPACEMAN_CIB        0x00000007
#define OBJECT_TYPE_SPACEMAN_BITMAP     0x00000008
#define OBJECT_TYPE_SPACEMAN_FREE_QUEUE 0x00000009

#define OBJECT_TYPE_EXTENT_LIST_TREE    0x0000000a
#define OBJECT_TYPE_OMAP                0x0000000b
#define OBJECT_TYPE_CHECKPOINT_MAP      0x0000000c

#define OBJECT_TYPE_FS                  0x0000000d
#define OBJECT_TYPE_FSTREE              0x0000000e
#define OBJECT_TYPE_BLOCKREFTREE        0x0000000f
#define OBJECT_TYPE_SNAPMETATREE        0x00000010

#define OBJECT_TYPE_NX_REAPER           0x00000011
#define OBJECT_TYPE_NX_REAP_LIST        0x00000012
#define OBJECT_TYPE_OMAP_SNAPSHOT       0x00000013
#define OBJECT_TYPE_EFI_JUMPSTART       0x00000014
#define OBJECT_TYPE_FUSION_MIDDLE_TREE  0x00000015
#define OBJECT_TYPE_NX_FUSION_WBC       0x00000016
#define OBJECT_TYPE_NX_FUSION_WBC_LIST  0x00000017
#define OBJECT_TYPE_ER_STATE            0x00000018

#define OBJECT_TYPE_GBITMAP             0x00000019
#define OBJECT_TYPE_GBITMAP_TREE        0x0000001a
#define OBJECT_TYPE_GBITMAP_BLOCK       0x0000001b

#define OBJECT_TYPE_ER_RECOVERY_BLOCK   0x0000001c
#define OBJECT_TYPE_SNAP_META_EXT       0x0000001d
#define OBJECT_TYPE_INTEGRITY_META      0x0000001e
#define OBJECT_TYPE_FEXT_TREE           0x0000001f
#define OBJECT_TYPE_RESERVED_20         0x00000020

#define OBJECT_TYPE_INVALID             0x00000000
#define OBJECT_TYPE_TEST                0x000000ff

/*
 * Media keybag types (object types that correspond to an instance of
 * `media_keybag_t`). The type values don't use only the low 16 bits of the
 * `o_type` field. Instead, they use all 32 bits of that field, meaning these
 * objects don't have type flags, and that comparing `o_type & OBJECT_TYPE_MASK`
 * with these values doesn't work; you must compare `o_type` directly with these
 * values instead.
 */
#define OBJECT_TYPE_CONTAINER_KEYBAG    'keys'
#define OBJECT_TYPE_VOLUME_KEYBAG       'recs'
#define OBJECT_TYPE_MEDIA_KEYBAG        'mkey'

/** Object Type Flags **/

#define OBJ_VIRTUAL                     0x00000000
#define OBJ_EPHEMERAL                   0x80000000
#define OBJ_PHYSICAL                    0x40000000

#define OBJ_NOHEADER                    0x20000000
#define OBJ_ENCRYPTED                   0x10000000
#define OBJ_NONPERSISTENT               0x08000000

#endif // APFS_OBJECT_H
