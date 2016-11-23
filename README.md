Holberton School Project - Rewrite Printf

Goal: rewrite the c implementation of printf with custom specifications. Modular design allows addition of specifications as needed.

Current implementation handles d, i, u, o, x, X, c, s, p the same as printf.
We also handle the flags +, -, 0, #, (space), and precision and width for strings and numbers.

Our custom specifiers:

b: Format the int as binary.
S: Format a string with unprintable characters replaced by Hex ie \n becomes '\x0A'.
r: Format a string reversed.
R: Format a string in ROT13.
