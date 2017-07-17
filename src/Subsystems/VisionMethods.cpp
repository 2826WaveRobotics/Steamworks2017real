/*
 * VisionMethods.h
 *
 *  Created on: Feb 3, 2017
 *      Author: matthewacho
 */
#include "../GripPipeline.h"
#include "../Robot.h" //If you don't know what some variables are, they were probably defined in here
#include <string>
#include <vector>
#ifndef SRC_VISIONMETHODS_H_
#define SRC_VISIONMETHODS_H_


std::vector<std::vector<cv::Point>> filteredContours(int cameranum) {
	cv::Mat frame;
	cv::VideoCapture cap(cameranum);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	bool bSuccess = cap.read(frame);
	grip::GripPipeline gp;
	return gp.GripPipeline::findContoursOutput;
}

cv::Point centerOfContour(std::vector<cv::Point> contour) {
	int totalx=0.0; //given a contour, outputs its center
	int totaly=0.0;
	for(int d=0; d<contour.size();d++) {
		totalx+=contour[d].x;
		totaly+=contour[d].y;
	}
	cv::Point pt;
	pt.x=totalx/contour.size();
	pt.y=totaly/contour.size();
	return pt;
}

std::vector<cv::Point> contourCenters(std::vector<std::vector<cv::Point>> contours) {
	std::vector<cv::Point> centers; //given a vector of contours, outputs a vector consisting of their centers
	double totalx;
	double totaly;
	for(int c=0;c<contours.size();c++) {
		centers.push_back(centerOfContour(contours[c]));
	}
	return centers;
}

//std::string initialOrientation() {
//	int score=0; //negative for left, positive for right
//	std::vector<cv::Point> centers = contourCenters(filteredContours(cameraPortLow));
//	for(int c=0;c<centers.size();c++) {
//		if(centers[c].x>640/2+10) {
//			score++;
//		}
//		else if(centers[c].x<640/2-10) {
//			score--;
//		}
//	}
//	if(score==0) {return "middle";}
//	else if(score<0) {return "right";}
//	else {return "left";}
//}

#endif
