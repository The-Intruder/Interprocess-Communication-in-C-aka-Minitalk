```text
        ##     ## #### ##    ## #### ########    ###    ##       ##    ##
        ###   ###  ##  ###   ##  ##     ##      ## ##   ##       ##   ##
        #### ####  ##  ####  ##  ##     ##     ##   ##  ##       ##  ##
        ## ### ##  ##  ## ## ##  ##     ##    ##     ## ##       #####
        ##     ##  ##  ##  ####  ##     ##    ######### ##       ##  ##
        ##     ##  ##  ##   ###  ##     ##    ##     ## ##       ##   ##
        ##     ## #### ##    ## ####    ##    ##     ## ######## ##    ##
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
this:

```bash
user@host$ ./client <PID> "lorem ipsum"
```

Now the trick here _(or the question)_ is in sending the messages from one
program to another, we'll do that using signals, you'll later understand what
I'm talking about, but for now, just keep on torturing your eyes with this
bull£%!§.

_**Note:** Errors MUST be CORRECTLY handled._

## Allowed functions and what they do

- `ssize_t write(int fd, const void *buf, size_t count);`

  - **Library:** `unistd.h`
  - **Description:** Not even gonna try explaining this one. C'mon, get your SH%! together
  - **Return Value:**
  - **Additional Notes:** you can view them by typing `man 2 write` on the terminal, don't be lazy.

- `int ft_printf(char *str, ...);`

  - **Library:** `libft.h` _(the one you made earlier in the common-core)_
  - **Description:** Ol' Reliable `printf`, but made by you, **i.e.** a crappy version of the original `printf` called `ft_printf`

- `void( *signal(int sig,void(*handler)(int))(int)`:

  - **Library:** `signal.h`
  - **Description:** What it basically does is that it keeps on listening for _specific_ incoming signals; and whenever they come, it calls the function _(passed as its 2nd argument)_ with the signal number as its argument. _**TL;DR**_ it executes a function whenever a signal is received
  - **Return Value:** It returns a
  - **Additional notes:** It doesn't _(necessarily)_ block other signals from arriving while the current handler is executing. And its behaviour varies between systems. As the linux _man_ describes it: _"The effects of `signal()` in a multi-threaded process are unspecified."_

- `sigemptyset()`

  - **Library:**
  - **Description:** lorem ipsum

- `sigaddset`

  - **Library:**
  - **Description:** lorem ipsum

- `int sigaction(int sig,const struct sigaction *act, struct sigaction *oldact)`

  - **Library:** `signal.h`
  - **Description:** Same as `signal()`, but much more recommended,
  - **Return Value:** It returns the value 0 if successful; otherwise the value -1 is returned and the global variable errno is set to indicate the error.
  - **Additional Notes:**

- `kill`

  - **Library:**
  - **Description:** lorem ipsum

- `pid_t getpid(void)`

  - **Library:** `unistd.h`
  - **Description:** When called, it simply returns the Process ID of the program that its being called from.
  - **Return Value:** The PID of the program
  - **Additionnal Notes:**

- `malloc`

  - **Library:**
  - **Description:** Allocates memory to the heap.

- `free`

  - **Library:**
  - **Description:** Frees allocated memory from heap

- `pause`

  - **Library:**
  - **Description:** lorem ipsum

- `sleep`

  - **Library:**
  - **Description:** You can think of it as an automatic Pause/Play function, you just give it how many seconds it should wait, and it does the rest for you

- `usleep`

  - **Library:**
  - **Description:** Just like `sleep`, but this one works with _mili-seconds_

- `exit`
  - **Library:**
  - **Description:** Exits a program with the _error code_ it was given as its parameter. Usually, we pass either the Macro `EXIT_SUCCESS` or the macro `EXIT_FAILURE`, both are declared in the `stdlib.h` library

### Additional fucntions _(not allowed in our project, but good to know if you're a nerd, no offense)_

- `int fork(void);`

  - **Library:** `unistd.h`
  - **Description:** This function splits the program into two distinct processes, and all the following code gets executed by the two processes _(the parent process or the main process, and the child process)_.
  - **Return Value:**
  - **Additionnal Notes:**

- `pid_t getpid(void)`

  - **Library:** `unistd.h`
  - **Description:** When called, it simply returns the Process ID of the program that its being e
  - **Return Value:**
  - **Additionnal Notes:**

- `()`

  - **Library:**
  - **Description:**
  - **Return Value:**
  - **Additionnal Notes:**

- `()`

  - **Library:**
  - **Description:**
  - **Return Value:**
  - **Additionnal Notes:**

- `()`
  - **Library:**
  - **Description:**
  - **Return Value:**
  - **Additionnal Notes:**

### What is `struct sigaction`

It's basicaly a structure defined in the `<signal.h>` library, that holds certain dta needed by certain functions to operate with signals.

It includes the following members:

1. `union __sigaction_u`:
   - `void (*__sa_handler)(int)`: `SIG_DFL`, `SIG_IGN`, or a pointer to a signal-handling function.
   - `void (*__sa_sigaction)(int, siginfo_t *, void *)`: Pointer to a signal-handling function if `sa_flags` is set to `SA_SIGINFO`.

2. `sa_mask`: .
3. `sa_flags`: Special flags to affect behavior of signal.

### The proper way to terminate a program on signal catching

The following may not be that useful in our program, but it is good to know overall.

So whenever we have a program that listenes for some signals, we always have some code that needs to be executed while the signal is not received yet, so what if we wanted the program to terminate itself as soon as the signal is received, the most obvious choice is to have an `exit()` in our `handler()` function, but that will discard any unexecuted code, because as we know, the handler gets called as soon as the signal is received, so the code after the `signal` or `sigaction` function may not be properly executed.

To avoid that, we declare a **global** variable of type `sig_atomic_t`