#include "GripPipelineThree.h"

namespace grip {

GripPipelineThree::GripPipelineThree() {
}
/**
* Runs an iteration of the pipeline and updates outputs.
*/
void GripPipelineThree::Process(cv::Mat& source0){
	//Step HSL_Threshold0:
	//input
	cv::Mat hslThresholdInput = source0;

	if(source0.empty()){
		std::cout << "Source is empty!" << std::endl;
	}
	double hslThresholdHue[] = {0.0, 132.38907849829351};
	double hslThresholdSaturation[] = {0.0, 255.0};
	double hslThresholdLuminance[] = {2.559944165528518, 188.76498013675155};
	hslThreshold(hslThresholdInput, hslThresholdHue, hslThresholdSaturation, hslThresholdLuminance, this->hslThresholdOutput);
	//Step Find_Contours0:
	//input
	cv::Mat findContoursInput = hslThresholdOutput;
	bool findContoursExternalOnly = false;  // default Boolean
	findContours(findContoursInput, findContoursExternalOnly, this->findContoursOutput);
	//Step Filter_Contours0:
	//input
	std::vector<std::vector<cv::Point> > filterContoursContours = findContoursOutput;
	double filterContoursMinArea = 100.0;  // default Double
	double filterContoursMinPerimeter = 0.0;  // default Double
	double filterContoursMinWidth = 25.0;  // default Double
	double filterContoursMaxWidth = 200.0;  // default Double
	double filterContoursMinHeight = 5.0;  // default Double
	double filterContoursMaxHeight = 100.0;  // default Double
	double filterContoursSolidity[] = {70.14388489208633, 100.0};
	double filterContoursMaxVertices = 1000000.0;  // default Double
	double filterContoursMinVertices = 0.0;  // default Double
	double filterContoursMinRatio = 0.0;  // default Double
	double filterContoursMaxRatio = 1000.0;  // default Double
	filterContours(filterContoursContours, filterContoursMinArea, filterContoursMinPerimeter, filterContoursMinWidth, filterContoursMaxWidth, filterContoursMinHeight, filterContoursMaxHeight, filterContoursSolidity, filterContoursMaxVertices, filterContoursMinVertices, filterContoursMinRatio, filterContoursMaxRatio, this->filterContoursOutput);
}

/**
 * This method is a generated getter for the output of a HSL_Threshold.
 * @return Mat output from HSL_Threshold.
 */
cv::Mat* GripPipelineThree::GetHslThresholdOutput(){
	return &(this->hslThresholdOutput);
}
/**
 * This method is a generated getter for the output of a Find_Contours.
 * @return ContoursReport output from Find_Contours.
 */
std::vector<std::vector<cv::Point> >* GripPipelineThree::GetFindContoursOutput(){
	return &(this->findContoursOutput);
}
/**
 * This method is a generated getter for the output of a Filter_Contours.
 * @return ContoursReport output from Filter_Contours.
 */
std::vector<std::vector<cv::Point> >* GripPipelineThree::GetFilterContoursOutput(){
	return &(this->filterContoursOutput);
}
	/**
	 * Segment an image based on hue, saturation, and luminance ranges.
	 *
	 * @param input The image on which to perform the HSL threshold.
	 * @param hue The min and max hue.
	 * @param sat The min and max saturation.
	 * @param lum The min and max luminance.
	 * @param output The image in which to store the output.
	 */
	//void hslThreshold(Mat *input, double hue[], double sat[], double lum[], Mat *out) {
	void GripPipelineThree::hslThreshold(cv::Mat &input, double hue[], double sat[], double lum[], cv::Mat &out) {
		cv::cvtColor(input, out, cv::COLOR_BGR2HLS);
		cv::inRange(out, cv::Scalar(hue[0], lum[0], sat[0]), cv::Scalar(hue[1], lum[1], sat[1]), out);
	}

	/**
	 * Finds contours in an image.
	 *
	 * @param input The image to find contours in.
	 * @param externalOnly if only external contours are to be found.
	 * @param contours vector of contours to put contours in.
	 */
	void GripPipelineThree::findContours(cv::Mat &input, bool externalOnly, std::vector<std::vector<cv::Point> > &contours) {
		std::vector<cv::Vec4i> hierarchy;
		contours.clear();
		int mode = externalOnly ? cv::RETR_EXTERNAL : cv::RETR_LIST;
		int method = cv::CHAIN_APPROX_SIMPLE;
		cv::findContours(input, contours, hierarchy, mode, method);
	}


	/**
	 * Filters through contours.
	 * @param inputContours is the input vector of contours.
	 * @param minArea is the minimum area of a contour that will be kept.
	 * @param minPerimeter is the minimum perimeter of a contour that will be kept.
	 * @param minWidth minimum width of a contour.
	 * @param maxWidth maximum width.
	 * @param minHeight minimum height.
	 * @param maxHeight  maximimum height.
	 * @param solidity the minimum and maximum solidity of a contour.
	 * @param minVertexCount minimum vertex Count of the contours.
	 * @param maxVertexCount maximum vertex Count.
	 * @param minRatio minimum ratio of width to height.
	 * @param maxRatio maximum ratio of width to height.
	 * @param output vector of filtered contours.
	 */
	void GripPipelineThree::filterContours(std::vector<std::vector<cv::Point> > &inputContours, double minArea, double minPerimeter, double minWidth, double maxWidth, double minHeight, double maxHeight, double solidity[], double maxVertexCount, double minVertexCount, double minRatio, double maxRatio, std::vector<std::vector<cv::Point> > &output) {
		std::vector<cv::Point> hull;
		output.clear();
		for (std::vector<cv::Point> contour: inputContours) {
			cv::Rect bb = boundingRect(contour);
			if (bb.width < minWidth || bb.width > maxWidth) continue;
			if (bb.height < minHeight || bb.height > maxHeight) continue;
			double area = cv::contourArea(contour);
			std::cout << "Areas?:  " << area << std::endl;
			if (area < minArea) continue;
			if (arcLength(contour, true) < minPerimeter) continue;
			cv::convexHull(cv::Mat(contour, true), hull);
			double solid = 100 * area / cv::contourArea(hull);
			if (solid < solidity[0] || solid > solidity[1]) continue;
			if (contour.size() < minVertexCount || contour.size() > maxVertexCount)	continue;
			double ratio = (double) bb.width / (double) bb.height;
			if (ratio < minRatio || ratio > maxRatio) continue;
			output.push_back(contour);

			std::cout << "Height" << bb.height << std::endl;

				std::cout << "Ratio: ";
				for(unsigned int i=1; i < bb.height; i++){
					double ratio = bb.height[i]/bb.width[i];
					std::cout << ratio << " ";

//					if(fabs(ratio-0.45)< fabs(heights[bestContour]/widths[bestContour] - .45)){
//						bestContour = i;
//						std::cout << "Best Contour =  " << bestContour << std::endl;
//					}
					//visionMethods->filteredContours(i);

				}
				std::cout << std::endl;
			//
//				if(widths[bestContour] > 30 && widths[bestContour] < 60 ){
//					std::cout << "In target range" << std::endl;
//					Robot::drivePID->ArcadeDrive(0, 0, 0);
//				}
//				else if (widths[bestContour] < 40){
//					Robot::drivePID->ArcadeDrive(-.6, 0, 0);
//				}
//				else{
//					Robot::drivePID->ArcadeDrive(.6, 0, 0);
//				}
		}
	}

//	void GripPipelineThree::GetHeights(std::vector<std::vector<cv::Point> > &inputContours, double minArea, double minPerimeter, double minWidth, double maxWidth, double minHeight, double maxHeight, double solidity[], double maxVertexCount, double minVertexCount, double minRatio, double maxRatio, std::vector<std::vector<cv::Point> > &output) {
//			std::vector<cv::Point> hull;
//			output.clear();
//			for (std::vector<cv::Point> contour: inputContours) {
//				cv::Rect bb = boundingRect(contour);
//				if (bb.width < minWidth || bb.width > maxWidth) continue;
//				if (bb.height < minHeight || bb.height > maxHeight) continue;
//				double area = cv::contourArea(contour);
//				std::cout << "Areas?:  " << area << std::endl;
//				if (area < minArea) continue;
//				if (arcLength(contour, true) < minPerimeter) continue;
//				cv::convexHull(cv::Mat(contour, true), hull);
//				double solid = 100 * area / cv::contourArea(hull);
//				if (solid < solidity[0] || solid > solidity[1]) continue;
//				if (contour.size() < minVertexCount || contour.size() > maxVertexCount)	continue;
//				double ratio = (double) bb.width / (double) bb.height;
//				if (ratio < minRatio || ratio > maxRatio) continue;
//				output.push_back(contour);
//			}
//		}


} // end grip namespace

