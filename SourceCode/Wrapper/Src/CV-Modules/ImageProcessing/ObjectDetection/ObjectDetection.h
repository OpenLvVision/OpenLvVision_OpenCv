#pragma once

#include "opencv2/imgproc.hpp"
#include "../../../Interorp/MatHandling/Mathandling.h"
#include "../../../Interorp/ErrorHandling/ErrorHandling.h"
#include "../../../Interorp/ArrayHandling/Array1D.hpp"
#include "../../../Interorp/ArrayHandling/Array2D.hpp"
#include "../../../Interorp/Points.hpp"

using namespace std;
using namespace cv;

extern "C"
{
    _declspec(dllexport) void CV_OBJECTDETECTION_matchTemplate(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressTempl, lvi::mat::MatInfo* matInfoTempl,
        void* addressResult, lvi::mat::MatInfo* matInfResult,
		void* addressMask, lvi::mat::MatInfo* matInfoMask,
        int32_t methode);
}