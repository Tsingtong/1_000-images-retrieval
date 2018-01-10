# 1_000-images-classification
1_000-images-classification Branch:master

# 适配了Ubuntu 16.04LTS版本，修改了部分代码
Created by luminglin , Adapted by Tsingtong for ubuntu16.04LTS
* 在ubuntu 16.04LTS系统基础上进行了适配，并且改变智能指针`auto_ptr`为`unique_ptr`
* 在query文件中增加了1000张图片遍历查询方法(ongoing...)

  通过对每张图片用SIFT算法提取特征表达和特征描述后生成BoWs

  完成了idf计算
  
# 使用步骤

## 1. 配置环境
需要安装 `opencv2.4.13` from https://github.com/opencv/opencv/archive/2.4.13.5.zip 

确认`makefile`中`C 编译器的选项`、`include路径`、`lib路径`都为正确的路径，以下为标准路径
```
# Example
CFLAGS = -std=c++11
INCPATH = -I/usr/local/include
LIBPATH = -L/usr/local/lib
```

## 2. 下载1000张图片
下载图像集
```
wget http://wang.ist.psu.edu/~jwang/test1.tar
```
tar -zxvf 到本地文件夹，并在train.cpp中修改目录地址为解压出来的文件目录`.../image.orig`

## 3. 编译
`make`...
我们得到三个可执行文件：train genBOW query

## 4. 执行程序
在shell中依次执行下面三步

* `./train 1000`
    训练文件夹中的1000张图片
    
* `./genBOW /Users/lml/Desktop/image.orig/`
    为每张图片生成BoW Mat，包括idf

* `./query /Users/lml/Desktop/image.orig/999.jpg`
    现在可以在./result.html中查看执行的结果了
    如遇到图片不显示问题，请逐一在每个cpp文件中的检查目录路径是否正确

# 相关链接
https://github.com/willard-yuan/image-retrieval/tree/master/bag-of-words-dev-version
https://github.com/psastras/vocabtree
