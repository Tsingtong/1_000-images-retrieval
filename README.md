# 1_000-images-classification
Using BoW to classify 1000 images<br>
1_000-images-classification Branch:master<br>
Source was created by luminglin on 2017.11.17<br>

# 版本日志
适配了Ubuntu 16.04LTS版本，并修改了部分代码
* 新增html页面显示图片查询结果及分类
* 改变智能指针`auto_ptr`为`unique_ptr`
* 图片集已经整合到release的repo中，无需单独下载图片集

# 目录结构
* 你将用到以下两个文件夹<br>
./BoW_image_classification ..................... Project dir<br>
./image.orig ................................................... Dataset dir<br>
* 图片集标签<br>
./image.orig_index.txt<br>

# 使用步骤

## 1. 配置环境
* Ubuntu 16.04 LTS<br>
`Ubuntu 16.04 LTS` from http://releases.ubuntu.com/16.04/ubuntu-16.04.3-desktop-amd64.iso <br>

* OpenCV 2.4.13<br>
编译安装 `opencv2.4.13` from https://github.com/opencv/opencv/archive/2.4.13.5.zip <br>

* C++11<br>
introduction from https://gcc.gnu.org/onlinedocs/gcc-4.8.1/libstdc++/manual/manual/status.html#status.iso.2011
Ubuntu 16.04 LTS 默认C编译器为c++11

### 修改makefile文件
* 若按默认安装编译方式编译的OpenCV 2.4.13，则可不用修改makefile文件，直接进行下一步
确认`makefile`中`C 编译器的选项`、`include路径`、`lib路径`都为正确的路径，以下为标准路径样式<br>
```
# Example
CFLAGS = -std=c++11
INCPATH = -I/usr/local/include
LIBPATH = -L/usr/local/lib
```

## 2. 修改路径
修改`BagOfFeature.cpp`,`query.cpp`,`train.cpp`中的路径字符串，确保正确的`image.orig`路径和`data`路径被描述

## 3. 编译
```
make
```
我们将得到三个可执行文件：train genBOW query<br>
* 预计遇到的问题及解决方案<br>
 1.  缺少include文件`"boost/move/unique_ptr.hpp"`<br>
```
sudo apt-get install libboost-dev
```

## 4. 执行程序
在shell中依次执行下面三条命令

* `./train 1000`<br>
    训练文件夹中的1000张图片<br>
![train](https://github.com/Tsingtong/1_000-images-classification/raw/release/Screenshots/train.png)

* `./genBOW /Users/lml/Desktop/image.orig/`<br>
    为每张图片生成BoW Mat，包括idf<br>
![genBOW](https://github.com/Tsingtong/1_000-images-classification/raw/release/Screenshots/genBOW.png)

* `./query /Users/lml/Desktop/image.orig/999.jpg`<br>
    查询某图片的检索结果<br>
![query](https://github.com/Tsingtong/1_000-images-classification/raw/release/Screenshots/query.png)

## 查看结果
   结果保存为html文件了，可以在./result.html中查看执行的结果了
![result](https://github.com/Tsingtong/1_000-images-classification/raw/release/Screenshots/result.png)
* 如遇到result.html页面内图片不显示问题，请检查cpp文件中的目录路径是否填写正确，修改后重新编译生成

# 相关链接
* bag-of-words-dev-version<br>
https://github.com/willard-yuan/image-retrieval/tree/master/bag-of-words-dev-version
* vocabtree<br>
https://github.com/psastras/vocabtree
