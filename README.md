***

_**README.md** not yet finished_

***

```text
	.___  ___.  __  .__   __.  __  .___________.    ___       __       __  ___ 
	|   \/   | |  | |  \ |  | |  | |           |   /   \     |  |     |  |/  / 
	|  \  /  | |  | |   \|  | |  | `---|  |----`  /  ^  \    |  |     |  '  /  
	|  |\/|  | |  | |  . `  | |  |     |  |      /  /_\  \   |  |     |    <   
	|  |  |  | |  | |  |\   | |  |     |  |     /  _____  \  |  `----.|  .  \  
	|__|  |__| |__| |__| \__| |__|     |__|    /__/     \__\ |_______||__|\__\ 
                                                                           
```
---

# Preface

This project is NOT quite straight-forward, and I haven't found any ressource
that explains it in a clear way, as a matter of fact, I haven't found any
ressource that explains this project at all, so I thought to myself "Well
there's always a first time for everything, so why not do it youself!!". And
that is how I made the horrible thing that you're about to read, so be ready,
and prepare yourself for you're about to lay your eyes on the most terrible
project documentation ever. You've been warned.

_**P.S.:** If there is anything that you don't like about this `README.md` or if
something is not quite right, please feel free to hit me up with a DM, either on
Twitter, IG, or just by shouting my name out loud three times, and I'll
immediatly spawn in front of you, I kid you not._

---

## Project Description

From what I understood, this project is all about sending messages from one
program to another. In our case, the program that sends the messages should
be called `client`, and the program that'll receive the messages should be called
`server`.

The `server` should print its **PID** _(Process ID)_ when launched, and keep on
waiting for signals to catch, until it gets interrupted either by the user or by
an error.

Launching the `client` executable must be *(after the `server` got launched, and)
*followed by the `server`'s PID and the string that we want to send, just like
this*:

```bash
user@host$ ./client <PID> "lorem ipsum"
```

Now the trick here _(or the question)_ is in sending the messages from one
program to another, we'll do that using signals, you'll later understand what
I'm talking about, but for now, just keep on torturing your eyes with this
bull£%!§.

_**Note:** Errors MUST be CORRECTLY handled._

## Allowed functions and what they do

```c
/* ------------------------------ Prototypes -------------------------------- */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ssize_t	write(int fd, const void *buf, size_t count);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int	ft_printf(const char *str, ...);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void	*signal(int sig, void *handler)(int);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int	sigemptyset(sigset_t *set);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int	sigaddset(sigset_t *set, int signo);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int	sigaction(int sig, const struct sigaction *act, struct sigaction *oldact);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int	kill(pid_t pid, int sig);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
pid_t	getpid(void);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void	*malloc(size_t size);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void	free(void *ptr);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int	pause(void);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
unsigned int	sleep(unsigned int seconds);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int	usleep(useconds_t microseconds);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void	exit(int status);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
```

| Function |   Library    | Return Value | Description |
| :------------- | :----------: | :----------- | :---------- |
|     **write**      | `<unistd.h>` | Number of written bytes on _SUCCESS_, `-1` on _FAILURE_. | Not even gonna try explaining this one. C'mon, get your SH%! together. You can view everything about it by typing `man 2 write` on the terminal, don't be lazy. |
|     **ft_printf**      | `"libft.h"` _(the one you made earlier in the common-core)_ | It really just depends on how you've coded it. | Ol' Reliable `printf`, but made by you, **i.e.** a crappy version of the original `printf` called `ft_printf`. |
|     **signal**      | `<signal.h>` | Lorem Ipsum | It executes a function whenever a signal is received. It doesn't _(necessarily)_ block other signals from arriving while the current handler is executing |
|     **sigemptyset**      | `<signal.h>` | Returns 0 on _SUCCESS_|  takes a declared variable of type `sigset_t`, initializes the to empty, it is somwhat similar to `bzero()` or `memset(0)`.|
|     **sigaddset**      | `<signal.h>` | Returns 0 on _SUCCESS_, -1 on _FAILURE_ |  Adds a signal to the set of signals already recorded in a variable of type `sigset_t`. |
|     **sigaction**      | `<signal.h>` | Returns 0 on _SUCCESS_, -1 on _FAILURE_. | Same as `signal()`, but much more recommended., it takes three args, as you can see. The first one is the _Signal_ to expect, the 2nd and the 3rd one is a struct of type `sigaction`. More on that later. |
|     ****      | Lorem Ipsum | Lorem Ipsum | Lorem Ipsum |
|     **7**      | `unistd.h` | The PID of the program | When called, it simply returns the Process ID of the program that its being called from. |
|     **8**      | Lorem Ipsum | Lorem Ipsum | Lorem Ipsum |
|     **9**      | Lorem Ipsum | Lorem Ipsum | Lorem Ipsum |
|     **10**     | Lorem Ipsum | Lorem Ipsum | Lorem Ipsum |
|     **11**     | Lorem Ipsum | Lorem Ipsum | Lorem Ipsum |
|     **12**     | Lorem Ipsum | Lorem Ipsum | Lorem Ipsum |
|     **13**     | Lorem Ipsum | Lorem Ipsum | Exits a program with the _error code_ it was given as its parameter. Usually, we pass either the Macro `EXIT_SUCCESS` or the macro `EXIT_FAILURE`, both are declared in the `stdlib.h` library |

### Additional functions _(not allowed in our project, but useful to know)_

```c
/* ------------------------------ Prototypes -------------------------------- */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int fork(void);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
```

| Function Index |   Library    | Return Value | Description |
| :------------- | :----------: | :----------- | :---------- |
|     **1**      | `<unistd.h>` |  | This function splits the program into two distinct processes, and all the following code gets executed by the two processes _(the parent process or the main process, and the child process)_. |

### What is `struct sigaction`

It's basicaly a structure defined in the `<signal.h>` library, that holds certain dta needed by certain functions to operate with signals.

It includes the following members:

1. `union __sigaction_u`:
   - `void (*__sa_handler)(int)`: _defined as macro `sa_handler`_
     - `SIG_DFL` _(default behaviour of the signal)_, `SIG_IGN` _(Ignore the signal)_, or a pointer to a signal-handling function.
   - `void (*__sa_sigaction)(int, siginfo_t *, void *)`: _defined as macro `sa_sigaction`_
     - Pointer to a signal-handling function if `sa_flags` is set to `SA_SIGINFO`.

2. `sa_mask`: Set of signals to be blocked _(pended)_ while the handler is still running.
3. `sa_flags`: Special flags that affect the behavior of the signal.

### The proper way to terminate a program on signal catching

The following may not be that useful in our program, but it is good to know overall.

So whenever we have a program that listenes for some signals, we always have some code that needs to be executed while the signal is not received yet, so what if we wanted the program to terminate itself as soon as the signal is received, the most obvious choice is to have an `exit()` in our `handler()` function, but that will discard any unexecuted code, because as we know, the handler gets called as soon as the signal is received, so the code after the `signal` or `sigaction` function may not be properly executed.

To avoid that, we declare a **global** variable of type `sig_atomic_t`