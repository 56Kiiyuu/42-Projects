# ft_printf – Custom Printf Implementation

This repository contains my implementation of **ft_printf**, a recreation of the standard C `printf` function as part of the 42 curriculum.  
The goal of this project is to handle formatted output without relying on the original libc version.

---

## Repository Structure

```text
ft_printf/
├── ft_printf.c        # Core printf logic + dispatcher
├── ft_printf.h        # Header file
├── ft_printchar.c     # Handles %c
├── ft_printstr.c      # Handles %s
├── ft_printnbr.c      # Handles %d / %i
├── ft_printuint.c     # Handles %u
├── ft_printhex.c      # Handles %x / %X
├── ft_printptr.c      # Handles %p
├── ft_printper.c      # Handles %%
├── libft/             # (Optional) Libft used by ft_printf
├── Makefile           # Build rules
└── main.c             # Testing file (not evaluated by 42)
```
"Reinvent the wheel to learn how it rolls."
