/*
 * Cluster.h
 *
 *  Created on: Oct 25, 2017
 *      Author: potato
 */

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Color.h"
#include <iostream>
#include <vector>
#include <map>

using namespace cv;
using namespace std;

#ifndef CLUSTER_H_
#define CLUSTER_H_



class Cluster {
public:
	Cluster(String file,int clusters_);
	virtual ~Cluster();
	void show();
	void execute();



private:
	Mat image;
	vector<Color>means;
	vector<vector<Color> > pixels;
	map<pair<int,int>,int > clusters;
	void updateMeans();


};

#endif /* CLUSTER_H_ */
