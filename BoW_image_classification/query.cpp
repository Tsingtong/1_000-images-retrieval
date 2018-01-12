#include "BagOfFeature.h" 
#include "boost/move/unique_ptr.hpp"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

//HTML _Edited by liuqingtong 
void writeHtml(vector<pair<string,float> > result,string queryImg,string classification){
	int flag = 0;
	ofstream ofs("result.html");
	if (!ofs) throw runtime_error("Cannot open file.");
	ofs << "<html><head><style> img {width:250px; border:0px; margin:5px 5px; padding:0px 0px;} .divcss5{text-align:center} </style></head><body><div class=\"divcss5\"><h2>Query</h2><div><img src=\"" << queryImg << "\" alt=\"\" /><br />";
	ofs << "<div class=\"divcss5\"><h2>Result="<<classification<<"</h2></div><table><tbody>";
	ofs <<"<div align='center' style='margin-left:auto;margin-right:auto'>";
	for (vector<pair<string,float> >::reverse_iterator iter=result.rbegin();iter!=result.rend();iter++) {
		ofs << "<div style='float:left'>" <<iter->second<<"<br>";
		ofs << "<img alt=\""<<iter->second<<"\" src=\"" << iter->first << "\" />";
		ofs <<"</div>";
	}
	ofs <<"</div>";
	ofs << "</tbody></table></body></html>";
	ofs.close();
	cerr << "Html outputted." << endl;
}

int main(int argc, char **argv){
	if(argc !=2){
		cout<<"please input ./query /x/x/x/x.jpg"<<endl;
		return -1;
	}
	string queryImg=argv[1];
	cout<<"queryis:"<<queryImg;
	boost::movelib::unique_ptr<BagOfFeature> bow(new BagOfFeature());

	//load the codebook here
	string dictDir="/home/liu/Desktop/BoW_image_classification/data/dictionary.yml";
	Mat dictionary=bow->loadDictionay(dictDir);
	cout<<"dictionary size: "<<dictionary.size()<<endl;

	Mat idf;
	Mat bows=bow->loadBows("/home/liu/Desktop/BoW_image_classification/data/bows.yml",idf);
	cout<<"bows size:"<<bows.size()<<endl;
	Mat img = imread(queryImg);

	clock_t last_time=clock();
	vector<pair<string,float> > result= bow->queryImg(img,dictionary,bows,idf);

	//Result_to_html _Written by liuqingtong 
	int sequence[15];
	int flag_seq=0;
	cout<<"Similarity images:"<<"\n";
	for (vector<pair<string,float> >::reverse_iterator iter=result.rbegin();iter!=result.rend();iter++){
		string name_s;	
		name_s = iter->first.substr(29,7);
		if ( ! (istringstream(name_s) >> sequence[flag_seq]) ) sequence[flag_seq] = 0;  
		flag_seq++;
	}
	
	string classification;
	if(sequence[0]>=0 && sequence[0]<=108){
		classification="people";
	}
	else if(sequence[0]>=109 && sequence[0]<=199){
		classification="beach";
	}
	else if(sequence[0]>=200 && sequence[0]<=299){
		classification="building";
	}
	else if(sequence[0]>=300 && sequence[0]<=399){
		classification="bus";
	}
	else if(sequence[0]>=400 && sequence[0]<=499){
		classification="dinosaur";
	}
	else if(sequence[0]>=500 && sequence[0]<=599){
		classification="elephant";
	}
	else if(sequence[0]>=600 && sequence[0]<=699){
		classification="flower";
	}
	else if(sequence[0]>=700 && sequence[0]<=799){
		classification="horse";
	}
	else if(sequence[0]>=800 && sequence[0]<=899){
		classification="mountain";
	}
	else if(sequence[0]>=900 && sequence[0]<=999){
		classification="food";
	}

	writeHtml(result,queryImg,classification);
	cout<<"retrieval time used :"<<(double)(clock()-last_time)/CLOCKS_PER_SEC<<endl;
	return 0;
}
