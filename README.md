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
    <td>
    -
    </td>
    <td>
    d, i, u, o, x, X, b, c, s
    </td>
    <td>
	Left justify</br>
	  <code>
	    _printf("A%3dlast", 5);
	  </code></br>
	  <code>
	    _printf("A%-3dlast", 5);
	  </code></br>
	output</br>
	  <code>
	    $ A  5last
	  </code></br>
          <code>
            $ A5  last
      	  </code></br>
    </td>
  </tr>
  <tr>
    <td>
    +
    </td>
    <td>
    d, i
    </td>
    <td>
    Forces proceed to with a sign even if positive</br>
      <code>_printf("A%dlast", 5);</code></br>
      <code>_printf("A%+dlast", 5);</code></br>
    output</br>
      <code>$ A5last</code></br>
      <code>$ A+5last</code></br>
    </td>
  </tr>
</table>

| **flags** | **specifiers that it effects**        | **Description**                                                                                                                                                                       |
|-----------|---------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| -         | d, i, u, o, x, X, b, c, s             | Left justify  ``` _printf("A%3dlast", 5); _printf("A%-3dlast", 5); ``` output ``` $ A  5last $ A5  last ```                                                                           |
| +         | d, i                                  | Forces proceed to with a sign even if positive  ``` _printf("A%dlast", 5); _printf("A%+dlast", 5); ``` output ``` $ A5last $ A+5last ```                                              |
| (space)   | d, i                                  | if no sign is given, proceed with space ``` _printf("A%dlast", 5); _printf("A% dlast", 5); ``` output ``` $ A5last $ A 5last ```                                                      |
| #         | o, x, X                               | Used with o, x or X specifiers the value is preceded with  0, 0x,or 0X respectively for values different than zero. ``` _printf("%o, 1 ); _printf("%#o, 1); ``` output ``` $1 $01 ``` |
| 0         | d, i, u, o, x                         | left pad with spaces with 0 ``` _printf("A%3dlast", 5); _printf("A%03dlast", 5); ``` output ``` $ A  5last $ A005last ```                                                             |
| X         | unsigned hexadecimal int (Upper Case) |                                                                                                                                                                                       |
| b         | Binary                                |                                                                                                                                                                                       |
| p         | pointer address                       |                                                                                                                                                                                       |
|           |                                       |                                                                                                                                                                                       |     
##Completed Features
###Delimiters

#### digits `i, d`
