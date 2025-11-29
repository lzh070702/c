# 函数
## 系统调用函数
### open()函数
> open()调用既能打开一个业已存在的文件，也能创建并打开一个新文件。

1. 函数原型
```c
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *pathname,int flags,mode_t mode)
```
2. 函数参数
* pathname:文件路径
* flags：打开方式
  * O_RDONLY：以只读方式打开文件（0）
  * O_WRONLY：以只写方式打开文件（1）
  * O_RDWR：以读写方式打开文件（2）
    > 三选一（必写）
  * ...（其他方式）
    > 多个方式之间用 | （按位与）拼接
* mode:文件权限
  > 仅在O_CREAT时填写（创建新文件时需要指明权限）
3. 函数返回值
* 失败：返回-1并设置errno
* 成功：返回fd（>=3）
  > 文件描述符
  
  |文件描述符|用途|POSIX名称|stdio流|
  |--|--|--|--|
  |0|标准输入|STDIN_FILENO|stdin|
  |1|标准输出|STDOUT_FILENO|stdout|
  |2|标准错误|STDERR_FILENO|stderr|
### read()函数
> read()系统调用从文件描述符 fd 所指代的打开文件中读取数据。 
1. 函数原型
```c
#include <unistd.h>

ssize_t read(int fd, void *buf, size_t count);
```
2. 函数参数
