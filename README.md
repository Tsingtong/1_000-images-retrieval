#  k-means image compression
* Written by `Qingtong` in `2017-01-08`
* 用k-means算法对图片进行压缩<br>
* 此算法使用了[OpenCV](https://opencv.org)开源计算机视觉库<br>
## Procedure
1. 读入图片<br>
```c++
image = imread(file,CV_LOAD_IMAGE_COLOR;
imshow("real",image);
```
2. 创建10个聚类中心<br>
```c++
means.resize(clusters_);
```
3. 进行10次聚类尝试<br>
```c++
for(int i = 0;i<means.size();i++)
	if( abs(preVals[i].B - means[i].B) + abs(preVals[i].G - means[i].G) + abs(preVals[i].R - means[i].R) > 10)
	{
		converged=false;
	}
```
4. 显示result&cluster<br>
```c++
imshow("clusters",clustercolors);
imshow("result",result);
```
## Example
### real
![real](http://112.74.19.125/owncloud/index.php/s/8PyoRhqFWAtxUiI/download "real")
### result
![result](http://112.74.19.125/owncloud/index.php/s/bDr914hNhL7yob6/download "result")
### cluster
![cluster](http://112.74.19.125/owncloud/index.php/s/u0Y2U4jYraN1NZ1/download "cluster")
