linux编译c的静态库(libcfun.a)，再编译C++的动态库(libclassfun.so)调用libcfun.a，最后编译在main(cpp文件)中调用.so动态库中类的成员函数。

linux下使用动态库步骤：

==============================================================
1. linux下动态库(.so)文件默认的查找路径：/lib和/usr/lib和/usr/local/lib 里的库直接用-l参数就能链接。

==============================================================
2. 如果库文件没放在这三个目录里，而是放在其他目录里，就需要使用-L参数，后面跟着的是库文件所在的目录名；

==============================================================
3. 程序编译连接，程序运行都需要知道动态库所在位置。"-L"参数可以指定编译连接时的库文件路径，无法提供程序运行时库文件的路径。可以采用下面方法来提供:

(方法1)使用环境变量LD_LIBRARY_PATH,命令如下：
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/yangxt/demo

(方法2)将所用到的动态库文件放到/usr/lib目录下；

(方法3)可以在/usr/lib目录下创建软连接，连接到你自己目录下的动态库，命令如下：
ln -s /home/yangxt/demo/libmydyn.so /usr/lib/libmydyn.so 	# ln -s 源文件 目标文件
这样就在/usr/lib目录下创建了一个指向/home/yangxt/demo/libmydyn.so动态库的软连接；

(方法4)修改"vi /etc/ld.so.conf"文件,添加你自己的动态库文件路径，内容如下：
include ld.so.conf.d/*.conf
/home/yangxt/demo 	#你自己的动态库文件路径
添加完成之后，使用"ldconfig"重新加载配置文件使之生效。

==============================================================
4. 使用linux系统下安装的其他gcc编译器，只需要在makefile文件中指定变量"CC"的值即可，如：
CC=/usr/local/arm/4.3.2/bin/arm-linux-gcc

==============================================================
5.
(1)在一种计算机环境中运行的编译程序，能编译出在另外一种环境下运行的代码，我们就称这种编译器支持交叉编译。这个编译过程就叫交叉编译。

(2)使用交叉编译工具(如arm-linux-gcc)编译出来的.so动态库，使用这个动态库的程序也需要在相同的编译环境下编译(arm-linux-gcc),否则会编译不成功：
/usr/bin/ld: skipping incompatible /usr/lib/libxxx.so when searching for -lxxx

(3)使用交叉编译工具arm-linux-gcc编译出来的程序(以连接 用arm-linux-gcc编译的.so动态库)，需要在arm平台上运行。否则报错：
bash: ./xxxx: cannot execute binary file

==============================================================


