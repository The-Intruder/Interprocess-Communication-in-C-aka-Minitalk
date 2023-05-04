<br/>
<p align="center">
  <a href="https://github.com/The-Intruder/Interprocess-Communication-in-C-aka-Minitalk">
    <img src="https://img.icons8.com/cotton/512/binary-file.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Interprocess Communication in C <em>(Minitalk)</em></h3>

  <p align="center">
    A simple client-server communication program implemented in C, which allows for the exchange of messages between a client and server over a network using only Unix signals.
    <br/>
    <br/>
    <a href="https://github.com/The-Intruder/Interprocess-Communication-in-C-aka-Minitalk/issues">Report Bug</a>
    .
    <a href="https://github.com/The-Intruder/Interprocess-Communication-in-C-aka-Minitalk/issues">Request Feature</a>
  </p>
</p>

<div  style="display: flex; justify-content: center;">
<a  href="https://twitter.com/i_am_amine" target="_blank">
  <img  alt="Twitter Follow"  src="https://img.shields.io/twitter/follow/i_am_amine?style=social">
</a>
<img  src="https://img.shields.io/github/repo-size/The-Intruder/Interprocess-Communication-in-C-aka-Minitalk"  alt="Repo Size">
<img  src="https://img.shields.io/github/last-commit/The-Intruder/Interprocess-Communication-in-C-aka-Minitalk"  alt="Last Commit">
<img  src="https://img.shields.io/github/license/The-Intruder/Interprocess-Communication-in-C-aka-Minitalk" alt="License" >
<img  src="https://img.shields.io/badge/Made%20with-❤-1f425f.svg"  alt="made-with-love">
</div>


## Table Of Contents

- [Table Of Contents](#table-of-contents)
- [About The Project](#about-the-project)
- [Built With](#built-with)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
- [Usage](#usage)
- [Roadmap](#roadmap)
- [Contributing](#contributing)
  - [Creating A Pull Request](#creating-a-pull-request)
- [License](#license)
- [Authors](#authors)
- [Acknowledgements](#acknowledgements)

## About The Project

As said before, Minitalk is a client-server communication program implemented in C. It allows for the exchange of messages between a client and server over a network using only signals.

The goal of the Minitalk project is to demonstrate interprocess communication (IPC) using signals in Unix-like systems. It showcases how two separate processes, the client and the server, can establish a reliable communication channel using signals to transmit data.

The Minitalk project consists of two main components:

- **Server:** The server is responsible for receiving messages from the client and displaying them. It waits for incoming signals from the client, decodes the binary data, and prints the corresponding message to the console.

- **Client:** The client is responsible for sending messages to the server. It takes user input, converts it to binary data, and transmits it to the server using signals.

The communication between the client and server is achieved through the use of UNIX signals, specifically `SIGUSR1` and `SIGUSR2`. The bits of the message are encoded as a series of signals, where `SIGUSR1` represents a binary 1 and `SIGUSR2` represents a binary 0.

The Minitalk project provides an interesting opportunity to explore the concepts of signals, signal handling, binary encoding, and interprocess communication in a practical manner. It showcases how signals can be leveraged to establish a lightweight and efficient communication mechanism between processes, while gaining valuable insights into low-level system programming, signal handling techniques, and the challenges of synchronization and data integrity in interprocess communication.

## Built With

The Minitalk project is built using the following technologies and concepts:

- **C Programming Language:** The entire project is implemented in the C programming language, leveraging its low-level capabilities and system APIs for signal handling and interprocess communication.

- **UNIX Signals:** The communication between the client and server in Minitalk is achieved through the use of UNIX signals. The SIGUSR1 and SIGUSR2 signals are utilized to represent binary data for message transmission.

- **Unix-like Systems:** The project is designed to run on Unix-like systems such as Linux and macOS, which provide the necessary system APIs for signal handling and interprocess communication.

## Getting Started

These instructions will guide you on how to get the Minitalk project up and running on your local machine. The following steps assume you are using a Unix-like system.

### Prerequisites

Before running the Minitalk project, ensure that you have the following prerequisites installed:

- **GCC:** The GNU Compiler Collection (GCC) is required to compile the C source code. You can install GCC using package managers like `apt` or `brew` based on your operating system.

## Usage

Follow these steps to install and run the Minitalk project:

1. Clone the project repository:

```bash
git clone https://github.com/The-Intruder/Interprocess-Communication-in-C-aka-Minitalk minitalk
```

2. Change into the project directory:

```bash
cd minitalk
```

3. Compile the source code using the Makefile:

```bash
make bonus
```

4. Run the server:

```bash
./server
```

5. Run the client in a separate terminal window or tab:

```bash
./client <SERVER_PID> <MESSAGE>
```

  - Replace `<SERVER_PID>` with the process ID of the server (printed when the server starts), and `<MESSAGE>` with the message you want to send.

  - ***Note:** You can open a new terminal window or tab by pressing `Ctrl+Shift+T` (Linux) or `Command+T` (macOS).*

6. Observe the message being received and displayed by the server.

Congratulations! You have successfully set up and run the Minitalk project on your local machine.

## Roadmap

This roadmap outlines the key milestones and potential future enhancements for the Minitalk project:

- **Basic Client-Server Communication:** Implement the basic functionality of the client and server, allowing for the exchange of messages using signals.

- **Error Handling and Validation:** Enhance the project by implementing error handling and input validation to ensure robustness and prevent unexpected behavior.

- **Signal Handling:** Refine the signal handling mechanism to handle edge cases, such as signal interruptions, signal queuing, and signal blocking.

- **Large Message Support:** Modify the project to support the transmission of large messages by dividing them into smaller chunks and sending them sequentially.

- **Encryption and Security:** Explore methods to enhance the security of the communication channel, such as implementing encryption algorithms to secure message transmission.

- **Performance Optimization:** Analyze the performance of the project and identify areas for optimization, such as reducing signal latency, minimizing resource usage, and improving overall efficiency.

- **Cross-Platform Support:** Adapt the project to be compatible with different operating systems and platforms, broadening its usability and reach.

The roadmap provides a general outline of the potential future steps for the Minitalk project.

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

- If you have suggestions for adding or removing projects, feel free to [open an issue](https://github.com/The-Intruder/Interprocess-Communication-in-C-aka-Minitalk/issues/new) to discuss it, or directly create a pull request after you edit the _README.md_ file with necessary changes.
- Please make sure you check your spelling and grammar.
- Create individual PR for each suggestion.

### Creating A Pull Request

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

Distributed under the **GPL-3** License. See [LICENSE](https://github.com/The-Intruder/Interprocess-Communication-in-C-aka-Minitalk/blob/main/LICENSE.md) for more information.

## Authors

- **Mohamed Amine Naimi** aka ***[The-Intruder](https://github.com/The-Intruder/)*** - _Computer Science Student_ - *Built the Minitalk project*

## Acknowledgements

- [The-Intruder](https://github.com/The-Intruder/)

<!--
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
-->
