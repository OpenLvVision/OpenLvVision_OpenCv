#include "ObjectDetection.h"

using namespace cv;
using namespace std;
using namespace lvi;
using namespace lvi::mat;
using namespace lvi::array;
using namespace lvi::point;
using namespace lvi::error;
using namespace lvi::edvr;

_declspec(dllexport) void CV_OBJECTDETECTION_matchTemplate(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc,  
    void* addressResult, lvi::mat::MatInfo* matInfResult,
	void* addressTempl, lvi::mat::MatInfo* matInfoTempl,
    void* addressMask, lvi::mat::MatInfo* matInfoMask,
    int32_t methode)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat templ = lvMatToCvMat(addressTempl, matInfoTempl);
        Mat result = lvMatToCvMat(addressResult, matInfResult);
        Mat mask = lvMatToCvMat(addressMask, matInfoMask);

        if (!mask.empty())
        {
			cv::matchTemplate(src, templ, result, methode, noArray());
        }
        else
        {
            cv::matchTemplate(src, templ, result, methode, mask);
        }

        return mgNoErr;
    });
}