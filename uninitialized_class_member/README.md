# 未初始化的类成员

这个例子展示了：
- 一个典型的 C++ 错误： 类成员没有初始化就拿去使用，得到非预期的取值，这会引发潜在的内存非法访问， 造成crash
- 在基于 CMake 的构建中， 仅通过两行 CMake 代码， 就引入了 clang-tidy， 编译阶段检查到未初始化的问题

需要注意：
- 需要提前安装 clang-tidy
- 需要生成 compile_commands.json 文件， 否则 clang-tidy 可能不能生效
- Visual Studio 用户可以使用 VS 自带的 CodeAnalysis 中的 clang-tidy
- 如果不使用 .clang-tidy 文件， 会看到 warning，它是默认开启的 check 项中的
```bash
Error while trying to load a compilation database:
Could not auto-detect compilation database for file "main.cpp"
No compilation database found in /home/zz/.my_config/clang-tidy-examples/uninitialized_class_member or any parent directory
fixed-compilation-database: Error while opening fixed database: No such file or directory
json-compilation-database: Error while opening JSON database: No such file or directory
Running without flags.
1 warning generated.
/home/zz/.my_config/clang-tidy-examples/uninitialized_class_member/main.cpp:10:41: warning: The right operand of '*' is a garbage value [clang-analyzer-core.UndefinedBinaryOperatorResult]
        data = (int*)malloc(sizeof(int) * cameraNum);
                                        ^
/home/zz/.my_config/clang-tidy-examples/uninitialized_class_member/main.cpp:30:12: note: Calling default constructor for 'Entity'
    Entity e;
           ^
/home/zz/.my_config/clang-tidy-examples/uninitialized_class_member/main.cpp:10:41: note: The right operand of '*' is a garbage value
        data = (int*)malloc(sizeof(int) * cameraNum);
                                        ^ ~~~~~~~~~
```

- 使用的 .clang-tidy 则是把这一warning提升为error
```bash
1 warning generated.
/home/zz/.my_config/clang-tidy-examples/uninitialized_class_member/main.cpp:10:41: error: The right operand of '*' is a garbage value [clang-analyzer-core.UndefinedBinaryOperatorResult,-warnings-as-errors]
        data = (int*)malloc(sizeof(int) * cameraNum);
                                        ^
/home/zz/.my_config/clang-tidy-examples/uninitialized_class_member/main.cpp:30:12: note: Calling default constructor for 'Entity'
    Entity e;
           ^
/home/zz/.my_config/clang-tidy-examples/uninitialized_class_member/main.cpp:10:41: note: The right operand of '*' is a garbage value
        data = (int*)malloc(sizeof(int) * cameraNum);
                                        ^ ~~~~~~~~~
1 warning treated as error
```