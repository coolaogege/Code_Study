<!-- 这是一个Markdown文档 -->
<!-- 以此记录Vscode中C++编译出现的问题 -->


# issue list

## 1. 编译多文件
    修改 tasks.json 中的 "${file}"  改为  "${fileDirname}\\*.cpp"  
    然而测试发现 改动之后  出现其他文件编译不通过
    因此学习阶段暂时不改动  -- 工程阶段 改动！
