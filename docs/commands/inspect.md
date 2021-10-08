(command_inspect)=

# {drat-command}`inspect`

## Description

The {drat-command}`inspect` command inspects all aspects of an APFS container,
primarily by simulating the process of mounting it. It displays info about the
inspection process, reporting info, warnings, and errors about the container's
state.

## Example usage and output

```
$ drat --container /dev/disk2s2 inspect

Opening file at `/dev/disk2s2` in read-only mode ... OK.
Simulating a mount of the APFS container.
Validating checksum of block 0x0 ... OK.

Details of block 0x0:
--------------------------------------------------------------------------------
Stored checksum:    0xe25ef5e409032d45
OID:                0x1
XID:                0x1bca24
Storage type:       Ephemeral
Type flags:         (none)
Type:               Container superblock
Subtype:            (none/invalid)
Magic string:       NXSB
Block size:         4096 bytes
Block count:        117161676
Supported features:
- No feature flags are set.
Supported read-only compatible features:
- No read-only compatible feature flags are set.
Backward-incompatible features:
- No backward-incompatible feature flags are set.
UUID:       0x07531d831bda8f8c9944ee600d55fd37
Next OID:                       0x28709a
Next XID:                       0x1bca25
Space manager Ephemeral OID:    0x87d46
Object map Physical OID:        0xcfc19
Reaper Ephemeral OID:           0x401
Other flags:
- No other flags are set.
--------------------------------------------------------------------------------

Locating the checkpoint descriptor area:
- Its length is 280 blocks.
- It is contiguous.
- The address of its first block is 0x3629fe4.
Loading the checkpoint descriptor area into memory ... OK.
Locating the most recent well-formed container superblock in the checkpoint descriptor area:
- It lies at index 271 within the checkpoint descriptor area.

Details of this container superblock:
--------------------------------------------------------------------------------
Stored checksum:    0xe25eecc609033666
OID:                0x1
XID:                0x1bca24
Storage type:       Ephemeral
Type flags:         (none)
Type:               Container superblock
Subtype:            (none/invalid)
Magic string:       NXSB
Block size:         4096 bytes
Block count:        117161676
Supported features:
- No feature flags are set.
Supported read-only compatible features:
- No read-only compatible feature flags are set.
Backward-incompatible features:
- No backward-incompatible feature flags are set.
UUID:       0x07531d831bda8f8c9944ee600d55fd37
Next OID:                       0x28709a
Next XID:                       0x1bca25
Space manager Ephemeral OID:    0x87d46
Object map Physical OID:        0xcfc19
Reaper Ephemeral OID:           0x401
Other flags:
- No other flags are set.
--------------------------------------------------------------------------------
- The corresponding checkpoint starts at index 270 within the checkpoint descriptor area, and spans 2 blocks.

Loading the corresponding checkpoint ... OK.

Details of each block in this checkpoint:
--------------------------------------------------------------------------------
Stored checksum:    0xe63bc1554547b687
OID:                0x362a0f2
XID:                0x1bca24
Storage type:       Physical
Type flags:         (none)
Type:               Checkpoint map
Subtype:            (none/invalid)
Flags:
- Last checkpoint-mapping block in the corresponding checkpoint.
Number of mappings: 5
--------------------------------------------------------------------------------
Stored checksum:    0xe25eecc609033666
OID:                0x1
XID:                0x1bca24
Storage type:       Ephemeral
Type flags:         (none)
Type:               Container superblock
Subtype:            (none/invalid)
Magic string:       NXSB
Block size:         4096 bytes
Block count:        117161676
Supported features:
- No feature flags are set.
Supported read-only compatible features:
- No read-only compatible feature flags are set.
Backward-incompatible features:
- No backward-incompatible feature flags are set.
UUID:       0x07531d831bda8f8c9944ee600d55fd37
Next OID:                       0x28709a
Next XID:                       0x1bca25
Space manager Ephemeral OID:    0x87d46
Object map Physical OID:        0xcfc19
Reaper Ephemeral OID:           0x401
Other flags:
- No other flags are set.
--------------------------------------------------------------------------------

Details of each checkpoint-mapping in this checkpoint:
--------------------------------------------------------------------------------
Ephemeral OID:                      0x87d46
Logical block address on disk:      0x3624379
Object type:                        Space manager
Object subtype:                     (none/invalid)
Object size:                        4096 bytes
Associated volume OID (virtual):    0x0
--------------------------------------------------------------------------------
Ephemeral OID:                      0x87d47
Logical block address on disk:      0x362437a
Object type:                        B-tree (root node)
Object subtype:                     Space manager free-space queue
Object size:                        4096 bytes
Associated volume OID (virtual):    0x0
--------------------------------------------------------------------------------
Ephemeral OID:                      0x405
Logical block address on disk:      0x362437b
Object type:                        B-tree (root node)
Object subtype:                     Space manager free-space queue
Object size:                        4096 bytes
Associated volume OID (virtual):    0x0
--------------------------------------------------------------------------------
Ephemeral OID:                      0x401
Logical block address on disk:      0x362437c
Object type:                        Container reaper
Object subtype:                     (none/invalid)
Object size:                        4096 bytes
Associated volume OID (virtual):    0x0
--------------------------------------------------------------------------------
Ephemeral OID:                      0x178c0
Logical block address on disk:      0x362437d
Object type:                        Container reaper list
Object subtype:                     (none/invalid)
Object size:                        4096 bytes
Associated volume OID (virtual):    0x0
--------------------------------------------------------------------------------
- There are 5 checkpoint-mappings in this checkpoint.

Reading the Ephemeral objects used by this checkpoint ... OK.
Validating the Ephemeral objects ... OK.

Details of the Ephemeral objects:
--------------------------------------------------------------------------------
Stored checksum:    0x25850498fb2a64c7
OID:                0x87d46
XID:                0x1bca24
Storage type:       Ephemeral
Type flags:         (none)
Type:               Space manager
Subtype:            (none/invalid)
--------------------------------------------------------------------------------
Stored checksum:    0x5d65ceccea5e5cca
OID:                0x87d47
XID:                0x1bca24
Storage type:       Ephemeral
Type flags:         (none)
Type:               B-tree (root node)
Subtype:            Space manager free-space queue
--------------------------------------------------------------------------------
Stored checksum:    0x6b1aa7c5bd428590
OID:                0x405
XID:                0x1bca24
Storage type:       Ephemeral
Type flags:         (none)
Type:               B-tree (root node)
Subtype:            Space manager free-space queue
--------------------------------------------------------------------------------
Stored checksum:    0xfaf5a52944eb7745
OID:                0x401
XID:                0x1bca24
Storage type:       Ephemeral
Type flags:         (none)
Type:               Container reaper
Subtype:            (none/invalid)
--------------------------------------------------------------------------------
Stored checksum:    0x5f93fce79faa616f
OID:                0x178c0
XID:                0x1bca24
Storage type:       Ephemeral
Type flags:         (none)
Type:               Container reaper list
Subtype:            (none/invalid)
--------------------------------------------------------------------------------

The container superblock states that the container object map has Physical OID 0xcfc19.
Loading the container object map ... OK.
Validating the container object map ... OK.

Details of the container object map:
--------------------------------------------------------------------------------
Stored checksum:    0x1602d10c29c764ec
OID:                0xcfc19
XID:                0x1bca24
Storage type:       Physical
Type flags:         (none)
Type:               Object map
Subtype:            (none/invalid)
Flags:
- No snapshot support
Object mappings tree:
- Storage type:         Physical
- Type flags:           (none)
- Type:                 B-tree (root node)
- Object ID:            0xd03ba
Snapshots tree:
- Storage type:         Physical
- Type flags:           (none)
- Type:                 B-tree (root node)
- Object ID:            0x0
- Number of snapshots:  0 snapshots
- Latest snapshot XID:  0x0
In-progress revert:
- Minimum XID:          0x0
- Maximum XID:          0x0
--------------------------------------------------------------------------------

Reading the root node of the container object map B-tree ... OK.
Validating the root node of the container object map B-tree ... OK.

Details of the container object map B-tree:
--------------------------------------------------------------------------------
Stored checksum:    0xccda4948e1be42ff
OID:                0xd03ba
XID:                0x1bca24
Storage type:       Physical
Type flags:         (none)
Type:               B-tree (root node)
Subtype:            Object map
Flags:                          Root node, Leaf node, Fixed size for keys and values
Number of child levels:         0
Number of keys in this node:    4
Location of table of contents:
- Offset from start of node data area:  0x0 = 0
- Length (bytes):                       0x1c0 = 448
Location of key–value shared free space:
- Offset from start of keys area:       0x50 = 80
- Length (bytes):                       0xd40 = 3392

Info relating to the entire B-tree:
- Flags:
  - This B-tree is currently undergoing a series of sequential inserts --- optimise operations if possible
  - Child nodes are referred to using Physical OIDs
- Node size:                4096 bytes
- Key size:                 16 bytes
- Value size:               16 bytes

- Length of longest key:    16 bytes
- Length of longest value:  16 bytes
- Number of keys:           4
- Number of nodes:          1
--------------------------------------------------------------------------------

The container superblock lists 4 APFS volumes, whose superblocks have the following Virtual OIDs:
- 0x402
- 0x408
- 0x40a
- 0xa2cd

Reading the APFS volume superblocks ... OK.
Validating the APFS volume superblocks ... OK.

Details of these volume superblocks:
--------------------------------------------------------------------------------
Stored checksum:    0xb5b1a8822f1d487c
OID:                0x402
XID:                0x1bca24
Storage type:       Virtual
Type flags:         (none)
Type:               APFS volume
Subtype:            (none/invalid)

Magic string:                           APSB
Index within container volume array:    0

Volume name:        ### macOS ###

Flags:
- Volume is unencrypted.
Supported features:
- This volume has hardlink map records.
Supported read-only compatible features:
- No read-only compatible volume feature flags are set.
Backward-incompatible features:
- Filenames on this volume are case-insensitive.
Roles:
- This volume has no defined roles

Last unmount time:                  Mon Oct 28 00:39:51 2019
Last modification time:             Mon Oct 28 00:39:51 2019

Reserved blocks:                    0 blocks
Block quota:                        0 blocks
Allocated blocks:                   95004267 blocks

Volume object map Physical OID:     0xd0c91

Root tree info:
- Physical OID:     0x404
- Storage type:     Virtual
- Type flags:       (none)
- Object type:      B-tree (root node)

Extent-reference tree info:
- Physical OID:     0xcfbc1
- Storage type:     Physical
- Type flags:       (none)
- Object type:      B-tree (root node)

Snapshot metadata tree info:
- Physical OID:     0xd19b3
- Storage type:     Physical
- Type flags:       (none)
- Object type:      B-tree (root node)

On next mount, revert to:
- snapshot with this XID:                           0x0
- APFS volume superblock with this Physical OID:    0x0

Next file-system object ID that will be assigned:   0xb7b2d2
Next document ID that will be assigned:             0x39

Number of:

- regular files:                818284
- directories:                  149371
- symbolic links:               33513
- other file-system objects:    259

- snapshots:                    0
- block allocations ever made:  527393597
- block liberations ever made:  432520964

UUID:   0x6e8c1b74febf029f874ce36cbf63236e
--------------------------------------------------------------------------------
Stored checksum:    0x89a5ff1f4028c3dc
OID:                0x408
XID:                0x1ac206
Storage type:       Virtual
Type flags:         (none)
Type:               APFS volume
Subtype:            (none/invalid)

Magic string:                           APSB
Index within container volume array:    1

Volume name:        ### Preboot ###

Flags:
- Volume is unencrypted.
Supported features:
- This volume has hardlink map records.
Supported read-only compatible features:
- No read-only compatible volume feature flags are set.
Backward-incompatible features:
- Filenames on this volume are case-insensitive.
Roles:
- Preboot volume (contains files needed to boot from an encrypted volumes)

Last unmount time:                  Thu Jan  1 01:00:00 1970
Last modification time:             Tue Oct  1 22:09:26 2019

Reserved blocks:                    0 blocks
Block quota:                        0 blocks
Allocated blocks:                   5774 blocks

Volume object map Physical OID:     0xdfec2

Root tree info:
- Physical OID:     0x409
- Storage type:     Virtual
- Type flags:       (none)
- Object type:      B-tree (root node)

Extent-reference tree info:
- Physical OID:     0xd0dc1
- Storage type:     Physical
- Type flags:       (none)
- Object type:      B-tree (root node)

Snapshot metadata tree info:
- Physical OID:     0xd047a
- Storage type:     Physical
- Type flags:       (none)
- Object type:      B-tree (root node)

On next mount, revert to:
- snapshot with this XID:                           0x0
- APFS volume superblock with this Physical OID:    0x0

Next file-system object ID that will be assigned:   0x66d
Next document ID that will be assigned:             0x3

Number of:

- regular files:                85
- directories:                  19
- symbolic links:               0
- other file-system objects:    0

- snapshots:                    0
- block allocations ever made:  340093
- block liberations ever made:  334334

UUID:   0x4c6f78180f2d3fa5654347f662a09011
--------------------------------------------------------------------------------
Stored checksum:    0xcd5302d537353713
OID:                0x40a
XID:                0x1bc8be
Storage type:       Virtual
Type flags:         (none)
Type:               APFS volume
Subtype:            (none/invalid)

Magic string:                           APSB
Index within container volume array:    2

Volume name:        ### Recovery ###

Flags:
- Volume is unencrypted.
Supported features:
- This volume has hardlink map records.
Supported read-only compatible features:
- No read-only compatible volume feature flags are set.
Backward-incompatible features:
- Filenames on this volume are case-insensitive.
Roles:
- Recovery volume (contains a recovery system)

Last unmount time:                  Thu Jan  1 01:00:00 1970
Last modification time:             Sun Oct  6 22:32:29 2019

Reserved blocks:                    0 blocks
Block quota:                        0 blocks
Allocated blocks:                   123872 blocks

Volume object map Physical OID:     0xd01da

Root tree info:
- Physical OID:     0x40b
- Storage type:     Virtual
- Type flags:       (none)
- Object type:      B-tree (root node)

Extent-reference tree info:
- Physical OID:     0xd142f
- Storage type:     Physical
- Type flags:       (none)
- Object type:      B-tree (root node)

Snapshot metadata tree info:
- Physical OID:     0xd04ed
- Storage type:     Physical
- Type flags:       (none)
- Object type:      B-tree (root node)

On next mount, revert to:
- snapshot with this XID:                           0x0
- APFS volume superblock with this Physical OID:    0x0

Next file-system object ID that will be assigned:   0xc6
Next document ID that will be assigned:             0x3

Number of:

- regular files:                29
- directories:                  3
- symbolic links:               0
- other file-system objects:    0

- snapshots:                    0
- block allocations ever made:  873153
- block liberations ever made:  749291

UUID:   0x4c9d52dcc5ca25ad34422a50db9597fd
--------------------------------------------------------------------------------
Stored checksum:    0xa040ad7c9b0dcaef
OID:                0xa2cd
XID:                0x1bca08
Storage type:       Virtual
Type flags:         (none)
Type:               APFS volume
Subtype:            (none/invalid)

Magic string:                           APSB
Index within container volume array:    3

Volume name:        ### VM ###

Flags:
- Volume is unencrypted.
Supported features:
- This volume has hardlink map records.
Supported read-only compatible features:
- No read-only compatible volume feature flags are set.
Backward-incompatible features:
- Filenames on this volume are case-insensitive.
Roles:
- Swap volume (used as swap space for virtual memory)

Last unmount time:                  Thu Jan  1 01:00:00 1970
Last modification time:             Sun Oct  6 22:59:23 2019

Reserved blocks:                    0 blocks
Block quota:                        0 blocks
Allocated blocks:                   786438 blocks

Volume object map Physical OID:     0xd607d

Root tree info:
- Physical OID:     0xa2ce
- Storage type:     Virtual
- Type flags:       (none)
- Object type:      B-tree (root node)

Extent-reference tree info:
- Physical OID:     0xd2365
- Storage type:     Physical
- Type flags:       (none)
- Object type:      B-tree (root node)

Snapshot metadata tree info:
- Physical OID:     0xd053e
- Storage type:     Physical
- Type flags:       (none)
- Object type:      B-tree (root node)

On next mount, revert to:
- snapshot with this XID:                           0x0
- APFS volume superblock with this Physical OID:    0x0

Next file-system object ID that will be assigned:   0x251
Next document ID that will be assigned:             0x3

Number of:

- regular files:                3
- directories:                  0
- symbolic links:               0
- other file-system objects:    0

- snapshots:                    0
- block allocations ever made:  130023424
- block liberations ever made:  129236992

UUID:   0x63c4ccbb1c4f6685084c983199a4a324
--------------------------------------------------------------------------------
END: All done.
```
