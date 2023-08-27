# 让 clang-tidy 检查 .h 文件

## 目的
在 .h 文件中， 想把小写字母开头的 `struct node` 报告出来， 提示用户修改为 `struct Node`.

## 解决方法

### 1. compile_commands.json 文件
确保生成了 compile_commands.json 文件。 如果是 VS 工程， 请安装 Clang Power Tools 插件， 开启 VS， 项目右键， 生成 compile_commands.json， 并拷贝到工程根目录。

### 2. .clang-tidy 文件
确保准备了 .clang-tidy 文件， 里面配置了 struct 命名风格为 CamelCase。

### 3. C++ 代码
这一步是在 CMakeLists.txt 里做检查和配置， 确保生成的 compile_commands.json 中， 有 "-x c++" 参数， 而不是 "-x c" 参数。

在 CMakeLists.txt 中， 确保当前 target 至少有一个 .cpp 文件。 如果是纯C工程， 也就是说没有 .cpp 文件， 那就没法检查了。。

## Reference
https://stackoverflow.com/questions/44888329/clang-tool-how-to-treat-h-header-as-c-file/76684972#76684972