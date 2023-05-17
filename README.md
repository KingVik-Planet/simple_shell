# 0x16. C - Simple Shell Project
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

# Commands in [Shell](https://intranet.alxswe.com/concepts/9 "Shell"), Credit: ALx
~~~~
awk # pattern scanning and processing language
basename # strip directory and suffix from filenames
bg # resumes suspended jobs without bringing them to the foreground
cat # print files
cd # change the shell working directory.
chmod # change file mode
chown # change file owner and group
crontab # maintain crontab files
curl # transfer a URL
cut # remove sections from each line of files
date # display or set date and time
dig # DNS lookup utility
df # report file system disk space usage
diff # compare files line by line
du # estimate file space usage
echo # display a line of text
find # search for files in a directory hierarchy
fg # resumes suspended jobs and bring them to the foreground
grep # print lines matching a pattern
kill # send a signal to a process
less # read file with pagination
ln # create links
ls # list directory contents
lsb_release # print distribution-specific information
lsof # list open files
mkdir # create
mv # move files
nc # arbitrary TCP and UDP connections and listens
netstat # print network connections, routing tables, interface statistics...
nice # execute a utility with an altered scheduling priority
nproc # print the number of processing units available
passwd # change user password
pgrep # look up processes based on name and other attributes
pkill # send signal to processes based on name and other attributes
printenv # print all or part of environment
pwd # print name of current/working directory
top # display Linux processes
tr # translate or delete characters
ps # report a snapshot of the current processes
rm # remove files or directories
rmdir # remove directories
rsync # remote file copy
scp # secure copy (remote file copy program)
sed # stream editor for filtering and transforming text
sleep # suspend execution for an interval of time
sort # sort lines of text file
ssh # OpenSSH SSH client (remote login program)
ssh-keygen # SSH key generation, management and conversion
su # substitute user identity
sudo # execute a command as another user
tail # output the last part of files
tar # manipulate archives files
tr # translate or delete characters
uname # Print operating system name
uniq # report or omit repeated lines
uptime # show how long system has been running
w # Show who is logged on and what they are doing
whereis # locate the binary, source, and manual page files for a command
which # locate a command
wc # print newline, word, and byte counts for each file
xargs # build and execute command lines from standard input
| # redirect standard output to another command
> # redirect standard output
< # redirect standard input
& # send process to background
~~~~

# Simple Shell [Shortcuts](https://intranet.alxswe.com/concepts/9 "Shortcuts"), Credit: Alx
~~~~
CTRL+A # go to beginning of line
CTRL+B # moves backward one character
CTRL+C # stops the current command
CTRL+D # deletes one character backward or logs out of current session
CTRL+E # go to end of line
CTRL+F # moves forward one character
CTRL+G # aborts the current editing command and ring the terminal bell
CTRL+K # deletes (kill) forward to end of line
CTRL+L # clears screen and redisplay the line
CTRL+N # next line in command history
CTRL+R # searches in your command history
CTRL+T # transposes two characters
CTRL+U # kills backward to the beginning of line
CTRL+W # kills the word behind the cursor
CTRL+Y # retrieves last deleted string
CTRL+Z # stops the current command, resume with fg in the foreground or bg in the background
~~~~

## Contributors
* [Koroworola Mauton](https://github.com/Kofoworola001 "Kofoworola001")
* [Kingsley Chika CHUKWU](https://github.com/KingVik-Planet "Kingsley Chika CHUKWU")
* Date:12/05/2023	
