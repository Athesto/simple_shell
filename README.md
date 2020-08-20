# Basic Shell

## What it's about:
We're creating our own Shell, it's part of the Holberton School projects.

---
## Autorized fuctions and macros:
* `chdir (man 2 chdir)`
* `execve (man 2 execve)`
* `exit (man 3 exit)`
* `fork (man 2 fork)`
* `free (man 3 free)`
* `getline (man 3 getline)`
* `isatty (man 3 isatty)`
* `malloc (man 3 malloc)`
* `perror (man 3 perror)`
* `signal (man 2 signal)`
* `stat (__xstat) (man 2 stat)`
* `strtok (man 3 strtok)`
* `wait (man 2 wait)`
* `write (man 2 write)`

---
## Content
---

### *How is it composed?*

- **PID & PPID**

A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process’ ID, getpid (man 2 getpid)

- **Arguments**

The command line arguments are passed through the main function: int main(int ac, char **av);

av is a NULL terminated array of strings
ac is the number of items in av
av[0] usually contains the name used to invoke the current program. av[1] is the first argument of the program, av[2] the second, and so on.

- **Executing a program**

The system call execve allows a process to execute another program (man 2 execve). Note that this system call does load the new program into the current process’ memory in place of the “previous” program: on success execve does not return to continue the rest of the “previous” program.

- **Creating processes**

The system call fork (man 2 fork) creates a new child process, almost identical to the parent. Once fork successfully returns, two processes continue to run the same program, but with different stacks, datas and heaps.

- **Wait**

The wait system call (man 2 wait) suspends execution of the calling process until one of its children terminates.


- **File information**

The stat (man 2 stat) system call gets the status of a file (If it exists or not). On success, zero is returned. On error, -1 is returned.

- **Environment**

Environment variables are “stored”. The list is an array of strings, with the following format: var=value, where var is the name of the variable and value its value.

-----
## How the shell works?

The shell reads its standard input from your terminal, and sends its standard output and standard error back to your terminal unless you tell it to send them elsewhere. Is line oriented; it does not process your commands until you press *Enter* to indicate the end of a line.

The shell splits the line into tokens. A token is a command, variable, or other symbol recognized by the shell. It continues to build up a sequence of tokens until it comes to a reserved word function name, or operator.


![Shell Example](Assest/Shell.png)

---
## Example
----

### **Non-Interactive mode**
```bash
echo "[command]" | ./hsh
```
-----
### **Interactive mode**
```bash
./hsh

$ ls
```
Output:
```
0-strcat.c  9-strcpy.c  Shell.png         _exec_cmd.c  _isanum.c   a.out    hack         makefile            sh-check.sh     tmp
1-strdup.c  AUTHORS     _atoi.c           _getline.c   _putchar.c  betty.1  holberton.h  man_1_simple_shell  simple_shell.c  tst.sh
3-strcmp.c  README.md   _builtins_func.c  _getpath.c   _puts.c     cmd      hsh          noexe               test            write.2.gz
```
-----
```bash
$ echo Holberton
```
Output:
```
Holberton
```
----
```bash
$ env

$ pwd

$ /bin/ls
```

## How install
---
Copy this link and paste in you terminal with the **git clone** option
```
git clone git@github.com:julianamonr03/simple_shell.git
```
**TIP**

Once you done installing it you are able to write *make build* in your terminal and the shell will be running by then.

----
## AUTHORS
 Gustavo Mejía
 [@Athesto](https://github.com/Athesto)
 Twitter:
 [@im_tavo](https://twitter.com/im_tavo)

 Juliana Monroy
 [@julianamonr03](https://github.com/julianamonr03)
 Twitter:
 [@julianamonroy03](https://twitter.com/julianamonroy03)
----
