#pragma once

#include "opencv2/videoio.hpp"
#include <opencv2/videoio/registry.hpp>
#include "../../Interorp/ErrorHandling/ErrorHandling.h"
#include "../../Interorp/ArrayHandling/Array1D.hpp"


extern "C"
{

    _declspec(dllexport) void CV_VIDEOIO_GetBackends(lvi::error::ErrorClusterPtr errorCluster,     
		lvi::array::LV_1DArrayHandle<cv::VideoCaptureAPIs> backendsHandle);

	_declspec(dllexport) void CV_VIDEOIO_GetCameraBackends(lvi::error::ErrorClusterPtr errorCluster,
		lvi::array::LV_1DArrayHandle<cv::VideoCaptureAPIs> backendsHandle);

	_declspec(dllexport) void CV_VIDEOIO_GetStreamBackends(lvi::error::ErrorClusterPtr errorCluster,
		lvi::array::LV_1DArrayHandle<cv::VideoCaptureAPIs> backendsHandle);

	_declspec(dllexport) void CV_VIDEOIO_GetWriterBackends(lvi::error::ErrorClusterPtr errorCluster,
		lvi::array::LV_1DArrayHandle<cv::VideoCaptureAPIs> backendsHandle);

}
