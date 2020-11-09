# VScode_CMake_Setting
VSCode下C++项目编译调试框架（CMake）

🆔VScode所需要插件：
c/c++
c++intellisense
cmark
cmarktools

文件结构分为五部分，.vscode文件夹存放配置文件。build文件夹存放中间生成的静态库、临时文件、可执行文件等，可直接删除，避免了对源程序的污染。src文件存放cpp源程序。最后为主程序main.cpp以及对应的cmakelists.txt文件。
程序将cpp源程序和main.cpp分开存放，事实上，可直接合并到src文件夹中.这样只写一个cmakelists.txt文件即可。

✅launch.json：
"miDebuggerPath" 一定是自己当前使用电脑的gdb.exe路径
"program" 一定是cmakelists.txt生成的可执行文件的路径及名字
"preLaunchTask" 如果要只调试当前生成的exe文件，可将此行注释。如果是先build再直接调试则不用注释。（注：build 和debug是分开的，不注释则合并在一起操作了，如果注释了，要先手动build，再debug）

✅tasks.json：
该配置文件下面有三个task，供launch.json文件中"preLaunchTask" 选择，选择make即可。

🔵总结：
创建工程时，工程目录下创建 .vscode build src include 文件夹。
将三个.json配置文件直接拷贝到.vscode文件夹下，子目录的CMakeLists.txt放到src文件夹下面。主目录的CMakeLists.txt放到工程文件夹下面。环境便配置好了。之后就可以将自己写的头文件源文件放到include和src文件夹下面。
src include 文件夹名字若要修改，同时必须修改主目录下的CMakeLists.txt相关文件名。
build 文件夹下的东西可直接删除，避免污染源程序
