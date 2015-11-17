//
// Created by mereckaj on 11/17/15.
//

#include <opencv2/core/mat.hpp>
#include <opencv2/core.hpp>
#include "Utils.h"
cv::Mat StretchImage( cv::Mat& image )
{
    cv::Mat result = image.clone();
    // Find max value
    int image_rows = image.rows;
    int image_channels = image.channels();
    int values_on_each_row = image.cols * image_channels;
    uchar max = 0;
    for (int row=0; row < image_rows; row++) {
        uchar* value = image.ptr<uchar>(row);
        for (int column=0; column < values_on_each_row; column++)
        {
            if (*value > max)
                max= *value;
            value++;
        }
    }
    // Stretch values using a lookup-table
    int entries(256);
    cv::Mat lut(1,entries,CV_8U);
    for (int i=0; (i<256); i++)
        lut.at<uchar>(i) = (255*i)/max;
    cv::LUT(image,lut,result);

    return result;
}
cv::Mat JoinImagesHorizontally( cv::Mat& image1, cv::Mat& image2, int spacing, cv::Scalar passed_colour/*=-1.0*/ )
{
    cv::Mat result( (image1.rows > image2.rows) ? image1.rows : image2.rows,
                image1.cols + image2.cols + spacing,
                image1.type() );
    result.setTo(cv::Scalar(255,255,255));
    cv::Mat imageROI;
    imageROI = result(cv::Rect(0,0,image1.cols,image1.rows));
    image1.copyTo(imageROI);
    if (spacing > 0)
    {
        imageROI = result(cv::Rect(image1.cols,0,spacing,image1.rows));
        imageROI.setTo(cv::Scalar(255,255,255));
    }
    imageROI = result(cv::Rect(image1.cols+spacing,0,image2.cols,image2.rows));
    image2.copyTo(imageROI);
    return result;
}