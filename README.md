```text
	      :::::::::  ::::::::::     :::     :::::::::    :::   :::   :::::::::: 
	     :+:    :+: :+:          :+: :+:   :+:    :+:  :+:+: :+:+:  :+:         
	    +:+    +:+ +:+         +:+   +:+  +:+    +:+ +:+ +:+:+ +:+ +:+          
	   +#++:++#:  +#++:++#   +#++:++#++: +#+    +:+ +#+  +:+  +#+ +#++:++#      
	  +#+    +#+ +#+        +#+     +#+ +#+    +#+ +#+       +#+ +#+            
	 #+#    #+# #+#        #+#     #+# #+#    #+# #+#       #+# #+#             
	###    ### ########## ###     ### #########  ###       ### ##########      
```

***

# Preface

This project is NOT quite straight-forward, and I haven't found any ressource 
that explains this in a clear way, as a matter of fact, I haven't found any
ressource that explains this project at all, so I thought to myself "Well 
there's always a first time for everything, so why not do it youself!!". And 
that is how I made the horrible thing that you're about to read, so be ready, 
and prepare yourself for you're about to lay your eyes on the most terrible 
project documentation ever. You've been warned.

***P.S.:** If there is anything that you don't like about this `README.md` or if
something is not quite right, please feel free to hit me up with a DM, either on
Twitter, IG, or just by shouting my name out loud three times, and I'll 
immediatly spawn in front of you, I kid you not.*

***

# Project Description

From what I understood, this project is all about sending messages from one 
program to another. In our case, the program that sends the messages should 
be called `client`, and the program that'll receive the messages should be called
`server`.

The `server` should print its **PID** *(Process ID)* when launched, and keep on 
waiting for signals to catch, until it gets interrupted either by the user or by
an error.

Launching the `client` executable must be *(after the `server` got launched, and)
*followed by the `server`'s PID and the string that we want to send, just like 
this:

```bash
user@host$ ./client <PID> "lorem ipsum"
```

Now the trick here *(or the question)* is in sending the messages from one 
program to another, we'll do that using signals, you'll later understand what 
I'm talking about, but for now, just keep on torturing your eyes with this 
bull£%!§.

***Note:** Errors MUST be CORRECTLY handled.*

## Allowed functions and what they do

| Function | Description |
| -------- | ----------- |

| `write`  | Not even gonna try explaining this one. C'mon, get your SH%! 
together |

| `ft_printf` | Ol'reliable `printf`, but made by you, i.e. a crappy version of 
the original `printf` called `ft_printf` |

| `signal` | Prototyped `void (*signal(int sig, void (*func)(int)))(int)`, what 
it basically does is that it keeps on listening for incoming SPECIFIC signals, 
and whenever they come, it calls the function *(passed as its 2nd argument)* 
with the signal number as its argument. **TL;DR** it executes a function wheneve
a signal is received |

| `sigemptyset` |  |

| `sigaddset` |  |

| `sigaction` |  |

| `kill` |  |

| `getpid` |  |

| `malloc` |  |

| `free` |  |

| `pause` |  |

| `sleep` |  |

| `usleep` |  |

| `exit` |  |

