# 0x16. C - Simple Shell

## Description
In this project we are creating our own simple UNIX command interpreter. The program must have the exact same output as sh (/bin/sh) as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your argv[0].

## Usage
- Enter custom shell by typing "./hsh". You should be prompted with a ($).
- Type a command of your liking and press "Enter".
- Appropriate output will appear.
- Prompt reappears and awaits your next command.
- Exit shell by typing "exit"

## Installation
### Clone the repository. Compile the ".c" files. Run executable.
```
$ git clone https://github.com...
```

## Compilation
### Enter the following command to compile:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Example
### Interactive Mode
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

### non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
### Files
 | File | Description |
 | ------------- | ------------- |
 | main.c | entry point of shell
 | main.h | headers file
 | prompt.c | function which display the prompt on terminal
 | printerror.c | function which dislpay the error message
 | shell_loop.c | function which call others functions

## Project Requirements
- All your files will be compiled on Ubuntu 14.04 LTS
- Your C programs and functions will be compiled with gcc 4.8.4 using th- e flags -Wall -Werror -Wextra and -pedantic
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-s- tyle.pl and betty-doc.pl
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to

## Tasks