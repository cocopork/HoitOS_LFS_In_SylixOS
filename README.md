# HoitOS_LFS_In_SylixOS

## 项目目的

​	这是一个残废的LFS。本项目是以SylixOS为内核设计的日志文件系统。它不支持目录、软链接和垃圾回收，目前也不支持读写。本项目的目的仅仅是熟悉文件系统在SylixOS挂载和其他文件操作过程。

​	这个LFS是针对mini2440板子上的NOR FLASH设计，该flash的大小只有2MB，但是实际上他并没有真正去操作NOR FLASH，而是用了fake_nor.c来模拟NOR FLASH的读取。

## 目前进度

1. 可实现指令mount，remove，touch，ls，umount。
2. TODO：文件读写