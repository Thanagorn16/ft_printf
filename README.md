# ft_printf

A custom implementation of the standard C `printf` function, designed to replicate its behavior and formatting capabilities.

---

## 📌 Project Description

`ft_printf` is a project developed as part of the **42 School** curriculum, aiming to reimplement the standard C `printf` function. This project enhances understanding of variadic functions, format specifiers, and output formatting in C.

The primary objectives of this project are:

- To create a function that mimics the behavior of `printf`.
- To handle various format specifiers for different data types.
- To manage variable argument lists using `stdarg.h`.

### ✨ Technologies Used

- **C language** – For low-level system programming.
- **Make** – For build automation via a `Makefile`.

### 💡 Challenges Faced

- Handling variable argument lists and ensuring type safety.
- Implementing various format specifiers and ensuring accurate output.
- Managing buffer overflows and ensuring memory safety.


---

## 📖 Table of Contents

- [Project Description](#project-description)
- [How to Install and Run the Project](#how-to-install-and-run-the-project)
- [How to Use the Project](#how-to-use-the-project)
- [File Structure & Descriptions](#file-structure--descriptions)

---

## 🛠 How to Install and Run the Project

To compile and use the `ft_printf` library, follow these steps:

```bash
# Clone the repository
git clone https://github.com/Thanagorn16/ft_printf.git
cd ft_printf

# Build the library
make
```
---
## 📁 File Structure & Descriptions
Each file in this repository serves a specific purpose in the implementation of `ft_printf`:

* `ft_printf.c` – Contains the main ft_printf function, handling the parsing of format strings and coordinating the printing process.

* `ft_printf.h` – The main header file containing function prototypes, macro definitions, and necessary includes.

* `print_hexs.c` – Handles the formatting and printing of hexadecimal numbers.

* `print_nums.c` – Manages the formatting and printing of numeric values, including integers and unsigned numbers.

* `print_strs.c` – Deals with the formatting and printing of string and character data.

* `Makefile` – Automates the compilation and cleaning processes for the project.

---
