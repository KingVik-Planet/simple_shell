# 0x16. C - Simple Shell
# Collabrative Project on Simple_Shell
![Alt](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg "Title")
## AIM
It’s time for the famous Simple Shell project. 
This Deals with everything so far which Includes:
* Basics of C
* Basics of thinking like an engineer
* Group workBasics of programming
* Learning how to learn

# Materials Used
* [Unix shell](https://intranet.alxswe.com/rltoken/f0YU9TAhniMXWlSXtb64Yw "Unix shell")
* [Ken Thompson](https://intranet.alxswe.com/rltoken/wTSu31ZP1f7fFTJFgRQC7w "Ken Thompson")
* [Thompson shell](https://intranet.alxswe.com/rltoken/7LJOp2qP7qHUcsOK2-F3qA "Thompson shell")

# List of allowed functions and system calls
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* wait4 (man 2 wait4)
* write (man 2 write)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* access (man 2 access)
* execve (man 2 execve)
* exit (man 3 exit)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)

## General
- Editors: vi, vim, emacs
- Code Style: Betty style. To bechecked using betty-style.pl and betty-doc.pl
- No Shell memory leaks
- Author Files: AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format: [Docker](https://intranet.alxswe.com/rltoken/UL8J3kgl7HBK_Z9iBL3JFg "Docker")
- All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All files end with a new line
- Not More than:  5 functions per file
- All your header files should be include guarded

## Compilation
* Shell will be compiled this way:
~~~~
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
~~~~


## Output Sample:
~~~~
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
~~~~

## Contributors
* [Koroworola Mauton](https://github.com/Kofoworola001 "Kofoworola001")
* [Kingsley Chika CHUKWU](https://github.com/KingVik-Planet "Kingsley Chika CHUKWU")
* Date:12/05/2023		
