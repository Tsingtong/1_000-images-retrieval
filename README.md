# 1_000-images-classification
1_000-images-classification Branch:master<br>

# 适配了Ubuntu 16.04LTS版本，并修改了部分代码
由 luminglin 创建, liuqingtong 针对 ubuntu16.04LTS 进行了适配
* 在ubuntu 16.04LTS系统基础上进行了适配，并且改变智能指针`auto_ptr`为`unique_ptr`
* 在query中增加了1000张图片遍历查询方法(ongoing...)
  
# 使用步骤

## 1. 配置环境
* Ubuntu 16.04 LTS<br>
`Ubuntu 16.04 LTS` from http://releases.ubuntu.com/16.04/ubuntu-16.04.3-desktop-amd64.iso <br>

* OpenCV 2.4.13<br>
编译安装 `opencv2.4.13` from https://github.com/opencv/opencv/archive/2.4.13.5.zip <br>

* C++11<br>
introduction from https://gcc.gnu.org/onlinedocs/gcc-4.8.1/libstdc++/manual/manual/status.html#status.iso.2011

### 确认makefile文件
确认`makefile`中`C 编译器的选项`、`include路径`、`lib路径`都为正确的路径，以下为标准路径样式<br>
```
# Example
CFLAGS = -std=c++11
INCPATH = -I/usr/local/include
LIBPATH = -L/usr/local/lib
```

## 2. 下载1000张图片集
下载图像集 from PSU
![psu](http://112.74.19.125/owncloud/index.php/s/PCLoyIewd1b6nqY/download)
```
wget http://wang.ist.psu.edu/~jwang/test1.tar
```
tar -zxvf 到本地文件夹，并在train.cpp中修改目录地址为解压出来的文件目录`.../image.orig`

## 3. 编译
```
make...
```
我们将得到三个可执行文件：train genBOW query<br>
* 预计遇到的问题及解决方案<br>
 1.  缺少include文件`"boost/move/unique_ptr.hpp"`<br>
```
sudo apt-get install libboost-dev
```

## 4. 执行程序
在shell中依次执行下面三步

* `./train 1000`<br>
    训练文件夹中的1000张图片<br>
![train](http://112.74.19.125/owncloud/index.php/s/CVMcIMV7xpEg97c/download)

* `./genBOW /Users/lml/Desktop/image.orig/`<br>
    为每张图片生成BoW Mat，包括idf<br>
![genBOW](http://112.74.19.125/owncloud/index.php/s/Pw4U8fo0FZxIrkF/download)

* `./query /Users/lml/Desktop/image.orig/999.jpg`<br>
    查询某图片的检索结果<br>
![query](http://112.74.19.125/owncloud/index.php/s/jjiU3NrdSdF4N1v/download)

## 查看结果
   结果保存为html文件了，可以在./result.html中查看执行的结果了
![result](http://112.74.19.125/owncloud/index.php/s/Hn4iRi48iLo8gCa/download)
* 如遇到result.html页面内图片不显示问题，请检查cpp文件中的目录路径是否填写正确，修改后重新编译生成

# 相关链接
* bag-of-words-dev-version<br>
https://github.com/willard-yuan/image-retrieval/tree/master/bag-of-words-dev-version
* vocabtree<br>
https://github.com/psastras/vocabtree
