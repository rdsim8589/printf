#Holberton School Project - Rewrite Printf
## Description
This is a Holberton School partner project with @j-tyler and @rdsim8589. This project creates our version, _printf, of the C library function printf. Printf will load the data and converts them to character string and output to `stdout`. 

##How To Use
```
$ git clone git@github.com:j-tyler/printf.git
```
compile everything within the directory and use _printf instead of printf
```
$ gcc -Wall -Werror -Wextra -pedantic *.c
```
##Declarition
int _printf(const char *format, ...)

##Format tags
format tags must follow the format of [flags][width][.precision][length]specifier

| **specifier** | **output**                            |
|---------------|---------------------------------------|
| c             | characters                            |
| s		| string of characters                  |
| i or d        | signed decimal int                    |
| u             | unsigned decimal int                  |
| o             | signed octal                          |
| x             | unsigned hexadecimal int              |
| X             | unsigned hexadecimal int (Upper Case) |
| b             | Binary                                |
| p             | pointer address                       |


<table class="tg">
  <col width="45%">
  <col width="65%">
  <tr>
    <td><b>Flags</b></td>
    <td><b>Effected Specifers</b></td>
    <td><b>Description and Examples</b> </td>
  </tr>
  <tr>
    <td>-</td>
    <td>d, i, u, o, x, X, b, c, s</td>
    <td>
	Left justify</br>
	<code>_printf("A%3dlast", 5);</code></br>
	<code>_printf("A%-3dlast", 5);</code></br>
	output</br>
	<code>$ A  5last</code></br>
        <code>$ A5  last</code></br>
    </td>
  </tr>
  <tr>
    <td>+</td>
    <td>d, i</td>
    <td>
      Forces proceed to with a sign even if positive</br>
      <code>_printf("A%dlast", 5);</code></br>
      <code>_printf("A%+dlast", 5);</code></br>
    output</br>
      <code>$ A5last</code></br>
      <code>$ A+5last</code></br>
    </td>
  </tr>
  <tr>
    <td>(space)</td>
    <td>d, i</td>
    <td>
    if no sign is given, proceed with space
      <code>_printf("A%dlast", 5);</code></br>
      <code>_printf("A% dlast", 5);</code></br>
    output
      <code>$ A5last</code></br>
      <code>$ A 5last</code></br>
    </td>
  </tr>
  <tr>
    <td>#</td>
    <td>o, x, X </td>
    <td>
    Used with o, x or X specifiers the value is preceded with 0, 0x,or 0X respectively for values different than zero.
      <code>_printf("%o, 1");</code></br>
      <code>_printf("%#o, 1");</code></br>
    output
      <code>$1</code></br>
      <code>$01</code></br>
    </td>
  </tr>
  <tr>
    <td>0</td>
    <td>d, i, u, o, x</td>
    <td>
     left pad with spaces with 0
      <code>_printf("A%3dlast", 5);</code></br>
      <code>_printf("A%03dlast", 5);</code></br>
    output
      <code>$ A  5last</code></br>
      <code>$ A005last</code></br>
    </td>
  </tr>
</table>
##Completed Features
###Delimiters

#### digits `i, d`
