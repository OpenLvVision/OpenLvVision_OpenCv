#include "VideoIO.h"

using namespace cv;
using namespace lvi::array;

_declspec(dllexport) void CV_VIDEOIO_GetBackends(lvi::error::ErrorClusterPtr errorCluster,
    lvi::array::LV_1DArrayHandle<cv::VideoCaptureAPIs> backendsHandle)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        Array1D<cv::VideoCaptureAPIs> backendsArr(backendsHandle);
            
        std::vector<cv::VideoCaptureAPIs> backendsEnum = videoio_registry::getBackends();       

        return backendsArr.copyFrom(backendsEnum);
    });
}

_declspec(dllexport) void CV_VIDEOIO_GetCameraBackends(lvi::error::ErrorClusterPtr errorCluster,
    lvi::array::LV_1DArrayHandle<cv::VideoCaptureAPIs> backendsHandle)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        Array1D<cv::VideoCaptureAPIs> backendsArr(backendsHandle);

        std::vector<cv::VideoCaptureAPIs> backendsEnum = videoio_registry::getCameraBackends();

        return backendsArr.copyFrom(backendsEnum);
    });
}

_declspec(dllexport) void CV_VIDEOIO_GetStreamBackends(lvi::error::ErrorClusterPtr errorCluster,
    lvi::array::LV_1DArrayHandle<cv::VideoCaptureAPIs> backendsHandle)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        Array1D<cv::VideoCaptureAPIs> backendsArr(backendsHandle);

        std::vector<cv::VideoCaptureAPIs> backendsEnum = videoio_registry::getStreamBackends();

        return backendsArr.copyFrom(backendsEnum);
    });
}

_declspec(dllexport) void CV_VIDEOIO_GetWriterBackends(lvi::error::ErrorClusterPtr errorCluster,
    lvi::array::LV_1DArrayHandle<cv::VideoCaptureAPIs> backendsHandle)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        Array1D<cv::VideoCaptureAPIs> backendsArr(backendsHandle);

        std::vector<cv::VideoCaptureAPIs> backendsEnum = videoio_registry::getWriterBackends();

        return backendsArr.copyFrom(backendsEnum);
    });
}