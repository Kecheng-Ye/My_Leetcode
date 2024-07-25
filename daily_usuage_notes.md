**Delete certain files recursively within some directory**

```bash
find /path/to/directory -name "*.class" -type f -delete
```

Note:
* `find`: The command used to search for files and directories
* `/path/to/directory`: Replace this with the actual path to the directory you want to start the search from
* `-name "*.class"`: Specifies the pattern to match (all files ending with .class)
* `-type f`: Ensures that only regular files (not directories) are matched
* `-delete`: Deletes the matched files