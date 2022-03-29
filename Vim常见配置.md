## Vim配置

全局配置

```bash
/etc/vim/vimrc

/etc/vimrc
```

个人用户配置

```
~/.vimrc
```

配置示例（双引号是Vim配置的注释内容）

```bash
" 无需与Vi编辑器兼容
set nocompatible

" 打开语法高亮
syntax on

" 设置行号，命令模式下设置set nu
set number

" 在底部显示当前编辑器模式
set showmode

" 在底部显示当前输入的指令
set showcmd

" 设置UTF-8编码
set encoding=utf-8

" 启用256色
set t_Co=256

" 下一行的缩进自动与上一行保持一致
set autoindent

" tab显示等效的空格数
set tabstop=4

" 设置tab自动转为空格
set expandtab

" tab编辑等效的空格数
set softtabstop=4

" 显示相当于与光标行号
set relativenumber

" 光标所在行高亮
set cursorline

" 设置一行显示多少个字符
set textwidth=80

" 超出的行自动分行显示
set wrap

" 避免单词内部折叠，就和word一样
set linebreak

" 显示状态栏
set laststatus=2

" 在状态栏显示光标的当前位置
set  ruler

" 光标遇到圆括号、方括号、大括号时自动高亮配对的括号
set showmatch

" 搜索时，高亮显示匹配结果
set hlsearch

" 输入搜索模式时，每输入一个字符，就自动跳到第一个匹配的结果
set incsearch

" 搜索时忽略大小写
set ignorecase

" 不创建备份文件
set nobackup

" 不创建交换文件
set noswapfile

" 保留撤销历史
set undofile

" 出错提醒静音
set noerrorbells

" 出错时屏幕闪烁提醒
set visualbell

" Vim 需要记住多少次历史操作
set history=1000

" 命令模式下，底部操作指令按下 Tab 键自动补全
set wildmenu
set wildmode=longest:list,full
```

## Vim常用操作

Vim 共分为三种模式，分别是命令模式、输入模式和底线命令模式

### 保存 & 退出

进入输入模式 按 `I` / `O`，`O` 表示插入新行

设置行号 `:set nu` / `:set number`

保存并退出 `:wq` ，只保存 `:w` ，强制退出不保存 `:q!`

### 移动光标

上下左右移动光标 `K` 、`J`、`H`、`L`，目前普通键盘的上下左右键也支持，向上移动8行 `8K`

`CTRL` +  普通键盘的左右键快速跳到下一个单词

快读定位到15行 `:15`

定位到行首 数字 `0 `  ，定位到行尾 `$`，定位到下一行的行尾 `2$`

定位到文档头部 `gg` ，定位到文档尾部 `GG`

### 复制/粘贴/撤销

复制 `YY` ，复制3行 `3YY`

粘贴 `P` ，粘贴5次  `5P`

撤销 `U`，撤销10次 `10U`

### 删除操作

删除一行 `DD`， 删除8行 `8DD`

删除后面一个字符 `X`，删除5个字符 `5X`

### 快速注释操作

如何注释？

`CTRL V `进入可视模式，选择要注释的行，`Shift I` 进入插入模式，ESC回到命令模式

如何取消注释？

`CTRL V `进入可视模式，选择要取消注释的内容，按 `X` 删除即可

### 查找字符串

`?`  要查找的字符串，按回车键定位到结果行

>后面写代码的实际过程中我也会补充Vim的一些常用且实用的技巧