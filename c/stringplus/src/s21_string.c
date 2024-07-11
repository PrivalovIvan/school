#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *p = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    if (p[i] == (unsigned char)c) {
      return (void *)&p[i];
    }
  }
  return s21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *s1 = (unsigned char *)str1;
  unsigned char *s2 = (unsigned char *)str2;

  while (n--) {
    if (*s1 != *s2) {
      return *s1 - *s2;
    }
    s1++;
    s2++;
  }
  return 0;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *dest2 = (unsigned char *)dest;
  unsigned char *src2 = (unsigned char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    dest2[i] = src2[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *s = (unsigned char *)str;

  for (s21_size_t i = 0; i < n; i++) {
    s[i] = c;
  }

  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *start = dest;
  while (*dest) dest++;
  while (n--) *dest++ = *src++;
  *dest = '\0';

  return start;
}

char *s21_strchr(const char *str, int c) {
  char *s = (char *)str;
  while (*s != '\0' && *s != (char)c) s++;
  if (*s != (char)c) s = s21_NULL;
  return s;
}

int s21_strncmp(const char *s1, const char *s2, s21_size_t n) {
  int res = 0;
  s21_size_t counter = n;

  while (counter > 1 && *s1 && *s2 && *s1 == *s2) {
    s1++;
    s2++;
    counter--;
  }

  if (n) res = *s1 - *s2;

  return res;
}

char *s21_strncpy(char *s1, const char *s2, s21_size_t n) {
  char *start = s1;
  s21_size_t i;
  for (i = 0; i < n && s2[i]; ++i) {
    s1[i] = s2[i];
  }
  while (i < n) {
    s1[i] = '\0';
    i++;
  }
  return start;
}

s21_size_t s21_strcspn(const char *s1, const char *s2) {
  s21_size_t counter = 0;
  for (; *s1 != '\0'; s1++) {
    if (!s21_strchr(s2, *s1)) {
      counter++;
    } else {
      break;
    }
  }

  return counter;
}

static const char *error[] = {"Undefined error: 0",
                              "Operation not permitted",
                              "No such file or directory",
                              "No such process",
                              "Interrupted system call",
                              "Input/output error",
                              "Device not configured",
                              "Argument list too long",
                              "Exec format error",
                              "Bad file descriptor",
                              "No child processes",
                              "Resource deadlock avoided",
                              "Cannot allocate memory",
                              "Permission denied",
                              "Bad address",
                              "Block device required",
                              "Resource busy",
                              "File exists",
                              "Cross-device link",
                              "Operation not supported by device",
                              "Not a directory",
                              "Is a directory",
                              "Invalid argument",
                              "Too many open files in system",
                              "Too many open files",
                              "Inappropriate ioctl for device",
                              "Text file busy",
                              "File too large",
                              "No space left on device",
                              "Illegal seek",
                              "Read-only file system",
                              "Too many links",
                              "Broken pipe",
                              "Numerical argument out of domain",
                              "Result too large",
                              "Resource temporarily unavailable",
                              "Operation now in progress",
                              "Operation already in progress",
                              "Socket operation on non-socket",
                              "Destination address required",
                              "Message too long",
                              "Protocol wrong type for socket",
                              "Protocol not available",
                              "Protocol not supported",
                              "Socket type not supported",
                              "Operation not supported",
                              "Protocol family not supported",
                              "Address family not supported by protocol family",
                              "Address already in use",
                              "Can't assign requested address",
                              "Network is down",
                              "Network is unreachable",
                              "Network dropped connection on reset",
                              "Software caused connection abort",
                              "Connection reset by peer",
                              "No buffer space available",
                              "Socket is already connected",
                              "Socket is not connected",
                              "Can't send after socket shutdown",
                              "Too many references: can't splice",
                              "Operation timed out",
                              "Connection refused",
                              "Too many levels of symbolic links",
                              "File name too long",
                              "Host is down",
                              "No route to host",
                              "Directory not empty",
                              "Too many processes",
                              "Too many users",
                              "Disc quota exceeded",
                              "Stale NFS file handle",
                              "Too many levels of remote in path",
                              "RPC struct is bad",
                              "RPC version wrong",
                              "RPC prog. not avail",
                              "Program version wrong",
                              "Bad procedure for program",
                              "No locks available",
                              "Function not implemented",
                              "Inappropriate file type or format",
                              "Authentication error",
                              "Need authenticator",
                              "Device power is off",
                              "Device error",
                              "Value too large to be stored in data type",
                              "Bad executable (or shared library)",
                              "Bad CPU type in executable",
                              "Shared library version mismatch",
                              "Malformed Mach-o file",
                              "Operation canceled",
                              "Identifier removed",
                              "No message of desired type",
                              "Illegal byte sequence",
                              "Attribute not found",
                              "Bad message",
                              "EMULTIHOP (Reserved)",
                              "No message available on STREAM",
                              "ENOLINK (Reserved)",
                              "No STREAM resources",
                              "Not a STREAM",
                              "Protocol error",
                              "STREAM ioctl timeout",
                              "Operation not supported on socket",
                              "Policy not found",
                              "State not recoverable",
                              "Previous owner died",
                              "Interface output queue is full"};

char *s21_strerror(int errnum) {
  static char result[512] = {'\0'};
  if (errnum <= -1 || errnum > 106) {
    sprintf(result, "Unknown error: %d", errnum);
  } else {
    s21_strcpy(result, (char *)error[errnum]);  //
  }
  return result;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t result = 0;
  while (*str != '\0') {
    str++;
    result++;
  }
  return result;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  for (int i = 0; str1[i] != '\0'; i++) {
    for (int j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        return (char *)(str1 + i);
      }
    }
  }
  return s21_NULL;
}

char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  if (c == 0) return "";
  while (*str) {
    if (*str == c) result = (char *)str;
    str++;
  }
  return result;
}

int s21_find_matches(const char *haystack, const char *needle) {
  while (*needle != '\0') {
    if (*needle != *haystack) {
      return 0;
    }
    needle++;
    haystack++;
  }
  return 1;
}

char *s21_strstr(const char *haystack, const char *needle) {
  if (!*needle) return (char *)haystack;
  char *result = s21_NULL;
  while (*haystack) {
    if (*needle == *haystack && s21_find_matches(haystack, needle)) {
      result = (char *)haystack;
      break;
    }
    haystack++;
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *result = 0;
  if (str) result = 0;
  static char *temp = 0;
  int i = 0;
  if (result) {
    while (*result) result++;
    while (!(*result) && result != temp) result++;
  }
  while (str && *str) {
    if (s21_strchr(delim, *str)) {
      if (i == 0) {
        while (str && *str && s21_strchr(delim, *str)) str++;
      } else
        *str = '\0';
    }
    i++;
    if (*str && !result) result = str;
    str++;
    if (!(*str)) temp = str;
  }
  if (result == temp) result = 0;
  return result;
}

void *s21_to_upper(const char *str) {
  char *temp = s21_NULL;
  if (str != s21_NULL) {
    int n = s21_strlen(str);
    temp = calloc(n + 1, sizeof(char));
    s21_strncpy(temp, str, n);
    temp[n] = '\0';
    for (int i = 0; i < n; i++) {
      if (temp[i] >= 97 && temp[i] <= 122) {
        temp[i] = temp[i] - 32;
      }
    }
  }
  return temp;
}

void *s21_to_lower(const char *str) {
  char *copy = s21_NULL;
  if (str != s21_NULL) {
    int b = s21_strlen(str);
    copy = calloc(b + 1, sizeof(char));
    s21_strncpy(copy, str, b);
    copy[b] = '\0';
    for (int i = 0; i < b; i++) {
      if (copy[i] >= 65 && copy[i] <= 90) {
        copy[i] = copy[i] + 32;
      }
    }
  }
  return copy;
}

//Возвращает новую строку, в которой указанная строка (str) вставлена в
//указанную позицию (start_index) в данной строке (src). В случае какой-либо
//ошибки следует вернуть значение NULL

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t src_len = 0, str_len = 0;
  char *new_s = s21_NULL;

  if (src != s21_NULL && str != s21_NULL) {
    while (src[src_len] != 0) src_len++;
    while (str[str_len] != 0) str_len++;

    if (start_index <= str_len) {
      new_s = calloc(src_len + str_len + 1, sizeof(char));
      s21_size_t i, j;
      for (i = 0; i < start_index; i++) {
        new_s[i] = src[i];
      }
      for (j = 0; j < str_len; j++, i++) {
        new_s[i] = str[j];
      }
      for (j = start_index; j < str_len; j++, i++) {
        new_s[i] = src[j];
      }
    }
  }
  return new_s;
}

//Возвращает новую строку, в которой удаляются все начальные и конечные
//вхождения набора заданных символов (trim_chars) из данной строки (src). В
//случае какой-либо ошибки следует вернуть значение NULL

void *s21_trim(const char *src, const char *trim_chars) {
  s21_size_t src_len = 0, start_index = 0, end_index = 0, i, j;
  char *new_s = s21_NULL;
  if (src != s21_NULL && trim_chars != s21_NULL) {
    while (src[src_len] != '\0') src_len++;
    end_index = src_len - 1;

    for (i = 0; i < src_len; i++) {
      for (j = 0; trim_chars[j] != '\0'; j++) {
        if (src[i] == trim_chars[j]) {
          start_index = i + 1;
          break;
        }
      }
      if (trim_chars[j] == '\0') break;
    }

    for (i = src_len - 1; i >= start_index; i--) {
      for (j = 0; trim_chars[j] != '\0'; j++) {
        if (src[i] == trim_chars[j]) {
          end_index = i - 1;
          break;
        }
      }
      if (trim_chars[j] == '\0') break;
    }

    new_s = calloc(end_index - start_index + 2, sizeof(char));
    if (new_s != s21_NULL) {
      for (i = start_index, j = 0; i <= end_index; i++, j++) {
        new_s[j] = src[i];
      }
    }
  } else if (src != s21_NULL && trim_chars == s21_NULL) {
    new_s = (char *)src;
  }
  return new_s;
}

char *s21_strcpy(char *dst, const char *src) {
  for (int i = 0; i < (int)s21_strlen(src); i++) {
    dst[i] = src[i];
  }
  dst[s21_strlen(src)] = '\0';
  return dst;
}
