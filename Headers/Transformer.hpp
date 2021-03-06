//
// Created by mereckaj on 11/18/15.
//

#ifndef VISIONASSIGNMENT2_TRANSFORMER_H
#define VISIONASSIGNMENT2_TRANSFORMER_H

#include <opencv2/core/mat.hpp>

class Transformer{
public:

    Transformer();

    Transformer(cv::Mat src);

    ~Transformer();

    std::vector<cv::Point> FindCorners(cv::Mat);

    std::vector<cv::Point> WhiteToPoints(cv::Mat src);

    cv::Mat Draw(cv::Mat src,std::vector<cv::Point> vector,cv::Scalar color);

    cv::Mat Transform(cv::Mat src, std::vector<cv::Point> corners, std::vector<cv::Point> transformationRefPoints);

    cv::Mat UnsharpMask(cv::Mat im);

    std::vector<cv::Point> FindTemplateCorners(cv::Mat mat);

    cv::Mat Crop(cv::Mat src, cv::Mat ref);

    cv::Mat Sharpen(cv::Mat src);

    std::vector<std::vector<cv::Point>> FindClosestPoints(std::vector<cv::Point> corners, cv::Mat dots);

    cv::Mat DrawLine(cv::Mat mat, std::vector<std::vector<cv::Point>> vector);

    std::vector<cv::Vec4f> LinesOfBestFit(std::vector<std::vector<cv::Point>> lines);

    cv::Mat DrawVectorLines(cv::Mat src,std::vector<cv::Vec4f> vecs);

    std::vector<cv::Point> FindApproximateCornersFromCentresOfComponents(std::vector<cv::Point> moments);

    std::vector<cv::Point> FindIntersections(cv::Mat cv, std::vector<cv::Vec4f> rays);

private:

    cv::Mat mImage;

    std::vector<std::vector<cv::Point>> mPoints;

    std::vector<cv::Point> WhitePixelsToPoints(cv::Mat dots);

    cv::Point Intersection(cv::Vec4f a, cv::Vec4f b);
};
#endif //VISIONASSIGNMENT2_TRANSFORMER_H
