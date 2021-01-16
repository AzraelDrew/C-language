## 使用 GDB 命令行调试器调试 C 程序

- 安装 gcc

```
sudo apt install gcc

```

- 安装 GDB

```
sudo apt install gdb

```

- 编译代码

```
#必须使用 -g来编译程序 这样可执行程序才能通过GDB来运行
gcc -g test.c -o test
```

- 调试

```
#使用”-tui“选项可以将代码显示在一个漂亮的交互式窗口内（所以被称为“文本用户界面 TUI”），在这个窗口内可以使用光标来操控，同时在下面的GDB shell中输入命令。

gdb -tui test

```

- 设置断点

```
break [行号]
break 11

break [行号] if [条件]
break 11 if i > 97
```

- 观察断点

```
“观察断点”，当这个被观察的变量发生变化时，程序会被停止

watch [变量]
watch d
```

- 回溯

```
回溯功能（backtrace）可以让我们知道程序如何到达这条语句的

bt
```

- 查看所有变量值

```
这条语句会显示所有的局部变量以及它们的值（你可以看到，我没有为ｄ设置初始值，所以它现在的值是任意值）

info locals
```

- 查看一个变量的值

```
这个命令可以显示特定变量的值

p [变量]
```

- 查看变量类型

```
ptype [变量]
```

- 设置变量的值

```
这样会覆盖变量的值。不过需要注意，你不能创建一个新的变量或改变变量的类型

set var [变量] = [新的值]
```

- 单步调试

```
step
```

- 运行下一条语句

```
next
```

- 删除断点

```
delete [行号]
```

- 继续运行程序

```
continue
```

- 退出 GDB

```
quit
```

### 注意:

- 当设置断点后，使用"run"命令开始运行程序
- GDB 中，大多数的命令单词都可以简写为一个字母
- Update Url
