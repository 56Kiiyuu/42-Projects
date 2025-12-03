# Libft – Custom C Library (with Bonus)

This repository contains **Libft**, the first project of the 42 curriculum.  
The goal is to recreate a personal version of part of the standard C library, including essential functions for memory handling, string manipulation, and linked lists.

---

## About Libft

This project teaches the core concepts required for future 42 projects:

- Rewriting standard libc functions from scratch  
- Understanding how memory works in C  
- Manipulating pointers and arrays safely  
- Writing clean, reusable utility functions  
- Building a static library with a Makefile  

Libft will later be reused in projects like **ft_printf**, **get_next_line**, and **push_swap**.

---

## Repository Structure

```text
libft/
├── *.c            # All source files (mandatory + bonus)
├── libft.h        # Header file
├── Makefile       # Build rules (mandatory + bonus)
└── README.md
```
---
## Mandatory Part – Libc Functions

### Character checks
- ft_isalpha  
- ft_isdigit  
- ft_isalnum  
- ft_isascii  
- ft_isprint  

### Memory
- ft_memset  
- ft_bzero  
- ft_memcpy  
- ft_memmove  
- ft_memchr  
- ft_memcmp  
- ft_calloc  

### Strings
- ft_strlen  
- ft_strlcpy  
- ft_strlcat  
- ft_strchr  
- ft_strrchr  
- ft_strncmp  
- ft_strnstr  
- ft_strdup  

### Conversions
- ft_atoi  
- ft_itoa  

### Other
- ft_toupper  
- ft_tolower  

---

## Additional Functions

- ft_substr  
- ft_strjoin  
- ft_strtrim  
- ft_split  
- ft_strmapi  
- ft_striteri  

### File descriptor output
- ft_putchar_fd  
- ft_putstr_fd  
- ft_putendl_fd  
- ft_putnbr_fd  

---

## Bonus Part – Linked List Functions

- ft_lstnew  
- ft_lstadd_front  
- ft_lstadd_back  
- ft_lstsize  
- ft_lstlast  
- ft_lstdelone  
- ft_lstclear  
- ft_lstiter  
- ft_lstmap

"Build your own tools, and they will build the rest."
