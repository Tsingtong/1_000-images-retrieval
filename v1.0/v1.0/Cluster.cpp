/*
 * Cluster.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: potato
 */

#include "Cluster.h"

using namespace std;

Cluster::Cluster(String file,int clusters_) {

	image = imread(file,CV_LOAD_IMAGE_COLOR);

	imshow("real",image);
	if(! image.data )                              // Check for invalid input
	{
		cout <<  "Could not open or find the image" << std::endl ;
	}
	means.resize(clusters_);

	for(int i = 0;i<means.size();i++){
		means[i].makeRandom();
	}

	pixels.resize(image.rows);



	for(int i =0;i<image.rows;i++){
		pixels[i].resize(image.cols);

		for(int j = 0;j<image.cols;j++){
			//BGR

			pixels[i][j]=Color(image.at<Vec3b>(i,j)[2],image.at<Vec3b>(i,j)[1],image.at<Vec3b>(i,j)[0]);

		}

	}
	Mat result(image.rows,image.cols,CV_8UC3);
	cout<<"2"<<endl;
	for(int i = 0;i<result.rows;i++)
		for(int j = 0;j<result.cols;j++){
			result.at<cv::Vec3b>(i,j)[1] = pixels[i][j].G;
			result.at<cv::Vec3b>(i,j)[2] = pixels[i][j].R;
			result.at<cv::Vec3b>(i,j)[0] = pixels[i][j].B;
		}

	imshow("real2",result);




	// TODO Auto-generated constructor stub

}

Cluster::~Cluster() {
	// TODO Auto-generated destructor stub
}

void Cluster::execute(){

	bool converged = false;
	while(!converged){
		cout<<"not converged"<<endl;
		vector<Color>preVals;
		for(int i = 0;i<means.size();i++)
			preVals.push_back(means[i]);
		updateMeans();
		converged = true;
		for(int i = 0;i<means.size();i++)
			if( abs(preVals[i].B - means[i].B) + abs(preVals[i].G - means[i].G) + abs(preVals[i].R - means[i].R) > 10){
				converged=false;
			}
	}
}
void Cluster::show(){
	Mat result(image.rows,image.cols,CV_8UC3);
	cout<<"2"<<endl;
	for(int i = 0;i<result.rows;i++)
		for(int j = 0;j<result.cols;j++){
			result.at<cv::Vec3b>(i,j)[0] = means[clusters[make_pair(i,j)]].G;
			result.at<cv::Vec3b>(i,j)[2] = means[clusters[make_pair(i,j)]].R;
			result.at<cv::Vec3b>(i,j)[1] = means[clusters[make_pair(i,j)]].B;




		}

	Mat clustercolors(means.size()*50,100,CV_8UC3);
	cout<<"2"<<endl;
	for(int i = 0;i<clustercolors.rows;i++)
		for(int j = 0;j<clustercolors.cols;j++){
			clustercolors.at<cv::Vec3b>(i,j)[1] = means[i/50].B;
			clustercolors.at<cv::Vec3b>(i,j)[2] = means[i/50].R;
			clustercolors.at<cv::Vec3b>(i,j)[0] = means[i/50].G;




		}

	while(1){

		imshow("clusters",clustercolors);
		imshow("result",result);

		waitKey(0);
	}
}


void Cluster::updateMeans(){
	for(int i = 0;i<pixels.size();i++){
		for(int j = 0;j<pixels[i].size();j++){
			int minIndex = 0;
			for(int k = 0;k<means.size();k++)
				if(means[k].colorDistance(pixels[i][j])<means[minIndex].colorDistance(pixels[i][j]))
					minIndex=k;
			clusters[make_pair(i,j)] = minIndex;
		}
	}

	for(int i = 0;i<means.size();i++){
		int counter=0;
		Color sum;
		for(int j = 0;j<pixels.size();j++)
			for(int k = 0;k<pixels[j].size();k++)
				if(clusters[make_pair(j,k)]==i){
					sum=sum+pixels[j][k];
					counter++;
				}

		means[i] = counter!=0?sum/counter:means[i];

	}
	Mat result(image.rows,image.cols,CV_8UC3);
	cout<<"2"<<endl;
	for(int i = 0;i<result.rows;i++)
		for(int j = 0;j<result.cols;j++){
			result.at<cv::Vec3b>(i,j)[1] = means[clusters[make_pair(i,j)]].B;
			result.at<cv::Vec3b>(i,j)[2] = means[clusters[make_pair(i,j)]].R;
			result.at<cv::Vec3b>(i,j)[0] = means[clusters[make_pair(i,j)]].G;
		}

	imshow("temp",result);
	waitKey(100);


}


