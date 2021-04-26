![codam logo](https://www.datocms-assets.com/4526/1560770259-logocodamblack-copy.svg)

## ❔ Basic Overview

`ft_printf(const char *, ...)` is a part of Codam (42 network) curriculum for 2020 cohort. The aim is to implement your own version of the libc’s `printf()`. 

## ❕ Mandatory Part

### 🎌 Flags

| Character | Description | Example | Result |
| --- | --- | --- | --- |
| - <br />(minus) | Left justify. | `printf("%-5s", "a")` | `a␣␣␣␣` |
| 0 <br />(zero) | When the 'width' option is specified, prepends zeros for numeric types. | `printf("%04X", 3)` | `0003` |

### :left_right_arrow: Width

| Character | Description | Example | Result |
| --- | --- | --- | --- |
| (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. | `printf("%5d", -7)` | `␣␣␣-7` |
| * <br />(asterisk) | The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. | `printf("%*d", 5, -7)` | `␣␣␣-7` |

### :black_circle: Precision

| Character | Description | Example | Result |
| --- | --- | --- | --- |
| .(number) | For integer specifiers (`d`, `i`, `o`, `u`, `x`, `X`) − precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of `0` means that no character is written for the value `0`. For `s` − this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. For `c` type − it has no effect. When no precision is specified, the default is `1`. If the period is specified without an explicit value for precision, `0` is assumed. | `printf("%.3s", "abcdef")` | `abc` |
| * <br />(asterisk) | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. | `printf("%.*s", 3, "abcdef")` | `abc` |