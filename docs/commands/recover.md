(command_recover)=

# {drat-command}`recover`

The {drat-command}`recover` command allows you to easily recover a file or
entire directory tree and all the files within it. You must specify the same set
of parameters required by {drat-command}`explore-fs`, namely:

- a filesystem tree in the same manner as {drat-command}`explore-fs-tree`; and

- an object map in the same manner as {drat-command}`explore-fs-tree`; and

- an entry point, which is the item you wish to recover, and is either:

  - an absolute filesystem path via {argument}`path`, like `/`,
    `/Users/john`, `/Users/john/Documents/my document.txt`, or `/..`; or

  - a filesystem object ID via {argument}`fsoid`, like `0x7563`.

If no filesystem tree or object map is specified, the default is `--volume 1`.
The simplest usage thus involves only specifying {argument}`path`, in which case
the item at that path within the first volume will be recovered. You can
additionally specify {argument}`volume` or {argument}`volume-name` if the item
you wish to recover is not within the first volume.

Specify the output path (the path to write the recovered data to) with
{argument}`output`. If the output path is a directory and ends with `/`, the
item you wish to recover will be stored within that directory, and the item name
as determined by {argument}`path` or {argument}`fsoid` will be used as the
recovered item's name. The default is `--output ./`, so the recovered item will
be written to the current working directory. Specifying `--output -` when the
entry point is a file will result in the file data being sent to {file}`stdout`,
and all normal informational output will be sent to {file}`stderr` rather than
{file}`stdout`.

Whilst files are being recovered, they are temporarily named
`_com.dratapp.recover_<target name>`, and then renamed to `<target name>` once
they have been fully recovered.

If the item you wish to recover is a file, and a directory with the target name
already exists, an error will occur. If a file with the target name already
exists, it will not be overwritten unless you specify {argument}`overwrite`.

If the item you wish to recover is a directory, and a file with the target name
already exists, an error will occur. If a directory with the target name already
exists, the recovered directoy tree will be merged with the existing directory
tree. Any existing files that have the same relative path as recovered files
will not be overwritten unless you specify {argument}`overwrite`. This behaviour
means that if a directory tree recovery process gets interrupted or encounters
an error, you can issue the same command *without* {argument}`overwrite` to
effectively resume the recovery process from where it stopped, or *with*
{argument}`overwrite` to effectively restart the process from scratch.

## Example usage and output

```
$ drat --container /dev/disk0s2 recover --path /Users/john/Desktop/my-file.txt

$ drat --container /dev/disk0s2 recover --path /Users/john/Desktop/my-file.txt --output recovered-file.txt

$ drat --container /dev/disk0s2 recover --path /Users/john/Desktop/my-file.txt --output - | grep 'lorem ipsum'

$ drat --container /dev/disk0s2 recover --path /Users/john

$ drat --container /dev/disk0s2 recover --path /Users/john --output recovered-john --overwrite

$ drat --container /dev/disk0s2 recover --volume-name macOS --path /System

$ drat --container /dev/disk0s2 recover --volume 5 --path /System
```

```{todo} Provide example output
```