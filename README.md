# 井字棋游戏 (Tic-Tac-Toe)

一个使用 C 语言开发的终端井字棋游戏，支持单人和双人模式。

## 功能特性

- 双人对战模式
- 3x3 棋盘显示
- 输入验证（防止重复落子和越界输入）
- 胜负判定与平局检测
- 支持多局连续游玩

## 项目结构

```
Tictactoe/
├── CMakeLists.txt        # CMake 构建配置
├── LICENSE               # MPL-2.0 许可证
├── README.md
├── include/              # 头文件
│   ├── chessboard.h
│   ├── piece.h
│   ├── player.h
│   └── tictactoe.h
├── Src/                  # 源代码
│   ├── main.c
│   ├── chessboard.c
│   ├── piece.c
│   ├── player.c
│   └── tictactoe.c
└── lib/                  # 依赖库
    └── queue/
```

## 构建与运行

### 环境要求

- CMake >= 3.10
- C11 兼容的编译器 (GCC / Clang / MSVC)

### 构建步骤

```bash
# 创建构建目录
mkdir build && cd build

# 生成构建文件
cmake ..

# 编译
cmake --build .

# 运行
./Tictactoe
```

### Windows (MSVC)

```cmd
mkdir build && cd build
cmake .. -G "Visual Studio 17 2022"
cmake --build . --config Release
.\Release\Tictactoe.exe
```

## 游戏规则

1. 游戏在 3x3 的棋盘上进行
2. 两位玩家轮流落子（X 和 O）
3. 先将三个棋子连成一线（横、竖、斜）的玩家获胜
4. 棋盘填满且无人获胜则为平局

## 许可证

本项目基于 [Mozilla Public License 2.0](LICENSE) 开源。
