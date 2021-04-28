![codam logo](https://www.datocms-assets.com/4526/1560770259-logocodamblack-copy.svg)

## ❔ Basic Overview

`ft_printf(const char *, ...)` is a part of Codam (42 network) curriculum for 2020 cohort. The aim is to implement your own version of the libc’s `printf()`. 

The syntax is as follows: `%[🎌flags][:left_right_arrow: width][:black_circle: .precision][:straight_ruler: length][:abcd: type]`. Every specifier, apart from the type field (i.e. `c`, `s`) is optional.

## ❕ Mandatory Part

### 🎌 Flags

| Character | Description | Example | Output |
| --- | --- | --- | --- |
| - <br />(minus) | Left justify. | `printf("%-5s", "a")` | `a␣␣␣␣` |
| 0 <br />(zero) | When the 'width' option is specified, prepends zeros for numeric types. | `printf("%04X", 3)` | `0003` |

### :left_right_arrow: Width

| Character | Description | Example | Output |
| --- | --- | --- | --- |
| (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. | `printf("%5d", -7)` | `␣␣␣-7` |
| * <br />(asterisk) | The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. | `printf("%*d", 5, -7)` | `␣␣␣-7` |

### :black_circle: Precision

| Character | Description | Example | Output |
| --- | --- | --- | --- |
| .(number) | For integer specifiers (`d`, `i`, `o`, `u`, `x`, `X`) − precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of `0` means that no character is written for the value `0`. For `s` − this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. For `c` type − it has no effect. When no precision is specified, the default is `1`. If the period is specified without an explicit value for precision, `0` is assumed. | `printf("%.3s", "abcdef")` | `abc` |
| * <br />(asterisk) | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. | `printf("%.*s", 3, "abcdef")` | `abc` |

### :abcd: Type

| Character | Description |
| --- | --- |
| c | Print a single character. |
| s | Print a string of characters. | 
| p | Print a pointer to void in an implementation-defined format. | 
| d | Print a decimal (base 10) number. | 
| i | Print an integer in base 10. |
| u | Print an unsigned decimal (base 10) number. |
| x | Print a number in hexidecimal (base 16) in lower-case. |
| X | Print a number in hexidecimal (base 16) in upper-case. |
| % | Print a percent sign. |

## 🎰 Bonus Part

### 🎌 Flags

| Character | Description | Example | Output |
| --- | --- | --- | --- |
| #<br />(hash) | Used with `x` or `X` specifiers the value is preceded with `0x` or `0X` respectively for values different than zero. | `printf("%#x", 1)` | `0x1` |
| ␣<br />(space) | Prepends a space for positive signed-numeric types. positive = `␣`, negative = `-`. This flag is ignored if the `+` flag exists. | `printf("% -4d", 1)` | `␣␣␣1` |
| +<br />(plus) | Prepends a plus for positive signed-numeric types. positive = `+`, negative = `-`. | `printf("%+4d", 1)` | `␣␣+1` |

### :straight_ruler: Length

| Character | Description |
| --- | --- |
| hh | For integer types, causes `printf` to expect an int-sized integer argument which was promoted from a `char`. |
| h | For integer types, causes `printf` to expect an int-sized integer argument which was promoted from a `short`. |
| l | For integer types, causes `printf` to expect a `long`-sized integer argument. |
| ll | For integer types, causes `printf` to expect a `long long`-sized integer argument. |